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
		showSequenceState()
		// call getPlayerInputState()
		// call chechIfGameWon()
    }
}
	
	
	
	int showSequenceState()
	{
		// Blink the current sequence
		int i;
		for (i = 0; i < current_sequence_lenght; i++)
		{
			PORTA ^= (1 << sequence [i]);
			_delay_ms(1000);
			PORTA = 0xFF;
			_delay_ms(100);
		}
		return 0
	}
	
	
	
	int getButtonPress()
	{
		while (1)
		{
			uint8_t port_b_state = ~PINB;
			uint8_t port_b_validated;

			switch (port_b_state)
			{

				case (1<<PB0):
					_delay_ms(100);
					port_b_validated = ~PINB;
					if (port_b_validated == port_b_state)
					{
						return 0;
					}
					break;
				case (1<<PB1):
					_delay_ms(100);
					port_b_validated = ~PINB;
					if (port_b_validated == port_b_state)
					{
						return 1;
					}
					break;
				case (1<<PB2):
					_delay_ms(100);
					port_b_validated = ~PINB;
					if (port_b_validated == port_b_state)
					{
						return 2;
					}
					break;
				case (1<<PB3):
					_delay_ms(100);
					port_b_validated = ~PINB;
					if (port_b_validated == port_b_state)
					{
						return 3;
					}
					break;
				case (1<<PB4):
					_delay_ms(100);
					port_b_validated = ~PINB;
					if (port_b_validated == port_b_state)
					{
						return 4;
					}
					break;
				case (1<<PB5):
					_delay_ms(100);
					port_b_validated = ~PINB;
					if (port_b_validated == port_b_state)
					{
						return 5;
					}
					break;
				case (1<<PB6):
					_delay_ms(100);
					port_b_validated = ~PINB;
					if (port_b_validated == port_b_state)
					{
						return 6;
					}
					break;
				case (1<<PB7):
					_delay_ms(100);
					port_b_validated = ~PINB;
					if (port_b_validated == port_b_state)
					{
						return 7;
					}
					break;
			}
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
				// call resetGame()
				// return "wrong"
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
