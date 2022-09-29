#include "game.h"
#include <stdexcept>
#include "test/catch.hpp"

TEST_CASE("Mapping choice of player")
{
    Rule::Choice expected = Rule::Choice::PAPER;
    REQUIRE(expected == Global::mapping_choice(1));
    expected = Rule::Choice::ROCK;
    REQUIRE(expected == Global::mapping_choice(2));
    expected = Rule::Choice::SCISSORS;
    REQUIRE(expected == Global::mapping_choice(3));
}

TEST_CASE("Rule of the game")
{
    Rule::GameLogic rule;
    Rule::Choice expected = Rule::Choice::PAPER;
    REQUIRE(expected == rule(Rule::Choice::ROCK, Rule::Choice::PAPER));
    expected = Rule::Choice::PAPER;
    REQUIRE(expected == rule(Rule::Choice::PAPER, Rule::Choice::ROCK));
    expected = Rule::Choice::SCISSORS;
    REQUIRE(expected == rule(Rule::Choice::PAPER, Rule::Choice::SCISSORS));
    expected = Rule::Choice::SCISSORS;
    REQUIRE(expected == rule(Rule::Choice::SCISSORS, Rule::Choice::PAPER));
    expected = Rule::Choice::ROCK;
    REQUIRE(expected == rule(Rule::Choice::SCISSORS, Rule::Choice::ROCK));
    expected = Rule::Choice::ROCK;
    REQUIRE(expected == rule(Rule::Choice::ROCK, Rule::Choice::SCISSORS));
}

TEST_CASE("Computer responses for the number of games played")
{
    auto computer_actions = ComputerResponse::random_actions(3);
    //int len = sizeof(computer_actions)/sizeof(computer_actions[0]);
    REQUIRE(computer_actions[2] != Rule::Choice::NONE );
    REQUIRE(computer_actions[1] != Rule::Choice::NONE );
    REQUIRE(computer_actions[0] != Rule::Choice::NONE );
}

#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
