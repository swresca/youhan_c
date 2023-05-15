#include <stdio.h>

int main() {
    int choice = 0;

    char titleScreen[11][51] = {
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

    while (getchar() != '\n');  // 버퍼 비우기

    if (choice == 1) {
        // Start Game
        printf("Starting the game...\n");
        // 게임 시작에 필요한 코드를 추가하세요.
    } else if (choice == 2) {
        // How to Play
        printf("How to Play:\n");
        printf("1. Control the player using the arrow keys.\n");
        printf("2. Score goals by shooting the ball into the opponent's net.\n");
        printf("3. Avoid getting scored on by blocking the opponent's shots.\n");
        printf("4. The team with the most goals at the end wins.\n");
    } else if (choice == 3) {
        // Exit
        printf("Exiting the game...\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}
