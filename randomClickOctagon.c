#include<stdio.h> 
#include<GL/glut.h>
#include <unistd.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795
#define MAX_CLICK 3

int k=0;
int count=0;
int numbPoint=0;
double mousex, mousey;
// function to initialize 
void myInit (void) 
{ 	
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 
}
void draw(double X, double Y)
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(1.0, 1.0, 1.0); 
	glBegin(GL_LINE_LOOP);
	for (double i = 0;i < 2*PI;i +=2*PI/ 8 ) 
	{
		glVertex2f( X + 0.2 * cos(i), Y +  0.2 * sin(i)); 
	} 
	glEnd();
	glFlush();


}
void show(double X, double Y)
{
	for(double j=0.2; j<=0.5; j+=0.0001)
	{ 	
		glClear(GL_COLOR_BUFFER_BIT); 
		glColor3f(j+j, 1.0-j-j, j+j+j); 
		glBegin(GL_LINE_LOOP);
		for (double i = 0;i < 2*PI;i +=2*PI/ 8 ) 
		{
			glVertex2f( X + j * cos(i), Y + j * sin(i)); 
		} 
		glEnd();
		glFlush();
	}
	
	for(double j=0.5; j>=0.2; j-=0.0001)
	{ 
		glClear(GL_COLOR_BUFFER_BIT); 
		glColor3f(j+j, 1.0-j-j, j+j+j); 
		glBegin(GL_LINE_LOOP);
		for (double i = 0;i < 2*PI;i +=2*PI/ 8 ) 
		{
			glVertex2f( X + j * cos(i), Y + j * sin(i)); 
		} 
		glEnd();
		glFlush();
	}	
}

static void Key(unsigned char key, int x, int y)
{

    switch (key) {
      	case 27:
		glutDestroyWindow(1);
		break;
	case 32:
		show(mousex, mousey);
		
    }
}

void mouseClick(int button, int state, int X, int Y)
{	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mousex= (X-250)*(2.0/500);	
		mousey = (250-Y)*(2.0/500);	
		draw((X-250)*(2.0/500),(250-Y)*(2.0/500));
		glClear(GL_COLOR_BUFFER_BIT);
	}
}
int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	// giving window size in X- and Y- direction 
	glutInitWindowSize(500, 500); 
	// Giving name to window 
	glutCreateWindow("Random"); 
	myInit(); 
	glutKeyboardFunc(Key);
	glutMouseFunc(mouseClick);
	glutMainLoop(); 
} 


