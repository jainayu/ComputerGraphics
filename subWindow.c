#include<stdio.h>
#include<string.h>
#include<GL/glut.h>
#include <math.h>
#define A 100
#define B 50
double centerC[100][2];
double centerE[100][2];
double point[100][2];
int count = 0;
int numbPointC=-1;
int numbPointE=-1;
char buffer[10];
int mainWindow, subWindow1,subWindow2,subWindow3;
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
	type("Ayush Jain", 240, -235);
	type("CSE-CCVT B-1",240, -250);
	type("R110217039",240, -265);

}
void printXY(double X, double Y)
{
	gcvt(X,5,buffer);
	char str[20]={"Center: ( "};
	strcat(str, buffer);
	strcat(str,  ", ");
	gcvt(Y,5,buffer);
	strcat(str, buffer);
	strcat(str, " )");
	type(str, X, Y);
}
void mainInit (void) 
{ 	
	// making background color black as first 
	// 3 arguments all are 0.0 
	gluOrtho2D(-500,500,-500,500);
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT);
	myName(); 
	type("Window 4: Name Display", 1, -15);
}

void myInit (void) 
{ 	
	// making background color black as first 
	// 3 arguments all are 0.0 
	gluOrtho2D(-250,250,-250,250);
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT);
}

double clacRadius(double X, double Y)
{
	//printf("Radizus: %.2lf\n",sqrt((double)(pow(center[numbPoint][1]-Y, 2) + pow(center[numbPoint][0]-X, 2))));
	return sqrt((double)(pow(centerC[numbPointC][1]-Y, 2) + pow(centerC[numbPointC][0]-X, 2)));
}
void printR(double R, double X, double Y)
{
	gcvt(R,5,buffer);
	char str[20]={"Radius = "};
	strcat(str, buffer);
	type(str, X, Y);
}

