#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h> 
int flag = 0;
 
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height; 
 
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0); 
 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
} 
 
static void display(void)
{ 
 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(0,1,0); 

    if( flag == 1){
        glPushMatrix();
            glTranslated(0.0, 1.5, -6);
            glRotated(0, 0.0, -1.0, 0.0);
            glutSolidTeapot(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(3.0, 1.5, -6);
            glRotated(90, 0.0, -1.0, 0.0);
            glutSolidTeapot(1);
        glPopMatrix(); 

        glPushMatrix();
            glTranslated(-3.0, 1.5, -6);
            glRotated(120, 0.0, -1.0, 0.0);
            glutSolidTeapot(1);
        glPopMatrix(); 

    }
    else{
        glColor3d(1, 0, 0);
        glPushMatrix();
            glTranslated(3.0, -1.2, -6.0);
            glRotated(0, 0.0, -1.0, 0.0);

            glutWireTeapot(1);
        glPopMatrix();

        glColor3d(1, 0, 0);
        glPushMatrix();
            glTranslated(-3.0, -1.2, -6.0);
            glRotated(45, 0.0, -1.0, 0.0);
            glutWireTeapot(1);
        glPopMatrix();

        glColor3d(1, 0, 0);
        glPushMatrix();
            glTranslated(0.0, -1.2, -6.0);
            glRotated(90, 0.0, -1.0, 0.0);
            glutWireTeapot(1);
        glPopMatrix();
        
    }
 
    glutSwapBuffers();
 
    
} 
 
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 
 
void typeMenu (int option)
{
    if(option==1){
        flag = 1;
        display();
    }
    if(option==2){
        flag = 2;
        display();
    }
}
 
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
 
    glutCreateWindow("Programming Techniques - 3D Teapots"); 
 
    glutReshapeFunc(resize);
    glutDisplayFunc(display); 
 
    glClearColor(1,0.5,0.8,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK); 
 
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS); 
 
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); 
 
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
 
    //menu
    glutCreateMenu(typeMenu);
    glutAddMenuEntry("Solid",1);
    glutAddMenuEntry("Wired",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop(); 
 
    return EXIT_SUCCESS;
}