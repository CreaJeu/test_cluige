#ifndef TENTH_OF_SCREEN_H_INCLUDED
#define TENTH_OF_SCREEN_H_INCLUDED

//typedef Script;
//typedef Node2D;

typedef struct _TenthOfScreenScript TenthOfScreenScript;
struct _TenthOfScreenScript
{
//	Script* _this_Script;
//	Node2D* _this_Node2D;

	//@export from .gd
	float speed;//cluige characters per second

	//virtual methods - private copy of mother class pointers
	void (*_delete_super)(Script*);

	//virtual methods in .c
	//void (*process)(Script* this_Script, float delta);
};

Script* instantiate_TenthOfScreenScript(const SortedDictionary* parsed_params);
void delete_TenthOfScreenScript(Script* this_Script);
void process_TenthOfScreenScript(Script* this_Script, float delta);

#endif // _H_INCLUDED