void plot(double X, double Y)
{
	//printf("(%.2lf, %.2lf)\n", X, Y);
	glBegin(GL_POINTS);
	glVertex2f(X,Y);
	glEnd(); 
	glFlush();
}
void DrawLine(double X, double Y)
{
		glBegin(GL_LINES);
		glColor3f(0.8, 0.6, 0.2);
		glVertex2f(centerC[numbPointC][0],centerC[numbPointC][1]);
		glVertex2f(X, Y);
		glEnd(); 
		glFlush();
		printR(clacRadius(X,  Y), (X+centerC[numbPointC][0])/2, (Y+centerC[numbPointC][1])/2);	

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
		glColor3f(0.8, 0.6, 0.2);
		glVertex2f(Px+centerC[numbPointC][0], Py+centerC[numbPointC][1]);
		glVertex2f(Py+centerC[numbPointC][0], Px+centerC[numbPointC][1]);
		glVertex2f(Px+centerC[numbPointC][0], -Py+centerC[numbPointC][1]);
		glVertex2f(-Py+centerC[numbPointC][0], Px+centerC[numbPointC][1]);		
		glVertex2f(-Px+centerC[numbPointC][0], Py+centerC[numbPointC][1]);
		glVertex2f(-Px+centerC[numbPointC][0], -Py+centerC[numbPointC][1]);
		glVertex2f(Py+centerC[numbPointC][0], -Px+centerC[numbPointC][1]);
		glVertex2f(-Py+centerC[numbPointC][0], -Px+centerC[numbPointC][1]);
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
void DrawEllipse1()
{
	int a2 = pow(A, 2);
	int b2 = pow(B, 2);
	double Px = 0, Py = B;
	int P = (a2/4) + b2 - a2 * B;
	while(b2*Px <= a2*Py)
	{
		glColor3f(0.4, 0.0, 0.8);
		plot(Px+centerE[numbPointE][0], Py+centerE[numbPointE][1]);
		plot(Px+centerE[numbPointE][0], -Py+centerE[numbPointE][1]);
		plot(-Px+centerE[numbPointE][0], Py+centerE[numbPointE][1]);
		plot(-Px+centerE[numbPointE][0], -Py+centerE[numbPointE][1]);
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
		glColor3f(0.4, 0.0, 0.8);
		plot(Px+centerE[numbPointE][0], Py+centerE[numbPointE][1]);
		plot(Px+centerE[numbPointE][0], -Py+centerE[numbPointE][1]);
		plot(-Px+centerE[numbPointE][0], Py+centerE[numbPointE][1]);
		plot(-Px+centerE[numbPointE][0], -Py+centerE[numbPointE][1]);
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
void DrawEllipse2()
{
	int a2 = pow(B, 2);
	int b2 = pow(A, 2);
	double Px = 0, Py = A;
	int P = (a2/4) + b2 - a2 * A;
	while(b2*Px <= a2*Py)
	{
		glColor3f(0.8, 0.6, 0.6);
		plot(Px+centerE[numbPointE][0], Py+centerE[numbPointE][1]);
		plot(Px+centerE[numbPointE][0], -Py+centerE[numbPointE][1]);
		plot(-Px+centerE[numbPointE][0], Py+centerE[numbPointE][1]);
		plot(-Px+centerE[numbPointE][0], -Py+centerE[numbPointE][1]);
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
		glColor3f(0.8, 0.5, 0.5);
		plot(Px+centerE[numbPointE][0], Py+centerE[numbPointE][1]);
		plot(Px+centerE[numbPointE][0], -Py+centerE[numbPointE][1]);
		plot(-Px+centerE[numbPointE][0], Py+centerE[numbPointE][1]);
		plot(-Px+centerE[numbPointE][0], -Py+centerE[numbPointE][1]);
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

void mouseClickCircle(int button, int state, int X, int Y)
{	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		X = X - 250;
		Y = 250 - Y;
		
		if(count%2 == 0)
		{
			++numbPointC;
			centerC[numbPointC][0] = X;
			centerC[numbPointC][1] = Y;
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

void mouseClickEllipse1(int button, int state, int X, int Y)
{	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		X = X - 250;
		Y = 250 - Y;
	
		++numbPointE;
		centerE[numbPointE][0] = X;
		centerE[numbPointE][1] = Y;
		plot(X,Y);
		printXY(X, Y);
		DrawEllipse1();
			
	}
}
void mouseClickEllipse2(int button, int state, int X, int Y)
{	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		X = X - 250;
		Y = 250 - Y;
	
		++numbPointE;
		centerE[numbPointE][0] = X;
		centerE[numbPointE][1] = Y;
		plot(X,Y);
		printXY(X, Y);
		DrawEllipse2();
			
	}
}
void display1()
{

	glutSetWindow(subWindow1);
	gluOrtho2D(-250,250,-250,250);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glutMouseFunc(mouseClickCircle);
	type("Window 1: Circle", -249, 235);
	glColor3f(0.0, 1.0, 1.0);
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(-250,250);
	glVertex2f(250,250);
	glVertex2f(250,-250);
	glVertex2f(-250,-250);
	glEnd();
	glFlush();

}
void display2()
{

	glutSetWindow(subWindow2);
	gluOrtho2D(-250,250,-250,250);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glutMouseFunc(mouseClickEllipse1);
	type("Window 2: Ellipse 1", -249, 235);
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-250,250);
	glVertex2f(250,250);
	glVertex2f(250,-250);
	glVertex2f(-250,-250);
	glEnd();
	glFlush();
}
void display3()
{

	glutSetWindow(subWindow3);
	gluOrtho2D(-250,250,-250,250);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	type("Window 3: Ellipse 2", -249, 235);
	glutMouseFunc(mouseClickEllipse2);
	
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-250,250);
	glVertex2f(250,250);
	glVertex2f(250,-250);
	glVertex2f(-250,-250);
	glEnd();
	glFlush();
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
	mainWindow = glutCreateWindow("|| Implementing Sub Window concept ||"); 
	mainInit();
	// glutCreateSubWindow(mainWindow_id, X, Y,Width, Height)
 	subWindow1 =  glutCreateSubWindow(mainWindow, 0, 0,500, 500);
 	display1();
 	subWindow2 = glutCreateSubWindow(mainWindow, 500, 0,500, 500);
 	display2();
 	subWindow3 = glutCreateSubWindow(mainWindow, 0, 500,500, 500);
 	display3();

	//glutKeyboardFunc(Key);
	
	glutMainLoop(); 
} 
