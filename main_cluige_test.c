#include <stdio.h>
#include <cluige.h>
#include <float.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "common_test.h"
#include "transition.h"

//printf tests
#include "node_test.h"
#include "tscn_parser_test.h"

// WRITE use "Debug graphical" build target if you want to test graphical things like camera
// WRITE use "Debug printf" build target if you want to test non graphical things like node names
// WRITE but don't forget to recompile (not auto in code::blocks)

//#define IN_PRINTF_TEST  // use build targets instead, don't forget to recompile
//#define IN_GRAPHICAL_TEST  // use build targets instead, don't forget to recompile

int main()
{
	//SetConsoleOutputCP(CP_UTF8);

	//init
	cluige_init();//makes all roots, set all functions pointers, etc.

	init_transition();
	//all graphical tests are launched from 'transition'
	cluige_run();

	//printf tests
	node_all_tests();
	tscn_parser_all_tests();

	int finish = cluige_finish();
//#ifdef IN_PRINTF_TEST
//	utils_breakpoint_trick(NULL, true);
	printf("\nThe End ! Press ENTER key to quit...\n");
	getchar();
//#endif // IN_PRINTF_TEST
	return finish;
}

