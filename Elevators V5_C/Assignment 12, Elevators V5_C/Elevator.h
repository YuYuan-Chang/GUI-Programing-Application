// "Programmer: Yu-Yuan Chang\n"
 //"Programmer's ID: 1690647\n"

#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
using namespace std;

#include "Rider.h"
#include "Floor.h"


#include "Panel.h"

class Elevator
{
  static const int IDLE = 0; 
  static const int UP = 1;
  static const int DOWN = -1;
  static const int COURTESY_WAIT_TIME = 3;

  // elevator metrics
  int location; // inches above ground level
  int direction; // equal to IDLE, UP, DOWN
  int atFloorIndex;
  int timer;

  vector<Rider> riders;
  
  public:
  Elevator(unsigned int, int, int);
  operator int() const {return location;}

  Panel panel;
  const int speed; // inches per second, up or down
  const unsigned int CAPACITY; 
  
  // count-down timer before closing door
  void resetTimer() {timer = 3;}
  void tickTimer() {timer--;}
  bool timedOut() const {return timer == 0;}
  
  bool isOpen() const {return atFloorIndex >= 0;}
  void openDoorTo(int); // parameter is index in Building::floors array
  void board(const Rider&); // adds a Rider to the Elevator
  
  bool hasRiderForFloor() const;
  void removeRider();
  bool isFull() const {return CAPACITY == riders.size();}
  bool goingUp() const {return direction == UP;}
  bool goingDown() const {return direction == DOWN;}
  int getFloorIndex() const {return atFloorIndex;}
  unsigned int getNumberOfRiders() const {return riders.size();}

  // Below are nwe function
  bool isIdle() const { return direction == IDLE; }
  bool closeDoor();
  bool move();
  void goIdle();
  void setDirectionUp();
  void setDirectionDown();

  // friend function
  friend ostream& operator<<(ostream&, const Elevator&); 
};

#endif