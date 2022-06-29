#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product
{
public:
	string name;
	int price;
	Product(const char* name, int price);
	Product(string, int price);
};
class Combo
{
public:
	Combo() {};
	void Add(Product& product);
	void SetPrice(int price);
	int price, discount = 0;
	bool hasSetPrice = false;
	vector<Product> products;
};

Combo operator+(Product&, Product&);
Combo operator+(Combo&, Product&);

class Store
{
public:
	void Add(Product& product);
	void Add(Combo combo);
	void Buy(const char* name);
	void PrintReceipt();
	int productIndex(const Product, vector<Product>);
	int comboIndex(const Combo);
	vector<string> split(string, char);
private:
	vector<Product> products;
	vector<Combo> combos;
	vector<Product> buyList;
	string getNewLineList(string, int);
};