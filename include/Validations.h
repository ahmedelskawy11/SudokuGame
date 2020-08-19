#ifndef VALIDATIONS_H
#define VALIDATIONS_H
#include<iostream>

using namespace std ;
class Validations
{
    public:
        Validations();

        int ValidateIntegers(int LoweBound , int UpperBound);
        string ValidateStrings(int Length );
};

#endif // VALIDATIONS_H
