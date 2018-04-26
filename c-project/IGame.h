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

int ifGameWonShowWinForever(int sequence_length, int current_sequence_length);
int getPlayerInputState(int sequence[8], int *current_sequence_length);
int resetGame(int *current_sequence_length);
int showSequenceState(int sequence[8], int current_sequence_length);
int getButtonPress();
int showFailPattern();
int showWinPattern(int *current_sequence_length);

#endif /* IGAME_H_ */