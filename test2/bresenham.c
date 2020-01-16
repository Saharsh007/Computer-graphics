#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
// using namespace std;

float x1,y11,x2,y2;

void bresenham() 
{ 
   int m_new = 2 * (y2 - y11); 
   int slope_error_new = m_new - (x2 - x1); 
   for (int x = x1, y = y11; x <= x2; x++) 
   { 

   		glPointSize(5);
   		glColor3f(0.5, 1.0, 0.4);

		glBegin(GL_POINTS);
		glVertex2f(x,y);
		glEnd();
	  
      // Add slope to increment angle formed 
      slope_error_new += m_new; 
  
      // Slope error reached limit, time to 
      // increment y and update slope error. 
      if (slope_error_new >= 0) 
      { 
         y++; 
         slope_error_new  -= 2 * (x2 - x1); 
      } 
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

// driver function 
int main(int argc, char** argv) 
{ 
	printf("enter x1,y1,x2,y2\n");
	// scanf("%f%f%f%f",&x1,&y11,&x2,&y2);
	x1 = 0,y11=0,x2=40,y2=0;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize (2560,1600);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Bresenham algo");
	init();
	glutDisplayFunc(bresenham);
	glutMainLoop();
} 
