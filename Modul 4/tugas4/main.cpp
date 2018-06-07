#include <Windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <Math.h>
void display()
{
    //kotak-kotak
    glColor3f(0.0, 0.0, 1.0);
    for (int i=0; i<12; i++)
    {
        glRotated(30, 0, 0, 1);
        if((i)%2==1){
            glRecti(-5, 35, 5, 45);
        }else{
            glRecti(-5, 35, 3, 43);
        }

    }
    //lingkaran
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINE_STRIP);
    for (float a=-40; a<=0; a+=0.01)
    {
        glVertex2f(40*cos(a), 40*sin(a));
    }
    glEnd();
    glFlush();
}
void myinit()
{
    gluOrtho2D(-50, 50, -50, 50);
}
int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("no2");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
