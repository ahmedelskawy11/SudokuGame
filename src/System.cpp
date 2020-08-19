#include "System.h"


System::System()
{
    // Default Console Settings
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    Set_Console_Colors() ;
    SetConsoleTitle("SuDoKu");

    welcoming() ;

    // Default Game Settings
    CurrentPlayer = "SkawY" ;
    Settings.first = 3 ;
    Settings.second = "Beginner" ;
}

System::~System()
{
    delete SystemColors ;
    cout<<"\n\t\tThanks For Using This Application \n\n"<<endl ;
}


bool System::MainMenu()
{
    bool Quit = false ;
    do
    {
        Set_Console_Colors() ;

        system("cls") ;
        cout<<"\n Hello "<<CurrentPlayer<<endl<<endl<<endl;
        cout<<" 1- Start New Game \n\n";
        cout<<" 2- Game Guide \n\n";
        cout<<" 3- Statistics \n\n";
        cout<<" 4- Settings \n\n";
        cout<<" 5- Quit \n\n";
        int choice = validation.ValidateIntegers(1,5) ;


        if(choice == 1 )
        {
            bool PlayAgain {true} ;

            while( PlayAgain )
            {
                NewGame();

                cout<<"\n Do You Want To Play Another Game "<<CurrentPlayer<<endl ;
                cout<<"\n 1 -> To Play  ";
                cout<<"\n\n 2 -> To Back To Main Menu \n\n " ;
                int again = validation.ValidateIntegers(1,2) ;

                if( again == 2 )
                {
                    PlayAgain = false ;
                }

            }
        }
        if(choice == 2 )
        {
            GameGuide();
        }
        if(choice == 3 )
        {
            if(!Get_Stat_From_Binary_File())
            {
                cout<<"\n\n\t Save File Does Not Exist Or You Did Not Play Any Game \n\n";
            }
            system("pause") ;
        }
        if(choice == 4 )
        {
            SettingsPage();
        }
        if(choice == 5 )
        {
            Quit = true;
        }
    }
    while( Quit == false ) ;

    return true ;
}

/*
    Starting New Game With Creating Game Object
    Take Information From This Object And Create New Object Called SaveData Which is Easier to Save To Binary File

*/
bool System::NewGame()
{
    Game PlayedGame(Settings, CurrentPlayer, validation) ;

    // SaveData(string Name , string isWon , int mistakes , int MaximumMistakes , string difficulty , double time)

    SaveData LastGame (
        PlayedGame.GetPlayerName(),
        PlayedGame.GetisWon() ? "Won" : "Lost",
        PlayedGame.GetMistakes(),
        PlayedGame.GetSettings().first,
        PlayedGame.GetSettings().second,
        PlayedGame.Time
    ) ;

    Save_Game_To_Binary_File(LastGame) ;

    return true ;
}

void System::welcoming()
{
    cout<<endl<<endl<<endl;
    cout<<"          \t    \t    __        __      _"<<endl ;
    cout<<"          \t    \t    \\ \\      / /   __| | ___ ___  _ __ ___   ___"<<endl;
    cout<<"          \t   \t     \\ \\ /\\ / /  / _ \\ |/ __/ _ \\|  _   _ \\ / _ \\"<<endl;
    cout<<"          \t    \t      \\ V  V /     __/ | (_| (_) | | | | | |  __/"<<endl;
    cout<<"          \t    \t       \\_/\\_/    \\___|_|\\___\\___/|_| |_| |_|\\___|"<<endl;

    Sleep(1500) ;
    system("cls") ;
}

void System::GameGuide()
{
    system("cls") ;

    cout<<endl<<endl<<endl;
    cout<<"\t This Game Is Very Easy \n\n";
    cout<<"\t You Have Empty Cells,You,ll Fill Them With Numbers From 1 to 9 \n\n" ;
    cout<<"\t But Any Number Can not Appear Twice In Same Row, Col And Block \n\n";
    cout<<"\t If You Complete Filling All Empty Cells, You Will Win The Game\n\n" ;
    cout<<"\t Difference Between Two Difficulties Is  Number  Of Empty Cells \n\n" ;
    cout<<"\t Good Luck And Have Fun With This Game \n\n\n ";

    system("Pause") ;
}

/* Saving Data Functions */
/*---------------------------------------*/

void System::Save_Game_To_Binary_File(SaveData PlayedGame)
{
    ofstream SaveFile;
    SaveFile.open( "SaveFile.bin",ios::binary |ios::app);
    SaveFile.write((char*)&PlayedGame,sizeof(SaveData)) ;
    SaveFile.close() ;
}

