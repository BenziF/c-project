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



int main(void)
{
	// Setup
		// Set port A to out
		DDRA = 0xFF;
		PORTA = 0xFF;
		// Set port B to in 
		DDRB = 0x00;
		PORTB = 0x00;
		// Set up array of int: sequence
		int sequence [8] = {6, 2, 7, 4, 4, 8, 1, 2};
		// Set up int: full sequence length
		int sequence_lenght = sizeof(sequence);
		// Set up int: current sequence length
		int current_sequence_lenght;
	
    while (1)
    {
		int i;
		for (i=0; i<8; i ++)
		{
			switch(sequence[i]){
				case 1 : PORTA ^= (1 << 0);
				_delay_ms(1000);
				PORTA ^= (1 << 0);
				break;
				case 2 : PORTA ^= (1 << 1);
				_delay_ms(1000);
				PORTA ^= (1 << 1);
				break;
				case 3 : PORTA ^= (1 << 2);
				_delay_ms(1000);
				PORTA ^= (1 << 2);
				break;
				case 4 : PORTA ^= (1 << 3);
				_delay_ms(1000);
				PORTA ^= (1 << 3);
				break;
				case 5 : PORTA ^= (1 << 4);
				_delay_ms(1000);
				 PORTA ^= (1 << 4);
				break;
				case 6 : PORTA ^= (1 << 5);
				_delay_ms(1000);
				 PORTA ^= (1 << 5);
				break;
				case 7 : PORTA ^= (1 << 6);
				_delay_ms(1000);
				PORTA ^= (1 << 6);
				break;
				case 8 : PORTA ^= (1 << 7);
				_delay_ms(1000);
				PORTA ^= (1 << 7);
				break;
				
			}
		
		}
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
