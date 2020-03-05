#include <GL/glut.h>
#include <stdio.h>
#define pi 3.14159
#include <math.h>
int x1, y11, x2, y2;
int theta;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D( -1366.0f, 1366.0f, -768.0f , 768.0f);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void drawTriangle(int theta)
{
	int x11,x22,x33,y111,y22,y33;
	x11=100;
	y111 = 400;
	x22 = 200;
	y22 = 400;
	x33 = 150;
	y33 = 500;
	//copy
	int x11copy,x22copy,x33copy,y111copy,y22copy,y33copy;
	x11copy=100;
	y111copy = 400;
	x22copy = 200;
	y22copy = 400;
	x33copy = 150;
	y33copy = 500;
	//changed values
	x11 = x11copy*cos(theta) - y111copy*sin(theta);
	y111 = x11copy*sin(theta) + y111copy*cos(theta);
	x22 = x22copy*cos(theta) - y22copy*sin(theta);
	y22 = x22copy*sin(theta) + y22copy*cos(theta);
	x33 = x33copy*cos(theta) - y33copy*sin(theta);
	y33 = x33copy*sin(theta) + y33copy*cos(theta);


    glColor3f(0.5, 0.5, 1.0);
   // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

        glBegin(GL_TRIANGLES);
                glVertex2f(x11, y111);
                glVertex2f(x22, y22);
                glVertex2f(x33, y33);
        glEnd();

    // glFlush();
}

void draw_line(int x1, int x2, int y11, int y2,int theta) {
	x1 = 0,y11=0,x2=200,y2=200;

	int x1copy = x1,x2copy = x2,y11copy = y11, y2copy = y2;

	x1 = x1copy*cos(theta) - y11copy*sin(theta);
	x2 = x2copy*cos(theta) - y2copy*sin(theta);
	y11 = x1copy*sin(theta)  + y11copy*cos(theta);
	y2 = x2copy*sin(theta)  + y2copy*cos(theta);
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y11;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y11) incy = -1;
	x = x1; y = y11;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
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
		for (i=0; i<dy; i++) {
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
}
	// myInit();

void myDisplay() {
	draw_line(x1, x2, y11, y2,0);
	drawTriangle(0);

	glFlush();

	printf("enter angle you want to rotate it with?\n");
	scanf("%d",&theta);
	theta = theta*pi/180;
	// printf("%d",theta);

	// glClear(GL_COLOR_BUFFER_BIT);
	draw_line(x1, x2, y11, y2,theta);
 	drawTriangle(theta);


	glFlush();
}

int main(int argc, char **argv) {

	// printf( "Enter (x1, y11, x2, y2)\n");
	// scanf("%d %d %d %d", &x1, &y11, &x2, &y2);
	x1 = 0,y11=0,x2=200,y2=200;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366,768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Rotation");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}