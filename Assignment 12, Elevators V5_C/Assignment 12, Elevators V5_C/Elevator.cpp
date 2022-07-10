// "Programmer: Yu-Yuan Chang\n"
 //"Programmer's ID: 1690647\n"

#include "Elevator.h"
#include "Panel.h"
#include"Building.h"

#include <iostream>
#include <vector>
using namespace std;

#include <cstdlib>

Elevator::Elevator(unsigned int capacity, int speed, int start)
    : CAPACITY(capacity), direction(IDLE), timer(0), speed(speed), atFloorIndex(-1), location(Building::floors[start])
{
    start = Building::floors[start];

    //panel.addButton(start);  How do I add?
    for (int i = 0; i < Building::FLOORS; i++)
    {
        panel.addButton(Building::floors[i].label);
    }
}

ostream& operator<<(ostream& out, const Elevator& a)
{
    out.width(5);
    out << "Elevator at ";
    out.width(5);
    out << a.location;

    out.width(11);
    switch (a.direction)
    {
    case 1:
        cout << "going up";
        break;

    case -1:
        cout << "going DOWN";
        break;

    case 0:
        cout << "IDLE";
        break;
    }

    out.width(3);
    out << a.riders.size() << " riders";

    out.width(16);
    if (a.atFloorIndex != -1)
    {
        out << " door is OPEN|" << a.timer << " " << a.panel;
    }
    else
    {
        out.width(15);
        out << a.panel;
    }


    return out;
}
void Elevator::openDoorTo(int x)
{
    panel.clear(Building::floors[x].label); // an element of floor array? Can't access
    atFloorIndex = x;
    resetTimer();
}
void Elevator::board(const Rider& x)
{

    riders.push_back(x);
    panel.press(Building::floors[x.to].label); //x.to.label Data type is not correct int / string
    if (x.goingUp == true)
    {
        // Elevator::UP;
        this->direction = Elevator::UP;

    }
    else
    {
        this->direction = Elevator::DOWN;
    }
    resetTimer();
}
bool Elevator::hasRiderForFloor() const
{
    if (atFloorIndex == -1)
    {
        return false;
    }
    for (int i = 0; i < riders.size(); i++)
    {
        if (riders[i].to == atFloorIndex)
        {
            return true;
        }
    }
    return false;


}

void Elevator::removeRider()
{
    for (int i = 0; i < riders.size(); i++)
    {
        if (riders[i].to == atFloorIndex && !riders.empty())
        {
            riders.erase(riders.begin() + i);
            panel.clear(Building::floors[i].label);
            resetTimer();
            break;

        }
    }
}
bool Elevator::closeDoor()
{
    if (atFloorIndex == -1) return false;

    if (this->goingUp() && !Building::floors[atFloorIndex].hasUpRider()) //how to access floor hasUpriders()
    {
        Building::floors[atFloorIndex].panel.clear(Floor::UP); //where to use atfloorIndex?
    }
    else if (this->goingDown() && !Building::floors[atFloorIndex].hasDownRider()) // how to acess Floor hasDownrider()
    {
        Building::floors[atFloorIndex].panel.clear(Floor::DOWN);
    }

    atFloorIndex = -1;
    return true;
}

bool Elevator::move()
{
    int temp;
    temp = this->location;

/*
    if (this->goingUp())
    {
        this->location = this->location + speed;
    }
    else if (this->goingDown())
    {
        this->location = this->location - speed;
    }
 */   
    /**/
     if (this->goingUp())
        {
        for (int i = 0; i < Building::FLOORS; i++)
        {
            if (Building::floors[i].elevation > this->location)
            {
                if (Building::floors[i].elevation <= this->location + speed )
                {
                    
                    if (Building::floors[i].panel.isLit(Floor::UP) || this->panel.isLit(Building::floors[i].label))
                    {   
                       
                        this->location = Building::floors[i].elevation; //this->location + speed; //where to put this?
                        this->openDoorTo(i);
                        return true; 
                    }
                    
                }
            }
           
        }
        if (Building::floors[Building::FLOORS - 1].elevation != this->location)
        {
            if (Building::floors[Building::FLOORS - 1].elevation <= this->location + speed)
            {
                this->location = Building::floors[Building::FLOORS - 1].elevation;
                this->atFloorIndex = Building::FLOORS - 1;
                return false;
            }
            else
            {
                this->location += speed;
                return true;
            }

        }
       

     }
     else if (this->goingDown())
     {
            for (int i = 0; i < Building::FLOORS; i++)
            {
                if (Building::floors[i].elevation < this->location)
                {
                    
                    if (Building::floors[i].elevation > this->location - speed  )
                    {
                        
                            if (this->panel.isLit(Building::floors[i].label) || Building::floors[i].panel.isLit(Floor::DOWN)) //how to do this?
                            {
                                this->location = Building::floors[i].elevation;
                                this->openDoorTo(i);
                                return true;
                            }

                            
                    }
                    
                }
            }
            if (Building::floors[0].elevation != this->location )
            {
               if (Building::floors[0].elevation >= this->location - speed)
               {
                this->location = Building::floors[0].elevation;
                this->atFloorIndex = -1;
                return false;
               }

            else
                {
                this->location -= speed;
                return true;
                } 

            }
            
     }   

     
    if (temp != this->location)
    {
        return true;
    }
    else
    {
        return false;
    }

}
void Elevator::goIdle()
{
    this->direction = IDLE;
    this->closeDoor();
} 
void Elevator::setDirectionUp()
{
    this->direction = UP;
}
void Elevator::setDirectionDown()
{
    this->direction = DOWN;
}
