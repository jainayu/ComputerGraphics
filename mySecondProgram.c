#include<stdio.h> 
#include<GL/glut.h> 

// function to initialize 
void myInit (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	// making picture color green (in RGB mode), as middle argument is 1.0 
	glColor3f(1.0, 1.0, 0.0); 
} 

void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POLYGON);
   	glVertex2f(0.5,0.5);
	glVertex2f(0.5,-0.5);
	glVertex2f(-0.5,-0.5);
	glVertex2f(-0.5,0.5);

	
	// iterate y up to 2*pi, i.e., 360 degree 
	// with small increment in angle as 
	// glVertex2i just draws a point on specified co-ordinate 
	
	glEnd(); 
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(300, 300); 
	// Giving name to window 
	glutCreateWindow("Testing I guess"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

