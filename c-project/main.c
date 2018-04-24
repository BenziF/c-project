/*
 * c-project.c
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "atmega2560_drivers.h"
#include "minunit.h"


int main(void)
{
	// Setup
	// Set port A to out
	// Set port B to in 
	// Set up array of int: sequence
	// Set up int: full sequence length
	// Set up int: current sequence length
	
    while (1)
    {
		// call showSequenceState()
		// call getPlayerInputState()
		// call chechIfGameWon()
    }
	
	
	
	// showSequenceState()
		// Blink the current sequence
		// return 0
		
		
		
	
	// getPlayerInputState()
		// Get button press
		// Compare each pres to current sequence value
			// If incorrect
				// call showFailPattern()
				// call resetGame()
				// return "wrong"
		// call showCorrectPattern()
		// return 0
				
	
	
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

