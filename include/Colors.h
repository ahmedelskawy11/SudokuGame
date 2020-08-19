#ifndef COLORS_H
#define COLORS_H
#include<iostream>

using namespace std;


class Colors
{
    public:

        static Colors *getInstance()  {

          if (!instance) { instance = new Colors; }

          return instance;
        }

        char Int_To_Char( int Color );

        /*  All Getters And Setters
            Some Functions Need The Color As Char Form Thats Why we Have 2 Getters
        */

        int GetBackgroundColor() { return this -> Background; }
        char GetBackgroundColorAsChar() { return this -> Int_To_Char(Background) ; }
        void SetBackgroundColor(int color) { this -> Background = color; }


        int GetDefaultFontColor() { return this -> DefaultFont; }
        char GetDefaultFontColorAsChar() { return this -> Int_To_Char(DefaultFont); }
        void SetDefaultFontColor(int color) { this -> DefaultFont = color; }

        int Get_Specific_Number_Color(int index) { return this -> Numbers[index-1]; }
        void Set_Specific_Number_Color(int index,int color) { this -> Numbers[index-1] = color; }


    private:
        Colors();
        static Colors *instance;

        int Background ;
        int DefaultFont ;
        int Numbers[9] = {13,3,4,5,7,9,10,11,12} ;
};

#endif // COLORS_H
