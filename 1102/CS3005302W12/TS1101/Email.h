// Name: ������
// Date: May 10, 2022
// Last Update: May 10, 2022
// Problem statement: Class Inheritance
#pragma once
#include "Document.h"
class Email :
    public Document
{
private:
    std::string title;
    std::string sender;
    std::string recipient;
public:
    Email(std::string, std::string, std::string, std::string);
    Email& operator=(const Email&);
    void setTitle(std::string);
    void setSender(std::string);
    void setRecipient(std::string);
    std::string getTitle() const;
    std::string getSender() const;
    std::string getRecipient() const;
};
