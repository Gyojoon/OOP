//
//  utility.hpp
//  Football Manager
//
//  Created by Yooseung Kim on 2022/05/29.
//

#ifndef utility_hpp
#define utility_hpp

//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
#include <string>
#include <iomanip>
//#include <random>

#include "player_club.hpp"
//class Utility {
//private:
//    static std::string player_txt;
//    static std::string club_txt;
//    static std::string init_player_txt;
//    static std::string init_club_txt;
//public:
//    static void readPlayer();
//
//    static void readClub();
//
//    static void chooseClub();
//
//    static void showMenu();
//
//    static void writeFile();
//};

void readClub();
void readPlayer();
void showMenu();
void chooseClub();
void writeFile();
#endif

