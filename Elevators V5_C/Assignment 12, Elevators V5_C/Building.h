// "Programmer: Yu-Yuan Chang\n"
 //"Programmer's ID: 1690647\n"

#ifndef BUILDING_H
#define BUILDING_H

#include "Floor.h"
#include "Elevator.h"

struct Building
{
  static Floor floors[];
  static Elevator elevators[];
  static const int FLOORS; //array size
  static const int ELEVATORS;

  // helper functions
  static void getDifferentInts(int&, int&);
  static int getPoisson(double);
  static void placeNewRiders(double);
  
  static bool disembarkRider(int); // parameter is an elevator's index
  static bool boardRider(int); // parameter is an elevator's index

  // actions
  static void action(double); // the main "action function"
  static bool openDoorToDisembarkRider(int); // step 1 of 9

  //Blow are new function
  static bool waitingForMoreRiders(int);
  static bool doneWaitingMove(int);
  static bool moveableMove(int);
  static bool setIdleElevatorInMotion(int);
  static bool sendIdleElevatorToCallingFloor(int);
};
#endif