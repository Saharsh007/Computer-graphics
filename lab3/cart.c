
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <unistd.h>
// Center of the cicle = (320, 240)

float x1, y11, x2, y2;
#define pi 3.14159265358979323846


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
void plot_point(int x, int y,float xc,float yc)
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
void bresenham_circle(int r,float xc,float yc)
{
  int x=0,y=r;
  float d=3-2*r;

  /* Plot the points */
  /* Plot the first point */
  plot_point(x,y,xc,yc);
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
    plot_point(x,y,xc,yc);
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
    float r1 = 50.0f, r2 = 100.0f;
        float xc = -1000, yc = 0;
    float xcc = -400;

    float theta = 0.0f;

    while(1){
    theta += 0.01f;
     xc++;
     xcc++;
       sleep(0.00005);
        if(xc > 2000) break;
  
    /* Clears buffers to preset values */
    glClear(GL_COLOR_BUFFER_BIT);

    //FIRST CIRCLE
    //INNER CIRCLE RED
    glColor3f(1.0,0.0,0.0);
    bresenham_circle(r1,xc,yc);
    glColor3f(0.0,0.0,1.0);
    bresenham_circle(r2,xc,yc);
    glColor3f(0.0,0.0,0.0);

    //SECOND CIRCLE
    glColor3f(1.0,0.0,0.0);
    bresenham_circle(r1,xcc,yc);
    glColor3f(0.0,0.0,1.0);
    bresenham_circle(r2,xcc,yc);
    glColor3f(0.0,0.0,0.0);


    for(int i=0;i<8;i++){
      float ii = i;
      x1 = r1*sin(theta+ ii*pi/4) + xc, y11 = r1*cos(theta+ ii*pi/4) + yc, x2 = r2*sin(theta+ii*pi/4)  + xc, y2 = r2*cos(theta+ ii*pi/4) + yc;
      drawlines();
      
    }


    for(int i=0;i<8;i++){
      float ii = i;
      x1 = r1*sin(theta+ ii*pi/4) + xcc, y11 = r1*cos(theta+ ii*pi/4) + yc, x2 = r2*sin(theta+ii*pi/4)  + xcc, y2 = r2*cos(theta+ ii*pi/4) + yc;
      drawlines();
      
    }
    
        //BOTTOM LINE
    glColor3f(0.0,0.0,0.0);
    x1 = -1500, y11 = -r2, x2 = 2000,  y2 = -r2;
    drawlines();

    //OTHER LINES
        
        //BOTTOM LINE
    glColor3f(0.0,0.0,0.0);
    x1 = xc, y11 = yc, x2 = xcc,  y2 = yc;
    drawlines();

    glColor3f(0.0,0.0,0.0);
    x1 = xc, y11 = yc, x2 = xc,  y2 = yc+500;
    drawlines();

    glColor3f(0.0,0.0,0.0);
    x1 = xcc, y11 = yc, x2 = xcc,  y2 = yc+500;
    drawlines();

    glColor3f(0.0,0.0,0.0);
    x1 = xc, y11 = yc+500, x2 = xcc,  y2 = yc+500;
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