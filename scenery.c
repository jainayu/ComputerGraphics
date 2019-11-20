#include<stdio.h> 
#include<GL/glut.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795




double j=0.0;
static int cnt=0;
double x,y,k;
static double radius = 0.12; 

// function to initialize 
void myInit (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 0.0); 
	
} 

void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT); 
	//Grass
	glColor3f(0.0, 0.9-j+0.085, 0.0); 
	glBegin(GL_POLYGON);
   	glVertex2f(1.0,-0.0);
	glVertex2f(-1.0,-0.0);
	glVertex2f(-1.0,-1.0);
	glVertex2f(1.0,-1.0);
	glEnd();
	//Sky
	glColor3f(0.0, 1.0-j, 1.0-j+0.1); 
	glBegin(GL_POLYGON);
   	glVertex2f(1.0,0.0);
	glVertex2f(-1.0,0.0);
	glVertex2f(-1.0,1.0);
	glVertex2f(1.0,1.0);
	glEnd();
	//Rectangle House front
	glColor3f(1.0-j, 0.5-j, 0.0); 
	glBegin(GL_POLYGON);
   	glVertex2f(0.0,0.4);
	glVertex2f(0.25,0.4);
	glVertex2f(0.25,-0.2);
	glVertex2f(0.0,-0.2);
	glEnd();
	
	//Parallelogram House side
	glColor3f(0.8-j, 0.3-j, 0.0);
	if(j>0.0)
	glColor3f(0.8-j+0.3, 0.3-j+0.3, 0.0);  
	glBegin(GL_POLYGON);
   	glVertex2f(0.25,0.4);
	glVertex2f(0.7,0.5);
	glVertex2f(0.7,-0.1);
	glVertex2f(0.25,-0.2);
	glEnd();
	
	glColor3f(0.8-j, 0.3-j, 0.0);
	//Triangle Top House
	glBegin(GL_TRIANGLES);
   	glVertex2f(0.125,0.61650635);
	glVertex2f(0.0,0.4);
	glVertex2f(0.25,0.4);
	glEnd();
	//Parallelogram Top House
	glColor3f(1.0-j, 0.5-j, 0.0); 
	if(j>0.0)
	glColor3f(1.0-j+0.3, 0.5-j+0.3, 0.0); 
	glBegin(GL_POLYGON);
	glVertex2f(0.125,0.61650635);
   	glVertex2f(0.575,0.71650635);
	glVertex2f(0.7,0.5);
	glVertex2f(0.25,0.4);
	glEnd();
	//House Door
	glColor3f(0.8-j, 0.3-j, 0.0); 
	glBegin(GL_POLYGON);
   	glVertex2f(0.07,0.2);
	glVertex2f(0.18,0.2);
	glVertex2f(0.18,-0.2);
	glVertex2f(0.07,-0.2);
	glEnd();
	
	//Stem Tree
	glColor3f(0.8-j, 0.3-j, 0.0); 
	glBegin(GL_POLYGON);
   	glVertex2f(-0.45,0.2);
	glVertex2f(-0.55,0.2);
	glVertex2f(-0.55,-0.2);
	glVertex2f(-0.45,-0.2);
	glEnd();
	
	//tree body nd leaves
	glColor3f(0.0, 0.5-j+0.2, 0.0); 
	glBegin(GL_POLYGON);
   	glVertex2f(-0.4,0.2);
	glVertex2f(-0.6,0.2);
	glVertex2f(-0.6,0.4);
	glVertex2f(-0.4,0.4);
	glEnd();
	
	glBegin(GL_POLYGON);
	for(double i = 0; i < 2 * PI; i += PI /30)
		glVertex2f(-0.4 + cos(i) * radius, 0.2 + sin(i) * radius);
 	glEnd();
 	glBegin(GL_POLYGON);
	for(double i = 0; i < 2 * PI; i += PI /30)
		glVertex2f(-0.6 + cos(i) * radius, 0.2 + sin(i) * radius);
 	glEnd();
 	glBegin(GL_POLYGON);
	for(double i = 0; i < 2 * PI; i += PI /30)
		glVertex2f(-0.4 + cos(i) * radius, 0.4 + sin(i) * radius);
 	glEnd();
 	glBegin(GL_POLYGON);
	for(double i = 0; i < 2 * PI; i += PI /30)
		glVertex2f(-0.6 + cos(i) * radius, 0.4 + sin(i) * radius);
 	glEnd();
 	glBegin(GL_POLYGON);
	for(double i = 0; i < 2 * PI; i += PI /30)
		glVertex2f(-0.5 + cos(i) * radius, 0.573205+ sin(i) * radius);
 	glEnd();
 	
	//lamp pole
 	glColor3f(j-0.8, j-0.8, j-0.8); 
	glBegin(GL_POLYGON);
	glVertex2f(0.83,-0.1);
	glVertex2f(0.87,-0.1);
	glVertex2f(0.87,0.4);
	glVertex2f(0.83,0.4);
	glEnd();
	
	//Road 
	glColor3f(0.0, 0.0, 0.0); 
	glBegin(GL_POLYGON);
	glVertex2f(-1.0,-0.8);
	glVertex2f(-1.0,-0.9);
	glVertex2f(1.0,-0.9);
	glVertex2f(1.0,-0.8);
	glEnd();
	int c=0;
	/*
	for(k=0.0;k<=2.0;k+=0.2, ++c)
	{	 
		
		if(c%2!=0)
		{
			 glColor3f(1.0-j, 1.0-j, 1.0-j);
		}
		else
		{
			 glColor3f(0.0, 0.0, 0.0);
		}
		glColor3f(0.0, 0.0, 0.0);	
		glBegin(GL_POLYGON);
		glVertex2f(-1.0+k,-0.75);
		glVertex2f(-1.0+k,-0.8);
		glVertex2f(-1.0+k+0.2,-0.8);
		glVertex2f(-1.0+k+0.2,-0.75);
		glEnd();

	}
	*/

	// car base
	glColor3f(0.0, 0.0, 0.9-j); 
	glBegin(GL_POLYGON);
	glVertex2f(-0.9,-0.60);
	glVertex2f(-0.9,-0.72);
	glVertex2f(-0.5,-0.72);
	glVertex2f(-0.5,-0.60);
	glEnd();

	glColor3f(0.0, 0.0, 0.9-j); 
	glBegin(GL_POLYGON);
	glVertex2f(-0.85,-0.5);
	glVertex2f(-0.85,-0.6);
	glVertex2f(-0.55,-0.6);
	glVertex2f(-0.55,-0.5);
	glEnd();

	for(k=0.0; k<=0.07; k+=0.0001)
	{ 
		glColor3f(0.2-j, 0.2-j, 0.2-j); 
 		glBegin(GL_POINTS);
		for (double i = 0;i < 6.29;i += 0.001) 
		{
			x = k * cos(i); 
			y = k * sin(i); 
			glVertex2f(-0.8+x, -0.75+ y); 
		} 
		glEnd();
		
		glBegin(GL_POINTS);
		for (double i = 0;i < 6.29;i += 0.001) 
		{
			x = k * cos(i); 
			y = k * sin(i); 
			glVertex2f(-0.6+x, -0.75+ y); 
		} 
		glEnd();
	}
 	
 	if(j==0.9)
 	{	
 		for(k=0.0; k<=0.1; k+=0.0001)
		{ 
			glColor3f(0.9, 0.9, 0.9); 
 			glBegin(GL_POINTS);
			for (double i = 0;i < 6.29;i += 0.001) 
			{
				x = k * cos(i); 
				y = k * sin(i); 
				glVertex2f(-0.8+x, 0.8+ y); 
			} 
			glEnd();
		}
		for(k=0.0; k<=0.1; k+=0.0001)
		{ 
			glColor3f(0.0, 1.0-j, 1.0-j+0.1); 
 			glBegin(GL_POINTS);
			for (double i = 0;i < 6.29;i += 0.001) 
			{
				x = k * cos(i); 
				y = k * sin(i); 
				glVertex2f(-0.85+x, 0.85+ y); 
			} 
			glEnd();
		}
		for(k=0.0; k<=0.1; k+=0.0001)
		{ 
			glColor3f(0.9, 0.9, 0.0); 
 			glBegin(GL_POINTS);
			for (double i = 0;i < 6.29;i += 0.001) 
			{
				x = k * cos(i); 
				y = k * sin(i); 
				glVertex2f(0.85+x, 0.45+ y); 
			} 
			glEnd();
		}
		
			
 	}
 	else
 	{
 		for(k=0.0; k<=0.1; k+=0.0001)
		{ 
			glColor3f(1.0, 1.0, 0.0); 
 			glBegin(GL_POINTS);
			for (double i = 0;i < 6.29;i += 0.001) 
			{
				x = k * cos(i); 
				y = k * sin(i); 
				glVertex2f(-0.8+x, 0.8+ y); 
			} 
			glEnd();
		}
		
		for(k=0.0; k<=0.1; k+=0.0001)
		{ 
			glColor3f(0.8, 0.8, 0.8); 
 			glBegin(GL_POINTS);
			for (double i = 0;i < 6.29;i += 0.001) 
			{
				x = k * cos(i); 
				y = k * sin(i); 
				glVertex2f(0.85+x, 0.45+ y); 
			} 
			glEnd();
		}
		
 	}
	
	glFlush(); 
} 
void mouseClick(int button, int state, int x, int y)
{	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		++cnt;
		if(cnt%2!=0){
			j=0.9;
			display();
		}
		else{
			j=0.0;
			display();	
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
	glutCreateWindow("Scenery"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMouseFunc(mouseClick);
	glutMainLoop(); 
} 


