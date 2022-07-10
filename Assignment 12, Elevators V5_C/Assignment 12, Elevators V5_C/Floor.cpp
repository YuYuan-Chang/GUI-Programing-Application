// "Programmer: Yu-Yuan Chang\n"
 //"Programmer's ID: 1690647\n"

#include "Floor.h"
#include "Rider.h"
#include "Building.h"
//#include "Panel.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <climits>

const char* const Floor::UP = "Up";
const char* const Floor::DOWN = "Down";
int Floor::TOP = INT_MIN; // defined in climits
int Floor::BOTTOM = INT_MAX; // also in climits

Floor::Floor(const int elevation, const char* const name, const char* const label)
:elevation(elevation),name(name), label(label)
{
  
	panel.addButton(UP);
	panel.addButton(DOWN);
	
	
  if (TOP < elevation) TOP = elevation;
  if (elevation < BOTTOM) BOTTOM = elevation;

}

ostream& operator<<(ostream& out, const Floor& floor)
{
	out.width(3);
	out << floor.label;
	out.width(15);
	out << floor.name << " at";
	out.width(6);
	out << floor.elevation << "\" UP/Down: ";
	out.width(4);
	//out << floor.upRiders.size() << "/" << floor.downRiders.size() << "   BUtton: " << floor.panel;
	out << floor.upRiders.size() << "/" << floor.downRiders.size() << "   Button: ";
	out << floor.panel;
  return out;
}
void Floor::addRider(const Rider& r)
{
	if (r.goingDown == true)
	{
		panel.press(DOWN);
		downRiders.push(r);
	}
	else
	{
		panel.press(UP);
		upRiders.push(r);
	}

}

Rider Floor::removeUpRider()
{
	if (upRiders.empty())
	{
		throw new string("upRiders is empty!");
	}
	Rider a = upRiders.front();
	upRiders.pop();
	return a;


}
Rider Floor::removeDownRider()
{
	if (downRiders.empty())
	{
		throw new string("upRiders is empty!");
	}
	Rider a = downRiders.front();
	downRiders.pop();
	return a;


}