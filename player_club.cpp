//
//  player_ club.cpp
//  Football Manager
//
//  Created by Yooseung Kim on 2022/05/29.
//

#include "player_club.hpp"

#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> STAT(60, 100);
std::uniform_int_distribution<int> PROB(1, 100);

using namespace std;
Player::Player(string n, string c, string p, int num, int v)
    : name(n), club(c), pos(p), number(num), value(v)
{
    stat = STAT(gen);
    playerList.push_back(this);
    Club *clubPtr = Club::strToClub(club);
    clubPtr->squad.push_back(this);
}

Player::Player(string n, string c, string p, int num, int v, int s)
    : name(n), club(c), pos(p), number(num), value(v), stat(s)
{
    playerList.push_back(this);
    Club *clubPtr = Club::strToClub(club);
    clubPtr->squad.push_back(this);
}

vector<Player *> Player::playerList;

Player *Player::strToPlayer(string name)
{
    for (int i = 0; i < playerList.size(); i++)
    {
        if (name == playerList[i]->name)
        {
            return playerList[i];
        }
    }
    return nullptr;
}

bool Player::isSuccessful(double coeff)
{
    int prob = PROB(gen);
    if (stat * coeff > prob)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Player::getStat()
{
    return stat;
}

string Player::getName()
{
    return name;
}

string Player::getClub()
{
    return club;
}

vector<Player *> Player::getPlayerList()
{
    return playerList;
}

ostream &operator<<(ostream &o, Player &p)

{
    if (p.name.size() > 10)
    {
        o << p.name.substr(0, 7) << "..." << left << "(" << setw(2) << p.number << ")"
          << " | Position: " << p.pos
          << " | Club: " << p.club << " | Stat : " << p.stat << " | Value : " << p.value << " $ " << endl;
    }
    else
    {
        o << setw(10) << p.name << left << "(" << setw(2) << p.number << ") "
          << "| Position: " << p.pos
          << " | Club: " << p.club << " | Stat : " << p.stat << " | Value : " << p.value << " $ " << endl;
    }
    return o;
}
ofstream &operator<<(ofstream &o, Player &p)
{
    o << p.name << " " << p.club << " " << p.pos << " " << p.number << " " << p.value << " " << p.stat;
    return o;
};

Club::Club(string n, int m)
    : name(n), money(m)
{
    clublist.push_back(this);
}

vector<Club *> Club::clublist;

int Club::findIdx(Player *p)
{
    for (int i = 0; i < squad.size(); i++)
    {
        if (squad[i] == p)
        {
            return i;
        }
    }
    return -1;
}

bool Club::buy(Player *p, bool fa)
{
    if (fa == false || p->club == "fa")
    {
        if (p->value > money)
        {
            cout << "Not enough money" << endl; // error for insufficient money
            return false;
        }
        else
        {
            money -= p->value;
        }
    }

    Club *before = strToClub(p->club);
    before->sell(p, fa);
    squad.push_back(p);
    p->club = name;
    return true;
}

void Club::sell(Player *p, bool fa)
{
    if (fa == false)
    {
        this->money += p->value;
    }
    int idx = findIdx(p);
    squad.erase(squad.begin() + idx);

    p->club = "fa";
}

void Club::printSquad()
{
    for (int i = 0; i < squad.size(); i++)
    {
        cout << squad[i]->getName() << "    ";
        if (i % 5 == 4)
        {
            cout << endl;
        }
    }
}

string Club::getName()
{
    return name;
}

vector<Club *> Club::getClublist()
{
    return clublist;
}

void Club::trade(Player *p1, Player *p2)
{
    Club *temp = strToClub(p2->club);
    strToClub(p1->club)->buy(p2, true);
    temp->buy(p1, true);
}

Club *Club::strToClub(string clubname)
{
    Club *club = nullptr;
    for (int i = 0; i < clublist.size(); i++)
    {
        if (clubname == clublist[i]->name)
        {
            club = clublist[i];
            break;
        }
    }

    if (club == nullptr)
    {
        // cout << "invalid team" << endl; // club name does not exist
    }

    return club;
}

ostream &operator<<(ostream &o, Club &club)
{
    o << club.name << endl
      << "Squad Size: " << club.squad.size() << endl;
    o << "Capital: " << club.money << "$" << endl
      << "==================================================================" << endl;

    for (int i = 0; i < club.squad.size(); i++)
    {
        o << *(club.squad[i]) << endl;
    }

    return o;
}

ofstream &operator<<(ofstream &o, Club &c)
{
    o << c.name << " " << c.money;
    return o;
}


GK::GK(string name, string club, string pos, int number, int value)
    : Player(name, club, pos, number, value)
{
}
GK::GK(string name, string club, string pos, int number, int value, int stat)
    : Player(name, club, pos, number, value, stat)
{
}
void GK::print() { cout << "GK" << endl; }
bool GK::block()
{
    return isSuccessful(0.9);
}
bool GK::shoot()
{
    return isSuccessful(0.3);
}
bool GK::pass()
{
    return isSuccessful(0.7);
}

bool GK::tackle()
{
    return isSuccessful(0.8);
}
// ======================================================================
DF::DF(string name, string club, string pos, int number, int value)
    : Player(name, club, pos, number, value) {}
DF::DF(string name, string club, string pos, int number, int value, int stat)
    : Player(name, club, pos, number, value, stat)
{
}
void DF::print() { cout << "DF" << endl; }

bool DF::shoot()
{
    return isSuccessful(0.6);
}

bool DF::pass()
{
    return isSuccessful(0.8);
}

bool DF::tackle()
{
    return isSuccessful(0.9);
}
// ======================================================================
MF::MF(string name, string club, string pos, int number, int value)
    : Player(name, club, pos, number, value)
{
}

MF::MF(string name, string club, string pos, int number, int value, int stat)
    : Player(name, club, pos, number, value, stat)
{
}

void MF::print() { cout << "MF" << endl; }
bool MF::shoot()
{
    return isSuccessful(0.7);
}

bool MF::pass()
{
    return isSuccessful(0.9);
}

bool MF::tackle()
{
    return isSuccessful(0.7);
}

// ======================================================================
FW::FW(string name, string club, string pos, int number, int value)
    : Player(name, club, pos, number, value)
{
}

FW::FW(string name, string club, string pos, int number, int value, int stat)
    : Player(name, club, pos, number, value, stat)
{
}

void FW::print() { cout << "FW" << endl; }
bool FW::shoot()
{
    return isSuccessful(0.9);
}
bool FW::pass()
{
    return isSuccessful(0.8);
}

bool FW::tackle()
{
    return isSuccessful(0.6);
}


