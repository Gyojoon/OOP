//
//  utility.cpp
//  Football Manager
//
//  Created by Yooseung Kim on 2022/05/29.
//

#include "utility.hpp"

using namespace std;

Club *myClub = nullptr;
string player_txt = "/Users/yooseungkim/Desktop/data/player.txt";
string club_txt = "/Users/yooseungkim/Desktop/data/club.txt";
string init_player_txt = "/Users/yooseungkim/Desktop/data/init_player.txt";
string init_club_txt = "/Users/yooseungkim/Desktop/data/init_club.txt";

//string Utility::player_txt = "/Users/yooseungkim/Desktop/data/player.txt";
//string Utility::club_txt = "/Users/yooseungkim/Desktop/data/club.txt";
//string Utility:: init_player_txt = "/Users/yooseungkim/Desktop/data/init_player.txt";
//string Utility::init_club_txt = "/Users/yooseungkim/Desktop/data/init_club.txt";

//void Utility::readPlayer()
//{
//    string line;
//
//    ifstream input_file(player_txt);
//    if (!input_file.is_open())
//    {
//        cerr << "Could not open the file - ' " << club_txt << " ' " << endl;
//    }
//    while (getline(input_file, line))
//    {
//        vector<string> player;
//        int pos = 0;
//        int i;
//        for (i = 0; i < line.size(); i++)
//        {
//            if (line[i] == ' ')
//            {
//                player.push_back(line.substr(pos, i - pos));
//                pos = i + 1;
//            }
//        }
//        player.push_back(line.substr(pos, i - pos));
//        if (player.size() < 5)
//        {
//            continue;
//        }
//        string position = player[2];
//        if (player.size() == 5) // no initial stat
//        {
//
//            if (position == "GK")
//            {
//                GK *newPlayer = new GK(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]));
//            }
//            else if (position == "DF")
//            {
//                DF *newPlayer = new DF(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]));
//            }
//            else if (position == "MF")
//            {
//                MF *newPlayer = new MF(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]));
//            }
//            else if (position == "FW")
//            {
//                FW *newPlayer = new FW(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]));
//            }
//        }
//        else if (player.size() == 6) // initial stat
//        {
//
//            if (position == "GK")
//            {
//                GK *newPlayer = new GK(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]), stoi(player[5]));
//            }
//            else if (position == "DF")
//            {
//                DF *newPlayer = new DF(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]), stoi(player[5]));
//            }
//            else if (position == "MF")
//            {
//                MF *newPlayer = new MF(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]), stoi(player[5]));
//            }
//            else if (position == "FW")
//            {
//                FW *newPlayer = new FW(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]), stoi(player[5]));
//            }
//        }
//    }
//
//    input_file.close();
//}
//
//void Utility::readClub()
//{
//
//    string line;
//
//    ifstream input_file(club_txt);
//    if (!input_file.is_open())
//    {
//        cerr << "Could not open the file - ' " << club_txt << " ' " << endl;
//    }
//
//    while (getline(input_file, line))
//    {
//        vector<string> club;
//        int pos = 0;
//        int i;
//        for (i = 0; i < line.size(); i++)
//        {
//            if (line[i] == ' ')
//            {
//                club.push_back(line.substr(pos, i - pos));
//                pos = i + 1;
//            }
//        }
//        club.push_back(line.substr(pos, i - pos));
//        if (club.size() < 2)
//        {
//            continue;
//        }
//        Club *newClub = new Club(club[0], stoi(club[1]));
//    }
//}
//
//void Utility::writeFile()
//{
//    ofstream fout;
//    fout.open(player_txt);
//    for (int i = 0; i < Player::getPlayerList().size(); i++)
//    {
//        fout << *(Player::getPlayerList()[i]) << endl;
//    }
//    fout.close();
//
//    fout.open(club_txt);
//    for (int i = 0; i < Club::getClublist().size(); i++)
//    {
//        fout << *(Club::getClublist()[i]) << endl;
//    }
//    fout.close();
//}
//void Utility::chooseClub()
//{
//    cout << "============ Welcome To FM! ================" << endl;
//    cout << "(1) Make your own club" << endl
//         << "(2) Use existing club" << endl;
//
//    int sel = 0;
//    cin >> sel;
//
//    if (sel == 1)
//    {
//        string name;
//        int money;
//        cout << "What is your club's name? : ";
//        cin >> name;
//        myClub = Club::strToClub(name);
//        if (myClub == nullptr)
//        {
//
//            cout << "How much is your club's capital? : ";
//            cin >> money;
//            myClub = new Club(name, money);
//        }
//        else
//        {
//            cout << "Club with given name already exists" << endl
//                 << "Do you want to use existing club? (y/n) ";
//            string choice;
//            cin >> choice;
//            if (choice == "y")
//            {
//            }
//            else if (choice == "n")
//            {
//                chooseClub();
//                return;
//            }
//            else
//            {
//                cout << "Enter valid option" << endl;
//                chooseClub();
//                return;
//            }
//        }
//        cout << "Welcome! You manage " << myClub->getName() << endl;
//        return;
//    }
//    else if (sel == 2)
//    {
//        cout << "Which club do you want to play?" << endl
//             << endl
//             << endl;
//        cout << "Possible options are : " << endl;
//        for (int i = 0; i < Club::getClublist().size(); i++)
//        {
//            cout << "(" << i + 1 << ") " << Club::getClublist()[i]->getName() << endl;
//        }
//
//        int choice;
//        cin >> choice;
//        if (choice > Club::getClublist().size())
//        {
//            cout << "Invalid Choice" << endl
//                 << endl;
//            chooseClub();
//        }
//        else
//        {
//            myClub = Club::getClublist()[choice - 1];
//            cout << "Welcome! You manage " << myClub->getName() << " from now on" << endl
//                 << endl
//                 << endl;
//        }
//    }
//    else
//    {
//        cout << "Inappropriate Choice" << endl;
//        chooseClub();
//    }
//}
//
//void Utility::showMenu()
//{
//    cout << "============"
//         << "Menu"
//         << "============" << endl;
//    cout << "Choose function from below" << endl
//         << "(1) Show my club" << endl
//         << "(2) Show other club" << endl
//         << "(3) Buy player" << endl
//         << "(4) Trade player" << endl
//         << "(5) Sell Player" << endl
//         << "(6) Make New Player" << endl
//         << "(7) Reset and Quit" << endl
//         << "(9) Save and Quit" << endl;
//
//    int sel;
//
//    cin >> sel;
//
//    cout << endl
//         << "============================" << endl
//         << endl;
//
//    switch (sel)
//    {
//    case 1:
//    {
//        cout << *myClub << endl;
//        break;
//    }
//    case 2:
//    {
//        cout << "Which club do you want to print ? : " << endl;
//        string club;
//        cin >> club;
//        Club *selectedClub = Club::strToClub(club);
//        if (selectedClub == nullptr)
//        {
//            cout << "Inappropriate club" << endl;
//        }
//        else
//        {
//            cout << *selectedClub << endl;
//        }
//        break;
//    }
//    case 3:
//    {
//        cout << "Which player do you want to buy ? : " << endl;
//        string player = "";
//        cin >> player;
//        Player *toBuy = nullptr;
//        for (int i = 0; i < Player::getPlayerList().size(); i++)
//        {
//            if (Player::getPlayerList()[i]->getName() == player)
//            {
//                toBuy = Player::getPlayerList()[i];
//            }
//        }
//
//        if (toBuy == nullptr)
//        {
//            cout << "The player does not exist" << endl;
//            break;
//        }
//        if (toBuy->getClub() == myClub->getName())
//        {
//            cout << "The player is already in your club" << endl;
//            break;
//        }
//        if (myClub->buy(toBuy))
//        {
//            cout << "Successfully Bought" << endl;
//        }
//        else
//        {
//            cout << "Failed to Buy" << endl;
//        }
//        break;
//    }
//    case 4:
//    {
//        cout << "Choose player from your club : " << endl;
//        string p1;
//        cin >> p1;
//        Player *myPlayer = nullptr;
//        for (int i = 0; i < myClub->squad.size(); i++)
//        {
//            if (p1 == myClub->squad[i]->getName())
//            {
//                myPlayer = myClub->squad[i];
//            }
//        }
//        if (myPlayer == nullptr)
//        {
//            cout << "Choose player from your club" << endl
//                 << "Your club's squad: " << endl;
//            myClub->printSquad();
//
//            break;
//        }
//        cout << *myPlayer << endl;
//        cout << "Choose player from other club : " << endl;
//        string p2;
//        cin >> p2;
//        Player *otherPlayer = Player::strToPlayer(p2);
//        // for (int i = 0; i < Player::getPlayerList().size(); i++)
//        // {
//        //     if (p2 == Player::getPlayerList()[i]->getName())
//        //     {
//        //         otherPlayer = Player::getPlayerList()[i];
//        //     }
//        // }
//        if (otherPlayer == nullptr)
//        {
//            cout << "Player with given name does not exist" << endl;
//            break;
//        }
//        if (otherPlayer->getClub() == myClub->getName())
//        {
//            cout << "The player is already your team" << endl;
//            break;
//        }
//        cout << *otherPlayer << endl;
//        Club::trade(myPlayer, otherPlayer);
//        cout << "Successfuly Traded" << endl;
//        break;
//    }
//    case 5:
//    {
//        cout << "Choose player to sell : ";
//        string player = "";
//        cin >> player;
//        Player *toSell = nullptr;
//        for (int i = 0; i < myClub->squad.size(); i++)
//        {
//            if (player == myClub->squad[i]->getName())
//            {
//                toSell = myClub->squad[i];
//            }
//        }
//        if (toSell == nullptr)
//        {
//            cout << "Choose player from your club" << endl
//                 << "Your club's squad: " << endl;
//            myClub->printSquad();
//
//            break;
//        }
//        cout << "Choose club to sell to (if none, enter fa)" << endl;
//        string clubname;
//        cin >> clubname;
//        if (clubname == "fa")
//
//        {
//        }
//        else
//        {
//            Club *club = Club::strToClub(clubname);
//            club->buy(toSell);
//        }
//        break;
//    }
//    case 6:
//    {
//        string name, club, position;
//        int number, value;
//        cout << "Make new Player" << endl;
//        cout << "Name : ";
//        cin >> name;
//        Player *player = Player::strToPlayer(name);
//        if (player != nullptr)
//        {
//            cout << "Player with given name already exists" << endl;
//            break;
//        }
//        cout << "Club : ";
//        cin >> club;
//        Club *clubPtr = Club::strToClub(club);
//        if (clubPtr == nullptr)
//        {
//            cout << "Given club does not exist" << endl;
//            break;
//        }
//        cout << "Position(GK, DF, MF, FW) : ";
//        cin >> position;
//        cout << "Back Number : ";
//        cin >> number;
//        cout << "Market Value : ";
//        cin >> value;
//        if (position == "GK")
//        {
//            GK *newPlayer = new GK(name, club, position, number, value);
//        }
//        else if (position == "DF")
//        {
//            DF *newPlayer = new DF(name, club, position, number, value);
//        }
//        else if (position == "MF")
//        {
//            MF *newPlayer = new MF(name, club, position, number, value);
//        }
//        else if (position == "FW")
//        {
//            FW *newPlayer = new FW(name, club, position, number, value);
//        }
//        cout << endl
//             << name << " has successfully created" << endl;
//        break;
//    }
//    case 7:
//    {
//        string line;
//        ifstream fin;
//        ofstream fout;
//        fin.open(init_player_txt);
//        fout.open(player_txt);
//
//        if (!fin.is_open())
//        {
//            cerr << "Could not open the file - ' " << club_txt << " ' " << endl;
//        }
//        while (getline(fin, line))
//        {
//            fout << line << endl;
//        }
//        fin.close();
//        fout.close();
//
//        fin.open(init_club_txt);
//        fout.open(club_txt);
//
//        while (getline(fin, line))
//        {
//            fout << line << endl;
//        }
//        fin.close();
//        fout.close();
//        cout << "Please restart the game" << endl;
//        return;
//    }
//    case 9:
//    {
//        writeFile();
//        cout << "Closed FM successfully" << endl
//             << "Thank you for playing!" << endl;
//        return;
//    }
//    default:
//        cout << "Inappropriate Choice" << endl;
//        break;
//    }
//    cout << endl
//         << endl;
//    showMenu();
//}


