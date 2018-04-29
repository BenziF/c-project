/*
 * Game.c
 */
#include "IGame.h"

int handleResultOfRound(int gameRoundResult, int sequence_length, int *current_sequence_length)
{
	// 0 if player NOT incorrect
	if (gameRoundResult == 0)
	{
		showWinPattern();
		*current_sequence_length = *current_sequence_length + 1;
		// Check if game is finished
		if ((sequence_length - 1) == *current_sequence_length)
		{
			showWinForever();
		}
	} 
	// 1 if player was incorrect
	else if (gameRoundResult == 1)
	{
		showFailPattern();
		resetGame(current_sequence_length);
	}
	//Reset for next round
	PORTA = 0xFF;
	_delay_ms(2000);
	return 0; 
}

int showWinForever()
{
	//If game finished, keep displaying win pattern
	while(1)
	{
		showWinPattern();
	}
	return 0;
}
	
int getPlayerInputState(int sequence[2], int *current_sequence_length)
{
	//Setup
	int buttonPressed;
	int intputResult = 0;
	int i;
	//Receive input from the player for as long as the current sequence lasts
	for (i = 0; i < *current_sequence_length; i++)
	{
		_delay_ms(1000);
		buttonPressed = getButtonPress();
		// Compare each pres to current sequence value
		// If incorrect
		if (buttonPressed + 1 != sequence[i])
		{
			intputResult = 1;
			break;
		}
	}
	return intputResult;
}
	
	
	
int resetGame(int *current_sequence_length)
{
	//Restart the game, setting the sequence lenght back to 1
	*current_sequence_length = 1;
	return 0;
}
	
	
	
int showSequenceState(int sequence[2], int current_sequence_length)
{
	// Blink the current sequence
	int i;
	for (i = 0; i < current_sequence_length; i++)
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
		//Read the current status of the input port
		uint8_t port_b_state = ~PINB;
		uint8_t port_b_validated;
		int result = 9;

		switch (port_b_state)
		{
			//For each button, input the correspondent value
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
			//If a button is pressed, send the correspondent input to the system
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
	//Show a predefined fail pattern in case of wrong sequence
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
	//Show a predefined win pattern in case of correct sequence
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
	_delay_ms(2000);

	return 0;
}