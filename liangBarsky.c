#include<stdio.h> 
#include<GL/glut.h>
#include <unistd.h>
#include<math.h>
#define PI 3.1415926536
#define MAX_CLICK 1
#define SQUARE_SIDE 200
#define INFINITE 99999999

int k=0;
int count=0;
int numbPoint=0;
double vertex[100][2];
double m[99];
double c[99];
char buffer[10];
double p[4], q[4];
double xi,yi, xf, yf;
double xmax=1000, ymax=0, xmin=-1000, ymin=-1000;
// function to initialize 
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
	type("Ayush Jain", -495, 490);
	type("CSE-CCVT B-1",-495, 475);
	type("R110217039",-495, 460);

}
void myInit (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	gluOrtho2D(-500,500,-500,500);
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 
	
}
void clip(double x1, double y1, double x2, double y2)
{
	double dx = x2-x1;
	double dy = y2-y1;
	double xio,xfo,yio,yfo;
	double x,y;
	double t1=0, t2=1, t;
	p[0] = -dx;	q[0] = x1 - xmin;//(xmin*cos(-PI/4)-ymin*sin(-PI/4));
	p[1] = dx;	q[1] = xmax - x1; //(xmax*cos(-PI/4)-ymax*sin(-PI/4)) - x1;
	p[2] = -dy;	q[2] = y1 - ymin;//(xmin*sin(-PI/4)+ymin*cos(-PI/4));
	p[3] = dy;	q[3] = ymax - y1;//(xmax*sin(-PI/4)+ymax*cos(-PI/4)) -y1;
	
	for(int i=0; i<4; i++)
	{
		if(p[i]==0 && q[i]<0)
		{
			break;
		}
		
		if(p[i]<0)
		{
			t = (q[i]) / (p[i]);
			if(t>t1 && t<t2)
			{
				t1 = t;
			}
		}
		if(p[i]>0)
		{
			t = (q[i]) / (p[i]);
			if(t>t1 && t<t2)
			{
				t2 = t;
			}
		}
	}
	if(t1<t2)
	{
		//printf("t1: %lf\n", t1);
		//printf("t2: %lf\n", t2);
		
		xi = x1 + t1*dx;
		yi = y1 + t1*dy;
		xf = x1 + t2*dx;
		yf = y1 + t2*dy;
		
		glBegin(GL_LINES);	
		glColor3f(0.7, 0.7, 1.0);
	        glVertex2f(x1*cos(-PI/4)-y1*sin(-PI/4) ,x1*sin(-PI/4)+y1*cos(-PI/4));
    		glVertex2f(x2*cos(-PI/4)-y2*sin(-PI/4),x2*sin(-PI/4)+y2*cos(-PI/4));
    	    
    	  	if(xi>=xmin && xf<=xmax && yi>=ymin && yf<=ymax)
    	  	{
    	    	glColor3f(1.0, 0.0, 0.0);
    	    	glVertex2f(xi*cos(-PI/4)-yi*sin(-PI/4), xi*sin(-PI/4)+yi*cos(-PI/4));
    	    	glVertex2f(xf*cos(-PI/4)-yf*sin(-PI/4), xf*sin(-PI/4)+yf*cos(-PI/4));
    	    	}
        glEnd();
        glFlush();
	}
}

void DrawLine() 
{
	double P[2][2];
	int maxPoint, minPoint;
	double x1, y1, x2, y2, x3, y3, x4, y4;
	double dx, dy;
	for(int i=0;k<numbPoint;k++,i++)
	{
		P[i][0] = vertex[k][0];
		P[i][1] = vertex[k][1];
	}

	//clip(P[0][0], P[0][1], P[1][0], P[1][1]);

	
	x1 = P[0][0]*cos(PI/4)-P[0][1]*sin(PI/4);
	y1 = P[0][0]*sin(PI/4)+P[0][1]*cos(PI/4);

	x2 = (P[0][0]+SQUARE_SIDE)*cos(PI/4)-P[0][1]*sin(PI/4);
	y2 = (P[0][0]+SQUARE_SIDE)*sin(PI/4)+P[0][1]*cos(PI/4);
	
	x3 = (P[0][0]+SQUARE_SIDE)*cos(PI/4)-(P[0][1]-SQUARE_SIDE)*sin(PI/4);
	y3 = (P[0][0]+SQUARE_SIDE)*sin(PI/4)+(P[0][1]-SQUARE_SIDE)*cos(PI/4);

	x4 = P[0][0]*cos(PI/4)-(P[0][1]-SQUARE_SIDE)*sin(PI/4);
	y4 = P[0][0]*sin(PI/4)+(P[0][1]-SQUARE_SIDE)*cos(PI/4);
	
	
	clip(x1, y1, x2, y2);
	clip(x2, y2, x3, y3);
	clip(x3, y3, x4, y4);
	clip(x4, y4, x1, y1);

	//clip(P[0][0],P[0][1],P[1][0]+SQUARE_SIDE,P[1][1]);
	//clip(P[0][0],P[0][1],P[0][0],P[0][1]-SQUARE_SIDE);
	//clip(P[0][0]+SQUARE_SIDE,P[0][1],P[0][0]+SQUARE_SIDE,P[0][1]-SQUARE_SIDE);
	//clip(P[0][0],P[0][1]-SQUARE_SIDE,P[0][0]+SQUARE_SIDE,P[0][1]-SQUARE_SIDE);
	
}

 
void store(double X, double Y)
{
	vertex[numbPoint][0] = X;
	vertex[numbPoint][1] = Y;
	++numbPoint;
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
		if(count<=MAX_CLICK)
		{
			store((X-500),(500-Y));
			count++;
			if(count == MAX_CLICK){
				DrawLine();
				count=0;
				//printf("Number of Line(s): %d\n",numbPoint/2);
			}
		}
	}

}
void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	myName();
	glColor3f(0.0, 1.0, 1.0);
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin*cos(-PI/4)-ymax*sin(-PI/4),xmin*sin(-PI/4)+ymax*cos(-PI/4));
	glVertex2f(xmin*cos(-PI/4)-ymin*sin(-PI/4),xmin*sin(-PI/4)+ymin*cos(-PI/4));
	glVertex2f(xmax*cos(-PI/4)-ymin*sin(-PI/4),xmax*sin(-PI/4)+ymin*cos(-PI/4));
	glVertex2f(xmax*cos(-PI/4)-ymax*sin(-PI/4),xmax*sin(-PI/4)+ymax*cos(-PI/4));
	//glVertex2f(xmin,ymin);
	//glVertex2f(xmax,ymin);
	//glVertex2f(xmax,ymax);
	glEnd();
	glFlush();
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1000, 1000); 
	// Giving name to window 
	glutCreateWindow("Line Clipping using Liang Barsky Algorithm"); 
	myInit(); 
	glutDisplayFunc(display); 
	glutMouseFunc(mouseClick);
	glutMainLoop(); 
} 


