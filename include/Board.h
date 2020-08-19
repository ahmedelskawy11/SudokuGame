#ifndef BOARD_H
#define BOARD_H
#include<Colors.h>
#include <iostream>
#include <time.h>

/* If You Have This Problem GetConsoleWindow' was not declared in this scope UnComment Next Line */
//#define _WIN32_WINNT 0x0500
#include <windows.h>


using namespace std;

class Board
{
    public:
        Board();
        Board(const Board& otherObject);

        bool Assign_Numbers_To_The_Board() ;

        bool Random_Numbers_Generator(int *Array  , int Length ,int LowerBound , int UpperBound) ;
        bool is_Found_In_The_Array(int Array[], int Length , int Value) ;
        bool Shifting_An_Array_To_The_Right(int Array[], int Length , int ElementsToShift) ;

        void Printing_The_Full_Board () ;
        void Printing_A_Single_Row(int RowNumber) ;
        void Changing_The_Text_Color(int Color );

        bool Changing_Random_Cells_To_Zeros(char Difficulty);
        bool Changing_Random_Cells_To_Zeros_In_Row(int Row , char Difficulty );


        int Get_Cell_Value( int Row , int Col ) { return board[Row-1][Col-1] ; }
        void Set_Cell_Value( int Row , int Col , int Value ) { board[Row-1][Col-1] = Value ; }

        int Get_Number_Of_Empty_Cells(){ return EmptyCells ;}

    private:
        int board[9][9];
        int EmptyCells {0};
};

#endif // BOARD_H
