#include <stdio.h>
#include <cluige.h>
#include <float.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "common_test.h"
#include "node_test.h"
#include "camera_test.h"

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

	#ifdef IN_PRINTF_TEST
	node_all_tests();
	#endif // IN_PRINTF_TEST

	#ifdef IN_GRAPHICAL_TEST
	inputs_camera();
	launch_camera();
	cluige_run();
	#endif // IN_GRAPHICAL_TEST

	printf("Finishing...\n");
	return cluige_finish();
}

