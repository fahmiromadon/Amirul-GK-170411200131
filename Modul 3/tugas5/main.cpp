#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
void monster(float a,float b,float c, float d, float e) {
    glColor3f(c,d,e);
    glBegin(GL_POLYGON);
        for (float x=0.0; x<3.14; x+=0.01) {
            glVertex2f(cos(x)*1.5+a, sin(x)*4+b);
        }
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-1.5+a, 0+b);
        glVertex2f(-1.5+a, -1.5+b);
        bool naik = false;
        float x;
        for (x=-1.5; x<=1.5; x+=3.0/6.0) {
            if (naik) {
                glVertex2f(x+a, -1.8+b);
                naik = false;
            } else {
                glVertex2f(x+a, -1.5+b);
                naik = true;
            }
        }
        glVertex2f(1.5+a, 0+b);
    glEnd();
}

void mataputih(float a , float b){
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        for (float x=0; x<2*3.14; x+=0.01) {
            glVertex2f(cos(x)*0.6+a, sin(x)*1.0+b);
        }
    glEnd();
}
void matahitam(float a , float b){
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        for (float x=0; x<2*3.14; x+=0.01) {
            glVertex2f(cos(x)*0.3+a, sin(x)*0.5+b);
        }
    glEnd();

}

void bulat(float a , float b){
    glColor3f (1,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(0+a,0+b);
    for(float x=0.8; x<5.50; x+=0.01){
        glVertex2f(cos(x)*2.5+a,sin(x)*2.5+b);
    }

    glEnd();


}

void bulat_kecil(float a , float b){
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    for (float x =0.0; x < 2*3.14; x+=0.01){
        glVertex2f(cos(x)*0.6+a,sin(x)*0.8+b);
    }
    glEnd();
}





void display(void) {
    /* bersihkan layar */
    glClear (GL_COLOR_BUFFER_BIT);
    monster(-4.0, -3.0,0.0,0.0,1.0);
    mataputih(-3.3,-2);
    mataputih(-4.7,-2);
    matahitam(-3.1,-2);
    matahitam(-4.5,-2);

    monster(2.0,-3.0, 1.0,0.5,0.0);
    mataputih(1.3,-2);
    mataputih(2.7,-2);
    matahitam(1.5,-2);
    matahitam(2.8,-2);

    bulat(8,-2);
    bulat_kecil(10.5,-1.8);
    bulat_kecil(12.5,-1.8);


    glFlush();



}



void kunci(unsigned char key, int x, int y) {
    switch (key){
        /* aplikasi berhenti ketika tombol q ditekan */
        case 27 :
        case 'q':
        exit(0);
        break;
        }

glutPostRedisplay();

}

void myinit(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-15.0,15.0,-15.0,15.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f (1.0, 1.0, 0.0);
}
int main(int argc, char *argv[])
{
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("PACMAN");
    glutDisplayFunc(display);
    glutKeyboardFunc(kunci);
    myinit();
    glutMainLoop();

    return 0;
}
