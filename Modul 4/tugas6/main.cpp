#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
void bulat(float a , float b){
    glColor3f(1,0,0.8);
    glBegin(GL_POLYGON);
        for (float x=0; x<2*3.14; x+=0.01) {
            glVertex2f(cos(x)*2.0+a, sin(x)*2.0+b);
        }
    glEnd();
}

void kelopak(float a , float b){
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex3f (6.5+a,-1+b, 0.0);
    glColor3f(1,0,1);
        for(float t = -1.5; t<=2.5; t+=0.01){
            glVertex3f (a+t*t, b+t*5.0, 0.0);
        }
            for(float t = -1.5; t<=2.5; t+=0.01){
                glVertex3f (a+12.5-t*t, b+t*5.0, 0.0);
            }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    bulat(0.0,0.0);
    glScaled(0.5, 0.5, 0.0);
    for (int i=0; i<=9; i++){
        glRotated(40,0,0,1);
        kelopak(-7.0,-20.0);
    }
    glFlush();
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0,50.0,-50.0,50.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0,0.0,0.0,0.0);
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
