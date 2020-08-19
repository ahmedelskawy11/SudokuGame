#include "Board.h"


Board::Board()
{
    Assign_Numbers_To_The_Board();
}

Board::Board(const Board& otherObject)
{
    for(int r = 0 ; r < 9 ; r ++)
    {
        for(int c = 0 ; c < 9 ; c++)
        {
            board[r][c] = otherObject.board[r][c] ;
        }
    }
}

bool Board::Assign_Numbers_To_The_Board()
{
    int RandomNumbers[9] = {0} ;

    //Random_Numbers_Generator(int *Array  , int Length ,int LowerBound , int UpperBound)

    Random_Numbers_Generator(RandomNumbers,9,1,9);

    /* We Created Random Array[9] and then we will divide it into 3 Array [3]
    to create a block
    [1,2,3]
    [4,5,6]
    [7,8,9]
    but in Random Form
    */

    int Layers = 0 ;

    /*
     We Divided The Matrix to 3 Layers
     Each Layer Has 3 Blocks in A Row
     every Block is a 3 * 3 matrix
     */

    while( Layers < 3)
    {

        int  CurrentIndex = 9 - (Layers * 3);

        int One_Third_Of_Randoms[3] = {0} ;

        for(int i = 0 ; i<3 ; i++)
        {
            One_Third_Of_Randoms[i] = RandomNumbers[i + ( Layers * 3 )] ;
        }

        for(int i = 0 ; i<9 ; i ++ )
        {

            if(CurrentIndex == 9) { CurrentIndex = 0 ;}

            if(i % 3 == 0 )
            {
                board[i][CurrentIndex++] = One_Third_Of_Randoms[0] ;
                board[i][CurrentIndex++] = One_Third_Of_Randoms[1] ;
                board[i][CurrentIndex++] = One_Third_Of_Randoms[2] ;
            }

            if(i % 3 == 1 )
            {

                board[i][CurrentIndex++] = One_Third_Of_Randoms[0] ;
                board[i][CurrentIndex++] = One_Third_Of_Randoms[1] ;
                board[i][CurrentIndex++] = One_Third_Of_Randoms[2] ;
            }

            if(i % 3 == 2 )
            {
                board[i][CurrentIndex++] = One_Third_Of_Randoms[0] ;
                board[i][CurrentIndex++] = One_Third_Of_Randoms[1] ;
                board[i][CurrentIndex++] = One_Third_Of_Randoms[2] ;
                Shifting_An_Array_To_The_Right(One_Third_Of_Randoms,3,1) ;
            }
        }
        Layers++ ;
    }
    return true ;
}

bool Board::Random_Numbers_Generator(int Array[], int Length,int LowerBound, int UpperBound)
{
    srand(time(0));

    int random = rand() % UpperBound + LowerBound ;

    int counter = 0 ;

    if( Length == 0 ) { Array [0] = random ; }

    while(counter < Length)
    {
        random = rand() % UpperBound + LowerBound ;

        if(is_Found_In_The_Array(Array,9, random))
        {
            continue ;
        }
        Array[counter] = random ;
        counter++ ;
    }

    return true ;
}

bool Board::is_Found_In_The_Array(int Array[], int Length, int Value)
{
    for(int i  = 0 ; i < Length ; i++)
    {
        if(Array[i] == Value )
        {
            return true ;
        }
    }

    return false ;
}

bool Board::Shifting_An_Array_To_The_Right(int Array[], int Length, int ElementsToShift)
{
    if(ElementsToShift == 0)
    {
        return false ;
    }

    int temp[ElementsToShift] ;

    for(int i = 0 ; i < ElementsToShift ; i++)
    {
        temp[i] = Array[ (Length - ElementsToShift) + i ] ;
    }

    for(int i= Length-1 ; i - ElementsToShift >= 0 ; i-- )
    {
        Array[i] = Array[i-ElementsToShift] ;
    }

    for( int i = 0 ; i<ElementsToShift ; i++)
    {
        Array[i] = temp[i] ;
    }

    return true ;
}


