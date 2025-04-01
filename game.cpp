#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include "game.h"

extern int score;
extern bool gameOver;
extern bool gameStarted;

int gridX, gridY;
int snake_length = 5;
bool food = true;
int foodX, foodY;
short sDirection = RIGHT;

int posX[60] = {20, 20, 20, 20, 20}, posY[60] = {20, 19, 18, 17, 16};

void initGrid(int x, int y) {
    gridX = x;
    gridY = y;
}

void drawGrid() {
    // Left line
    glBegin(GL_QUADS);
        glColor3d(1, 0, 0);
        glVertex2d(0, 0);
        glColor3d(1, 0, 0);
        glVertex2d(1, 0);
        glColor3d(1, 0, 0);
        glVertex2d(1, 40);
        glColor3d(1, 0, 0);
        glVertex2d(0, 40);
    glEnd();

    // Right line
    glBegin(GL_QUADS);
        glColor3d(1, 0, 0);
        glVertex2d(39, 0);
        glColor3d(1, 0, 0);
        glVertex2d(40, 0);
        glColor3d(1, 0, 0);
        glVertex2d(40, 40);
        glColor3d(1, 0, 0);
        glVertex2d(39, 40);
    glEnd();

    // Top line
    glBegin(GL_QUADS);
        glColor3d(1, 0, 0);
        glVertex2d(0, 39);
        glColor3d(1, 0, 0);
        glVertex2d(40, 39);
        glColor3d(1, 0, 0);
        glVertex2d(40, 40);
        glColor3d(1, 0, 0);
        glVertex2d(0, 40);
    glEnd();

    // Bottom line
    glBegin(GL_QUADS);
        glColor3d(1, 0, 0);
        glVertex2d(0, 0);
        glColor3d(1, 0, 0);
        glVertex2d(40, 0);
        glColor3d(1, 0, 0);
        glVertex2d(40, 1);
        glColor3d(1, 0, 0);
        glVertex2d(0, 1);
    glEnd();
}

void drawFood() {
    if (food)
        random(foodX, foodY);
    food = false;
    glColor3f(1.0, 0.0, 1.0);
    glRectd(foodX, foodY, foodX + 1, foodY + 1);
}

void drawSnake() {
    for (int i = snake_length - 1; i > 0; i--) {
        posX[i] = posX[i - 1];
        posY[i] = posY[i - 1];
    }

    if (sDirection == UP)
        posY[0]++;
    else if (sDirection == DOWN)
        posY[0]--;
    else if (sDirection == RIGHT)
        posX[0]++;
    else if (sDirection == LEFT)
        posX[0]--;

    for (int i = 0; i < snake_length; i++) {
        if (i == 0) {
            glColor3f(1.0, 1.0, 1.0);
        } else {
            glColor3f(0.0, 1.0, 0.0);
        }
        glRectd(posX[i], posY[i], posX[i] + 1, posY[i] + 1);
    }

    if (posX[0] == 0 || posX[0] == gridX - 1 || posY[0] == 0 || posY[0] == gridY - 1)
        gameOver = true;

    if (posX[0] == foodX && posY[0] == foodY) {
        score++;
        snake_length++;
        if (snake_length > MAX) {
            snake_length = MAX;
        }
        food = true;
    }

    for (int j = 1; j < snake_length; j++) {
        if (posX[j] == posX[0] && posY[j] == posY[0])
            gameOver = true;
    }
}

void random(int &x, int &y) {
    int _maxX = gridX - 2;
    int _maxY = gridY - 2;
    int _min = 1;
    srand(time(NULL));
    x = _min + rand() % (_maxX - _min);
    y = _min + rand() % (_maxY - _min);
}

// Reset game to initial state - implementation only in game.cpp
void resetGame() {
    score = 0;
    snake_length = 5;
    food = true;
    sDirection = RIGHT;
    gameOver = false;
    gameStarted = false;

    // Reset snake position
    for (int i = 0; i < snake_length; i++) {
        posX[i] = 20 - i;
        posY[i] = 20;
    }
}
