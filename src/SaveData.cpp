#include "SaveData.h"

SaveData::SaveData()
{
    //ctor
}

SaveData::SaveData(string Name , string isWon , int mistakes , int maxmistakes , string difficulty , double time)
{
    strcpy(PlayerName,Name.c_str()) ;
    strcpy(Won,isWon.c_str()) ;
    strcpy(Difficulty,difficulty.c_str()) ;

    this->Mistakes = mistakes ;
    this->MaxMistakes = maxmistakes ;
    this->Time = time ;

}



