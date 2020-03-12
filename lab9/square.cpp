#include <GL/glut.h>
#include<stdio.h>

/* a point data type
typedef GLfloat point2[2];
/* initial triangle */
struct point2{
    int x;
    int y;
}p[4];


 
int n; /* number of recursive steps */


void square( point2 a, point2 b, point2 c,point2 d)
/* display one square  */
{
    glBegin(GL_POLYGON); 
    glColor3f(1.0,0.0,0.0);
    glVertex2f(a.x,a.y); 
    // glColor3f(0.0,1.0,0.0);
    glVertex2f(b.x,b.y);  
    // glColor3f(0.0,0.0,1.0);
    glVertex2f(c.x,c.y);
    // glColor3f(0.0,0.0,0.0);
    glVertex2f(d.x,d.y);
       
    glEnd();
}


void divide_square(point2 a, point2 b, point2 c,point2 d ,int m)
{
    /* triangle subdivision 
    using vertex numbers */
    /*
        v0 v11 v10 v9     
        v1 v14 v15 v8
        v2 v12 v13 v7
        v3 v4  v5  v6
        a   b
        d   c
    */
    point2 v0, v1, v2, v3, v4, v5, v6, v7,v8,v9, v10, v11, v12, v13, v14, v15;
    if(m>0)
    {
        v0 = a;
        v1.x = a.x;     v1.y = (1/3)*(2*a.y+d.y);
        v2.x = a.x;     v2.y = (1/3)*(a.y+2*d.y);
        v3 = d;     
        v4.x =  (1/3)*(2*c.x+d.x);     v4.y = d.y;
        v5.x = (1/3)*(c.x+2*d.x);       v5.y = d.y;
        v6 = c;
        v7.x = c.x;     v7.y = v2.y;
        v8.x = c.x;     v8.y = v1.y;
        v9 = b;
        v10.x = v5.x;     v10.y = a.y;
        v11.x = v4.x;     v11.y = a.y;
        v12.x = v4.x;     v12.y = v2.y;
        v13.x = v5.x;   v13.y = v2.y;
        v14.x = v4.x;   v14.y = v1.y;
        v15.x = v5.x;   v15.y = v1.y;

        divide_square(v0,v11,v14,v1,m-1);
        divide_square(v1,v14,v12,v2,m-1);
        divide_square(v2,v12,v4,v3,m-1);
        divide_square(v11,v10,v15,v14,m-1);
        // divide_square(v12,v14,v15,v13,m-1);
        divide_square(v12,v13,v5,v4,m-1);
        divide_square(v10,v9,v8,v15,m-1);
        divide_square(v15,v8,v7,v13,m-1);
        divide_square(v13,v7,v6,v5,m-1);
    }
    else(square(a,b,c,d));
    /* draw triangle at end of recursion */
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    divide_square(p[0], p[1], p[2],p[3], n);
    // square(p[0],p[1],p[2],p[3]);
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
    p[0].x = -700; p[0].y = 700;
    p[1].x = 700; p[1].y = 700;
    p[2].x = 700; p[2].y = -700;
    p[3].x = -700; p[3].y = -700;

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