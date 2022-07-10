// "Programmer: Yu-Yuan Chang\n"
 //"Programmer's ID: 1690647\n"

#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <ostream> 
#include <algorithm>
#include<set>
#include <sstream>

using namespace std;

class Panel
{
	struct  Button
	{
		string label;
		bool lit;
		int sequence;
		static int count;
	};
	vector<Button> buttons;


public:
	void addButton(string);
	void press(string);
	void clear(string);
	string getFirstLit() const;
	bool isLit(string) const;
	bool areAnyLit() const;
	friend ostream& operator<<(ostream&, const Panel&);



};
//int Panel::Button::count = 1;
