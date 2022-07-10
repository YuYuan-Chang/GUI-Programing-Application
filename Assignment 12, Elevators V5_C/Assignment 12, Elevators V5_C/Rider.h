// "Programmer: Yu-Yuan Chang\n"
 //"Programmer's ID: 1690647\n"
#pragma  once

struct Rider
{
	const int from, to;
	Rider(int, int);
	Rider& operator=(const Rider&);
	const bool goingUp;
	const bool goingDown;
};

