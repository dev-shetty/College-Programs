#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

GLfloat v[8][3] = {
    {-200, -200, 200},  {200, -200, 200},  {200, 200, 200},  {-200, 200, 200},
    {-200, -200, -200}, {200, -200, -200}, {200, 200, -200}, {-200, 200, -200},
};

void init();
void display();
void spincube();
void drawcube(GLfloat *, GLfloat *, GLfloat *, GLfloat *);
void keys(unsigned char, int, int);

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500, 500, -500, 500, -500, 2000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRotatef(0.01, 1.0, 0.0, 1.0);
    glColor3f(0.6, 0.3, 0.5);
    drawcube(v[0], v[1], v[2], v[3]);
    glColor3f(0.1, 0.8, 0.3);
    drawcube(v[1], v[5], v[6], v[2]);
    glColor3f(0.8, 0.4, 0.2);
    drawcube(v[3], v[2], v[6], v[7]);
    glColor3f(0.7, 0.1, 0.5);
    drawcube(v[4], v[5], v[1], v[0]);
    glColor3f(0.2, 0.8, 0.9);
    drawcube(v[7], v[6], v[5], v[4]);
    glColor3f(0.5, 0.2, 0.3);
    drawcube(v[3], v[7], v[4], v[0]);
    glFlush();
}

void drawcube(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d) {
    glBegin(GL_POLYGON);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glVertex3fv(d);
    glEnd();
}

void keys(unsigned char k, int x, int y) {
    if (k == 's') glScalef(0.5, 0.5, 0.5);
    if (k == 'S') glScalef(1.5, 1.5, 1.5);
    if (k == 't') glTranslatef(-10, -10, -10);
    if (k == 'T') glTranslatef(10, 10, 10);
    glutPostRedisplay();
}

void spincube() { glutPostRedisplay(); }

void main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Spin the cube!");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glutIdleFunc(spincube);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
