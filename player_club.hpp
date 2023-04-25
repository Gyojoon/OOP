//
//  player_ club.hpp
//  Football Manager
//
//  Created by Yooseung Kim on 2022/05/29.
//

#ifndef player_club_hpp
#define player_club_hpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


class Club;

class Player
{
    std::string name;
    std::string club;
    std::string pos;
    int number;
    int value;
    static std::vector<Player *> playerList;
    int stat;

public:
    Player(std::string, std::string, std::string, int, int);
    Player(std::string, std::string, std::string, int, int, int);

    bool isSuccessful(double);
    std::string getName();
    std::string getClub();
    int getStat();
    static std::vector<Player *> getPlayerList();
    static Player *strToPlayer(std::string);
    friend class Club;
    friend std::ostream &operator<<(std::ostream &o, Player &p);
    friend std::ofstream &operator<<(std::ofstream &o, Player &p);
    virtual void print() = 0;
    virtual bool tackle() = 0;
    virtual bool pass() = 0;
    virtual bool shoot() = 0;
};
// ======================================================================
class Club
{
    std::string name;
    int money;
    static std::vector<Club *> clublist;

    int findIdx(Player *);

public:
    Club(std::string, int = 0);
    std::vector<Player *> squad;

    bool buy(Player *, bool = false);
    void sell(Player *, bool = false);
    void printSquad();
    std::string getName();
    static void trade(Player *, Player *);
    static std::vector<Club *> getClublist();
    static Club *strToClub(std::string clubname);

    friend std::ostream &operator<<(std::ostream &, Club &);
    friend std::ofstream &operator<<(std::ofstream &o, Club &);
    friend class Player;
    friend class Game;
};

class GK : public Player
{
public:
    GK(std::string, std::string, std::string, int, int);
    GK(std::string, std::string, std::string, int, int, int);

    void print();
    bool block();
    bool shoot();
    bool pass();
    bool tackle();
};

class MF : public Player
{
public:
    MF(std::string, std::string, std::string, int, int);
    MF(std::string, std::string, std::string, int, int, int);

    void print();
    bool shoot();
    bool pass();
    bool tackle();
};
class DF : public Player
{
public:
    DF(std::string, std::string, std::string, int, int);
    DF(std::string, std::string, std::string, int, int, int);

    void print();
    bool shoot();
    bool pass();
    bool tackle();
};
class FW : public Player
{
public:
    FW(std::string, std::string, std::string, int, int);
    FW(std::string, std::string, std::string, int, int, int);

    void print();
    bool shoot();
    bool pass();
    bool tackle();
};

#endif
