//#include <stdlib.h> //already in cluige.h
//#include <stddef.h> //already in cluige.h
#include <cluige.h>
#include "common_test.h"
#include "recursive_tscn_test.h"


bool recursive_tscn_test_started = false;

Node* tmp_test_Node;


//struct _PlayerScript
//{
//	Script* this_Script;
//	int ...
//};
//typedef struct _PlayerScript PlayerScript;
//PlayerScript* newPlayer(Node* this_Node);
//static void process_Player(Script* this_Script, float elapsed_seconds);

//PlayerScript* newPlayer(Node* this_Node)
//{
//	Script* new_Script = iCluige.iScript.new_Script(this_Node);
//	PlayerScript* newPlayer = iCluige.checked_malloc(sizeof(PlayerScript));
//
//	newPlayer->this_Script = new_Script;
//	newPlayer->... = ...;
//	...
//	return newPlayer;
//}

//static void process_Player(Script* this_Script, float elapsed_seconds)
//{
//	...
//}

void inputs_recursive_tscn_test()
{
//	UP = iCluige.iInput.add_action("UP");
//	iCluige.iInput.bind_key(UP, 'z');
//	iCluige.iInput.bind_key(UP, 'Z');
}

void launch_recursive_tscn_test()
{
//	iCluige.wanted_frame_seconds = 1.666;
	recursive_tscn_test_started = true;

	TscnParser parser_sub;
	iCluige.iTscnParser.tscn_parser_alloc(&parser_sub, "assets/tmp_test/sub.tscn");
	bool ok = parser_sub.parse_scene(&parser_sub);
	utils_breakpoint_trick(&ok, false);

	SortedDictionary* path_to_ps = &(iCluige.iPackedScene.dico_path_to_packed);
	Checked_Variant cv = iCluige.iSortedDictionary.get(
			path_to_ps, "assets/tmp_test/sub.tscn");
	if(!(cv.valid) || cv.v.ptr != parser_sub.scene_root)
	{
		printf("FAILED ---  'note' scene not correctly registered in _dico_path_to_packed | test_pksc_instanciate_with_instance\n ");
	}
	iCluige.iTscnParser.pre_delete_TscnParser(&parser_sub);

	TscnParser parser_up;
	iCluige.iTscnParser.tscn_parser_alloc(&parser_up, "assets/tmp_test/up.tscn");
	ok = parser_up.parse_scene(&parser_up);
	utils_breakpoint_trick(&ok, false);

	cv = iCluige.iSortedDictionary.get(
			path_to_ps, "assets/tmp_test/up.tscn");
	if(!(cv.valid) || cv.v.ptr != parser_up.scene_root)
	{
		printf("FAILED ---  'note' scene not correctly registered in _dico_path_to_packed | test_pksc_instanciate_with_instance\n ");
	}
	PackedScene* ps = (PackedScene*)(cv.v.ptr);
	iCluige.iTscnParser.pre_delete_TscnParser(&parser_up);

	tmp_test_Node = iCluige.iPackedScene.instanciate(ps);
	iCluige.iNode.add_child(iCluige.public_root_2D, tmp_test_Node);

//	newPlayer(playerNode);// attach script to The player node
}

void end_recursive_tscn_test()
{
	iCluige.iNode.queue_free(tmp_test_Node);
}

TestStep make_recursive_tscn_test_step()
{
	TestStep res;
	res.started = &recursive_tscn_test_started;
	res.inputs = inputs_recursive_tscn_test;
	res.launch = launch_recursive_tscn_test;
	res.finish = end_recursive_tscn_test;
	res.help_text =
"\
 ~ Tscn that instanciates another tscn ~\n\
 \n\
Next phase : N";
	return res;
}
