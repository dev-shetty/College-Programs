#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

void init();
void bresenhams(int, int, int, int);
void display();
void plotline(int, int);

int x1, y11, x2, y2;

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    printf("Enter the dimensions: ");
    scanf("%d%d%d%d", &x1, &y11, &x2, &y2);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    bresenhams(x1, y11, x2, y2);
    glFlush();
}

void plotline(int x, int y) {
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void bresenhams(int x1, int y1, int x2, int y2) {
    int dx, dy, x, y, xinc, yinc, pk;
    dx = x2 - x1;
    dy = y2 - y1;
    x = x1, y = y1;
    plotline(x, y);
    xinc = dx > 0 ? 1 : -1;
    yinc = dy > 0 ? 1 : -1;
    if (fabs(dy) > fabs(dx)) {
        pk = 2 * fabs(dx) - fabs(dy);
        for (int i = 0; i < fabs(dy); i++) {
            if (pk > 0) {
                pk += 2 * fabs(dx) - fabs(dy);
                x += xinc;
            } else {
                pk += 2 * fabs(dx);
            }
            y += yinc;
            plotline(x, y);
        }
    } else {
        pk = 2 * fabs(dy) - fabs(dx);
        for (int i = 0; i < fabs(dx); i++) {
            if (pk > 0) {
                pk += 2 * fabs(dy) - fabs(dx);
                y += yinc;
            } else {
                pk += 2 * fabs(dy);
            }
            x += xinc;
            plotline(x, y);
        }
    }
}