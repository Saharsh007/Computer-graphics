#include<GL/glut.h>
#include<stdio.h>
// #include<math.h>
#include<iostream>

using namespace std;
void display();

float xmin = -200;
float ymin = -200;
float xmax = 200;
float ymax = 200;
float xd1,yd1,xd2,yd2;

int bitcode(float x, float y){
    int c=0;
    if(x<xmin) c |= 1;
    if(x>xmax) c |= 2;
    if(y<ymin) c |= 4;
    if(y>ymax) c |= 8;
    return c; 
}

void cohen_line_algo(float x1, float y1, float x2, float y2){
    int c1 = bitcode(x1,y1);
    int c2 = bitcode(x2,y2);
    float m = (y2-y1)/(x2-x1);
    
    while( (c1|c2) > 0){            //not completely inside
        if( (c1 & c2) > 0){         //completely outside 
            exit(0);
        }
        float xi = x1;
        float yi = y1;
        int c = c1;
        if(c == 0){                 //one point lies inside
            c = c2;
            xi = x2;
            yi = y2;
        }
        //at this point 
        //if c = c2 means xi = x2 and yi = y2;
        // if c != c2 xi = x1 and yi = y1; 
        float x,y;
        if( (c & 8) > 0)            //one point top portion
        {
            y = ymax;
            x = xi + (1.0/m)*(ymax-yi);
        }
        //xi and yi are the new points intersecting the boundry lines made
        //by the rectangle

        else if( (c & 4) > 0)            //one point in bottom portion
        {
            y = ymin;
            x = xi + (1.0/m)*(ymin-yi);
        }

        else if( (c & 2) > 0)            //one point in right portion
        {
            x = xmax;
            yi = yi + m*(xmax-xi);
        }

        else if( (c & 1) > 0)            //one point in left portion
        {
            x = xmin;
            yi = yi + m*(xmin-xi);
        }

        if(c == c1){                    //c1 lies outside of rectangle
            xd1 = x;
            yd1 = y;
            c1 = bitcode(xd1,yd1);
        }
        if(c == c2){                    //c1 lies inside of rectangle
            xd2 = x;
            yd2 = y;
            c2 = bitcode(xd2,yd2);
        }
    }
    display();
}

void init(void)
{
    glClearColor(0.0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1366,1366,-768,768);
}


void mykey(unsigned char key, int x, int y){
    if(key=='l'){
        printf("IT HAPPENED\n");
        cohen_line_algo(xd1,yd1,xd2,yd2);
        glFlush();
    }
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,1);
    // 2 3
    // 1 4
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);
    glVertex2i(xmin,ymax);
    glVertex2i(xmax,ymax);
    glVertex2i(xmax,ymin);
    glEnd();

    glColor3f(1,1,0);
    glBegin(GL_LINES);
    glVertex2i(xd1,yd1);
    glVertex2i(xd2,yd2);
    glEnd();
    glFlush();
}

int main(int argc, char **argv){

    printf("ENTER LINE COORDINATES\n");
    scanf("%f%f%f%f",&xd1,&yd1,&xd2,&yd2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("clip");
    glutDisplayFunc(display);
    glutKeyboardFunc(mykey);
    init();
    glutMainLoop();
    return 0;
}

/*
g++ clip.cpp -lglut -lGL -lGLU
*/