
// Name: ¤ý¥¿§»
// Date: May 13, 2022
// Last Update: May 31, 2022
// Problem statement: Template Binary Search
#pragma once

// method of for loop
template <typename T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	found = false;
	for (int mid; first <= last;)
	{
		mid = (first + last) >> 1;
		if (key > a[mid])
		{
			first = mid + 1;
		}
		else if (key < a[mid])
		{
			last = mid - 1;
		}
		else
		{
			found = true;
			location = mid;
			return;
		}
	}
}

// method of call self
template <typename T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	if (first > last)
		return;
	found = false;
	int mid = (first + last) >> 1;
	if (key > a[mid])
	{
		RecBinarySearch(a, mid + 1, last, key, found, location);
	}
	else if (key < a[mid])
	{
		RecBinarySearch(a, first, mid - 1, key, found, location);
	}
	else
	{
		found = true;
		location = mid;
	}
}