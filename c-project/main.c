/*
 * c-project.c
 */ 

#define F_CPU 1000000UL

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
		
	// Enabling print function with STK
	init_stdio(0, 10000000L);	
	sei();
		
	// Set up array of int: sequence
	//int sequence [8] = {6, 2, 7, 4, 4, 8, 1, 2};
	int sequence [2] = {6, 2};
	// Set up int: full sequence length
	int sequence_length = sizeof(sequence);
	// Set up int: current sequence length
	int current_sequence_length = 1;
	// Setup int: gameRoundResult. 0 = correct, 1 = player incorrect
	int gameRoundResult = 0;
	
	test_CompareSequences();

    while (1)
    {
		showSequenceState(sequence, current_sequence_length);
		gameRoundResult = getPlayerInputState(sequence, &current_sequence_length);
		handleResultOfRound(gameRoundResult, sequence_length, &current_sequence_length);
    }
}