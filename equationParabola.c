#include<stdio.h>
#include<string.h>
#include<GL/glut.h>
#include <math.h>
double center[100][2];
double point[100][2];
int count = 0;
int numbPoint=-1;
char buffer[10];

void type(char *string, double X, double Y)
{
	char *c;
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f((X+1),Y);
	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
	}
	glFlush();
}
void myName()
{
	type("Ayush Jain", -249, 240);
	type("CSE-CCVT B-1",-249, 225);
	type("R110217039",-249, 210);
	type("Question 01",-249, 195);

}
void myInit (void) 
{ 	
	// making background color black as first 
	// 3 arguments all are 0.0 
	gluOrtho2D(-250,250,-250,250);
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT);
	myName(); 
}
void equation()
{
	int P = 1;
	int Px = 0, Py = 50;

	while(Px<=5)
	{
		printf("(%d, %d)\n", Px, Py);
		glBegin(GL_POINTS);
		glColor3f(0.0, 1.0, 1.0);
		glVertex2i(Px, Py);
		glVertex2i(-Px, Py);
		glEnd(); 
		glFlush();
		
		if(P>=0){
			P = P-1;			

			
		}
		else{
			P = P + 2*(Px) + 1;
			++Px;	
		}
		--Py;
		
	}
type("y = 50 - x^2", -249, -225);
type("-5 <= x <= 5", -249,-240);

	
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
	glutInitWindowSize(500, 500);
	glutCreateWindow("|| Equation Parabola ||"); 
	myInit(); 
	glutKeyboardFunc(Key);
	glutDisplayFunc(equation);
	glutMainLoop(); 
} 
