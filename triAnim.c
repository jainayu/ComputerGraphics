#include<stdio.h> 
#include<GL/glut.h>
#include <unistd.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795
double x,y,j,i;

// function to initialize 
void myInit (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	
} 

void display (void) 
{ 
	
		while(1){
		for(j=0.0; j<=1.0; j+=0.001)
		{ 	
			glClear(GL_COLOR_BUFFER_BIT); 
			glColor3f(j, 1.0-j, j+j); 
			glBegin(GL_LINE_LOOP);
			for (i = 0;i < 6.29;i += 0.001) 
			{
				glVertex2f( j * cos(PI/2), j * sin(PI/2)); 
				glVertex2f( j * cos(7* PI/6), j * sin(7 * PI/6));
				glVertex2f( j * cos(11* PI/6), j * sin(11* PI/6));
			} 
			glEnd();
			glFlush();
		}
		for(j=1.0; j>=0.0; j-=0.001)
		{ 	
			glClear(GL_COLOR_BUFFER_BIT); 
			glColor3f(j, 1.0-j, j+j); 
			glBegin(GL_LINE_LOOP);
			for (i = 0;i < 6.29;i += 0.001) 
			{
				glVertex2f( j * cos(PI/2), j * sin(PI/2)); 
				glVertex2f( j * cos(7* PI/6), j * sin(7 * PI/6));
				glVertex2f( j * cos(11* PI/6), j * sin(11* PI/6));
			} 
			glEnd();
			glFlush();
		}
		}
	
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	// giving window size in X- and Y- direction 
	glutInitWindowSize(500, 500); 
	// Giving name to window 
	glutCreateWindow("Triangle Animation"); 
	myInit(); 
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 


