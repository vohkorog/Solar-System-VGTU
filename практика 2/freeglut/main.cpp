#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#include <cmath>

unsigned int day = 0;

double rX=0;
double rY=15;
double p = 15;

GLfloat pos0[] = { 1.0, 1.0, 0.0, 0.0 };
GLfloat ambientColor0[] = { 0.1, 0.1, 0.1, 0.0 };
GLfloat diffuseColor0[] = { 0.8, 0.8, 0.8, 0.0 };


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseColor0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, pos0);
        //sun
    glColorMaterial(GL_FRONT, GL_AMBIENT);
    glColor3f(1.0, 1.0, 0.0);
    glutWireSphere(2.0, p, p);
    day += 1;
        if (day > std::numeric_limits<unsigned int>::max()) {
            day = 0;
        }
    glRotatef( rX, 1.0, 0.0, 0.0 );
        //first planet
    glPushMatrix();
    glRotatef((GLfloat)day*1.6, 0.0, 1.0, 0.0);
    glTranslatef (2.5, 0.0, 0.0);
    glRotatef((GLfloat)day*1.6, 0.0, 1.0, 0.0);
    glColor3f(1, 0, 0);
    glutWireSphere(0.038, p, p);
    glPopMatrix();
        //second planet
    glPushMatrix();
    glRotatef((GLfloat)day * 1.17, 0.0, 1.0, 0.0);
    glTranslatef (3.5, 0.0, 0.0);
    glRotatef((GLfloat)day * 1.17, 0.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 0);
    glutWireSphere(0.095, p, p);
    glPopMatrix();
        //third planet
    glPushMatrix();
    glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
    glTranslatef (4.5, 0.0, 0.0);
    glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
    glColor3f(0, 0.0, 1.0);
    glutWireSphere(0.1, p, p);
        //moon
    glRotatef((GLfloat)day*0.8, 0.0, 1.0, 0.0);
    glTranslatef (0.5, 0.0, 0.0);
    glColor3f(0, 0.0, 1.0);
    glutWireSphere(0.08, p, p);
    glPopMatrix();
        //fourth planet
    glPushMatrix();
    glRotatef((GLfloat)day*0.8, 0.0, 1.0, 0.0);
    glTranslatef (5.5, 0.0, 0.0);
    glRotatef((GLfloat)day*0.8, 0.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 0.5);
    glutWireSphere(0.053, p, p);
    glPopMatrix();
        //fifth planet
    glPushMatrix();
    glRotatef((GLfloat)day*0.43, 0.0, 1.0, 0.0);
    glTranslatef (8.5, 0.0, 0.0);
    glRotatef((GLfloat)day*0.43, 0.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 1.0);
    glutWireSphere(1.097, p, p);
    glPopMatrix();
        //sixth planet
    glPushMatrix();
    glRotatef((GLfloat)day*0.32, 0.0, 1.0, 0.0);
    glTranslatef (12.5, 0.0, 0.0);
    glRotatef((GLfloat)day*0.32, 0.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 1.0);
    glutWireSphere(0.914, p, p);
    glPopMatrix();
        //seventh planet
    glPushMatrix();
    glRotatef((GLfloat)day*0.228, 0.0, 1.0, 0.0);
    glTranslatef (15, 0.0, 0.0);
    glRotatef((GLfloat)day*0.228, 0.0, 1.0, 0.0);
    glColor3f(0.2, 0.5, 0.0);
    glutWireSphere(0.398, p, p);
    glPopMatrix();
        //eighth planet
    glPushMatrix();
    glRotatef((GLfloat)day*0.182, 0.0, 1.0, 0.0);
    glTranslatef (17, 0.0, 0.0);
    glRotatef((GLfloat)day*0.182, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.128, 0.255);
    glutWireSphere(0.38, p, p);
    glPopMatrix();
    
    glFlush();
    glutSwapBuffers();
    glClearColor(0, 0, 0, 0);
}

void timer(int v) {
    glLoadIdentity();
    gluLookAt(0, rY, rY, 0, 0, 0, 0, 1, 0);
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, v);
}

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
}
void MouseFunc(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON) {
        p+=241;
        if (p>=256){
            p=256;
        }
    }
    if (button == GLUT_RIGHT_BUTTON){
        p-=200;
        if(p<=0){
            p = 15;
        }
    }
}

void keyboard(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        {
                rY += 1;
        }
    else if (key == GLUT_KEY_LEFT)
        {
                rY -= 1;
        }
    else if (key == GLUT_KEY_DOWN)
        {
                rX -= 10;
        }
    else if (key == GLUT_KEY_UP)
       {
                rX += 10;
        }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Solar System Praktika");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(MouseFunc);
    glutSpecialFunc(keyboard);
    glutTimerFunc(100, timer, 0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glutMainLoop();
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}
