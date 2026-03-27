#include <stdio.h>
#include <cluige.h>
#include <float.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//#include "common_test.h"
#include "transition.h"

//printf tests
#include "node_test.h"
#include "tscn_parser_test.h"
#include "project_dot_godot_parser_test.h"

static void trick_for_tests_from_scratch()
{}

int main()
{
	//SetConsoleOutputCP(CP_UTF8);

	//init
	cluige_init(trick_for_tests_from_scratch);//makes all roots, set all functions pointers, etc.

	iCluige.window_title = "test cluige";
	iCluige.window_initial_size_cols = 110;
	iCluige.window_initial_size_lines = 50;


	// == printf tests ==

	node_all_tests();
	tscn_parser_all_tests();
	project_dot_godot_parser_all_tests();

	printf("\nEnd of printf tests. Press ENTER key to continue with graphical tests...\n");
	getchar();


	// == 'in-game' tests ==
	//////////////iCluige.window_title = "test cluige";

	//transition system : entry point of all graphical tests
	//consisting of a Node with a Script
	//input : 'n' to Next phase
	init_transition();


	// == run ==

	cluige_run();

	int finish = cluige_finish();

//	utils_breakpoint_trick(NULL, true);
	//printf("\nThe End ! Press ENTER key to quit...\n");
	//getchar();

	return finish;
}

