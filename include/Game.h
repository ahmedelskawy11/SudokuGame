#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<chrono>
#include<iomanip>

#include<Board.h>
#include<Validations.h>

using namespace std;

class Game
{
    public:
        Game() {}
        Game(pair <int,string> Settings , string currentPlayer , Validations myValidation ) ;

        bool StartTheGame(int AllowedMistakes,Validations myValidation );
        void Congratulation();


        // All Getters And Setters

        string GetPlayerName() { return PlayerName; }
        void SetPlayerName(string val) { PlayerName = val; }

        bool GetisWon() { return isWon; }
        void SetisWon(bool val) { isWon = val; }

        pair<int,string> GetSettings() { return Settings; }
        void SetSettings(pair<int,string> val) { Settings = val; }

        int GetMistakes() { return Mistakes; }
        void SetMistakes(int val) { Mistakes = val; }

        int GetEmptyCells() { return EmptyCells; }
        void SetEmptyCells(int val) { EmptyCells = val; }

    public:
        Board RealBoard;
        Board PlayerBoard = RealBoard;
        string PlayerName;
        bool isWon = false;
        pair<int,string> Settings;
        int Mistakes {0};
        int EmptyCells;
        double Time ;

};

#endif // GAME_H
