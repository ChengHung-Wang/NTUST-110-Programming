// Name: ¤ý¥¿§»
// Date: May 10, 2022
// Last Update: May 10, 2022
// Problem statement: Class Inheritance
#pragma once
#include "Document.h"
class File :
    public Document
{
private:
    std::string pathname;
public:
    File(std::string, std::string);
    File& operator=(const File&);
    void setPathname(std::string);
    std::string getPathname() const;
};
