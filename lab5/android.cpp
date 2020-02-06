#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int xc=0,yc=0,r=100;

void draw_pixel(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
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

void init(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-1366,1366,-768,768);
}

void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
     glVertex2i(x,y);
  glEnd();
}

void head(){
 
  int x=0,y=r;
  int d = 3 - 2*r;    // = 1 - r
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f( 1 ,0, 0);
  while(x<=y){
    setPixel(xc+x,yc+y);
    setPixel(xc+y,yc+x);  //find other points by symmetry
    setPixel(xc-x,yc+y);
    // setPixel(xc+y,yc-x);
    // setPixel(xc-x,yc-y);
    // setPixel(xc-y,yc-x);
    // setPixel(xc+x,yc-y);
    setPixel(xc-y,yc+x);
    draw_line(xc-r,xc+r,yc,yc);
    if (d<0)
  d += (4*x)+6;
    else {
 d += (4*(x-y))+10;
 y -= 1;
    }
    x++;
  }

}

void body(){
    glBegin(GL_POLYGON);
    glVertex2i(xc+r,yc-10);
    glVertex2i(xc+r,yc-150);
    glVertex2i(xc-r,yc-150);
    glVertex2i(xc-r,yc-10);
    // printf("%d",r);
    glEnd();



}
void hand(){
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2i(xc+r+50,yc-10);
    glVertex2i(xc+r+50,yc-150);
    glVertex2i(xc+r+10,yc-150);
    glVertex2i(xc+r+10,yc-10);
    // printf("%d",r);
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glVertex2i(xc-10-r,yc-10);
    glVertex2i(xc-10-r,yc-150);
    glVertex2i(xc-60-r,yc-150);
    glVertex2i(xc-60-r,yc-10);
    // printf("%d",r);
    glEnd();

}


void display(void) {

    head();
    body();
    hand();
    glFlush();

}

void keyboard( unsigned char key, int x, int y )
{
    if( key =='i' ) NULL;
}



int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1366,768);
    glutCreateWindow("android");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc( keyboard );	

    glutMainLoop();
    return 0;
}