#ifndef SAVEDATA_H
#define SAVEDATA_H
#include<iostream>
#include<string.h>

using namespace std;
class SaveData
{
    public:
        SaveData();
        SaveData(string Name , string isWon , int mistakes , int maxmistakes , string difficulty , double time) ;

        char PlayerName[10];
        char Won[5];
        int Mistakes;
        int MaxMistakes;
        char Difficulty[10];
        double Time;
};

#endif // SAVEDATA_H
