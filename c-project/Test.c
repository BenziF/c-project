/*
 * Test.c
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <util/delay.h>
#include "atmega2560_drivers.h"
#include "minunit.h"
#include "IGame.h"

int tests_run = 0;

static char * test_CompareSequences()
{
	int CurrentSequenceValueTest = 2;
	handleResultOfRound(0,5,CurrentSequenceValueTest);
	mu_assert("handleResultOfRound(0,5,2) != 3",  CurrentSequenceValueTest== 0);
	return 0;
}
