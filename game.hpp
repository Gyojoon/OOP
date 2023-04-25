//
//  game.hpp
//  Football Manager
//
//  Created by Yooseung Kim on 2022/05/29.
//

#ifndef game_hpp
#define game_hpp

#include <iostream>
#include <string>
#include <vector>
#include "player_club.hpp"


//class Club;

class Game
{
private:
    static std::vector<Game *> gameList;
    Club *club1;
    Club *club2;
    std::string result;

    std::string play();

public:
    Game(Club *, Club *);

    static std::vector<Game *> getGameList();
    friend std::ostream &operator<<(std::ostream &, Game &);

    friend class Club;
};

#endif
