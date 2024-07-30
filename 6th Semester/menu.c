#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

void init();
void display();
void menu(int);

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-100, -100);
    glVertex2f(0, 200);
    glVertex2f(100, -100);
    glVertex2f(-100, 100);
    glVertex2f(0, -200);
    glVertex2f(100, 100);
    glEnd();
    glFlush();
}

void menu(int id) {
    if (id == 1) glTranslatef(0, 10, 0);
    if (id == 2) glTranslatef(0, -10, 0);
    if (id == 3) glTranslatef(-10, 0, 0);
    if (id == 4) glTranslatef(10, 0, 0);
    if (id == 5) glRotatef(-15, 0, 0, 1);
    if (id == 6) glRotatef(15, 0, 0, 1);
    if (id == 7) glScalef(1.5, 1.5, 1);
    if (id == 8) glScalef(0.5, 0.5, 1);
    glutPostRedisplay();
}

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Move it!");
    init();
    glutDisplayFunc(display);
    int translate = glutCreateMenu(menu);
    glutAddMenuEntry("Up", 1);
    glutAddMenuEntry("Down", 2);
    glutAddMenuEntry("Left", 3);
    glutAddMenuEntry("Right", 4);
    int rotate = glutCreateMenu(menu);
    glutAddMenuEntry("Clockwise", 5);
    glutAddMenuEntry("Anti-clockwise", 6);
    int scale = glutCreateMenu(menu);
    glutAddMenuEntry("Maximize", 7);
    glutAddMenuEntry("Minimize", 8);
    glutCreateMenu(menu);
    glutAddSubMenu("Translate", translate);
    glutAddSubMenu("Rotate", rotate);
    glutAddSubMenu("Scale", scale);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}