void readPlayer()
{
    string line;

    ifstream input_file(player_txt);
    if (!input_file.is_open())
    {
        cerr << "Could not open the file - ' " << club_txt << " ' " << endl;
    }
    while (getline(input_file, line))
    {
        vector<string> player;
        int pos = 0;
        int i;
        for (i = 0; i < line.size(); i++)
        {
            if (line[i] == ' ')
            {
                player.push_back(line.substr(pos, i - pos));
                pos = i + 1;
            }
        }
        player.push_back(line.substr(pos, i - pos));
        if (player.size() < 5)
        {
            continue;
        }
        string position = player[2];
        if (player.size() == 5) // no initial stat
        {

            if (position == "GK")
            {
                GK *newPlayer = new GK(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]));
            }
            else if (position == "DF")
            {
                DF *newPlayer = new DF(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]));
            }
            else if (position == "MF")
            {
                MF *newPlayer = new MF(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]));
            }
            else if (position == "FW")
            {
                FW *newPlayer = new FW(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]));
            }
        }
        else if (player.size() == 6) // initial stat
        {

            if (position == "GK")
            {
                GK *newPlayer = new GK(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]), stoi(player[5]));
            }
            else if (position == "DF")
            {
                DF *newPlayer = new DF(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]), stoi(player[5]));
            }
            else if (position == "MF")
            {
                MF *newPlayer = new MF(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]), stoi(player[5]));
            }
            else if (position == "FW")
            {
                FW *newPlayer = new FW(player[0], player[1], player[2], stoi(player[3]), stoi(player[4]), stoi(player[5]));
            }
        }
    }

    input_file.close();
}

