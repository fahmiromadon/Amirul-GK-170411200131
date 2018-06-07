#include <Windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <Math.h>
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
    for(int i=0; i<12; i++){
        glRotated(90,0,0,1);
        glPushMatrix();
        if((i)%2==1){
            glColor3f(0.0,0.0,1.0);
            glPushMatrix();
                glScalef(0.75,0.75,0);
                glRecti(-44, -3, -35, 6 );
            glPopMatrix();
            glRecti(-30, 11, -21, 20 );
            glPushMatrix();
                glScalef(0.75,0.75,0);
                glRecti(-24, 30, -15, 39 );
            glPopMatrix();
        }else{
            glColor3f(0.0,0.0,1.0);
            glRecti(-34, -3, -25, 6 );
            glPushMatrix();
                glScalef(0.75,0.75,0);
                glRecti(-37, 18, -28, 27 );
            glPopMatrix();
            glRecti(-18, 21, -9, 30 );
        }
        glPopMatrix();
    }

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,0.0);
    for(float a = -30; a<30; a+=0.1){

        glVertex2f(30*sin(a), 30*cos(a));

    }
    glEnd();
    glFlush();
}


void myinit()
{
    gluOrtho2D(-40, 40, -40, 40);
}
int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("no4");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
