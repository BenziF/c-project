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
	// Set up sequence
	// Set up current sequence length
	
    while (1)
    {
		// call showSequenceState()
		// call getPlayerInputState()
		// call chechIfGameWon()
    }
	
	
	
	// showSequenceState()
		// Blink the current sequence
		
		
		
	
	// getPlayerInputState()
		// Get button press
		// Compare each pres to current sequence value
			// If incorrect
				// call showFailPattern()
				// reset game
				// return "wrong"
		// call showCorrectPattern()
		// return 0
				
	
	
	// chechIfGameWon()
		// If full sequence has been shown
			// call showWinPatternForever()
	
	
	
	// showFailPattern()
		// resetGame()
	
	
	
	// showCorrectPattern()
	
	
	
	
	// showWinPatternForever()
	
}

