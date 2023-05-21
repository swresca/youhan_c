#include <stdio.h>

int main() {
    int choice = 0;

    const char* titleScreen[] = {
        "###############################################",
        "##                                           ##",
        "##       fostering of soccer players         ##",
        "##                   V.0.1                   ##",
        "##                                           ##",
        "##  1. Start Game                            ##",
        "##  2. How to Play                           ##",
        "##  3. Exit                                  ##",
        "##                                           ##",
        "###############################################"
    };

    for (int i = 0; i < 11; i++) {
        printf("%s\n", titleScreen[i]);
    }

    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Consume the remaining characters in the input buffer including the newline character
    while (getchar() != '\n');

    if (choice == 1) {
        // Start Game
        const char* startGameScreen[] = {
            "###############################################",
            "##                                           ##",
            "##                                           ##",
            "##                                           ##",
            "##                                           ##",
            "##           Starting the game...            ##",
            "##                                           ##",
            "###############################################"
        };

        for (int i = 0; i < 8; i++) {
            printf("%s\n", startGameScreen[i]);
        }

        // Add the necessary code for starting the game here
    } else if (choice == 2) {
        // How to Play
        const char* howToPlayScreen[] = {
            "###################################################",
            "##                   How to play                  ##",
            "## 1. 축구선수가 아기때부터 최고의 선수가 될때    ##",
            "##    까지 키운다                                 ##",
            "## 2. 배가 고프면 1번을 누르면 된다               ##",
            "## 3. 훈련을 하려면 2번을 누르면 된다             ##",
            "## 4. 어떤 식으로 키우는지 에 따라 앤딩이 결정된다##",
            "##                                                ##",
            "####################################################"
        };

        for (int i = 0; i < 9; i++) {
            printf("%s\n", howToPlayScreen[i]);
        }
    } else if (choice == 3) {
        const char* exitScreen[] = {
            "###############################################",
            "##                                           ##",
            "##                                           ##",
            "##             Exiting the game...           ##",
            "##                                           ##",
            "##                                           ##",
            "##                                           ##",
            "###############################################"
        };

        for (int i = 0; i < 8; i++) {
            printf("%s\n", exitScreen[i]);
        }
    } else {
        printf("\nInvalid choice. Please try again.\n");
    }

    return 0;
}
