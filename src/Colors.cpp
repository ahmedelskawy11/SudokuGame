#include "Colors.h"

Colors::Colors()
{
    Background = 0;
    DefaultFont = 14;
}

char Colors::Int_To_Char( int Color )
{
    char Color_Char ;

    if(Color <= 9) { Color_Char = 48 + Color ;}

    if(Color <= 15 && Color >= 10  ) { Color_Char = 55 + Color ; }
    return Color_Char ;

}
