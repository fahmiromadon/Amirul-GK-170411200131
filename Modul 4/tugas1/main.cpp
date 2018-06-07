#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glRotated(45, 0, 0, 1);
for (int i=0; i<=10; i++)
    {
        for (int j=-10; j<=10; j++)
    {
       if((i+j)%2==0)
       {
           glColor3f(1.0,1.0,0.0);
       }else
       {
           glColor3f(0,0,1);
       }
       glRecti((i*10),(j*10),(i*10)+10,(j*10)+10);
    }
    }
glFlush();
}
void myinit()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,55.0,0.0,55.0);
glMatrixMode(GL_MODELVIEW);
glClearColor(1.0,1.0,0.0,1.0);
glColor3f(0.0,0.0,0.0);
}
int main(int argc, char* argv[])
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(400,400);
glutInitWindowPosition(100,100);
glutCreateWindow("Transform");
glutDisplayFunc(display);
myinit();
glutMainLoop();
return 0;
}