bool System::Get_Stat_From_Binary_File()
{

    system("cls") ;

    ifstream SaveFile ;

    SaveFile.open( "SaveFile.bin",ios::binary ) ;

    // File Does Not Exist
    if( !SaveFile )
    {
        return false ;
    }

    SaveData PlayedGames ;
    SaveFile.read((char*)&PlayedGames,sizeof(SaveData));

    int counter {1} ;

    cout<<"\n\t\t\t All Games \n\n" ;

    while(!SaveFile.eof())
    {
        cout<<" Game ["<<counter<<"]:" ;
        cout<<" "<<PlayedGames.PlayerName ;
        cout<<", Mistakes "<<PlayedGames.Mistakes  ;
        cout<<" / "<<PlayedGames.MaxMistakes ;
        cout<<", "<<PlayedGames.Won ;

        cout<<", "<<PlayedGames.Difficulty ;
        cout<<", "<<fixed<<setprecision(2)<<PlayedGames.Time<<" Minutes "<<endl<<endl ;

        cout<<endl<<endl ;

        SaveFile.read((char*)&PlayedGames,sizeof(PlayedGames));
        counter++ ;
    }

    SaveFile.close();

    return true ;
}

/* All Settings Functions */
/*---------------------------------------*/

bool System::SettingsPage()
{
    system("cls");
    /* Current Game Settings */
    cout<<"\n\n Allowed Mistakes: "<<Settings.first<<endl<<endl ;
    cout<<" Difficulty: "<<Settings.second<<endl<<endl ;
    cout<<" Current Player: "<<CurrentPlayer<<endl<<endl ;

    cout<<" 1- To Change Your Allowed Mistakes Number\n\n";
    cout<<" 2- To Change Your Difficulty\n\n";
    cout<<" 3- To Change Player Name\n\n";
    cout<<" 4- To Change Your Colors\n\n";
    cout<<" 5- To Go Back To Main Menu\n\n" ;
    cout<<" Choice ";
    int choice = validation.ValidateIntegers(1,5) ;

    switch(choice)
    {
        case 1:
        {
            cout<<"\n\n Number Of Maximum Number Of Mistakes ";
            int number = validation.ValidateIntegers(1,9);
            Settings.first = number ;
            break;
        }

        case 2:
        {
            cout<<"\n\n Difficulty You Want: \n\n";
            cout<<" 1- Beginner\n\n";
            cout<<" 2- Expert\n\n ";

            int number = validation.ValidateIntegers(1,2);
            Settings.second  = number == 1 ? "Beginner" : "Expert" ;
            break;
        }

        case 3:
        {
            cout<<"\n\n Player Name ";
            string Name = validation.ValidateStrings(10);
            CurrentPlayer = Name ;

            break;
        }

        case 4:
        {
            colorsSettings();
        }

    }

    return true;
}

bool System::colorsSettings()
{
    /* SetConsoleTextAttribute Changes Incoming Text Color */
    system("cls");

    cout<<"\n All Colors: "<<endl<<endl ;

//   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 );
//   cout<<" 0- Black \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 );
    cout<<" 1- Blue \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout<<" 2- GREEN \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout<<" 3- CYAN \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<" 4- RED \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout<<" 5- MAGENTA \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout<<" 6- BROWN \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout<<" 7- LIGHTGREY \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout<<" 8- DARKGREY \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout<<" 9- LIGHTBLUE \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout<<" 10- LIGHTGREEN \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout<<" 11- LIGHTCYAN \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<" 12- LIGHTRED \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    cout<<" 13- LIGHTMAGENTA \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout<<" 14- YELLOW \n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<" 15- WHITE  \n\n";

    cout<<endl ;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), SystemColors->GetDefaultFontColor() );

    cout<<" 1- To Change Default Font Color \n\n" ;
    cout<<" 2- To Change In Game Number Color \"Numbers In The Sudoku Board\" \n\n" ;
    cout<<" 3- To Back To Main Menu \n\n" ;
    int Choice = validation.ValidateIntegers(1,3);

    if( Choice == 1 )
    {
        cout<<" Color You Want " ;
        int Color = validation.ValidateIntegers(1,15) ;
        SystemColors -> SetDefaultFontColor(Color) ;
    }
    if( Choice == 2 )
    {
        cout<<" The Number You Want To Change Its Color " ;
        int TheNumber = validation.ValidateIntegers(1,9) ;
        int Color = validation.ValidateIntegers(1,15) ;
        SystemColors -> Set_Specific_Number_Color(TheNumber,Color) ;
    }

    system("Pause");

    return true ;
}


void System::Set_Console_Colors()
{
    string Word = "Color " ;
    char Background = SystemColors->GetBackgroundColorAsChar() ;
    char Foreground = SystemColors->GetDefaultFontColorAsChar();

    //Like system("Color 0E") Changing Background And Foreground Color
    system((Word+Background+Foreground).c_str()) ;
}

