#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
// GLfloat angle = 0.0f;  // rotational angle of the shapes
// int refreshMills = 1; // refresh interval in milliseconds


// void Timer(int value) {
//    glutPostRedisplay();      // Post re-paint request to activate display()
//    glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
// }

int r1=50,r2=100;

struct Point {
	GLint x;
	GLint y;
};

Point p1, p2;



void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}
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


void Circle(int xCenter,int yCenter,int r){
 
  int x=0,y=r;
  int d = 3 - 2*r;    // = 1 - r
  while(x<=y){
    setPixel(xCenter+x,yCenter+y);
    setPixel(xCenter+y,yCenter+x);  //find other points by symmetry
    setPixel(xCenter-x,yCenter+y);
    setPixel(xCenter+y,yCenter-x);
    setPixel(xCenter-x,yCenter-y);
    setPixel(xCenter-y,yCenter-x);
    setPixel(xCenter+x,yCenter-y);
    setPixel(xCenter-y,yCenter+x);

    if (d<0)
      d += (4*x)+6;
    else {
      d += (4*(x-y))+10;
        y -= 1;
    }
    x++;
  }
  // glFlush();
}
void drawcircle(Point p1){
    // glClear(GL_COLOR_BUFFER_BIT);
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glColor3f( 1 ,0, 0);
    Circle(p1.x,p1.y,r1);
    Circle(p1.x,p1.y,r2);
    printf("\t%d,%d\n",p1.x,p1.y);
    // glPushMatrix();
    // glRotatef(angle,0.0f,0.0f,1.0f);
    // draw_line(x1,x2,y1,y2);

    draw_line(p1.x, p1.x, p1.y+r1 ,p1.y+r2);
    draw_line(p1.x+r1,p1.x+r2,p1.y,p1.y);
    draw_line(p1.x, p1.x,p1.y-r1,p1.y-r2);
    draw_line(p1.x-r1,p1.x-r2,p1.y,p1.y);
    // draw_line(100,400,0,0);
    // draw_line(-100,-400,0,0);
    // draw_line(69,285,69,285);
    // draw_line(-69,-285,-69,-285);
    // draw_line(69,285,-69,-285);
    // draw_line(-69,-285,69,285);
    glEnd();
    // glPopMatrix();
    // draw_line(-500,500,-400,-400);
    glFlush();
    // angle += 0.02f;
}


void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON) {
		p1.x = x;
		p1.y = 768-y;
    drawcircle(p1);
	}
  if(button == GLUT_RIGHT_BUTTON) {
        exit(0);
	}
}

// void init(void)
// {
//   glClearColor(1.0,1.0,1.0,0.0);
//   glMatrixMode(GL_PROJECTION);
//   gluOrtho2D(-500,500,-500,500.0);
// }

void keyboard( unsigned char key, int x, int y )
{
    if( key =='i' )
    {
        r1 +=50;
        r2 +=50;

    }
    if(key=='d')
    {
      r1 -=2;
      r2 -=2;
    }
    if(key=='c')
    {
      glClear(GL_COLOR_BUFFER_BIT);
      // init();
      glEnd();
      glFlush();
    }
    

}

void init() {
  glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(1.0f);
	gluOrtho2D(0.0f, 1366.0f, 0.0f, 768.0f);
}

void display(void) {}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1366,768);
    glutCreateWindow("Mouse Circle");
    glutDisplayFunc(display);
    glutKeyboardFunc( keyboard );	
    glutMouseFunc(myMouseFunc);
    init();
    // glutTimerFunc(0, Timer, 0);     // First timer call immediately
    glutMainLoop();
    return 0;
}