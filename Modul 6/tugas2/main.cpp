#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

float d = 0;
float x2 = 0;
float y2 = 0;
float z2 = 0;

void kubus(float s){
    float x1=(s/2);
    float y1=(s/2);
    float z1=(s/2);
    glColor3d(0,0,1);
    glBegin(GL_POLYGON);
        glVertex3d(-x1,y1,z1);
        glVertex3d(x1,y1,z1);
        glVertex3d(x1,-y1,z1);
        glVertex3d(-x1,-y1,z1);
    glEnd();
    glColor3d(0,1,0);
    glBegin(GL_POLYGON);
        glVertex3d(-x1,y1,-z1);
        glVertex3d(x1,y1,-z1);
        glVertex3d(x1,-y1,-z1);
        glVertex3d(-x1,-y1,-z1);
    glEnd();
    glColor3d(0,1,1);
    glBegin(GL_POLYGON);
        glVertex3d(x1,y1,z1);
        glVertex3d(x1,y1,-z1);
        glVertex3d(x1,-y1,-z1);
        glVertex3d(x1,-y1,z1);
    glEnd();
    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3d(-x1,-y1,z1);
        glVertex3d(-x1,-y1,-z1);
        glVertex3d(-x1,y1,-z1);
        glVertex3d(-x1,y1,z1);
    glEnd();
    glColor3d(1,0,1);
    glBegin(GL_POLYGON);
        glVertex3d(-x1,y1,z1);
        glVertex3d(-x1,y1,-z1);
        glVertex3d(x1,y1,-z1);
        glVertex3d(x1,y1,z1);
    glEnd();
    glColor3d(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3d(-x1,-y1,z1);
        glVertex3d(-x1,-y1,-z1);
        glVertex3d(x1,-y1,-z1);
        glVertex3d(x1,-y1,z1);
    glEnd();

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glPointSize(10);

    glRotated(d,x2,y2,z2);

    glPushMatrix();
    glScaled(4,1,1);
    kubus(2);
    glPopMatrix();

    glPushMatrix();
    glScaled(1,4,1);
    kubus(2);
    glPopMatrix();
//
//    glBegin(GL_LINES);
//        glColor3d(1,0,0);
//        glVertex3d(5,0,0);
//        glVertex3d(-5,0,0);
//
//        glColor3d(0,1,0);
//        glVertex3d(0,5,0);
//        glVertex3d(0,-5,0);
//
//        glColor3d(0,0,1);
//        glVertex3d(0,0,5);
//        glVertex3d(0,0,-5);
//    glEnd();

    glFlush();
}

void kunci(unsigned char key, int x, int y)
{
    switch (key)
    {

//    case 27 :
    case 'q':
        exit(0);
        break;
    case 'a':
        d=1;
        x2=1;
        y2=0;
        z2=0;
        glutPostRedisplay();
        break;
    case 's':
        d=1;
        x2=0;
        y2=1;
        z2=0;
        glutPostRedisplay();
        break;
    case 'd':
        d=1;
        x2=0;
        y2=0;
        z2=1;
        glutPostRedisplay();
        break;
    }
}

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Kubus");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(kunci);
    glutMainLoop();
    return 0;
}
