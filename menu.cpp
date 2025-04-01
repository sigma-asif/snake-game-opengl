#include <GL/gl.h>
#include <GL/glut.h>
#include <string.h>
#include <stdio.h>
#include "menu.h"
#include "game.h"

// Menu state
int currentMenu = MENU_MAIN;
int selectedDifficulty = DIFFICULTY_MEDIUM;
extern int FPS;
extern bool gameStarted;

// Button dimensions
struct Button {
    float x1, y1, x2, y2;
    char text[50];
};

// Menu buttons
Button playButton = {15.0, 25.0, 25.0, 28.0, "PLAY"};
Button helpButton = {15.0, 20.0, 25.0, 23.0, "HELP"};
Button easyButton = {15.0, 25.0, 25.0, 28.0, "EASY"};
Button mediumButton = {15.0, 20.0, 25.0, 23.0, "MEDIUM"};
Button hardButton = {15.0, 15.0, 25.0, 18.0, "HARD"};
Button backButton = {15.0, 5.0, 25.0, 8.0, "BACK"};

// Function to draw text
void drawText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

// Function to draw a button
void drawButton(Button btn, bool selected) {
    if (selected) {
        glColor3f(0.0, 1.0, 0.0);  // Green for selected
    } else {
        glColor3f(0.5, 0.5, 0.5);  // Gray for unselected
    }

    // Draw button background
    glBegin(GL_QUADS);
    glVertex2f(btn.x1, btn.y1);
    glVertex2f(btn.x2, btn.y1);
    glVertex2f(btn.x2, btn.y2);
    glVertex2f(btn.x1, btn.y2);
    glEnd();

    // Draw button border
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(btn.x1, btn.y1);
    glVertex2f(btn.x2, btn.y1);
    glVertex2f(btn.x2, btn.y2);
    glVertex2f(btn.x1, btn.y2);
    glEnd();

    // Draw button text
    glColor3f(1.0, 1.0, 1.0);
    float textX = (btn.x1 + btn.x2) / 2.0 - strlen(btn.text) * 0.15;
    float textY = (btn.y1 + btn.y2) / 2.0 - 0.5;
    drawText(textX, textY, btn.text);
}

// Initialize the menu
void initMenu() {
    currentMenu = MENU_MAIN;
    gameStarted = false;
}

// Draw the main menu
void drawMainMenu() {
    // Draw title
    glColor3f(1.0, 1.0, 0.0);
    drawText(16.0, 32.0, "SNAKE GAME");

    // Draw buttons
    drawButton(playButton, false);
    drawButton(helpButton, false);
}

// Draw the play menu with difficulty options
void drawPlayMenu() {
    // Draw title
    glColor3f(1.0, 1.0, 0.0);
    drawText(12.0, 32.0, "SELECT DIFFICULTY");

    // Draw buttons
    bool easySelected = (selectedDifficulty == DIFFICULTY_EASY);
    bool mediumSelected = (selectedDifficulty == DIFFICULTY_MEDIUM);
    bool hardSelected = (selectedDifficulty == DIFFICULTY_HARD);

    drawButton(easyButton, easySelected);
    drawButton(mediumButton, mediumSelected);
    drawButton(hardButton, hardSelected);
    drawButton(backButton, false);
}


// Draw the help menu
void drawHelpMenu() {
    // Draw title
    glColor3f(1.0, 1.0, 0.0);
    drawText(17.0, 32.0, "HELP");

    // Draw help text
    glColor3f(1.0, 1.0, 1.0);
    drawText(5.0, 25.0, "Use arrow keys to control the snake");
    drawText(5.0, 22.0, "Eat food to grow and increase score");
    drawText(5.0, 19.0, "Don't hit the walls or yourself!");
    drawText(5.0, 16.0, "Easy: Slow snake speed - for beginners");
    drawText(5.0, 14.0, "Medium: Normal snake speed");
    drawText(5.0, 12.0, "Hard: Fast snake speed - for experts");

    // Draw back button
    drawButton(backButton, false);
}

// Draw the current menu
void drawMenu() {
    switch(currentMenu) {
        case MENU_MAIN:
            drawMainMenu();
            break;
        case MENU_PLAY:
            drawPlayMenu();
            break;
        case MENU_HELP:
            drawHelpMenu();
            break;
    }
}

// Check if a point is inside a button
bool isInsideButton(int x, int y, Button btn) {
    // Convert window coordinates to game coordinates
    float gameX = x * 40.0 / glutGet(GLUT_WINDOW_WIDTH);
    float gameY = 40.0 - (y * 40.0 / glutGet(GLUT_WINDOW_HEIGHT));

    return (gameX >= btn.x1 && gameX <= btn.x2 &&
            gameY >= btn.y1 && gameY <= btn.y2);
}

// Start the game with the selected difficulty
void startGame(int difficulty) {
    FPS = difficulty;
    gameStarted = true;
    selectedDifficulty = difficulty;
}

// Return to the main menu
void returnToMainMenu() {
    currentMenu = MENU_MAIN;
}

// Mouse callback function
void mouseCallback(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        switch(currentMenu) {
            case MENU_MAIN:
                if (isInsideButton(x, y, playButton)) {
                    currentMenu = MENU_PLAY;
                } else if (isInsideButton(x, y, helpButton)) {
                    currentMenu = MENU_HELP;
                }
                break;

            case MENU_PLAY:
                if (isInsideButton(x, y, easyButton)) {
                    startGame(DIFFICULTY_EASY);
                } else if (isInsideButton(x, y, mediumButton)) {
                    startGame(DIFFICULTY_MEDIUM);
                } else if (isInsideButton(x, y, hardButton)) {
                    startGame(DIFFICULTY_HARD);
                } else if (isInsideButton(x, y, backButton)) {
                    returnToMainMenu();
                }
                break;

            case MENU_HELP:
                if (isInsideButton(x, y, backButton)) {
                    returnToMainMenu();
                }
                break;
        }
    }
}
