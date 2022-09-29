#ifndef GAME_H
#define GAME_H

#include <memory>

namespace Rule {

    enum class Choice {	ROCK, PAPER, SCISSORS, NONE };

    class GameLogic {
        public:
            Choice operator()(const Choice lhs, const Choice rhs);
    };
}

namespace Global {

    Rule::Choice player_choice();

    int number_of_play();

    Rule::Choice mapping_choice(int choice);
}

namespace ComputerResponse {

    std::unique_ptr<Rule::Choice[]> random_actions(size_t number_games_tobe_played);

}

namespace Assets {

    void show(const Rule::Choice choice);

    void fist();

    void open_hands();

    void middle_finger();

}

#endif // GAME_H
