
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <random>

#include "utility.hpp"
#include "player_club.hpp"
#include "game.hpp"

using namespace std;

int main()
{
    //    Utility::readClub();
    //    Utility::readPlayer();
    //    Utility::chooseClub();
    //    Utility::showMenu();
    readClub();
    readPlayer();
    chooseClub();
    showMenu();
}