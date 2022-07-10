// "Programmer: Yu-Yuan Chang\n"
 //"Programmer's ID: 1690647\n"

#include"Panel.h"
#include <vector>

int Panel::Button::count = 0;

ostream& operator<<(ostream& out, const Panel& a)
{
	//out << "instructor "<< a.buttons.size() << " " << Panel::Button::count;
	for (int i = 0; i < a.buttons.size(); i++)
	{
		if (a.buttons[i].lit) {
			cout << "[" << a.buttons[i].label << "]";
		}
	}
	return out;
}


void Panel::addButton(string a)
{
	Button x;
	x.label = a;
	x.lit = false;
	buttons.push_back(x);
}
void Panel::press(string a) //fix
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i].label == a)
		{
			if (buttons[i].lit == false)
			{
				buttons[i].lit = true;
				buttons[i].sequence = Panel::Button::count;
				Panel::Button::count = Panel::Button::count + 1;
			}
		}
	}
}
void Panel::clear(string a)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i].label == a)
		{
			buttons[i].lit = false;
			Panel::Button::count--;
		}
	}

}
string Panel::getFirstLit() const //Fix
{
	//Button temp = buttons[0];
	/*
	Button temp;
	temp.sequence = 1;
	for (int i = 0; i < buttons.size(); i++)
	{

		if (temp.sequence < buttons[i].sequence && buttons[i].lit == true)
		{
			temp.label = buttons[i].label;
		}
	
	}
	

	return temp.label;
*/

	Button first;
	bool litting = false;
	first = buttons[0];
	for (unsigned int i = 0; i < buttons.size(); ++i)
	{
		if (buttons[i].lit && first.sequence > buttons[i].sequence)
		{
			first = buttons[i];
			litting = true;
		}
	}
	return litting ? first.label : "";

}
bool Panel::isLit(string a)const
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i].label == a)
		{
			if (buttons[i].lit == true)
			{
				return true;
			}
		}

	}
	return false;
}
bool Panel::areAnyLit() const
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i].lit == true)
		{
			return true;
		}
	}
	return false;
}