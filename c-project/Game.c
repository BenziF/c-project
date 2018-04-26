/*
 * Game.c
 */
#include "IGame.h"

	
int getPlayerInputState(int sequence[8], int *current_sequence_lenght)
{
	int buttonPressed;
	int i;
	int playerWrong = 0;
	for (i = 0; i < *current_sequence_lenght; i++)
	{
		_delay_ms(1000);
		buttonPressed = getButtonPress();
		// Compare each pres to current sequence value
		// If incorrect
		if (buttonPressed + 1 != sequence[i])
		{
			playerWrong = 1;
			break;
		}
	}
	if (playerWrong == 1)
	{
		showFailPattern();
		resetGame(current_sequence_lenght);
		return 1;
	}
	showWinPattern();
	return 0;
}
	
	
	
int resetGame(int *current_sequence_lenght)
{
	*current_sequence_lenght = 1;
	return 0;
}
	
	
	
int showSequenceState(int sequence[8], int current_sequence_lenght)
{
	// Blink the current sequence
	int i;
	for (i = 0; i < current_sequence_lenght; i++)
	{
		PORTA ^= (1 << (sequence [i] - 1));
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
		int result = 9;

		switch (port_b_state)
		{
			case (1<<PB0):
				_delay_ms(1000);
				port_b_validated = ~PINB;
				if (port_b_validated == port_b_state)
				{
					result = 0;
				}
				break;
			case (1<<PB1):
				_delay_ms(1000);
				port_b_validated = ~PINB;
				if (port_b_validated == port_b_state)
				{
					result = 1;
				}
				break;
			case (1<<PB2):
				_delay_ms(1000);
				port_b_validated = ~PINB;
				if (port_b_validated == port_b_state)
				{
					result = 2;
				}
				break;
			case (1<<PB3):
				_delay_ms(1000);
				port_b_validated = ~PINB;
				if (port_b_validated == port_b_state)
				{
					result = 3;
				}
				break;
			case (1<<PB4):
				_delay_ms(1000);
				port_b_validated = ~PINB;
				if (port_b_validated == port_b_state)
				{
					result = 4;
				}
				break;
			case (1<<PB5):
				_delay_ms(1000);
				port_b_validated = ~PINB;
				if (port_b_validated == port_b_state)
				{
					result = 5;
				}
				break;
			case (1<<PB6):
				_delay_ms(1000);
				port_b_validated = ~PINB;
				if (port_b_validated == port_b_state)
				{
					result = 6;
				}
				break;
			case (1<<PB7):
				_delay_ms(1000);
				port_b_validated = ~PINB;
				if (port_b_validated == port_b_state)
				{
					result = 7;
				}
				break;
		}
		if (result != 9)
		{
			port_b_state = ~PINB;
			while (port_b_state != 0b00000000)
			{
				port_b_state = ~PINB;
				_delay_ms(100);
			}
			return result;
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
	PORTA = 0xFF;
	_delay_ms(2000);

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
	PORTA = 0xFF;
	_delay_ms(2000);

	return 0;
}