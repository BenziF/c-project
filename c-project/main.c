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






int main(void)
{
	// Setup
		// Set port A to out
		DDRA = 0xFF;
		PORTA = 0xFF;
		// Set port B to in 
		DDRB = 0x00;
		PORTB = 0x00;
		
		init_stdio(0, 10000000L);
		
		sei();
		
		// Set up array of int: sequence
		int sequence [8] = {6, 2, 7, 4, 4, 8, 1, 2};
		// Set up int: full sequence length
		int sequence_lenght = sizeof(sequence);
		// Set up int: current sequence length
		int current_sequence_lenght = 3;

    while (1)
    {
		showSequenceState(sequence, current_sequence_lenght);
		getPlayerInputState(sequence, &current_sequence_lenght);
	
		// call chechIfGameWon()
		//showWinPattern();
    }
}
	

	
	
	

	
	
	
	
		
		
		
	

				
	
	// chechIfGameWon()
		// If full sequence has been shown
			// call showWinPatternForever()
		// return 0
	

	// showCorrectPattern()
		// return 0
	
	
	
	// showWinPatternForever()
		// while(1) aka do forever
	
	
	


