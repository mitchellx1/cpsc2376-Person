#include "AmazeGame.h"

int main() {
    int level = 1;
    printRules();

    while (level <= 3) {
        AmazeGame game(level);
        playGame(game);

        if (level < 3) {
            cout << "Press any key to continue to the next level...\n";
            (void)_getch();
        }
        else {
            cout << "\nThanks for playing AMAZE!\n";
            cout << "Press any key to exit...\n";
            (void)_getch();
            break;
        }

        level++;
    }

    return 0;
}
