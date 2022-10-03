#include "game.h"

#include <ctime>
#include <iostream>
#include <map>
#include <regex>
#include <stdexcept>
#include <tuple>
#include <memory>

Rule::Choice Global::mapping_choice(int choice) {
    std::map<int, Rule::Choice> table = {
        {1, Rule::Choice::PAPER},
        {2, Rule::Choice::ROCK},
        {3, Rule::Choice::SCISSORS}
    };
    return table[choice];
}

Rule::Choice Global::player_choice() {
    std::string str;
    std::regex pattern("[123]");

    do {
    std::cout << "Input 1 for paper \n";
    std::cout << "Input 2 for rock \n";
    std::cout << "Input 3 for scissors \n";
    std::cin >> str;
    } while(!std::regex_match(str, pattern));

    return mapping_choice(stoi(str));
}

int Global::number_of_play() {
    std::cout << "Remember the rules \n";

    std::cout << "paper beats (wraps) rock" << '\n';
    std::cout << "rock beats (blunts) scissors" << '\n';
    std::cout << "scissors beats (cuts) paper" << '\n';
    std::regex pattern("[123]");
    std::string str;

    do {
    std::cout << "Please enter the number of play you want (1-3): \n";
    std::cin >> str;
    } while(!std::regex_match(str, pattern));
    return stoi(str);
}

Rule::Choice Rule::GameLogic::operator()(const Rule::Choice lhs, const Rule::Choice rhs) {
    // Not handling error for same symbol in rule
    if (lhs == rhs) throw std::domain_error("Do not handle same choice of symbol");

    std::map<std::tuple<Rule::Choice, Rule::Choice>, Rule::Choice> rule;
    rule[std::make_tuple(Rule::Choice::ROCK, Rule::Choice::PAPER)] = Rule::Choice::PAPER;
    rule[std::make_tuple(Rule::Choice::PAPER, Rule::Choice::ROCK)] = Rule::Choice::PAPER;
    rule[std::make_tuple(Rule::Choice::ROCK, Rule::Choice::SCISSORS)] = Rule::Choice::PAPER;
    rule[std::make_tuple(Rule::Choice::SCISSORS, Rule::Choice::ROCK)] = Rule::Choice::ROCK;
    rule[std::make_tuple(Rule::Choice::SCISSORS, Rule::Choice::PAPER)] = Rule::Choice::SCISSORS;
    rule[std::make_tuple(Rule::Choice::PAPER, Rule::Choice::SCISSORS)] = Rule::Choice::SCISSORS;

    return rule[std::make_tuple(lhs, rhs)];

}


std::unique_ptr<Rule::Choice[]> ComputerResponse::random_actions(size_t number_games_tobe_played) {
    std::unique_ptr<Rule::Choice[]> p = std::make_unique<Rule::Choice[]>(number_games_tobe_played);
    const int number_of_choices = 3;
    srand( (unsigned)time( NULL ) );
    for (size_t i = 0; i < number_games_tobe_played; ++i) {
       p[i] = Global::mapping_choice(rand() % number_of_choices + 1);
    }
    return p;
}

void Assets::show(const Rule::Choice choice) {
    switch(choice) {
        case Rule::Choice::ROCK:
            Assets::fist();
            break;

        case Rule::Choice::PAPER:
            Assets::open_hands();
            break;

        case Rule::Choice::SCISSORS:
            Assets::middle_finger();
            break;

	case Rule::Choice::NONE:
	    break;
    }
}

void Assets::fist() {
    std::cout << "     _ ___   ___   ___    " 	<< std::endl;
    std::cout << ",--  |: :  :   : | " 			<< std::endl;
    std::cout << "| ;  | +,    +.; |  +: | "	<< std::endl;
    std::cout << "|    |     |     |     |. "	<< std::endl;
    std::cout << "| :  |     |     |     || "	<< std::endl;
    std::cout << "| :. |  :  |  :  |  :  | | "	<< std::endl;
    std::cout << "|____: :.. : :.. | :.. |+ "	<< std::endl;
    std::cout << "   +---____|,|___| __ "		<< std::endl;
    std::cout << "       +==._ .. . + "			<< std::endl;
    std::cout << "             -::-+ "			<< std::endl;
}


void Assets::open_hands() {
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
    std::cout << "$$$$$$$$$$$$$$$$$$____$$_____$$$$" << std::endl;
    std::cout << "$$$$_____$$____$$$____$$_____$$$$" << std::endl;
    std::cout << "$$$$_____$$____$$$____$$_____$$$$" << std::endl;
    std::cout << "$$$$_____$$____$$$____$$_____$$$$" << std::endl;
    std::cout << "$$$$_____$______$______$_____$$$$" << std::endl;
    std::cout << "$$$$_____$______$______$_____$$$$" << std::endl;
    std::cout << "$$$$_____$__________________$$$$$" << std::endl;
    std::cout << "$$$$_____$__________________$$$$$" << std::endl;
    std::cout << "$$$$_____$_____________________$$" << std::endl;
    std::cout << "$$$$__________$$_______________$$" << std::endl;
    std::cout << "$$$$___________$$______________$$" << std::endl;
    std::cout << "$$$$_____________$_________$$$$$$" << std::endl;
    std::cout << "$$$$$_____________________$$$$$$$" << std::endl;
    std::cout << "$$$$$$___________________$$$$$$$$" << std::endl;
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;

}

void Assets::middle_finger() {
    std::cout << "________________$" << std::endl;
    std::cout << "_____________$____$" << std::endl;
    std::cout << "_____________$____$" << std::endl;
    std::cout << "_____________$____$" << std::endl;
    std::cout << "_____________$____$" << std::endl;
    std::cout << "_____________$____$" << std::endl;
    std::cout << "_____________$____$" << std::endl;
    std::cout << "________$____$____$____$" << std::endl;
    std::cout << "________$____$____$____$__$" << std::endl;
    std::cout << "$__$____$____$____$____$" << std::endl;
    std::cout << "$____$________________$____$" << std::endl;
    std::cout << "$______$______________________$" << std::endl;
    std::cout << "__$____$______________________$" << std::endl;
    std::cout << "___$__$______________________$" << std::endl;
    std::cout << "____$__________________________$" << std::endl;
    std::cout << "_____$________________________$" << std::endl;
    std::cout << "______$______________________$" << std::endl;
    std::cout << "_______$____________________$" << std::endl;
    std::cout << "________$____________________$" << std::endl;
    std::cout << "_________$________________$" << std::endl;
    std::cout << "__________$________________$" << std::endl;
    std::cout << "__________$" << std::endl;
}