void readClub()
{

    string line;

    ifstream input_file(club_txt);
    if (!input_file.is_open())
    {
        cerr << "Could not open the file - ' " << club_txt << " ' " << endl;
    }

    while (getline(input_file, line))
    {
        vector<string> club;
        int pos = 0;
        int i;
        for (i = 0; i < line.size(); i++)
        {
            if (line[i] == ' ')
            {
                club.push_back(line.substr(pos, i - pos));
                pos = i + 1;
            }
        }
        club.push_back(line.substr(pos, i - pos));
        if (club.size() < 2)
        {
            continue;
        }
        Club *newClub = new Club(club[0], stoi(club[1]));
    }
}

void writeFile()
{
    ofstream fout;
    fout.open(player_txt);
    for (int i = 0; i < Player::getPlayerList().size(); i++)
    {
        fout << *(Player::getPlayerList()[i]) << endl;
    }
    fout.close();

    fout.open(club_txt);
    for (int i = 0; i < Club::getClublist().size(); i++)
    {
        fout << *(Club::getClublist()[i]) << endl;
    }
    fout.close();
}
void chooseClub()
{
    cout << "============ Welcome To FM! ================" << endl;
    cout << "(1) Make your own club" << endl
         << "(2) Use existing club" << endl;

    int sel = 0;
    cin >> sel;

    if (sel == 1)
    {
        string name;
        int money;
        cout << "What is your club's name? : ";
        cin >> name;
        myClub = Club::strToClub(name);
        if (myClub == nullptr)
        {

            cout << "How much is your club's capital? : ";
            cin >> money;
            myClub = new Club(name, money);
        }
        else
        {
            cout << "Club with given name already exists" << endl
                 << "Do you want to use existing club? (y/n) ";
            string choice;
            cin >> choice;
            if (choice == "y")
            {
            }
            else if (choice == "n")
            {
                chooseClub();
                return;
            }
            else
            {
                cout << "Enter valid option" << endl;
                chooseClub();
                return;
            }
        }
        cout << "Welcome! You manage " << myClub->getName() << endl;
        return;
    }
    else if (sel == 2)
    {
        cout << "Which club do you want to play?" << endl
             << endl
             << endl;
        cout << "Possible options are : " << endl;
        for (int i = 0; i < Club::getClublist().size(); i++)
        {
            cout << "(" << i + 1 << ") " << Club::getClublist()[i]->getName() << endl;
        }

        int choice;
        cin >> choice;
        if (choice > Club::getClublist().size())
        {
            cout << "Invalid Choice" << endl
                 << endl;
            chooseClub();
        }
        else
        {
            myClub = Club::getClublist()[choice - 1];
            cout << "Welcome! You manage " << myClub->getName() << " from now on" << endl
                 << endl
                 << endl;
        }
    }
    else
    {
        cout << "Inappropriate Choice" << endl;
        chooseClub();
    }
}

