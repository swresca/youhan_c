#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int clearBuffer(char* screenBuf, int width, int height);
int writeStringToBuffer(char* screenBuf, const char* string, int x, int y);

int main() {
    int width = 30;
    int height = 30;
    char* screenBuf = (char*)malloc(width * height * sizeof(char));

    // 초기 화면 그리기
    clearBuffer(screenBuf, width, height);

    // 화면 출력 함수
    void printScreen() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                printf("%c", screenBuf[y * width + x]);
            }
            printf("\n");
        }
    }

    // 상자 그리기 함수
    void drawBox() {
        for (int i = 0; i < width; i++) {
            writeStringToBuffer(screenBuf, "#", i, 0);
            writeStringToBuffer(screenBuf, "#", i, height - 1);
        }
        for (int i = 0; i < height; i++) {
            writeStringToBuffer(screenBuf, "#", 0, i);
            writeStringToBuffer(screenBuf, "#", width - 1, i);
        }
    }

    // 초기 화면 출력
    drawBox();
    printScreen();

    // 문자열 입력
    const char* inputString = "Raising a soccer player";
    int stringLength = strlen(inputString);
    int startX = (width - stringLength) / 2; // 중앙에 배치
    int startY = height / 2 - 1; // 문자열 위에 선택지 표시
    writeStringToBuffer(screenBuf, inputString, startX, startY);

    // 선택지 작성
    writeStringToBuffer(screenBuf, "1. Start Game", 10, startY + 3);
    writeStringToBuffer(screenBuf, "2. How to Play", 10, startY + 4);
    writeStringToBuffer(screenBuf, "3. Exit", 10, startY + 5);

    // 선택 후 화면 출력
    printScreen();

    // 메뉴 선택 및 동작 수행
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // 선택 후 화면 초기화
    clearBuffer(screenBuf, width, height);
    // 상자 그리기
    drawBox();

    // 선택한 문구
    const char* message;
    if (choice == 1) {
        message = "Starting the game...";
    } else if (choice == 2) {
        message = "How to play the game...";
    } else if (choice == 3) {
        message = "Exiting the game...";
    } else {
        message = "Invalid choice. Exiting the game...";
    }

    // 문구 가운데로 정렬
    int messageLength = strlen(message);
    int messageStartX = (width - messageLength) / 2;
    int messageStartY = height / 2;

    // 문구 입력
    writeStringToBuffer(screenBuf, message, messageStartX, messageStartY);

    // 선택 후 화면 출력
    printScreen();

    free(screenBuf);
    return 0;
}

int clearBuffer(char* screenBuf, int width, int height) {
    memset(screenBuf, ' ', width * height * sizeof(char));
    return 0;
}

int writeStringToBuffer(char* screenBuf, const char* string, int x, int y) {
    int stringLength = strlen(string);
    int startX = x;
    int startY = y;
    int width = 30;

    for (int i = 0; i < stringLength; i++) {
        screenBuf[startY * width + startX] = string[i];
        startX++;
    }

    return 0;
}
