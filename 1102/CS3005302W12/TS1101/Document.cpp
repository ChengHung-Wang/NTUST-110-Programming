// Name: ¤ý¥¿§»
// Date: May 10, 2022
// Last Update: May 10, 2022
// Problem statement: Class Inheritance
#pragma once
#include "Document.h"

Document::Document(std::string text)
{
	this->text = text;
}

void Document::setText(std::string text)
{
	this->text = text;
}

std::string Document::getText() const
{
	return text;
}

Document& Document::operator=(const Document& doc)
{
	this->text = doc.text;
	return *this;
}