void showMenu()
{
    cout << "============"
         << "Menu"
         << "============" << endl;
    cout << "Choose function from below" << endl
         << "(1) Show my club" << endl
         << "(2) Show other club" << endl
         << "(3) Buy player" << endl
         << "(4) Trade player" << endl
         << "(5) Sell Player" << endl
         << "(6) Make New Player" << endl
         << "(7) Reset and Quit" << endl
         << "(9) Save and Quit" << endl;

    int sel;

    cin >> sel;

    cout << endl
         << "============================" << endl
         << endl;

    switch (sel)
    {
    case 1:
    {
        cout << *myClub << endl;
        break;
    }
    case 2:
    {
        cout << "Which club do you want to print ? : " << endl;
        string club;
        cin >> club;
        Club *selectedClub = Club::strToClub(club);
        if (selectedClub == nullptr)
        {
            cout << "Inappropriate club" << endl;
        }
        else
        {
            cout << *selectedClub << endl;
        }
        break;
    }
    case 3:
    {
        cout << "Which player do you want to buy ? : " << endl;
        string player = "";
        cin >> player;
        Player *toBuy = nullptr;
        for (int i = 0; i < Player::getPlayerList().size(); i++)
        {
            if (Player::getPlayerList()[i]->getName() == player)
            {
                toBuy = Player::getPlayerList()[i];
            }
        }

        if (toBuy == nullptr)
        {
            cout << "The player does not exist" << endl;
            break;
        }
        if (toBuy->getClub() == myClub->getName())
        {
            cout << "The player is already in your club" << endl;
            break;
        }
        if (myClub->buy(toBuy))
        {
            cout << "Successfully Bought" << endl;
        }
        else
        {
            cout << "Failed to Buy" << endl;
        }
        break;
    }
    case 4:
    {
        cout << "Choose player from your club : " << endl;
        string p1;
        cin >> p1;
        Player *myPlayer = nullptr;
        for (int i = 0; i < myClub->squad.size(); i++)
        {
            if (p1 == myClub->squad[i]->getName())
            {
                myPlayer = myClub->squad[i];
            }
        }
        if (myPlayer == nullptr)
        {
            cout << "Choose player from your club" << endl
                 << "Your club's squad: " << endl;
            myClub->printSquad();

            break;
        }
        cout << *myPlayer << endl;
        cout << "Choose player from other club : " << endl;
        string p2;
        cin >> p2;
        Player *otherPlayer = Player::strToPlayer(p2);
        // for (int i = 0; i < Player::getPlayerList().size(); i++)
        // {
        //     if (p2 == Player::getPlayerList()[i]->getName())
        //     {
        //         otherPlayer = Player::getPlayerList()[i];
        //     }
        // }
        if (otherPlayer == nullptr)
        {
            cout << "Player with given name does not exist" << endl;
            break;
        }
        if (otherPlayer->getClub() == myClub->getName())
        {
            cout << "The player is already your team" << endl;
            break;
        }
        cout << *otherPlayer << endl;
        Club::trade(myPlayer, otherPlayer);
        cout << "Successfuly Traded" << endl;
        break;
    }
    case 5:
    {
        cout << "Choose player to sell : ";
        string player = "";
        cin >> player;
        Player *toSell = nullptr;
        for (int i = 0; i < myClub->squad.size(); i++)
        {
            if (player == myClub->squad[i]->getName())
            {
                toSell = myClub->squad[i];
            }
        }
        if (toSell == nullptr)
        {
            cout << "Choose player from your club" << endl
                 << "Your club's squad: " << endl;
            myClub->printSquad();

            break;
        }
        cout << "Choose club to sell to (if none, enter fa)" << endl;
        string clubname;
        cin >> clubname;
        if (clubname == "fa")

        {
        }
        else
        {
            Club *club = Club::strToClub(clubname);
            club->buy(toSell);
        }
        break;
    }
    case 6:
    {
        string name, club, position;
        int number, value;
        cout << "Make new Player" << endl;
        cout << "Name : ";
        cin >> name;
        Player *player = Player::strToPlayer(name);
        if (player != nullptr)
        {
            cout << "Player with given name already exists" << endl;
            break;
        }
        cout << "Club : ";
        cin >> club;
        Club *clubPtr = Club::strToClub(club);
        if (clubPtr == nullptr)
        {
            cout << "Given club does not exist" << endl;
            break;
        }
        cout << "Position(GK, DF, MF, FW) : ";
        cin >> position;
        cout << "Back Number : ";
        cin >> number;
        cout << "Market Value : ";
        cin >> value;
        if (position == "GK")
        {
            GK *newPlayer = new GK(name, club, position, number, value);
        }
        else if (position == "DF")
        {
            DF *newPlayer = new DF(name, club, position, number, value);
        }
        else if (position == "MF")
        {
            MF *newPlayer = new MF(name, club, position, number, value);
        }
        else if (position == "FW")
        {
            FW *newPlayer = new FW(name, club, position, number, value);
        }
        cout << endl
             << name << " has successfully created" << endl;
        break;
    }
    case 7:
    {
        string line;
        ifstream fin;
        ofstream fout;
        fin.open(init_player_txt);
        fout.open(player_txt);

        if (!fin.is_open())
        {
            cerr << "Could not open the file - ' " << club_txt << " ' " << endl;
        }
        while (getline(fin, line))
        {
            fout << line << endl;
        }
        fin.close();
        fout.close();

        fin.open(init_club_txt);
        fout.open(club_txt);

        while (getline(fin, line))
        {
            fout << line << endl;
        }
        fin.close();
        fout.close();
        cout << "Please restart the game" << endl;
        return;
    }
    case 9:
    {
        writeFile();
        cout << "Closed FM successfully" << endl
             << "Thank you for playing!" << endl;
        return;
    }
    default:
        cout << "Inappropriate Choice" << endl;
        break;
    }
    cout << endl
         << endl;
    showMenu();
}
