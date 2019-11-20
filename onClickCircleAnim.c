#include<stdio.h> 
#include<GL/glut.h>
#include <unistd.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795
double x,y,j,i;

// function to initialize 
void myInit (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	
} 
void show(double X, double Y)
{
	for(j=0.0; j<=0.5; j+=0.0001)
	{ 	
		glClear(GL_COLOR_BUFFER_BIT); 
		glColor3f(j+j, 1.0-j-j, j+j+j); 
		glBegin(GL_LINE_LOOP);
		for (i = 0;i < 2*PI;i +=2*PI/ 30 ) 
		{
			glVertex2f( X + j * cos(i), Y + j * sin(i)); 
		} 
		glEnd();
		glFlush();
	}
	
	for(j=0.5; j>=0.0; j-=0.0001)
	{ 
		glClear(GL_COLOR_BUFFER_BIT); 
		glColor3f(j+j, 1.0-j-j, j+j+j); 
		glBegin(GL_LINE_LOOP);
		for (i = 0;i < 2*PI;i +=2*PI/ 30 ) 
		{
			glVertex2f( X + j * cos(i), Y + j * sin(i)); 
		} 
		glEnd();
		glFlush();
	}	
}
void mouseClick(int button, int state, int X, int Y)
{	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		show((X-250)*(2.0/500),(250-Y)*(2.0/500));
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
	glutCreateWindow("Cicle Animation"); 
	myInit(); 
	//glutDisplayFunc(display);
	glutMouseFunc(mouseClick);
	glutMainLoop(); 
} 


