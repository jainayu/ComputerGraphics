#include<stdio.h> 
#include <stdlib.h>
#include<GL/glut.h>
#include <unistd.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795
double Point[3][100];
int k=0;
int numbPoint=0;
double Xm,Ym;

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
	type("Ayush Jain", -495, 490);
	type("CSE-CCVT B-1",-495, 475);
	type("R110217039",-495, 460);
	DrawAxis(); 
}

// function to initialize 
void myInit (void) 
{ 	
	// making background color black as first 
	// 3 arguments all are 0.0 
	gluOrtho2D(-500, 500,-500,500);
	glClearColor(0.0, 0.0, 0.0, 0.0); 
	myName();
	glFlush();	
	
}
void Draw()
{
	//glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	for(int i=k; i<numbPoint; i++)
	{
		glColor3f(1.0,1.0,1.0);
		glVertex2f(Point[0][i], Point[1][i]);
	}	
	glEnd(); 
	glFlush();
}

void rotate(float deg)
{
	double x,y; 
	for(int i=k; i<numbPoint; i++)
	{
		x = cos(deg)*Point[0][i] - sin(deg)*Point[1][i];
		y = sin(deg)*Point[0][i] + cos(deg)*Point[1][i];
		Point[0][i] = x;
		Point[1][i] = y;
		
	}
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	myName();
	Draw();

}

void move(double tx, double ty)
{
	for(int i=k; i<numbPoint; i++)
	{
		
		Point[0][i] += tx;
		Point[1][i] += ty;
		
	}
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	myName();
	Draw();

}

void reflection(int rx, int ry)
{
	for(int i=k; i<numbPoint; i++)
	{
		
		Point[0][i] *= rx;
		Point[1][i] *= ry;
		
	}
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	myName();
	Draw();

}

void scale(double sx, double sy)
{ 
	for(int i=k; i<numbPoint; i++)
	{
		
		Point[0][i] *= sx;
		Point[1][i] *= sy;
		
	}
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	myName();
	Draw();

}

void shear(double sx, double sy)
{
	double x,y; 
	for(int i=k; i<numbPoint; i++)
	{
		
		x = Point[0][i]+ sx*Point[1][i];
		y = sy*Point[0][i] + Point[1][i];
		Point[0][i] = x;
		Point[1][i] = y;
		
	}
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	myName();
	Draw();

}

void menu(int num){
	switch(num)
	{
		case 0:
			exit(0);
			break;
		case 1:
			glClearColor(0.0, 0.0, 0.0, 0.0);
			glClear(GL_COLOR_BUFFER_BIT);
			myName(); 
			k=0;
			numbPoint=0;
			break;
		case 2:
			rotate(PI/6);
			break;
		case 3:
			rotate(PI/3);
			break;
		case 4:
			rotate(PI/2);
			break;
		/*
		case 5:
			exit(0)
			break;
		*/
		case 6:
			move(70,0);
			break;
		case 7:
			move(-90,0);
			break;
		case 8:
			move(0,60);
			break;
		case 9:
			move(0,-80);
			break;
		case 10:
			reflection(1,-1);
			break;
		case 11:
			reflection(-1,1);
			break;
		case 12:
			reflection(-1,-1);
			break;
		case 13:
			scale(3,3);
			break;
		case 14:
			scale(0.5,0.5);
			break;
		case 15:
			scale(4,1);
			break;
		case 16:
			scale(1,2);
			break;
		case 17:
			shear(2,0);
			break;
		case 18:
			shear(0,2);
			break;
		case 19:
			shear(3,3);
			break;
	}
} 
void createMenu(void)
{     
	int submenu1 = glutCreateMenu(menu);
    glutAddMenuEntry("30 Deg about origin", 2);
    glutAddMenuEntry("60 Deg about origin", 3);
    glutAddMenuEntry("90 Deg about origin", 4);
   // glutAddMenuEntry("30deg about center", 5);
    
    int submenu2 = glutCreateMenu(menu);
    glutAddMenuEntry("Move 70 steps in right", 6);
    glutAddMenuEntry("Move 90 steps in left", 7);
    glutAddMenuEntry("Move 60 steps upwards", 8);
    glutAddMenuEntry("Move 80 steps downwards", 9);   
    
    int submenu3 = glutCreateMenu(menu);
    glutAddMenuEntry("About x-axis", 10);
    glutAddMenuEntry("About y-axis", 11);
    glutAddMenuEntry("About origin", 12);
    
    int submenu4 = glutCreateMenu(menu);
    glutAddMenuEntry("3x Size", 13);
    glutAddMenuEntry("0.5x size", 14);
    glutAddMenuEntry("4x along x-axis", 15);
    glutAddMenuEntry("2x along y-axis", 16);
    
    int submenu5 = glutCreateMenu(menu);
    glutAddMenuEntry("with factor 2 in x-direction", 17);
    glutAddMenuEntry("with factor 2 in y-direction", 18);
    glutAddMenuEntry("with factor 3 in x and y-direction", 19);
    
    
    int main_menu = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Rotate", submenu1);
    glutAddSubMenu("Move", submenu2);
    glutAddSubMenu("Reflection", submenu3);
    glutAddSubMenu("Resize/Scale", submenu4);
    glutAddSubMenu("Shear", submenu5);
    glutAddMenuEntry("Quit", 0);     
    
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
} 
 

void store(double X, double Y)
{
	Point[0][numbPoint] = X;
	Point[1][numbPoint] = Y;
	Point[2][numbPoint++] = 1;
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
		
		store(X-500,500-Y);
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		Xm = X-500;
		Ym = 500-Y;
		
	}
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1000, 1000); 
	// Giving name to window 
	glutCreateWindow("2-D Transformation"); 
	myInit(); 
	glutKeyboardFunc(Key);
	glutMouseFunc(mouseClick);
	createMenu();
	glutMainLoop(); 
	return 0;
}
