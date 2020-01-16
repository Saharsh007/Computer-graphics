#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void bresenham(int x1, int x2, int y1, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<=dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<=dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
	glFlush();
}
 

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	bresenham(-900,900,900,900);
	bresenham(-900,-900,-900,900);
	bresenham(900,900,900,-900);
	bresenham(900,-900,-900,-900);


	bresenham(0,900,-900,0);
	bresenham(-900,0,0,-900);
	bresenham(0,-900,900,0);
	bresenham(900,0,0,900);

	bresenham(-450,450,450,450);
	bresenham(-450,-450,-450,450);
	bresenham(450,450,450,-450);
	bresenham(450,-450,-450,-450);
	glFlush();
}


void init(void)
{
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000,1000,-1000,1000);
}
 
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (2560,1600);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Pattern");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
 
	return 0;
}
