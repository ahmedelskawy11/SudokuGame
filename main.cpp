#include<System.h>
#include<Colors.h>

Colors *Colors::instance = 0;
System *System::instance = 0;

int main()
{

    System *mySystem = mySystem -> getInstance();

    mySystem->MainMenu() ;

    delete mySystem ;

    return 0;
}
