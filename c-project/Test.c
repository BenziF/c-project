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
	int gameRoundResult = 0;
	gameRoundResult = handleResultOfRound(gameRoundResult, 5, &CurrentSequenceValueTest);
	mu_assert("handleResultOfRound(0,5,2) != 3",  CurrentSequenceValueTest == 3);
	return 0;
}

static char * all_tests()
{
	mu_run_test(test_CompareSequences);
	return 0;
}


//#ifdef TEST
int runTests()
{
	//init_stdio(0, 10000000L);
	//sei();

	char *result = all_tests();
	if (result != 0) {
		printf("error: %s\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n");
	}

	printf("Tests run: %d\n", tests_run);

	while(1);
	return result != 0;
}
//#endif