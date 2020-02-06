#include <GL/glut.h>
#include<stdio.h>
float s=5;
char spin = 0;
void keyboard( unsigned char key, int x, int y )
{
    if( key =='S' )
    {
        s*=2;
    }
if(key=='R')
s/=2;

}
void draw(int x,int y)
{
//glClearColor (0.0, 0.0, 0.0, 0.0);
 //glClear (GL_COLOR_BUFFER_BIT);
    //glColor3f( 1, 1, 1 );
    glColor3f(1.0, 0.0, 0.0);
glBegin(GL_TRIANGLES);
glVertex3f(x+s*(0),y+s*(0.57),0);
glVertex3f(x+s*(-0.5),y+s*(-0.285),0);
glVertex3f(x+s*(0.5),y+s*(-0.285),0);
glEnd();
glBegin(GL_TRIANGLES);
glVertex3f(x+s*(0),y+s*(-0.57),0);
glVertex3f(x+s*(-0.5),y+s*(0.285),0);
glVertex3f(x+s*(0.5),y+s*(0.285),0);
glEnd();
glFlush();
 
}
float angle = 0;
void timer( int value )
{
    if( spin==1 )
    {
        angle += 3;
    }



    glutTimerFunc( 16, timer, 0 );
    glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:

			exit(0);
		break;
	
	case GLUT_RIGHT_BUTTON:
			draw(x,y);
printf("%d %d\n",x,y);
		break;
	default:
		break;
	}
}


void display()

{
//draw(100,100);
 //glClear (GL_COLOR_BUFFER_BIT);
//glClearColor (0.0, 0.0, 0.0, 0.0);
 glutSwapBuffers();
}
 void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-1000.0, 1000.0, -1000.0, 1000.0, -1.0, 1.0);
 }
int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize( 1000, 1000 );
glutInitWindowPosition (1000, 1000);
    glutCreateWindow( "GLUT" );
init();
    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );	
    glutMouseFunc(mouse);
glutIdleFunc(display);
   // glutTimerFunc( 0, timer, 0 );
    glutMainLoop();
    return 0;
}