#ifndef SYSTEM_H
#define SYSTEM_H

#include<bits/stdc++.h>
#include<fstream>

/* If You Have This Problem " GetConsoleWindow' was not declared in this scope " UnComment Next Line */
//#define _WIN32_WINNT 0x0500
#include <windows.h>

#include<Board.h>
#include<Game.h>
#include<Validations.h>
#include<Colors.h>
#include<SaveData.h>

using namespace std;

class System
{
public:

    static System *getInstance()
    {
        if (!instance)
            instance = new System;
        return instance;
    }

    ~System();


    bool MainMenu();
    bool NewGame() ;
    void welcoming() ;
    void GameGuide() ;

    void Save_Game_To_Binary_File(SaveData LastGame) ;
    bool Get_Stat_From_Binary_File();

    bool SettingsPage() ;
    bool colorsSettings();
    void Set_Console_Colors() ;


private:
    System();
    static System *instance;

    string CurrentPlayer;
    pair<int,string> Settings; // int Mistakes Allowed , string Difficulty

    Validations validation;
    Colors *SystemColors = SystemColors -> getInstance();
};

#endif // SYSTEM_H
