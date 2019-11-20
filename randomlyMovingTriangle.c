#include<stdio.h> 
#include <stdlib.h>
#include<GL/glut.h>
#include <unistd.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795
double x,y,j=50;
int i=0;
double clickX[3], clickY[3], startX[3], startY[3];
int factor[3]={1, 1, 1};
int m[3]={2, 2, 2};
void store(double X, double Y)
{
	if(i<1){
		clickX[i] = X;
		clickY[i] = Y;
		startX[i] = clickX[i];
   		startY[i] = clickY[i];
		i++;
		
		glColor3f(1.0, 1.0, 1.0); 
		glBegin(GL_LINE_LOOP);
		glVertex2f(X + j * cos(PI/2), Y + j * sin(PI/2)); 
		glVertex2f(X + j * cos(7* PI/6), Y + j * sin(7 * PI/6));
		glVertex2f(X + j * cos(11* PI/6), Y + j * sin(11* PI/6)); 
		glEnd();
		glFlush();
	}
	
}
// function to initialize 
void myInit (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	gluOrtho2D(-500,500,-500,500);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
} 

void display (double X, double Y) 
{ 
		glClear(GL_COLOR_BUFFER_BIT); 
		glColor3f(1.0, 1.0, 1.0); 
		glBegin(GL_LINE_LOOP);
		glVertex2f(X + j * cos(PI/2), Y + j * sin(PI/2)); 
		glVertex2f(X + j * cos(7* PI/6), Y + j * sin(7 * PI/6));
		glVertex2f(X + j * cos(11* PI/6), Y + j * sin(11* PI/6)); 
		glEnd();
		glFlush();
}
void onKeyPress()
{
	while(1){
		for(i=0; i<1; i++){
		if((m[i]>=1 && m[i]<9999) || (m[i]<=-1 && m[i]>-9999))
		{
			clickY[i]+=factor[i]*0.5;
			clickX[i]= ((clickY[i]-startY[i])/m[i])+startX[i];
			
			if((clickX[i]<455 && clickX[i]>-455) && (clickY[i]<450 && clickY[i]>-475))
			{
				display(clickX[i], clickY[i]);
					
			}
			else
			{
			 	m[i] = rand() % 10 - 5;
			 	if(m[i]==0)
			 	{
			 		m[i]=1;
			 	}
			 	//printf("%d\n", m);
			 	if(clickY[i]>=450 || clickY[i]<=-475)
				{
					factor[i]*=(-1);
				}	
      			startX[i] = clickX[i];
      			startY[i] = clickY[i];
			}
		
		}
		}
	}

}
static void Key(unsigned char key, int x, int y)
{
    switch (key) 
    {
      	case 32:
      		
			onKeyPress();
			break;
	}
}
void mouseClick(int button, int state, int X, int Y)
{	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//glClear(GL_COLOR_BUFFER_BIT);
		double clickx = X-500;
		double clicky = 500-Y;
		store(clickx, clicky);
		//display(clickx, clicky);
	}
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1000, 1000); 
	// Giving name to window 
	glutCreateWindow("Randomly Moving Triangle"); 
	myInit(); 
	glutKeyboardFunc(Key);
	glutMouseFunc(mouseClick);
	glutMainLoop(); 
} 


