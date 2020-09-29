/*
Integrantes:
- Henrique Canterle Fava
- Kelvin Pereira Alves
- Renato dos Santos Machado Júnior
- Wesley Arthur Batista

2. Utilizando o programa preenchimento.c como referência, implemente um programa selecao.c. Este
programa deverá desenhar numa janela com fundo branco, de dimensões 256x256 pixels, quatro polígonos
com as mesmas coordenadas dos polígonos do programa de referência. Todos os polígonos devem estar
inicialmente preenchidos de amarelo e com bordas pretas. Quando o usuário clicar com o botão esquerdo do
mouse dentro de um dos polígonos, a cor de preenchimento deste polígono deverá mudar para uma cor
aleatória. Quando a tecla b (keycode=98) for pressionada, o programa passará a mudar as cores das bordas e
não mais dos fundos dos polígonos. Quando a tecla f (keycode=102) for pressionada, o programa passará a
mudar as cores dos fundos dos polígonos e não mais das bordas.
*/

#include <GL/glut.h>
#include <stdlib.h>

#define QUADRADO_INFERIOR_DIREITO 2
#define QUADRADO_INFERIOR_ESQUERDO 3
#define QUADRADO_SUPERIOR_DIREITO 0
#define QUADRADO_SUPERIOR_ESQUERDO 1

#define AZUL 2
#define VERDE 1
#define VERMELHO 0

#define BORDA 1
#define FUNDO 2

#define BTN_B 98
#define BTN_ESC 27
#define BTN_F 102

GLfloat corDeFundo[4][3] = {
    {1, 1, 0},
    {1, 1, 0},
    {1, 1, 0},
    {1, 1, 0}};

GLfloat corDaBorda[4][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
};

int tipoDeMudanca = FUNDO;

void atualizarCorDoElemento(int elemento);
void definirQuadradoInferiorDireito(void);
void definirQuadradoInferiorEsquerdo(void);
void definirQuadradoSuperiorDireito(void);
void definirQuadradoSuperiorEsquerdo(void);
void eventosDoMouse(int botao, int estado, int x, int y);
void eventosDoTeclado(unsigned char tecla, int x, int y);
void exibir(void);
void inicializar(void);

void atualizarCorDoElemento(int elemento)
{
    if (tipoDeMudanca == FUNDO)
    {
        corDeFundo[elemento][VERMELHO] = (GLfloat)rand() / (RAND_MAX + 1.0);
        corDeFundo[elemento][VERDE] = (GLfloat)rand() / (RAND_MAX + 1.0);
        corDeFundo[elemento][AZUL] = (GLfloat)rand() / (RAND_MAX + 1.0);
    }

    if (tipoDeMudanca == BORDA)
    {
        corDaBorda[elemento][VERMELHO] = (GLfloat)rand() / (RAND_MAX + 1.0);
        corDaBorda[elemento][VERDE] = (GLfloat)rand() / (RAND_MAX + 1.0);
        corDaBorda[elemento][AZUL] = (GLfloat)rand() / (RAND_MAX + 1.0);
    }
}

void definirQuadradoInferiorDireito()
{
    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(corDaBorda[QUADRADO_INFERIOR_DIREITO][VERMELHO], corDaBorda[QUADRADO_INFERIOR_DIREITO][VERDE], corDaBorda[QUADRADO_INFERIOR_DIREITO][AZUL]);

    glBegin(GL_POLYGON);
    glVertex2i(137, 119);
    glVertex2i(232, 119);
    glVertex2i(232, 24);
    glVertex2i(137, 24);
    glEnd();

    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(corDeFundo[QUADRADO_INFERIOR_DIREITO][VERMELHO], corDeFundo[QUADRADO_INFERIOR_DIREITO][VERDE], corDeFundo[QUADRADO_INFERIOR_DIREITO][AZUL]);

    glBegin(GL_POLYGON);
    glVertex2i(143, 113);
    glVertex2i(226, 113);
    glVertex2i(226, 30);
    glVertex2i(143, 30);
    glEnd();
}

