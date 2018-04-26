/*
 * IGame.h
*/

#ifndef IGAME_H_
#define IGAME_H_


#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <util/delay.h>
#include "atmega2560_drivers.h"
#include "minunit.h"

int getPlayerInputState(int sequence[8], int current_sequence_lenght);
int resetGame(int *current_sequence_lenght);
int showSequenceState(int sequence[8], int current_sequence_lenght);
int getButtonPress();
int showFailPattern();
int showWinPattern();





#endif /* IGAME_H_ */