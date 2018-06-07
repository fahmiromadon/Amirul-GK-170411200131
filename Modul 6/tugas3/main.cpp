#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

float a=0;
float x1=0;
float y1=0;
float z1=0;

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



void display(void) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);



    glRotated(a,x1,y1,z1);

    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glutWireCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,0);
    glTranslated(10,0,0);
    glScaled(0.5,0.5,0.5);
    glutWireTeapot(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,0);
    glTranslated(-10,0,0);
    glScaled(0.4,0.4,0.4);
    glutWireSphere(3,7,9);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1,1,0);
    glTranslated(0,10,0);
    glScaled(0.5,0.5,0.5);
    glutWireCone(2,4,7,9);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,1);
    glTranslated(0,-10,0);
    glScaled(1.5,1.5,1.5);
    glutWireTetrahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,1);
    glTranslated(0,0,10);
    glScaled(1.5,1.5,1.5);
    glutWireOctahedron();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,-10);
    //glScaled(1.5,1.5,1.5);
    kubus(2);
    glPopMatrix();


    glBegin(GL_LINES);
        glColor3d(1,0,0);
        glVertex3d(10,0,0);
        glVertex3d(-10,0,0);

        glColor3d(0,1,0);
        glVertex3d(0,10,0);
        glVertex3d(0,-10,0);

        glColor3d(0,0,1);
        glVertex3d(0,0,10);
        glVertex3d(0,0,-10);
    glEnd();

    glFlush();

}

void init(void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0,10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

void kunci(unsigned char key, int x, int y) {
    switch (key){

    case 'q':
        exit(0);
        break;
    case 'a':
        a=1;
        x1=1;
        y1=0;
        z1=0;
        //glutPostRedisplay();
        break;
    case 's':
        a=1;
        x1=0;
        y1=1;
        z1=0;
        //glutPostRedisplay();
        break;
    case 'd':
        a=1;
        x1=0;
        y1=0;
        z1=1;
        //glutPostRedisplay();
        break;
        }
        glutPostRedisplay();
}

int main(int argc, char** argv){

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
