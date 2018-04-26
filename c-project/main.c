/*
 * c-project.c
 */ 

# define F_CPU 1000000UL

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
int current_sequence_lenght = 3;


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
		showSequenceState(sequence, current_sequence_lenght);
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
				showFailPattern();
				resetGame(&current_sequence_lenght);
				return 1;
			}
			// call showCorrectPattern()
		}
		return 0;	
	}
				
	
	// chechIfGameWon()
		// If full sequence has been shown
			// call showWinPatternForever()
		// return 0
	

	// showCorrectPattern()
		// return 0
	
	
	
	// showWinPatternForever()
		// while(1) aka do forever
	
	
	


