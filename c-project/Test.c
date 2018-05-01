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
	int gameRoundResultTest = 0;
	gameRoundResultTest = handleResultOfRound(gameRoundResultTest, 5, &CurrentSequenceValueTest);
	mu_assert("handleResultOfRound(0,5,2) != 3",  CurrentSequenceValueTest == 3);
	return 0;
}

static char * test_CompareSequencesFail()
{
	int CurrentSequenceValueTest = 4;
	int gameRoundResultTest = 1;
	gameRoundResultTest = handleResultOfRound(gameRoundResultTest, 5, &CurrentSequenceValueTest);
	mu_assert("handleResultOfRound(0,5,4) != 1",  CurrentSequenceValueTest ==1);
	return 0;
}

static char * all_tests()
{
	mu_run_test(test_CompareSequences);
	mu_run_test(test_CompareSequencesFail);
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

	return result != 0;
}
//#endif