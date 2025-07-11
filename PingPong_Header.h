#pragma once
// PingPong_Header.h : This is the header file
//
#include "mbed.h"
#include <iostream>
#include <vector>
using namespace std;

class PingPong
{
	// Declaring or Defining states, inputs and outputs
	private: // data members, which are the states (Moore)
		enum State {start=1, Ball_move_left, Ball_move_right, Correct_Return}; // defining states
		enum LEDs {led0=1, led1, led2, led3}; // defining states for LED movement, there are 4 LEDs on the ARM mbed microcontroller
		
	public: // data functions
        void Game_StateMachine(int nL); // To play the game
        void LED_StateMachine(int nL); // to access the LED states
        
        

};
