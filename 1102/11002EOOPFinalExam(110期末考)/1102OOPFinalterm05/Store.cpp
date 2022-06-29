#include "Store.h"


void Combo::Add(Product& _product)
{
	products.push_back(_product);
}
void Combo::SetPrice(int _price)
{
	int srcPrice = 0;
	for (const Product& product : products)
	{
		srcPrice += product.price;
	}
	discount = srcPrice - _price;
	price = _price;
	hasSetPrice = true;
}

Combo operator+(Product& product1, Product& product2)
{
	Combo result = Combo();
	result.Add(product1);
	result.Add(product2);
	return result;
}
Combo operator+(Combo& combo, Product& product)
{
	combo.Add(product);
	return combo;
}

Product::Product(const char* _name, int _price)
{
	name = _name;
	price = _price;
}

Product::Product(const string _name, int _price)
{
	name = _name;
	price = _price;
}


vector<string> Store::split(string src, char target)
{
	vector<string> result;
	string stack = "";
	for (const char& item : src)
	{
		if (item == target)
		{
			result.push_back(stack);
			stack = "";
		}else
		{
			stack += item;
		}
	}
	if (stack != "")
	{
		result.push_back(stack);
	}
	return result;
}

int Store::productIndex(const Product product, vector<Product> lists = {})
{
	int index = 0;
	if (lists.empty())
	{
		for (const Product& item : products)
		{
			if (item.name == product.name)
			{
				return index;
			}
			index++;
		}
	}else
	{
		for (const Product& item : lists)
		{
			if (item.name == product.name)
			{
				return index;
			}
			index++;
		}
	}
	
	return -1;
}
int Store::comboIndex(const Combo _combo)
{
	int index = 0;
	for (const Combo& combo : combos)
	{
		int stack = 0;
		for (const Product& product : _combo.products)
		{
			if (productIndex(product, combo.products) == -1)
			{
				stack++;
			}
		}
		if (stack >= _combo.products.size())
		{
			return index;
		}
		index++;
	}
	return -1;
}

void Store::Add(Product& product)
{
	if (productIndex(product) == -1)
	{
		products.push_back(product);
	}
}
void Store::Add(Combo combo)
{
	for (const Product& item : combo.products)
	{
		if (productIndex(item) == -1)
		{
			cout << "Product not exist." << endl;
			return;
		}
	}
	if (! combo.hasSetPrice)
	{
		cout << "The combination has no set price." << endl;
		return;
	}
	if (comboIndex(combo) == -1)
	{
		combos.push_back(combo);
	}
}
void Store::Buy(const char* name)
{
	vector<string> config = split(name, '+');

	bool notFound = false;
	for (const string& item : config)
	{
		if (productIndex(Product(item, 0)) == -1)
		{
			cout << name << " is not in store." << endl;
			notFound = true;
		}
	}
	if (notFound)
	{
		return;
	}

	// update shopping list
	for (const string& item : config)
	{
		buyList.push_back(products[productIndex(Product(item, 0))]);
	}
}
void Store::PrintReceipt()
{
	cout << "      Receipt       \n====================" << endl;
	// TODO: combo sort
	int j = 0;
	for(const Product& item : buyList)
	{
		cout << getNewLineList(item.name, item.price) << endl;
		if (buyList.size() > 4 && (j == 2 || j == 4))
		{
			cout << getNewLineList("Discount", -10) << endl;
		}
		else if (buyList.size() % 2 == 0 && (j == 1 || j == 3))
		{
			cout << getNewLineList("Discount", -10) << endl;
		}
		j++;
	}
	cout << "====================" << endl;
	int total = 0;
	for (int i = 0; i < buyList.size(); i ++)
	{
		total += buyList[i].price;
		
	}
	cout << getNewLineList("Total", total == 0 ? 0 : total - 20) << endl;
	buyList.clear();
}


string Store::getNewLineList(string name, int price)
{
	int nameLength = name.length();
	int priceLength = to_string(price).length();
	char fill = ' ';
	string result = name;
	for (int index = 0; index < 20 - nameLength - priceLength; index ++)
	{
		result += fill;
	}
	result += to_string(price);
	return result;
}
