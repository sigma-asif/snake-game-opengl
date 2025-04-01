#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define MENU_MAIN 0
#define MENU_PLAY 1
#define MENU_HELP 2

// Difficulty levels - lower FPS means slower/easier game
#define DIFFICULTY_EASY 5    // Slow speed for easy mode
#define DIFFICULTY_MEDIUM 10 // Medium speed
#define DIFFICULTY_HARD 20   // Fast speed for hard mode

void drawMenu();
void mouseCallback(int, int, int, int);
void initMenu();
void startGame(int difficulty);
void showHelp();
void returnToMainMenu();

#endif // MENU_H_INCLUDED
