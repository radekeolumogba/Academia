// Ping Pong Game Implementation: Source File
#include <iostream>
#include <vector>
#include <cmath>
#include "PingPong_Header.h"
#include "mbed.h"

using namespace std;

int n; // random variable for testing purposes

void PingPong::LED_StateMachine(int n) // routine to play game
{
    // Instatiating the pushbuttons which cause transition from LED State to LED State (left or right movement)
    DigitalIn L(p18); // left movement from pushbutton, pin16
    DigitalIn R(p15); // right movement from pushbutton, pin15
    BusIn T(p8); // pin8

    // Activating the buttons: high by default, therefore press initiates movement (pull pin low).
    L.mode(PullUp); 
    R.mode(PullUp);
    wait_us(1); // wait for 1 us as path to ground is established.

    
    
    //now wait for a change in state of the buttons
    bool GETOUT = false; // no change in state
    while (!GETOUT) // while there is a change in state
    {
        if (!L || n == 1) //left button pressed
        { 
            GETOUT = true; // there is a change in the state of button
            int LEDs; // instantiate the state for LEDs
            switch (LEDs) // start the left-directioned transition of lighting one after the other
            {
                case led0:
                    cout << led0 << endl << endl; // for test bench purposes to identify successful entry into LED State
                case led1:
                    cout << led1 << endl << endl; // for test bench purposes
                case led2:
                    cout << led2 << endl << endl; // for test bench purposes
                case led3:
                    cout << led3 << endl << endl; // for test bench purposes
                    break; // out of switch block
                default:
                    led0;
                    cout << "inside the default state setting" << endl << endl; // for test bench purposes 
            }
            
        }//
        
        if (!R || n == 4) //right button pressed
        {
            GETOUT = true; // there is a change in state of button
            int LEDs; // instantiate the state for LEDs
            switch (LEDs) // start the right-directioned transition of lighting one after the other
            {
                case led3:
                    cout << led3 << endl << endl; // for test bench purposes to identify successful entry into LED State
                case led2:
                    cout << led2 << endl << endl; // for test bench purposes
                case led1:
                    cout << led1 << endl << endl; // for test bench purposes
                case led0:
                    cout << led0 << endl << endl; // for test bench purposes
                    break; // out of switch block
                default:
                    led3;
                    cout << "inside the default state setting" << endl << endl; // for test bench purposes 
            }
            
        } 
    } //end while loop
    

};

void PingPong::Game_StateMachine(int nL) // To play the game
{
    // Instatiating the pushbuttons which cause transition from LED State to LED State (left or right movement)
    DigitalIn L(p16); // left movement from pushbutton, pin16
    DigitalIn R(p15); // right movement from pushbutton, pin15

    // Activating the buttons: high by default, therefore press initiates movement (pull pin low).
    L.mode(PullUp); 
    R.mode(PullUp);
    wait_us(1); // wait for 1 us as path to ground is established.

  //now wait for a change in state of the buttons
    bool GETOUT = false; // no change in state
    while (!GETOUT) // while there is a change in state
    {
        if (!L || n == 1) //left button pressed
        { 
            GETOUT = true; // there is a change in the state of button
            int State; // instantiate the state for LEDs
            switch (State) // start the left-directioned transition of lighting one after the other
            {
                case Ball_move_left:
                    LED_StateMachine(n); // activate state machine for movement
                    cout << "moving left state " << endl << endl; // for test bench purposes to identify successful entry into LED State
                case Correct_Return:
                    cout << "checking for correct return or not " << endl << endl; // for test bench purposes
                    break;
                default:
                     start;
                    cout << "inside the default state setting" << endl << endl; // for test bench purposes 
            }
            
        }//
        
        if (!R || n == 4) //right button pressed
        {
            GETOUT = true; // there is a change in the state of button
            int State; // instantiate the state for LEDs
            switch (State) // start the left-directioned transition of lighting one after the other
            {
                case Ball_move_right:
                    LED_StateMachine(n); // activate state machine for movement
                    cout << "moving right state " << endl << endl; // for test bench purposes to identify successful entry into LED State
                case Correct_Return:
                    cout << "checking for correct return or not " << endl << endl; // for test bench purposes
                    break;
                default:
                     start;
                    cout << "inside the default state setting " << endl << endl; // for test bench purposes 
            }
            
        } 
    } //end while loop

};
     


	
	//	vector<bool> PingPong::flash_winner(bool clk)
		//{
			//while (clk)
			//{
				//if ((score[0] > score[1]) && (score[0] == 5))
					//led[0], led[1], led[2], led[3], led[4];
				//else if ((score[1] > score[0]) && (score[1] == 5))
					//led[7], led[6], led[5], led[4], led[3];
				

			//}
			

		//}
		

		// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
		// Debug program: F5 or Debug > Start Debugging menu

		// Tips for Getting Started: 
		//   1. Use the Solution Explorer window to add/manage files
		//   2. Use the Team Explorer window to connect to source control
		//   3. Use the Output window to see build output and other messages
		//   4. Use the Error List window to view errors
		//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
		//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
