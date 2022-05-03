// Name: ¤ý¥¿§»
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: Namespace
#include <iostream>

#include "user.h"
#include "password.h"
using namespace std;
using namespace Authenticate;

int main()
{
    inputUserName();
    inputPassword();
    cout << "Your username is " << getUserName() <<
        " and your password is: " <<
        getPassword() << endl;
    return 0;
}