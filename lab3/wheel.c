
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <unistd.h>
// Center of the cicle = (320, 240)
int xc = -2500, yc = 0;
int x1, y11, x2, y2;



void draw_point(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y11, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y11;

	dx = abs(dx);
	dy = abs(dy);
	incx = 1;
	// increment in right direction if coming from right to left
	if (x2 < x1) incx = -1;
	incy = 1;
	// increment in down direction if coming from up to down
	if (y2 < y11) incy = -1;

	//starting from intial point
	x = x1; y = y11;
	
	//if slope if less than 1
	if (dx > dy) {
		//plot the point
		draw_point(x, y);
		//e is the new slope
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
			draw_point(x, y);
		}

	//slope > 1
	} else {
		draw_point(x, y);
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
			draw_point(x, y);
		}
	}
}
// Plot eight points using circle's symmetrical property
void plot_point(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}

// Function to draw a circle using bresenham's
// circle drawing
    //BOTTOM  algorithm
void bresenham_circle(int r)
{
  int x=0,y=r;
  float d=3-2*r;

  /* Plot the points */
  /* Plot the first point */
  plot_point(x,y);
  int k;
  /* Find all vertices till x=y */
  while(x <= y)
  {
    x = x + 1;
    if( d < 0)
      d = d + 4*x+6;
    else
    {
      y = y - 1;
      d = d + 4*(x - y) + +10;
    }
    plot_point(x,y);
  }

  
  glFlush();
}

void drawlines() {
	draw_line(x1, x2, y11, y2);
	glFlush();
}

// Function to draw two concentric circles
void concentric_circles(vogluOrtho2Did)
{
    int r1 = 150, r2 = 600;



    while(1){
     xc++;
       sleep(0.00005);
        if(xc > 2000) break;
  
    /* Clears buffers to preset values */
    glClear(GL_COLOR_BUFFER_BIT);

    //INNER CIRCLE RED
    glColor3f(1.0,0.0,0.0);
    bresenham_circle(r1);
    glColor3f(0.0,0.0,1.0);
    bresenham_circle(r2);
    glColor3f(0.0,0.0,0.0);

    //1
    x1 = 0 + xc, y11 = r1 + yc, x2 = 0  + xc, y2 = r2 + yc;
    drawlines();
    //2
    x1 = r1/sqrt(2) + xc, y11 = r1/sqrt(2) + yc, x2 = r2/sqrt(2) + xc , y2 = r2/sqrt(2) + yc;
    drawlines();
    //3
    x1 = r1 + xc, y11 = 0 + yc, x2 = r2 + xc , y2 = 0 + yc;
    drawlines();
    //4
    x1 = r1/sqrt(2) + xc, y11 = -r1/sqrt(2) + yc, x2 =  r2/sqrt(2)  + xc, y2 =  -r2/sqrt(2) + yc;
    drawlines();
    //5
    x1 = 0 + xc, y11 = -r1 + yc, x2 = 0 + xc , y2 = -r2 + yc;
    drawlines();
    //6
    x1 =-r1/sqrt(2) + xc, y11 = -r1/sqrt(2) + yc, x2 = - r2/sqrt(2)  + xc, y2 =  -r2/sqrt(2) + yc;
    drawlines();
    //7
    x1 = -r1 + xc, y11 = 0 + yc, x2 = -r2  + xc, y2 = 0 + yc;
    drawlines();
    //8
    x1 = -r1/sqrt(2) + xc, y11 = r1/sqrt(2) + yc, x2 = - r2/sqrt(2)  + xc, y2 =  r2/sqrt(2) + yc;
    drawlines();
    
        //BOTTOM LINE
    glColor3f(0.0,0.0,0.0);
    x1 = -1500, y11 = -r2, x2 = 2000,  y2 = -r2;
    drawlines();
      }

}

void Init()
{
  /* Set clear color to white */
  glClearColor(0.0,1.0,1.0,0);
  /* Set fill color to black */
  glColor3f(0.0,0.0,0.0);
  /* glViewport(0 , 0 , 640 , 480); */
  /* glMatrixMode(GL_PROJECTION); */
  /* glLoadIdentity(); */
  gluOrtho2D(-1366 , 1366 , -768 , 768);
}

void main(int argc, char **argv)
{
  /* Initialise GLUT library */
  glutInit(&argc,argv);
  /* Set the initial display mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(1366,768);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("bresenham_circle");
  /* Initialize drawing colors */
  Init();
  /* Call the displaying function */
  glutDisplayFunc(concentric_circles);
  /* Keep displaying untill the program is closed */
  glutMainLoop();
}