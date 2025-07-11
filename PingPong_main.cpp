// PingPong_main.cpp : This is the executable
//
#include "mbed.h"
#include <iostream>
#include "PingPong_Header.h"

using namespace std;

int main() {
	while (true)
	{
        int n = 1; // Test left movement
        PingPong Game; // Start the game

        Game.Game_StateMachine(n); // start left movement

        n = 4; // Test right movement
        Game.Game_StateMachine(n); // start right movement
		
	}
}