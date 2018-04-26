/*
 * Game.c
 */
#include "IGame.h"

	
int resetGame(int *current_sequence_lenght)
{
	*current_sequence_lenght = 0;
	return 0;
}
	
	
	
int showSequenceState(int sequence[8], int current_sequence_lenght)
{
	// Blink the current sequence
	int i;
	for (i = 0; i < current_sequence_lenght; i++)
	{
		PORTA ^= (1 << sequence [i] - 1);
		_delay_ms(10000);
		PORTA = 0xFF;
		_delay_ms(2000);
	}
	return 0;
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

int showFailPattern()
{
	_delay_ms(2000);
	PORTA = 0b00011000;
	_delay_ms(2000);
	PORTA = ~PORTA;
	_delay_ms(2000);
	PORTA = ~PORTA;
	_delay_ms(2000);
	PORTA = ~PORTA;
	_delay_ms(2000);
	PORTA = ~PORTA;
	_delay_ms(2000);
	PORTA = ~PORTA;

	return 0;
}

int showWinPattern()
{
	_delay_ms(2000);
	PORTA = 0b01010101;
	_delay_ms(2000);
	PORTA = ~PORTA;
	_delay_ms(2000);
	PORTA = ~PORTA;
	_delay_ms(2000);
	PORTA = ~PORTA;
	_delay_ms(2000);
	PORTA = ~PORTA;
	_delay_ms(2000);
	PORTA = ~PORTA;

	return 0;
}