// Name: ¤ý¥¿§»
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: Namespace
#include "password.h"

namespace Authenticate
{
    string password;
    void inputPassword()
    {
        do
        {
            cout << "Enter your password (at least 8 characters " <<
                "and at least one non-letter)" << endl;
            cin >> password;
        } while (!isValid());
    }

    string getPassword()
    {
        return password;
    }
}

namespace
{
    bool isValid()
    {
        if (Authenticate::password.size() < 8)
            return false;
        for (const auto& c : Authenticate::password)
        {
            if (!isalpha(c))
                return true;
        }
        return false;
    }
}