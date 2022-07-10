// "Programmer: Yu-Yuan Chang\n"
 //"Programmer's ID: 1690647\n"

#include "Rider.h"
#include "Building.h"

Rider::Rider(int x, int y) : from(x), to(y),
goingDown((Building::floors[to] < Building::floors[from] ? true : false)),
	goingUp((Building::floors[to] > Building::floors[from] ? true : false))
{
	
}

Rider& Rider::operator=(const Rider& copyThis)
{

	Rider& host = *this;
	if (this != &copyThis)
	{
		const_cast<int&>(host.from) = copyThis.from;
		const_cast<int&>(host.to) = copyThis.to;
		const_cast<bool&>(host.goingUp) = copyThis.goingUp;
		const_cast<bool&>(host.goingDown) = copyThis.goingDown;
	}
	return host;
}