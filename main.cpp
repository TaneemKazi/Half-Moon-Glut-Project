#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

void init (void)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20,20,-20,20);
}

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)
{
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i<=100; i++)
    {
        float angle = 2*3.1416*i/100;
        float x = rx*cosf(angle);
        float y=ry*sinf(angle);
        glVertex2f(x+cx,y+cy);

    }
    glEnd();
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    circle(8,8,1,1);
    glColor3f(1.0,1.0,1.0);
    circle(8,8,4,4);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (200,200);
    glutCreateWindow ("Half Moon");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
