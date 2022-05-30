// Name: ¤ý¥¿§»
// Date: May 10, 2022
// Last Update: May 10, 2022
// Problem statement: Class Inheritance
#pragma once
#include "File.h"

File::File(std::string text, std::string pathname) :Document(text)
{
	this->pathname = pathname;
}

File& File::operator=(const File& file)
{
	this->text = file.text;
	this->pathname = file.pathname;
	return *this;
}

void File::setPathname(std::string pathname)
{
	this->pathname = pathname;
}

std::string File::getPathname() const
{
	return pathname;
}