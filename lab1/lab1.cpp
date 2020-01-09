#include "GL/freeglut.h"
#include "GL/gl.h"
#include<math.h>

float angle = 30.0f;
float col1=0,col2=0,col3=0;
void update(int value)

{
angle+=2.0f;
col1 += sin(angle);
col2 += cos(angle);
col3 += sin(angle)-0.5;

if(angle>360.f)

{
angle-=360;
}
glutPostRedisplay();

glutTimerFunc(100,update,0);

}

void rotate()
{

    glClearColor(col1,col2,col3, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
 	glLoadIdentity(); 

	//triangle
	glPushMatrix();
	//move the center point around whose axis the object rotates
	// glTranslatef(-0.5f,0.0f,0.0f);
	//rotate (x-axis,y axis,z axis)
	glRotatef(angle,0.0f,1.0f,0.0f);
	//bring back the center point to the origin
	// glTranslatef(0.5f,0.0f,0.0f);
    glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
			glVertex2f(-0.4, 0.5);
			glVertex2f(0.4, 0.5);
			glVertex2f(0, 0);
	glEnd();


	//pentagon
	glPushMatrix();
	glTranslatef(0.6f,0.6f,0.0f);
	glRotatef(angle,1.0f,1.0f,1.0f);
	glTranslatef(-0.6f,-0.6f,0.0f);
	int v;
	float pent[5][2], ang, da = 6.2832 / 5.0;   // da is central angle between vertices in radians

	for (v = 0; v < 5; v++)  {                  // Computes vertex coordinates.
		ang = v * da;
		pent[v][0] = 0.3*cos (ang) + 0.6;
		pent[v][1] = 0.3*sin (ang) + 0.6;
	}

	glBegin (GL_POLYGON);                                         // Draws pentagon.
	for (v = 0; v < 5; v++)  glVertex2fv(pent[v]);
	glEnd();
 	// glPopMatrix();



	// //trapizium
	glPushMatrix();
	float trap[4][2],ang60 = 3.14/3, ang30 = 3.14/6, baselen = 0.6,seclen = 0.3;
	float x = 0.1*sin(ang60)/tan(ang30);
	glTranslatef(float( baselen/2) ,0.0f,0.0f);
	glRotatef(angle,1.0f,0.0f,0.0f);
	glTranslatef(-float( baselen/2),0.0f,0.0f);

	trap[0][0] = 0;
	trap[0][1] = 0;
	trap[1][0] = seclen*cos(ang60);
	trap[1][1] = seclen*sin(ang60) ;
	trap[2][0] = seclen+x;
	trap[2][1] = seclen*sin(ang60);
	trap[3][0] = baselen;
	trap[3][1] = 0;

	glBegin (GL_POLYGON);                                         // Draws pentagon.
	for (v = 0; v < 4; v++)  glVertex2fv(trap[v]);
	glEnd();
 	glPopMatrix();


    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(2560, 1600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Creating  triangle");
	glutTimerFunc(1,update,0); //important
    glutDisplayFunc(rotate);
    glutMainLoop();
    return 0;
}