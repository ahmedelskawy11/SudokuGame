#include "Validations.h"


Validations::Validations()
{
    // Cout<<"Creating Validation Object
}

int Validations::ValidateIntegers(int LowerBound, int UpperBound)
{
    int ValidInput ;
    bool loopBreaker = false ;
    cin.exceptions(std::istream::failbit);

    do
    {
        try
        {
            cout <<"Input: " ;
            cin >> ValidInput;
            cout<<endl;
            if( ValidInput <= UpperBound && ValidInput >= LowerBound  )
            {
                loopBreaker = true ;
            }
            else
            {
                cout << "\nOut of Boundaries, Please Insert It Again.\n\n";
            }
        }
        catch (std::ios_base::failure &fail)
        {
            loopBreaker = false;
            cout <<"\n\nInvalid Input, Please Insert It Again.\n\n";
            cin.clear();
            std::string IgnoredString;
            getline(cin, IgnoredString);

        }

    }
    while(loopBreaker == false );


    cin.clear();
    std::string IgnoredString;
    getline(cin, IgnoredString);

    return ValidInput;
}

string Validations::ValidateStrings(int MaxLength )
{
    string ValidInput ;

    int NameLength ;
    bool loopBreaker = false ;
    do
    {
        cout<<"Input: " ;
        getline(cin,ValidInput);

        NameLength = ValidInput.length();

        if( NameLength <= MaxLength ) { loopBreaker = true ;}
        else { cout << "\nMore Than Maximum Length, Please Insert It Again.\n\n"; }


    }
    while(loopBreaker == false );

    return ValidInput ;
}

