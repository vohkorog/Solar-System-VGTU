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
double p = true;

GLfloat pos0[] = { 1.0, 1.0, 0.0, 0.0 };
GLfloat ambientColor0[] = { 0.1, 0.1, 0.1, 0.0 };
GLfloat diffuseColor0[] = { 0.8, 0.8, 0.8, 0.0 };


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseColor0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, pos0);
    glColorMaterial(GL_FRONT, GL_AMBIENT);
    day += 1;
        if (day > std::numeric_limits<unsigned int>::max()) {
            day = 0;
        }
    glRotatef( rX, 1.0, 0.0, 0.0 );
        //sun
    glPushMatrix();
    glRotatef((GLfloat)day*0.09, 0.0, 1.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    if(p == true){
    glutWireSphere(2, 15, 15);
    }
    if(p == false){
    glutSolidSphere(2, 100, 100);
    }
    glPopMatrix();
        //first planet
    glPushMatrix();
    glRotatef((GLfloat)day*1.6, 0.0, 1.0, 0.0);
    glTranslatef (2.5, 0.0, 0.0);
    glRotatef((GLfloat)day*1.6, 0.0, 1.0, 0.0);
    glColor3f(1, 0, 0);
    if(p == true){
    glutWireSphere(0.038, 15, 15);
    }
    if(p == false){
    glutSolidSphere(0.038, 100, 100);
    }
    glPopMatrix();
        //second planet
    glPushMatrix();
    glRotatef((GLfloat)day * 1.17, 0.0, 1.0, 0.0);
    glTranslatef (3.5, 0.0, 0.0);
    glRotatef((GLfloat)day * 1.17, 0.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 0);
    if(p == true){
    glutWireSphere(0.095, 15, 15);
    }
    if(p == false){
    glutSolidSphere(0.095, 100, 100);
    }
    glPopMatrix();
        //third planet
    glPushMatrix();
    glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
    glTranslatef (4.5, 0.0, 0.0);
    glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
    glColor3f(0, 0.0, 1.0);
    if(p == true){
    glutWireSphere(0.1, 15, 15);
    }
    if(p == false){
    glutSolidSphere(0.1, 100, 100);
    }
    //moon
    glRotatef((GLfloat)day*0.8, 0.0, 1.0, 0.0);
    glTranslatef (0.5, 0.0, 0.0);
    glColor3f(0, 0.0, 1.0);
    if(p == true){
    glutWireSphere(0.1, 15, 15);
    }
    if(p == false){
    glutSolidSphere(0.1, 100, 100);
    }
    glPopMatrix();
        //fourth planet
    glPushMatrix();
    glRotatef((GLfloat)day*0.8, 0.0, 1.0, 0.0);
    glTranslatef (5.5, 0.0, 0.0);
    glRotatef((GLfloat)day*0.8, 0.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 0.5);
    if(p == true){
    glutWireSphere(0.053, 15, 15);
    }
    if(p == false){
    glutSolidSphere(0.053, 100, 100);
    }
    glPopMatrix();
        //fifth planet
    glPushMatrix();
    glRotatef((GLfloat)day*0.43, 0.0, 1.0, 0.0);
    glTranslatef (8.5, 0.0, 0.0);
    glRotatef((GLfloat)day*0.43, 0.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 1.0);
    if(p == true){
    glutWireSphere(1.097, 15, 15);
    }
    if(p == false){
    glutSolidSphere(1.097, 100, 100);
    }
    glPopMatrix();
        //sixth planet
    glPushMatrix();
    glRotatef((GLfloat)day*0.32, 0.0, 1.0, 0.0);
    glTranslatef (12.5, 0.0, 0.0);
    glRotatef((GLfloat)day*0.32, 0.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 1.0);
    if(p == true){
    glutWireSphere(0.914, 15, 15);
    }
    if(p == false){
    glutSolidSphere(0.914, 100, 100);
    }
    glPopMatrix();
        //seventh planet
    glPushMatrix();
    glRotatef((GLfloat)day*0.228, 0.0, 1.0, 0.0);
    glTranslatef (15, 0.0, 0.0);
    glRotatef((GLfloat)day*0.228, 0.0, 1.0, 0.0);
    glColor3f(0.2, 0.5, 0.0);
    if(p == true){
    glutWireSphere(0.398, 15, 15);
    }
    if(p == false){
    glutSolidSphere(0.398, 100, 100);
    }
    glPopMatrix();
        //eighth planet
    glPushMatrix();
    glRotatef((GLfloat)day*0.182, 0.0, 1.0, 0.0);
    glTranslatef (17, 0.0, 0.0);
    glRotatef((GLfloat)day*0.182, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.128, 0.255);
    if(p == true){
    glutWireSphere(0.38, 15, 15);
    }
    if(p == false){
    glutSolidSphere(0.38, 100, 100);
    }
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
        p=true;
        
    }
    if (button == GLUT_RIGHT_BUTTON){
        p=false;
        
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
