#include <GL/glut.h>
#include <stdlib.h>

#define AZUL 1
#define VERMELHO 2
#define BTN_ESC 27
#define BTN_A 97
#define BTN_V 118
#define TAMANHO 256
#define P1 30
#define P2 226

int cor = VERMELHO;

void inicializar(void);
void exibir(void);
void eventosTeclado(unsigned char tecla, int x, int y);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(TAMANHO, TAMANHO);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Quadrado");
    inicializar();
    glutDisplayFunc(exibir);
    glutKeyboardFunc(eventosTeclado);
    glutMainLoop();
    return 0;
}

void inicializar(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, 256, 0, 256, -1, 1);
    cor = VERMELHO;
}

void setColor()
{
    switch (cor)
    {
    case AZUL:
        glColor3f(0, 0, 1);
        break;
    case VERMELHO:
        glColor3f(1, 0, 0);
        break;
    default:
        glColor3f(1, 0, 0);
        break;
    }
}

void exibir(void)
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_POLYGON_STIPPLE);
    glPolygonMode(GL_BACK, GL_FILL);
    setColor();
    glBegin(GL_POLYGON);
    glVertex2i(P1, P2);
    glVertex2i(P2, P2);
    glVertex2i(P2, P1);
    glVertex2i(P1, P1);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void eventosTeclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case BTN_ESC:
        exit(0);
        break;
    case BTN_A:
        cor = AZUL;
        glutPostRedisplay();
        break;
    case BTN_V:
        cor = VERMELHO;
        glutPostRedisplay();
        break;
    }
}