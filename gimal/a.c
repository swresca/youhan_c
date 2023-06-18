#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#define WIDTH 20
#define HEIGHT 30
#define PADDLE_SIZE 9
#define BLOCK_WIDTH 10
#define BLOCK_HEIGHT 20

char screen[HEIGHT][WIDTH];
int paddleX;
int ballX, ballY;
int ballXDir, ballYDir;
int gameStart = 0;
int gameExit = 0;
int blocks[BLOCK_HEIGHT][BLOCK_WIDTH];

void moveCursorTo(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void initBlocks() {
    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            blocks[i][j] = 1;
        }
    }
}

void drawBall() {
    screen[ballY][ballX] = 'O';
}

void drawBlocks() {
    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            if (blocks[i][j] == 1) {
                screen[i][j] = '#';
            } else {
                screen[i][j] = ' ';
            }
        }
    }
}

void drawPaddle() {
    for (int i = HEIGHT - 2; i < HEIGHT - 1; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j >= paddleX && j < paddleX + PADDLE_SIZE) {
                screen[i][j] = '=';
            } else {
                screen[i][j] = ' ';
            }
        }
    }
}

void drawWalls() {
    for (int i = 0; i < HEIGHT; i++) {
        screen[i][0] = '|';
        screen[i][WIDTH - 1] = '|';
    }
}

void drawScreen() {
    moveCursorTo(0, 0);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void initGame() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }

    paddleX = (WIDTH - PADDLE_SIZE) / 2;

    ballX = paddleX + PADDLE_SIZE / 2;
    ballY = HEIGHT - 2;
    ballXDir = 1;
    ballYDir = -1;

    initBlocks();

    drawPaddle();
    drawBall();
    drawWalls();
    drawBlocks();
    drawScreen();
}

void playGame() {
    int remainingBlocks = BLOCK_HEIGHT * BLOCK_WIDTH;

    while (!gameExit) {
        if (gameStart) {
            if (_kbhit()) {
                char key = _getch();
                if (key == 'a' && paddleX > 0) {
                    paddleX--;
                } else if (key == 'd' && paddleX < WIDTH - PADDLE_SIZE) {
                    paddleX++;
                }
            }

            drawPaddle();

            screen[ballY][ballX] = ' ';

            ballX += ballXDir;
            ballY += ballYDir;

            if (ballX == 0 || ballX == WIDTH - 1) {
                ballXDir = -ballXDir;
            }

            if (ballY == HEIGHT - 2 && ballX >= paddleX && ballX < paddleX + PADDLE_SIZE) {
                ballYDir = -ballYDir;
            }

            if (ballY < BLOCK_HEIGHT && ballX >= 0 && ballX < BLOCK_WIDTH && blocks[ballY][ballX] == 1) {
                ballYDir = -ballYDir;
                blocks[ballY][ballX] = 0;
                remainingBlocks--;

                if (remainingBlocks == 0) {
                    gameStart = 0;
                    printf("Congratulations! You cleared all the blocks!\n");
                    printf("Press any key to go back to the main screen.\n");
                    _getch();
                }
            }

            if (ballY == 0) {
                ballYDir = -ballYDir;
            }

            if (ballY == HEIGHT - 1) {
                gameStart = 0;
                printf("Game Over!\n");
                printf("Press any key to go back to the main screen.\n");
                _getch();
            }

            drawBall();
            drawScreen();
            Sleep(50);
        } else {
            system("cls");
            printf("Welcome to Block Breaker!\n");
            printf("1. Start Game\n");
            printf("2. How to Play\n");
            printf("3. Exit\n");

            char key = _getch();
            if (key == '1') {
                gameStart = 1;
                initGame();
            } else if (key == '2') {
                printf("Instructions:\n");
                printf("Use 'a' and 'd' to move the paddle.\n");
                printf("Try to prevent the ball from touching the bottom of the screen.\n");
                printf("Press any key to go back to the main screen.\n");
                _getch();
            } else if (key == '3') {
                gameExit = 1;
            }
        }
    }
}

int main() {
    playGame();
    return 0;
}
