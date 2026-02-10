#ifndef CLUIGE_COMMON_TEST_H_INCLUDED
#define CLUIGE_COMMON_TEST_H_INCLUDED

//#include "cluige.h"

//#define MAX_SIZE 1000000
//#define PI 3.1415926535897932

//input actions
extern int UP;// Z Q S D
extern int DOWN;
extern int LEFT;
extern int RIGHT;
extern int ZOOM;// T
extern int ROT_90;// J K L
extern int ROT_45;
extern int ROT_180;
//extern int ROT_270;
extern int NEXT;
extern int JUMP;
//extern int EXIT_ACTION; // x


struct _TestStep
{
	bool* started;
	void (*inputs)();
	void (*launch)();
	void (*finish)();
	char* help_text;
};
typedef struct _TestStep TestStep;



#endif // CLUIGE_COMMON_TEST_H_INCLUDED
