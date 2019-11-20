#include<stdio.h> 
#include <stdlib.h>
#include<GL/glut.h>
#include <unistd.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795
double Point[100][2];
int k=0;
int numbPoint=0;

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

void DrawAxis()
{
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.0,1.0,0.8);
	glVertex2f(-500, 0);
	glVertex2f(500, 0);
	glVertex2f(0, 500);
	glVertex2f(0, -500);
	glEnd(); 
}

void DrawLine()
{
	glLineWidth(1);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(500, -2008/2);
	glVertex2f(-1008/4, 500);
	glEnd(); 
	type("4x + 2y + 8 = 0", -1008/4 + 15, 470);
	type("MIRROR",-1008/4 + 20, 455);
	glFlush();
}


void myName()
{
	glClear(GL_COLOR_BUFFER_BIT);
	type("Ayush Jain", -495, 490);
	type("CSE-CCVT B-1",-495, 475);
	type("R110217039",-495, 460);
	 DrawAxis();
	DrawLine();
	glFlush();

}

// function to initialize 
void myInit (void) 
{ 	
	// making background color black as first 
	// 3 arguments all are 0.0 
	gluOrtho2D(-500,500,-500,500);
	glClearColor(0.0, 0.0, 0.0, 0.0); 
	myName(); 
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
		
	//k = numbPoint;

	
}
void reflect()
{
	double x,y; 
	for(int i=k; i<numbPoint; i++)
	{
		x = (-3*Point[i][0]/5) - (4*Point[i][1]/5) - 16/5;
		y = (-4*Point[i][0]/5) + (3*Point[i][1]/5) - (4/5);
		Point[i][0] = x;
		Point[i][1] = y;
		
	}
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	myName();
	Draw();

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
		
		store(X-500,(500-Y));
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
		reflect();
	}
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1000, 1000); 
	// Giving name to window 
	glutCreateWindow("Reflection about an arbitrary line: 4x + 2y + 8 = 0"); 
	myInit(); 
	glutKeyboardFunc(Key);
	glutMouseFunc(mouseClick);
	glutMainLoop(); 
	return 0;
}
