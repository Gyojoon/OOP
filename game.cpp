//
//  game.cpp
//  Football Manager
//
//  Created by Yooseung Kim on 2022/05/29.
//

#include "game.hpp"

using namespace std;

Game::Game(Club *c1, Club *c2) : club1(c1), club2(c2)
{
    gameList.push_back(this);
    result = play();
}

string Game::play()
{
    int s1 = club1->squad.size();
    int s2 = club2->squad.size();

    bool ball = true; // true : club1's ball

    int g1 = 0;
    int g2 = 0;
    for (int ballChange = 0; ballChange < 20; ballChange++)
    {
    }

    if (g1 == g2)
    {
        return "Draw";
    }
    else if (g1 > g2)
    {
        return club1->name;
    }
    else
    {
        return club2->name;
    }
}

vector<Game *> Game::gameList;

vector<Game *> Game::getGameList()

{
    return gameList;
}

ostream &operator<<(ostream &o, Game &game)
{
    o << game.club1->getName() << "vs" << game.club2->getName() << endl;
    o << "Winner : " << game.result << endl;
    return o;
}
