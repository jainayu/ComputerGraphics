#include<stdio.h> 
#include <stdlib.h>
#include<GL/glut.h>
#include <unistd.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795
double Point[100][2];
int k=0;
int numbPoint=0;
int numb=0, flag=0;
int Xb=0, Yb=0;
double Xm,Ym;
double fact(double x)
{
    if(x==0)
    return 1;
    if(x==1)
    return 1;
    if(x>1)
    return x*fact(x-1);
}
double nCr(double n,double r)
{
    if (n>=r)
    {
        return fact(n)/((fact(r))*(fact(n-r)));
    }
    else
    {
        printf("\nnCr could not be found \n");
    	return 1;
    }
}


void DrawAxis()
{
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.4,1.0,0.2);
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
	int n = numbPoint;
	
	for(double t=0; t<=1; t+=0.0001)
	{
		
		double blending[1][n];
		double P[1][2];
		double sum=0;
		for (int i = 0; i < n; i++) 
		{
      		blending[0][i] = nCr(n-1,i) * pow(t,i) * pow((1-t),n-1-i);	
      	}
      	for (int i = 0; i < 1; i++) 
		{
      		for (int j = 0; j < 2; j++) 
      		{
        		for (int l = 0; l < n; l++) 
        		{
          			sum = sum + blending[i][l] * Point[l][j];
        		}
 				P[i][j] = sum;
        		sum = 0;
      		}
      	}
      	//printf("(%lf,%lf)\n", P[0][0], P[0][1]);
      	glPointSize(1);
      	glColor3f(1.0, 0.2, 0.2);
		glBegin(GL_POINTS);
		glVertex2f(P[0][0],P[0][1]);
		glEnd(); 
		if(flag==0)
			glFlush();
	}
	glFlush();
	flag=1;
	//k = numbPoint;
}

 
 

void store(double X, double Y)
{
	Point[numbPoint][0] = X;
	Point[numbPoint++][1] = Y;
	//printf("(%lf,%lf)\n", X, Y);
	glPointSize(4);
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
		if(flag==0)
		{
			store(X-500,500-Y);
		}
		else 
		{
			Xm = X-500;
			Ym = 500-Y;
			for(int i=0; i<numbPoint; i++ )
			{
				if
				(	
					Xm>=Point[i][0] - 4 && Xm<=Point[i][0] + 4
					&& Ym>=Point[i][1] - 4 && Ym<=Point[i][1] + 4 
				)
				{
					flag = 2;
					numb = i;
					break;	
				}
		
			}
		}
	}
	
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		Xm = X-500;
		Ym = 500-Y;
		if(flag==2)
		{
			Point[numb][0] = Xm;
			Point[numb][1] = Ym;
			
			myName();
			for(int i=0; i<numbPoint; i++)
			{
				glPointSize(4);
				glColor3f(1.0, 1.0, 1.0);
				glBegin(GL_POINTS);
				glVertex2f(Point[i][0], Point[i][1]);
				glEnd(); 
				glFlush();
			}		
			Draw();
		}
	}
	/*
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		Xm = X-500;
		Ym = 500-Y;
		if(flag==2)
		{
			Point[numb][0] = Xm;
			Point[numb][1] = Ym;
			
			myName();
			for(int i=0; i<numbPoint; i++)
			{
				glPointSize(4);
				glColor3f(1.0, 1.0, 1.0);
				glBegin(GL_POINTS);
				glVertex2f(Point[i][0], Point[i][1]);
				glEnd(); 
				glFlush();
			}		
			Draw();
		}
		
	}
	*/
} 
void mouseMove(int X, int Y)
{
	
	
	X = X-500;
	Y = 500-Y;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(Xb+5, Yb+5);
	glVertex2f(Xb+5, Yb-5);
	glVertex2f(Xb-5, Yb-5);
	glVertex2f(Xb-5, Yb+5);
	glEnd(); 
	glFlush();
	
	for(int i=0; i<numbPoint; i++ )
	{
		if
		(	
			X>=Point[i][0] - 4 && X<=Point[i][0] + 4
			&& Y>=Point[i][1] - 4 && Y<=Point[i][1] + 4 
		)
		{
			Xb = Point[i][0];
			Yb = Point[i][1];
			glColor3f(0.0, 1.0, 1.0);
			glBegin(GL_LINE_LOOP);
			glVertex2f(Xb+5, Yb+5);
			glVertex2f(Xb+5, Yb-5);
			glVertex2f(Xb-5, Yb-5);
			glVertex2f(Xb-5, Yb+5);
			glEnd(); 
			glFlush();
			break;	
		}
	
	}
}
int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1000, 1000); 
	// Giving name to window 
	glutCreateWindow("Beizer Curve"); 
	myInit(); 
	glutKeyboardFunc(Key);
	glutMouseFunc(mouseClick);
	glutPassiveMotionFunc( mouseMove);
	glutMainLoop(); 
	return 0;
}
