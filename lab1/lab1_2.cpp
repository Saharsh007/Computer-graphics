#include <GL/glut.h>  
char title[] = "3D Shapes";
 
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClearDepth(1.0f);                  
   glEnable(GL_DEPTH_TEST);   
   glDepthFunc(GL_LEQUAL);   
}
 
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   
   glLoadIdentity();                 
   glTranslatef(1.5f, 0.0f, -7.0f); 
   glBegin(GL_QUADS);
      // Top 
      glColor3f(1.0f, 0.0f, 0.0f);     
      /*---------beacause of translate, the centre of cube has moved, so we define the vertices wrt the new centre---------*/
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
 
      // Bottom 
      glColor3f(1.0f, 0.0f, 0.0f);     
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
 
      // Front 
      glColor3f(0.0f, 1.0f, 0.0f);     
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
 
      // Back 
      glColor3f(0.0f, 1.0f, 0.0f);     
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
 
      // Left 
      glColor3f(0.0f, 0.0f, 1.0f);     
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
 
      // Right 
      glColor3f(0.0f, 0.0f, 1.0f);     
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();  
 
   
   glLoadIdentity();                  
   glTranslatef(-1.5f, 0.0f, -6.0f);  
 
   glBegin(GL_TRIANGLES);           
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(1.0f, 0.0f, 0.0f);     
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(1.0f, 0.0f, 0.0f);        
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
      glColor3f(0.0f, 1.0f, 0.0f);     
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Back
      glColor3f(0.0f, 1.0f, 0.0f);    
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(1.0f, 0.0f, 0.0f);    
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(1.0f, 0.0f, 0.0f);    
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // Left
      glColor3f(0.0f,0.0f,1.0f);      
      glVertex3f( 0.0f, 1.0f, 0.0f);
     glColor3f(0.0f,0.0f,1.0f);      
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,0.0f,1.0f);      
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}