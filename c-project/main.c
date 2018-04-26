/*
 * c-project.c
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <util/delay.h>
#include "atmega2560_drivers.h"
#include "minunit.h"
#include "IGame.h"



// Set up array of int: sequence
int sequence [8] = {6, 2, 7, 4, 4, 8, 1, 2};
// Set up int: full sequence length
int sequence_lenght = sizeof(sequence);
// Set up int: current sequence length
int current_sequence_lenght;


int main(void)
{
	// Setup
		// Set port A to out
		DDRA = 0xFF;
		PORTA = 0xFF;
		// Set port B to in 
		DDRB = 0x00;
		PORTB = 0x00;

    while (1)
    {

		// call showSequenceState()
		showSequenceState();
		// call getPlayerInputState()
		// call chechIfGameWon()
    }
}
	

	
	
	

	
	
	
	
		
		
		
	
	int getPlayerInputState()
	{
		int buttonPressed;
		int i;
		for (i = 0; i < current_sequence_lenght; i++)
		{
			buttonPressed = getButtonPress();
			// Compare each pres to current sequence value
			// If incorrect
			if (buttonPressed != sequence[i])
			{
				// call showFailPattern()
				resetGame(&current_sequence_lenght);
				return "wrong";
			}
			// call showCorrectPattern()
		}
		return 0;	
	}
				
	
	
	// chechIfGameWon()
		// If full sequence has been shown
			// call showWinPatternForever()
		// return 0
	
	
	// showFailPattern()
		// return 0
	
	
	
	// showCorrectPattern()
		// return 0
	
	
	
	// showWinPatternForever()
		// while(1) aka do forever
	
	
	
	// resetGame()
		// return 0
	

		}
