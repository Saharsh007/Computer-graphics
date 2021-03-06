#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>
 
#define H 1366
#define W 768
 
int n=3;
float xd1[50],yd1[50], xd2[50], yd2[50];
using namespace std;
 
float xmin = -200;
float ymin = -200;
float xmax = 200;
float ymax = 200;
 
int bitcode(float x,float y)
{
   int c=0;
   if(y>ymax)c=8;
   if(y<ymin)c=4;
   if(x>xmax)c=c|2;
   if(x<xmin)c=c|1;
   return c;
}
 
void clip_points(float x1,float y1,float x2,float y2, int i)
{
   int c1=bitcode(x1,y1);
   int c2=bitcode(x2,y2);
   float m=(y2-y1)/(x2-x1);
 
   //one of them outside
   while((c1|c2)>0)
   {
       //both outside case
       if((c1 & c2)>0)
       {
           xd1[i]=0;
           xd2[i]=0;
           yd1[i]=0;
           yd2[i]=0;
           return;
       }
   float xi=x1;
   float yi=y1;
   int c=c1;
   if(c==0)
   {
        c=c2;
        xi=x2;
        yi=y2;
   }
   float x,y;
   if((c & 8)>0)
   {
      y=ymax;
      x=xi+ 1.0/m*(ymax-yi);
   }
   else
     if((c & 4)>0)
     {
         y=ymin;
         x=xi+1.0/m*(ymin-yi);
     }
     else
      if((c & 2)>0)
      {
          x=xmax;
          y=yi+m*(xmax-xi);
      }
      else
      if((c & 1)>0)
      {
          x=xmin;
          y=yi+m*(xmin-xi);
      }
 
      if(c==c1)
      {
          xd1[i]=x;
          yd1[i]=y;
          c1 = bitcode(xd1[i],yd1[i]);
 
      }
      if(c==c2)
      {
          xd2[i]=x;
          yd2[i]=y;
          c2=bitcode(xd2[i],yd2[i]);
      }
}
}
 
void myInit(void)
{
   glClearColor(0,0,0,0);
   glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1366,1366,-768,768);
}
 
void mykey(unsigned char key,int x,int y)
{
   if(key=='l')
   {  
       cout<<"DONE";
glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0,1.0,1.0);
 
  glBegin(GL_LINE_LOOP);
  glVertex2i(xmin,ymin);
  glVertex2i(xmin,ymax);
  glVertex2i(xmax,ymax);
  glVertex2i(xmax,ymin);
  glEnd();
 
for(int i=0;i<n;i++){
   clip_points(xd1[i],yd1[i],xd2[i],yd2[i],i);
  glColor3f(0.0,1.0,1.0);
  glBegin(GL_LINES);
  glVertex2i(xd1[i],yd1[i]);
  glVertex2i(xd2[i],yd2[i]);
  glEnd();
} 
//    printf("enter the rectangle coordintes (xmin, ymin, xmax, ymax): ");
//    cin>>xmin>>ymin>>xmax>>ymax;
 
       glFlush();
   }
}
 
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0,1.0,1.0);
 
  glBegin(GL_LINE_LOOP);
  glVertex2i(xmin,ymin);
  glVertex2i(xmin,ymax);
  glVertex2i(xmax,ymax);
  glVertex2i(xmax,ymin);
  glEnd();
 
 
for(int i=0;i<n;i++){
  glColor3f(1.0,1.0,0.0);
  glBegin(GL_LINES);
  glVertex2i(xd1[i],yd1[i]);
  glVertex2i(xd2[i],yd2[i]);
  glEnd();
}
 
 
       glFlush();
}
 
int main(int argc,char** argv)
{  
   float t1,t2,t3,y1,y2,y3;
   printf("ENTER COORDINATES");
   cin>>t1>>y1;
       cin>>t2>>y2;
   cin>>t3>>y3;
 
   xd1[0] = t1;
   yd1[0] = y1;
xd2[0] = t2;
   yd2[0] = y2;
 
 
   xd1[1] = t1;
   yd1[1] = y1;
xd2[1] = t3;
   yd2[1] = y3;
 
 
   xd1[2] = t2;
   yd1[2] = y2;
xd2[2] = t3;
   yd2[2] = y3;
 
 
//    printf("enter the rectangle coordintes (xmin, ymin, xmax, ymax): ");
//    cin>>xmin>>ymin>>xmax>>ymax;
 
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366,768);
       glutInitWindowPosition(0,0);
   glutCreateWindow("cohen sutherland algo");
   glutDisplayFunc(display);
           glutKeyboardFunc(mykey);
 
   myInit();
   glutMainLoop();
   return 0;
}
 
 
 



/*
g++ clip.cpp -lglut -lGL -lGLU
input
120 -170 150 170 250 -150
*/