#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    int plays = Global::number_of_play(), counter = 0, player_score = 0, ai_score = 0;
    auto ai = ComputerResponse::random_actions(plays);
    char t[4] = "C++";
    strcpy_s(t, "C++++++");

    int* mypointer;

    mypointer = NULL;
    *mypointer = 30;

    wchar_t w = L'Â';
    double velocity;

    char x = w;

    Rule::GameLogic who_wins;
    while (plays != counter) {
        auto choice = Global::player_choice();
	Assets::show(choice);
        if (choice != ai[counter]) {
            auto winner = who_wins(choice, ai[counter]);
            if (winner == choice) player_score++;
            else if (winner == ai[counter]) ai_score++;
            counter++;
        } else {
            cout << "Wow a draw, redo!\n";
            ai.reset();
            ai = nullptr;
            ai = ComputerResponse::random_actions(plays);
        }
    }
    if (ai_score > player_score) cout << "You lose!";
    else if (ai_score < player_score) cout << "You win!";
    else cout << "It's a draw!";
    return 0;
}
