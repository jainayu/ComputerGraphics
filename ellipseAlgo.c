#include<stdio.h>
#include<string.h>
#include<GL/glut.h>
#include <math.h>
#define A 200
#define B 100
double center[100][2]; 
double point[100][2];
int count = 0;
int numbPoint=-1;
char buffer[10];

void type(char *string, double X, double Y)
{
	char *c;
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(X+1,Y);
	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
	}
	glFlush();
}
void myName()
{
	type("Ayush Jain", -495, 490);
	type("CSE-CCVT B-1",-495, 475);
	type("R110217039",-495, 460);

}
void printXY(double X, double Y)
{
	gcvt(X,5,buffer);
	char str[20]={"( "};
	strcat(str, buffer);
	strcat(str, ", ");
	gcvt(Y,5,buffer);
	strcat(str, buffer);
	strcat(str, " )");
	type(str, X, Y);
}

void plot(double X, double Y)
{
	//printf("(%.2lf, %.2lf)\n", X, Y);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2f(X,Y);
	glEnd(); 
	glFlush();
}
void myInit (void) 
{ 	
	// making background color black as first 
	// 3 arguments all are 0.0 
	gluOrtho2D(-500,500,-500,500);
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT);
	myName(); 
}
void DrawEllipse()
{
	
	int a2 = pow(A, 2);
	int b2 = pow(B, 2);
	double Px = 0, Py = B;
	int P = (a2/4) + b2 - a2 * B;
	while(b2*Px <= a2*Py)
	{
		plot(Px+center[numbPoint][0], Py+center[numbPoint][1]);
		plot(Px+center[numbPoint][0], -Py+center[numbPoint][1]);
		plot(-Px+center[numbPoint][0], Py+center[numbPoint][1]);
		plot(-Px+center[numbPoint][0], -Py+center[numbPoint][1]);
		if(P>=0)
		{
			P+= b2 * (2*Px + 3) + a2 * (2 - 2*Py);
			--Py;
		}
		else
		{
			P+= b2 * (2*Px + 3);
		}
		++Px;
	}
	
	P = b2*pow((Px + (1/2)), 2) + a2*pow((Py - 1),2) - a2*b2; 
	while(Py >= 0)
	{
		plot(Px+center[numbPoint][0], Py+center[numbPoint][1]);
		plot(Px+center[numbPoint][0], -Py+center[numbPoint][1]);
		plot(-Px+center[numbPoint][0], Py+center[numbPoint][1]);
		plot(-Px+center[numbPoint][0], -Py+center[numbPoint][1]);
		if(P<0)
		{
			P+= b2 * (2*Px + 2) + a2 * (3 - 2*Py);
			++Px;
		}
		else
		{
			P+= a2 * (3 - 2*Py);
		}
		--Py;
	}
	

}

void mouseClick(int button, int state, int X, int Y)
{	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		X = X - 500;
		Y = 500 - Y;
	
		++numbPoint;
		center[numbPoint][0] = X;
		center[numbPoint][1] = Y;
		plot(X,Y);
		printXY(X, Y);
		DrawEllipse();
			
	}
}
static void Key(unsigned char key, int x, int y)
{
    switch (key) {
      	case 27:
			glutDestroyWindow(1);
			break;
	}
}
int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("|| Implementing Ellipse Algorithm ||"); 
	myInit(); 
	glutKeyboardFunc(Key);
	glutMouseFunc(mouseClick);
	glutMainLoop(); 
} 
