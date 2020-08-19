#include "Game.h"

/* The Game has 2 Boards Real Board and Copy From It Called Player Board
We Will Empty Some Cells By Changing It To Zeros in The player Board
*/

Game::Game(pair <int,string> Settings, string currentPlayer,Validations myValidation)
{

    PlayerBoard.Changing_Random_Cells_To_Zeros(Settings.second == "Beginner" ? 'B' : 'E') ;

    this->Settings.first = Settings.first ;
    this->Settings.second = Settings.second ;

    PlayerName = currentPlayer ;

    EmptyCells = PlayerBoard.Get_Number_Of_Empty_Cells();

    if( !StartTheGame(Settings.first, myValidation ) )
    {
        cout<<"The Game Did not Start, There is Some Problem \n\n" ;
    }
    else
    {
        if( isWon )
        {
            Congratulation();
        }

        if( !isWon )
        {
            cout<<"\n\n \t\t\t\tGame Over \n\n" ;
            cout<<"\n \t\t\t\tYou Have Lost This Game \n\n ";
        }

    }

}

bool Game::StartTheGame(int AllowedMistakes, Validations myValidation )
{
    chrono::steady_clock sc;   // create an object of `steady_clock` class
    auto start = sc.now();     // start timer

    do
    {

        PlayerBoard.Printing_The_Full_Board() ;

        cout<<"Mistakes: "<<Mistakes<<"/"<<AllowedMistakes<<endl;
        cout<<"Difficulty: "<<Settings.second<<endl<<endl ;
        cout<<"Insert Empty Cell You Want to Change. \n\n";
        int Row,Col,Value ;
        cout<<"Row " ;
        Row = myValidation.ValidateIntegers(1,9);
        cout<<"Col " ;
        Col = myValidation.ValidateIntegers(1,9);

        if( PlayerBoard.Get_Cell_Value(Row,Col) != 0 ) //If This cell in player board not zero so its not empty
        {
            cout<<"You Picked Unempty Cell, Please Try Again\n\n";

            system("PAUSE");
            system("cls") ;

            continue;
        }


        cout<<"Value ";
        Value= myValidation.ValidateIntegers(1,9);

        /* To Know If your Answer Was right we will compare this value with the same index at real board */

        if( RealBoard.Get_Cell_Value(Row,Col) != Value)
        {
            cout<<"Wrong Answer, Try Again \n\n" ;
            Mistakes++ ;

        }

        if( RealBoard.Get_Cell_Value(Row,Col) == Value )
        {
            cout<<"Right Answer, Well Done\n\n" ;

            PlayerBoard.Set_Cell_Value(Row,Col,Value) ;

            EmptyCells-- ;

            EmptyCells == 0 ? isWon = true : isWon = false ;

        }

        system("PAUSE");
        system("cls") ;

    }
    while(Mistakes < AllowedMistakes && !isWon) ;


    auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
    auto castTime = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end

    this->Time = castTime.count() / 60 ;

    return true ;
}

void Game::Congratulation()
{
    system("cls");
    cout<<endl<<endl ;
    cout<<"\t C \t W \n\n";
    Sleep(400);
    cout<<"\t o \t e \n\n";
    Sleep(400);
    cout<<"\t n \t l \n\n";
    Sleep(400);
    cout<<"\t g \t l \n\n";
    Sleep(400);
    cout<<"\t r \t . \n\n";
    Sleep(400);
    cout<<"\t a \t . \n\n";
    Sleep(400);
    cout<<"\t t \t . \n\n";
    Sleep(400);
    cout<<"\t u \t . \n\n";
    Sleep(400);
    cout<<"\t l \t . \n\n";
    Sleep(400);
    cout<<"\t a \t . \n\n";
    Sleep(400);
    cout<<"\t t \t D \n\n";
    Sleep(400);
    cout<<"\t i \t o \n\n";
    Sleep(400);
    cout<<"\t o \t n \n\n";
    Sleep(400);
    cout<<"\t n \t e \n\n";

    cout<<"You Have Won This Game AT time: "<< setprecision(2) << fixed << Time <<" Minutes";
    cout<<endl<<endl ;
}
