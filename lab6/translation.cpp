#include <GL/glut.h>
#include <stdio.h>
#define pi 3.14159
#include <math.h>
int x1, y11, x2, y2;
int xx,yy;
void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0f, 1366.0f, 0.0f, 768.0f);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_circle(int xx, int yy){
	// glClear(GL_COLOR_BUFFER_BIT); 
    glBegin(GL_POINTS); 
    float x, y, i; 
      
    // iterate y up to 2*pi, i.e., 360 degree 
    // with small increment in angle as 
    // glVertex2i just draws a point on specified co-ordinate 
    for ( i = 0; i < (2 * pi); i += 0.001) 
    { 
        // let 200 is radius of circle and as, 
        // circle is defined as x=r*cos(i) and y=r*sin(i) 
        x = 75 * cos(i)+150+xx; 
        y = 75 * sin(i)+300+yy; 
          
        glVertex2i(x, y); 
    } 
    glEnd(); 
    // glFlush(); 
}

void drawTriangle(int xx,int yy)
{
    // glClearColor(1.0, 0.0, 0.0, 1.0);
    // glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.5, 0.5, 1.0);
   // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

        glBegin(GL_TRIANGLES);
                glVertex2f(100+xx, 400+yy);
                glVertex2f(200+xx, 400+yy);
                glVertex2f(150+xx, 500+yy);
        glEnd();

    // glFlush();
}

void draw_line(int x1, int x2, int y11, int y2,int xx,int yy) {
	x1 +=xx;
	x2 +=xx;
	y11 +=yy;
	y2 +=yy;
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
	draw_line(x1, x2, y11, y2,0,0);
	drawTriangle(0,0);
	draw_circle(0,0);
	glFlush();

	printf("how much do you want to translate it with?\n");
	scanf("%d%d",&xx,&yy);

	// glClear(GL_COLOR_BUFFER_BIT);
	draw_line(x1, x2, y11, y2,xx,yy);
	drawTriangle(xx,yy);
	draw_circle(xx,yy);

	glFlush();
}

int main(int argc, char **argv) {

	// printf( "Enter (x1, y11, x2, y2)\n");
	// scanf("%d %d %d %d", &x1, &y11, &x2, &y2);
	x1 = 100,y11=100,x2=200,y2=200;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366,768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Translation");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}