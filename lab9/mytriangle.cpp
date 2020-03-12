#include <GL/glut.h>
#include<stdio.h>

/* a point data type
typedef GLfloat point2[2];
/* initial triangle */
struct point2{
    int x;
    int y;
}p[3];


 
int n; /* number of recursive steps */


void triangle( point2 a, point2 b, point2 c)
/* display one triangle  */
{
    glBegin(GL_POLYGON); 
    glColor3f(1.0,0.0,0.0);
    glVertex2f(a.x,a.y); 
    glColor3f(0.0,1.0,0.0);
    glVertex2f(b.x,b.y);  
    glColor3f(0.0,0.0,1.0);
    glVertex2f(c.x,c.y);
    glEnd();
}


void divide_triangle(point2 a, point2 b, point2 c, int m)
{
    /* triangle subdivision 
    using vertex numbers */
    point2 v0, v1, v2;
    if(m>0)
    {
        v0.x = (a.x+b.x)/2;     v0.y = (a.y+b.y)/2; 
        v1.x = (a.x+c.x)/2;     v1.y = (a.y+c.y)/2; 
        v2.x = (b.x+c.x)/2;     v2.y = (b.y+c.y)/2; 

        divide_triangle(a, v0, v1, m-1);
        divide_triangle(c, v1, v2, m-1);
        divide_triangle(b, v2, v0, m-1);
    }
    else(triangle(a,b,c));
    /* draw triangle at end of recursion */
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    divide_triangle(p[0], p[1], p[2], n);
    // triangle(p[0],p[1],p[2]);
    glFlush();
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1366,1366,-768,768);
    glMatrixMode(GL_MODELVIEW);
    glClearColor (0,0,0,0);
    glColor3f(0.0,0.0,0.0);
}


int main(int argc, char **argv)
{
    p[0].x = -1366; p[0].y = -768;
    p[1].x = 0; p[1].y = 768;
    p[2].x = 1366; p[2].y = -768;

    printf("enter value of n \n");
    scanf("%d",&n);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366, 768);
    glutCreateWindow("2D Gasket");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
}

/*
g++ triangle    .cpp -lglut -lGL -lGLU
*/