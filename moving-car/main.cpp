#include <GL/freeglut.h>
#include <cmath>

int carPositionX = 0; // Initial position of the car

void drawLine(int x1, int y1, int x2, int y2)
{
    glBegin(GL_LINES);
    glVertex2i(x1 + carPositionX, y1);
    glVertex2i(x2 + carPositionX, y2);
    glEnd();
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2i(x1 + carPositionX, y1);
    glVertex2i(x2 + carPositionX, y2);
    glVertex2i(x3 + carPositionX, y3);
    glEnd();
}

void drawRectangle(int x1, int y1, int x2, int y2, int r, int g, int b)
{
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex2i(x1 + carPositionX, y1);
    glVertex2i(x2 + carPositionX, y1);
    glVertex2i(x2 + carPositionX, y2);
    glVertex2i(x1 + carPositionX, y2);
    glEnd();
}

void rectangleNoMotion(int x1, int y1, int x2, int y2, int r, int g, int b)
{
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex2i(x1, y1);
    glVertex2i(x2, y1);
    glVertex2i(x2, y2);
    glVertex2i(x1, y2);
    glEnd();
}

void drawTrapezium(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int r, int g, int b)
{
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex2i(x1 + carPositionX, y1); // 100, 300
    glVertex2i(x2 + carPositionX, y2); // 300, 300
    glVertex2i(x3 + carPositionX, y3); // 250, 350
    glVertex2i(x4 + carPositionX, y4); // 150, 350
    glEnd();
}

void drawCircle(int x, int y, int radius, int r, int g, int b)
{
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(x + carPositionX + cos(degInRad) * radius, y + sin(degInRad) * radius);
    }
    glEnd();
}

void drawCar()
{
    drawTrapezium(100, 300, 300, 300, 250, 350, 150, 350, 1.0, 0.0, 0.0);
    drawTrapezium(100, 300, 300, 300, 250, 350, 150, 350, 1.0, 0.0, 0.0);
    drawTrapezium(110, 305, 290, 305, 245, 345, 155, 345, 0.0, 1.0, 0.0);
    drawTrapezium(120, 310, 200, 310, 200, 340, 160, 340, 1.0, 1.0, 1.0);
    drawTrapezium(200, 310, 200, 340, 235, 340, 280, 310, 0.0, 0.0, 0.0);

    drawCircle(210, 330, 5, 1, 1, 1);
    drawLine(210, 330, 210, 310);
    drawLine(210, 315, 230, 315);

    drawCircle(230, 315, 3, 0, 1, 0);
    drawLine(230, 315, 240, 310);

drawRectangle(50, 300, 350, 220, 0, 1, 0);
    drawRectangle(205, 260, 214, 250, 0, 0, 0);
    drawRectangle(130, 260, 138, 250, 1, 1, 1);

    drawRectangle(240, 300, 250, 290, 1, 1, 1);
    drawRectangle(242, 298, 248, 292, 1, 0, 1);
    drawRectangle(244, 296, 246, 294, 1, 1, 0);

    drawRectangle(199, 350, 201, 220, 1, 0, 0);

    drawRectangle(125, 300, 127, 220, 1, 1, 1);
    drawRectangle(125, 300, 275, 302, 1, 1, 1);
    drawRectangle(275, 300, 273, 220, 1, 1, 1);
    drawRectangle(125, 220, 273, 222, 1, 1, 1);

    drawCircle(100, 220, 25, 1, 0, 0);
    drawCircle(100, 220, 20, 0, 0, 0);
    drawCircle(100, 220, 15, 1, 1, 1);

    drawCircle(300, 220, 25, 1, 0, 0);
    drawCircle(300, 220, 20, 0, 0, 0);
    drawCircle(300, 220, 15, 1, 1, 1);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawCar();

    rectangleNoMotion(0, 195, 400, 190, 0, 0, 0);

    // glFlush();
    glutSwapBuffers();
}

void update(int value)
{
    carPositionX += 5;
    if (carPositionX > 400)
    {
        carPositionX = -10;
    }
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

// Function to set up the OpenGL environment
void init()
{
    glClearColor(1.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0); // Set the coordinate system
    glutTimerFunc(0, update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1500, 1000);
    glutCreateWindow("Simple Line Drawing");

    init();

    // Set the display function
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
