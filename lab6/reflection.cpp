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
	gluOrtho2D( -1366.0f, 1366.0f, -768.0f , 768.0f);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}


void drawTriangle(int xx,int yy)
{
    // glClearColor(1.0, 0.0, 0.0, 1.0);
    // glClear(GL_COLOR_BUFFER_BIT);

    // glColor3f(0.5, 0.5, 1.0);
   // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

        glBegin(GL_TRIANGLES);
                glVertex2f(100*xx, -200*yy);
                glVertex2f(200*xx, -200*yy);
                glVertex2f(150*xx, -300*yy);
        glEnd();
    // glClear(GL_COLOR_BUFFER_BIT);

    // glFlush();
}



void myDisplay() {
	// glClear(GL_COLOR_BUFFER_BIT);
	drawTriangle(1,1);
	glFlush();

	printf("where do you want to reflect, 1 for x and 0 for y\n");
	int flag;
	scanf("%d",&flag);
	if(flag)
		drawTriangle(-1,1);
	else
		drawTriangle(1,-1);

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