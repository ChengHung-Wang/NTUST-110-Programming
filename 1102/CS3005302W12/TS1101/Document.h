// Name: ¤ý¥¿§»
// Date: May 10, 2022
// Last Update: May 10, 2022
// Problem statement: Class Inheritance
#pragma once
#include <string>
class Document
{
protected:
	std::string text;
public:
	Document(std::string);
	void setText(std::string);
	std::string getText() const;
	Document& operator=(const Document&);
};