void Board::Printing_The_Full_Board ()
{
    cout<<endl<<endl;
    cout<<"        \t  \t\t\t\t  Sudoku Game\n\n\n";

    for(int i = 0 ; i< 9 ; i++)
    {
        if( i % 3 == 0 ){ cout<<endl ;}
        Printing_A_Single_Row(i);
    }

    cout<<endl<<endl ;
}

void Board::Printing_A_Single_Row(int RowNumber)
{
    // upper Bound
    if(RowNumber==0)
    {
        cout<<"        \t  \t\t";
        cout<<"  "<<1<<"  ";
        cout<<"  "<<2<<"  ";
        cout<<"  "<<3<<"  ";
        cout<<"\t" ;
        cout<<"  "<<4<<"  ";
        cout<<"  "<<5<<"  ";
        cout<<"  "<<6<<"  ";
        cout<<"\t" ;
        cout<<"  "<<7<<"  ";
        cout<<"  "<<8<<"  ";
        cout<<"  "<<9<<"  ";
        cout<<endl<<endl;
    }

    cout<<"        \t  \t\t";
    cout<<" --- ";
    cout<<" --- ";
    cout<<" --- ";
    cout<<"\t" ;
    cout<<" --- ";
    cout<<" --- ";
    cout<<" --- ";
    cout<<"\t" ;
    cout<<" --- ";
    cout<<" --- ";
    cout<<" --- ";
    cout<<endl ;
    //Row Numbers
    cout<<"Row "<<RowNumber+1;
    cout<<"        \t  \t\t";
    for(int i = 0 ; i <9 ; i++)
    {
        if( i % 3 == 0 && i!=0 ){cout<<"\t";}

        cout<<"| ";
        Changing_The_Text_Color(board[RowNumber][i]) ;

        cout<<board[RowNumber][i];

        Changing_The_Text_Color(-1) ;

        cout<<" |";
    }


    cout<<endl;
    //LowerBound
    cout<<"        \t  \t\t";
    cout<<" --- ";
    cout<<" --- ";
    cout<<" --- ";
    cout<<"\t" ;
    cout<<" --- ";
    cout<<" --- ";
    cout<<" --- ";
    cout<<"\t" ;
    cout<<" --- ";
    cout<<" --- ";
    cout<<" --- ";
    cout<<endl;
}

void Board::Changing_The_Text_Color(int Number)
{
    Colors *Current_System_Colors = Current_System_Colors -> getInstance() ;
    // Empty Cells Color
    int Color_To_Change;

    // Default Font

    if( Number == 0 ) { Color_To_Change = Current_System_Colors -> GetBackgroundColor() ;}

    else if(Number == -1){ Color_To_Change = Current_System_Colors -> GetDefaultFontColor() ;}

    else {Color_To_Change = Current_System_Colors -> Get_Specific_Number_Color( Number ) ;}

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_To_Change);
}

/* For Player Board */
bool Board::Changing_Random_Cells_To_Zeros(char Difficulty)
{
    system("cls") ;
    int Row = 0 ;

    cout<<"\n\t\t\t\t\t\t  Loading" ;
    while(Row<9)
    {
        Changing_Random_Cells_To_Zeros_In_Row(Row,Difficulty) ;
        if( Row%3 == 0){cout<<"." ;}
        Row++ ;
    }

    Sleep(200) ;
    system("cls") ;
    return true ;
}

bool Board::Changing_Random_Cells_To_Zeros_In_Row(int Row , char Difficulty )
{
    srand(time(0));

    int LowerBound = Difficulty == 'B' ? 1 : 3 ;

    Sleep(500) ;

    int Empty_Cells_In_The_Row = rand() % 3 + LowerBound ;

    int RandomArray[Empty_Cells_In_The_Row] ;

    Random_Numbers_Generator(RandomArray,Empty_Cells_In_The_Row,1,8) ;

    for(int i = 0 ; i < Empty_Cells_In_The_Row ; i++)
    {
        board[Row][RandomArray[i]] = 0 ;
        EmptyCells++ ;
    }


    return true ;
}