void definirQuadradoInferiorEsquerdo()
{
    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(corDaBorda[QUADRADO_INFERIOR_ESQUERDO][VERMELHO], corDaBorda[QUADRADO_INFERIOR_ESQUERDO][VERDE], corDaBorda[QUADRADO_INFERIOR_ESQUERDO][AZUL]);

    glBegin(GL_POLYGON);
    glVertex2i(24, 119);
    glVertex2i(119, 119);
    glVertex2i(119, 24);
    glVertex2i(24, 24);
    glEnd();

    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(corDeFundo[QUADRADO_INFERIOR_ESQUERDO][VERMELHO], corDeFundo[QUADRADO_INFERIOR_ESQUERDO][VERDE], corDeFundo[QUADRADO_INFERIOR_ESQUERDO][AZUL]);

    glBegin(GL_POLYGON);
    glVertex2i(30, 113);
    glVertex2i(113, 113);
    glVertex2i(113, 30);
    glVertex2i(30, 30);
    glEnd();
}

void definirQuadradoSuperiorDireito()
{
    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(corDaBorda[QUADRADO_SUPERIOR_DIREITO][VERMELHO], corDaBorda[QUADRADO_SUPERIOR_DIREITO][VERDE], corDaBorda[QUADRADO_SUPERIOR_DIREITO][AZUL]);

    glBegin(GL_POLYGON);
    glVertex2i(137, 232);
    glVertex2i(232, 232);
    glVertex2i(232, 137);
    glVertex2i(137, 137);
    glEnd();

    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(corDeFundo[QUADRADO_SUPERIOR_DIREITO][VERMELHO], corDeFundo[QUADRADO_SUPERIOR_DIREITO][VERDE], corDeFundo[QUADRADO_SUPERIOR_DIREITO][AZUL]);

    glBegin(GL_POLYGON);
    glVertex2i(143, 226);
    glVertex2i(226, 226);
    glVertex2i(226, 143);
    glVertex2i(143, 143);
    glEnd();
}

void definirQuadradoSuperiorEsquerdo()
{
    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(corDaBorda[QUADRADO_SUPERIOR_ESQUERDO][VERMELHO], corDaBorda[QUADRADO_SUPERIOR_ESQUERDO][VERDE], corDaBorda[QUADRADO_SUPERIOR_ESQUERDO][AZUL]);

    glBegin(GL_POLYGON);
    glVertex2i(24, 232);
    glVertex2i(119, 232);
    glVertex2i(119, 137);
    glVertex2i(24, 137);
    glEnd();

    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(corDeFundo[QUADRADO_SUPERIOR_ESQUERDO][VERMELHO], corDeFundo[QUADRADO_SUPERIOR_ESQUERDO][VERDE], corDeFundo[QUADRADO_SUPERIOR_ESQUERDO][AZUL]);

    glBegin(GL_POLYGON);
    glVertex2i(30, 226);
    glVertex2i(113, 226);
    glVertex2i(113, 143);
    glVertex2i(30, 143);
    glEnd();
}

void eventosDoMouse(int botao, int estado, int x, int y)
{
    switch (botao)
    {
    case GLUT_LEFT_BUTTON:
        if (estado == GLUT_DOWN)
        {
            if ((x >= 30 && x <= 113) && (y >= 143 && y <= 226))
            {
                atualizarCorDoElemento(QUADRADO_INFERIOR_ESQUERDO);
            }
            else if ((x >= 143 && x <= 226) && (y >= 30 && y <= 113))
            {
                atualizarCorDoElemento(QUADRADO_SUPERIOR_DIREITO);
            }
            else if ((x >= 143 && x <= 226) && (y >= 143 && y <= 226))
            {
                atualizarCorDoElemento(QUADRADO_INFERIOR_DIREITO);
            }
            else if ((x >= 30 && x <= 113) && (y >= 30 && y <= 113))
            {
                atualizarCorDoElemento(QUADRADO_SUPERIOR_ESQUERDO);
            }

            glutPostRedisplay();
        }
        break;
    }
}

void eventosDoTeclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case BTN_ESC:
        exit(0);
        break;
    case BTN_B:
        tipoDeMudanca = BORDA;
        break;

    case BTN_F:
        tipoDeMudanca = FUNDO;
        break;
    }
}

void exibir(void)
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_POLYGON_STIPPLE);
    definirQuadradoSuperiorEsquerdo();
    definirQuadradoSuperiorDireito();
    definirQuadradoInferiorEsquerdo();
    definirQuadradoInferiorDireito();
    glFlush();
    glutSwapBuffers();
}

void inicializar(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, 256, 0, 256, -1, 1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Quadradados");
    inicializar();
    glutDisplayFunc(exibir);
    glutKeyboardFunc(eventosDoTeclado);
    glutMouseFunc(eventosDoMouse);
    glutMainLoop();
    return 0;
}
