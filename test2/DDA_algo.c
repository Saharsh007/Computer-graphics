#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// using namespace std;

float x1,y11,x2,y2;

void drawline(){
	float dx,dy,xinc,yinc,x,y,steps;
	dy = y2-y11;
	dx = x2-x1;
	steps = dy>dx ? dy:dx;
	xinc = dx/steps;
	yinc = dy/steps;

	x = x1;
	y = y11;

	for(int i; x<x2 ; i++){
		glPointSize(10);  
		glColor3f(0.5, 1.0, 0.4);
		glBegin(GL_POINTS);
		glVertex2f(x,y);
		glEnd();
		x += xinc;
		y += yinc;
	}
	glFlush();
}


void init(void)
{
	glClearColor(0,0,0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv){

	printf("enter x1,y1,x2,y2\n");
	// scanf("%f%f%f%f",&x1,&y11,&x2,&y2);
	x1 = 0,y11=0,x2=30,y2=30;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize (2560,1600);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("DDA Line Algo");
	init();
	glutDisplayFunc(drawline);
	glutMainLoop();
	 

}