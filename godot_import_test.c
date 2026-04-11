//#include <stdlib.h> //already in cluige.h
//#include <stddef.h> //already in cluige.h
#include <cluige.h>
#include "common_test.h"
#include "godot_import_test.h"
#include "godot_example/scripts/tenth_of_screen.h"


bool godot_test_started = false;

void launch_godot_test()
{
	iCluige.set_resource_path("godot_example");
	godot_test_started = true;
	ScriptFactory* sf = iCluige.checked_malloc(sizeof(ScriptFactory));
	sf->instantiate = instantiate_TenthOfScreenScript;
	iCluige.iScript.register_ScriptFactory_no_ext("scripts/tenth_of_screen", sf);

	TscnParser tp_memo;
	iCluige.iTscnParser.tscn_parser_alloc(&tp_memo, "godot_only/memo.tscn", 2000);
	bool ok = tp_memo.parse_scene(&tp_memo);
	CLUIGE_BREAKPOINT(&ok, false);
	iCluige.iTscnParser.pre_delete_TscnParser(&tp_memo);

	TscnParser tp_main;
	iCluige.iTscnParser.tscn_parser_alloc(&tp_main, "scenes/main.tscn", 2000);
	ok = tp_main.parse_scene(&tp_main);
	CLUIGE_BREAKPOINT(&ok, !ok);
	iCluige.iTscnParser.pre_delete_TscnParser(&tp_main);

	ProjectDotGodotParser pdgp;
	iCluige.iProjectDotGodotParser.project_dot_godot_parser_alloc(&pdgp, "project.godot");
	ok = pdgp.run(&pdgp);
	CLUIGE_BREAKPOINT(&ok, !ok);
	iCluige.iProjectDotGodotParser.pre_delete_ProjectDotGodotParser(&pdgp);

}

void inputs_godot_test()
{
	//automatic in ProjectDotGodotParser::run()
	//but no new input in this test
}

void end_godot_test()
{
//	iCluige.iInput.un_bind_key_all_actions(' ');// no new input in this test
//	iCluige.iInput.remove_last_available_action();//"JUMP"

	Node* game_root = iCluige.iNode.get_node(iCluige.public_root_2D, "main_Node");
	iCluige.iNode.queue_free(game_root);

	SortedDictionary* fcties = &(iCluige.iScript.script_factories);
	Pair p = iCluige.iSortedDictionary.erase(fcties, "scripts/tenth_of_screen");
	ScriptFactory* sf = (ScriptFactory*)(p.second.ptr);
	free(sf);

	iCluige.set_resource_path("");
}

TestStep make_godot_test_step()
{
	TestStep res;
	res.started = &godot_test_started;
	res.inputs = inputs_godot_test;
	res.launch = launch_godot_test;
	res.finish = end_godot_test;
	res.help_text =
"\
 ~ Godot import test ~\n\
 \n\
 Move sprite : ZQSD or WASD\n\
 \n\
 Next phase : N";
	return res;
}
