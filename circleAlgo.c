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
	char str[20]={"Center: ( "};
	strcat(str, buffer);
	strcat(str, ", ");
	gcvt(Y,5,buffer);
	strcat(str, buffer);
	strcat(str, " )");
	type(str, X, Y);
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
double clacRadius(double X, double Y)
{
	printf("Radous: %.2lf\n",sqrt((double)(pow(center[numbPoint][1]-Y, 2) + pow(center[numbPoint][0]-X, 2))));
	return sqrt((double)(pow(center[numbPoint][1]-Y, 2) + pow(center[numbPoint][0]-X, 2)));
}
void printR(double R, double X, double Y)
{
	gcvt(R,5,buffer);
	char str[20]={"Radius = "};
	strcat(str, buffer);
	type(str, X, Y);
}
void DrawLine(double X, double Y)
{
		glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 1.0);
		glVertex2f(center[numbPoint][0],center[numbPoint][1]);
		glVertex2f(X, Y);
		glEnd(); 
		glFlush();
		printR(clacRadius(X,  Y), (X+center[numbPoint][0])/2, (Y+center[numbPoint][1])/2);	

}
void DrawCircle(double X, double Y)
{
	double radius = clacRadius(X,  Y);
	double P = 1 - radius;
	int Px = 0, Py = radius;

	while(Px <= Py)
	{
		printf("(%.2lf, %.2lf)\n", Px, Py);
		glBegin(GL_POINTS);
		glColor3f(0.0, 1.0, 1.0);
		glVertex2f(Px+center[numbPoint][0], Py+center[numbPoint][1]);
		glVertex2f(Py+center[numbPoint][0], Px+center[numbPoint][1]);
		glVertex2f(Px+center[numbPoint][0], -Py+center[numbPoint][1]);
		glVertex2f(-Py+center[numbPoint][0], Px+center[numbPoint][1]);		
		glVertex2f(-Px+center[numbPoint][0], Py+center[numbPoint][1]);
		glVertex2f(-Px+center[numbPoint][0], -Py+center[numbPoint][1]);
		glVertex2f(Py+center[numbPoint][0], -Px+center[numbPoint][1]);
		glVertex2f(-Py+center[numbPoint][0], -Px+center[numbPoint][1]);
		glEnd(); 
		glFlush();
		
		if(P>0){
			P = P + 2*(Px-Py) + 5;
			--Py;
		}
		else{
			P = P + 2*(Px) + 3;
		}
		++Px;
		
	
	
	}

}
void plot(double X, double Y)
{
	printf("(%.2lf, %.2lf)\n", X, Y);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2f(X,Y);
	glEnd(); 
	glFlush();
}
void mouseClick(int button, int state, int X, int Y)
{	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		X = X - 500;
		Y = 500 - Y;
		
		if(count%2 == 0)
		{
			++numbPoint;
			center[numbPoint][0] = X;
			center[numbPoint][1] = Y;
			plot(X,Y);
			printXY(X, Y);
			
		}
		else if(count%2 != 0)
		{
			//plot(X,Y);
			DrawLine(X,Y);
			DrawCircle(X,Y);
			printf("Number of Circle(s): %d\n",count/2);
		}
		
		++count;
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
	glutCreateWindow("|| Drawing Circle using Mid-Point Algorithm ||"); 
	myInit(); 
	glutKeyboardFunc(Key);
	glutMouseFunc(mouseClick);
	glutMainLoop(); 
} 
