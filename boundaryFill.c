#include<stdio.h> 
#include <stdlib.h>
#include<GL/glut.h>
#include <unistd.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795
double Point[100][100];
int k=0;
int numbPoint=0;
float fillCol[3]={1,1,1};
float borderCol[3]={1,1,1};

void type(char *string, double X, double Y)
{
	char *c;
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(X+1,Y);
	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
	}
}
void myName()
{
	glClear(GL_COLOR_BUFFER_BIT);
	type("Ayush Jain", 5, 990);
	type("CSE-CCVT B-1",5, 975);
	type("R110217039",5, 960);
	glFlush();

}

// function to initialize 
void myInit (void) 
{ 	
	// making background color black as first 
	// 3 arguments all are 0.0 
	gluOrtho2D(0,1000,0,1000);
	glClearColor(0.0, 0.0, 0.0, 0.0); 
	myName(); 
}
void setPixel(float x, float y){
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_POINTS);
  glVertex2f(x,y);
  glEnd();
}

void bfill(int x, int y, float fill[3], float boundary[3])
{
  	float current[3];
	glReadPixels(x, y, 1, 1, GL_RGB,GL_FLOAT, current);
	
	if(
		(current[0]!=boundary[0] && current[1]!=boundary[1] && current[2]!=boundary[2]) &&
		(current[0]!=fill[0] && current[1]!=fill[1] && current[2]!=fill[2])
	  )
	 {
    	setPixel(x,y);

		bfill(x,y-1,fill,boundary);
    	bfill(x-1,y,fill,boundary);
		bfill(x+1,y,fill,boundary);	    
	    bfill(x,y+1,fill,boundary);
		
    	//bfill(x-1,y-1,fill,boundary);
	    //bfill(x-1,y+1,fill,boundary);
	    //bfill(x+1,y-1,fill,boundary);
    	//bfill(x+1,y-1,fill,boundary);

	  	glFlush();
  	}

}
 
void Draw()
{
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	for(int i=k; i<numbPoint; i++)
	{
		glColor3f(1.0,1.0,1.0);
		glVertex2f(Point[i][0], Point[i][1]);
	}	
	glEnd(); 
	glFlush();
	
		
	k = numbPoint;

	
}
void store(double X, double Y)
{
	Point[numbPoint][0] = X;
	Point[numbPoint++][1] = Y;
	glPointSize(2);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2f(X,Y);
	glEnd(); 
	glFlush();
}
static void Key(unsigned char key, int x, int y)
{
    switch (key)
    {
      	case 32:
      		Draw();
			break;
	}
}
void mouseClick(int button, int state, int X, int Y)
{	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		store(X,(1000-Y));
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
		bfill(X,(1000-Y), fillCol, borderCol);
	}
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1000, 1000); 
	// Giving name to window 
	glutCreateWindow("Boundary Fill Algorithm"); 
	myInit(); 
	glutKeyboardFunc(Key);
	glutMouseFunc(mouseClick);
	glutMainLoop(); 
	return 0;
}
