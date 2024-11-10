//#include <stdlib.h> //already in cluige.h
//#include <stddef.h> //already in cluige.h
#include <cluige.h>
#include <assert.h>
#include <math.h>
#include "common_test.h"
#include "tscn_parser_test.h"


static void test_utils_bool_from_parsed()
{
	SortedDictionary placeholder_dico;
	iCluige.iSortedDictionary.sorted_dictionary_alloc(&placeholder_dico, VT_POINTER, VT_POINTER, 3);
	iCluige.iSortedDictionary.set_compare_keys_func(&placeholder_dico, iCluige.iDeque.default_compare_string_func);
	bool res = true;
	utils_bool_from_parsed(&res, &placeholder_dico, "test_bool");
	if(!res)
	{
		printf("FAILED --- should be true  | test_utils_bool_from_parsed 1\n ");
	}

	res = false;
	utils_bool_from_parsed(&res, &placeholder_dico, "test_bool");
	if(res)
	{
		printf("FAILED --- should be false  | test_utils_bool_from_parsed 2\n ");
	}

	res = false;
	iCluige.iSortedDictionary.insert(&placeholder_dico, "test_bool", "true");
	utils_bool_from_parsed(&res, &placeholder_dico, "test_bool");
	if(!res)
	{
		printf("FAILED --- should be true  | test_utils_bool_from_parsed 3\n ");
	}

	res = true;
	iCluige.iSortedDictionary.insert(&placeholder_dico, "test_bool", "false");
	utils_bool_from_parsed(&res, &placeholder_dico, "test_bool");
	if(res)
	{
		printf("FAILED --- should be false  | test_utils_bool_from_parsed 4\n ");
	}
	iCluige.iSortedDictionary.pre_delete_SortedDictionary(&placeholder_dico);
}

static void test_utils_char_from_parsed()
{
	SortedDictionary placeholder_dico;
	iCluige.iSortedDictionary.sorted_dictionary_alloc(&placeholder_dico, VT_POINTER, VT_POINTER, 3);
	iCluige.iSortedDictionary.set_compare_keys_func(&placeholder_dico, iCluige.iDeque.default_compare_string_func);
	char res = 'a';
	utils_char_from_parsed(&res, &placeholder_dico, "test");
	if(res != 'a')
	{
		printf("FAILED --- should be 'a'  | utils_char_from_parsed 1\n ");
	}

	res = 'z';
	utils_char_from_parsed(&res, &placeholder_dico, "test");
	if(res != 'z')
	{
		printf("FAILED --- should be 'z'  | utils_char_from_parsed 2\n ");
	}

	res = 'a';
	iCluige.iSortedDictionary.insert(&placeholder_dico, "test", "z");
	utils_char_from_parsed(&res, &placeholder_dico, "test");
	if(res != 'z')
	{
		printf("FAILED --- should be 'z'  | utils_char_from_parsed 3\n ");
	}

	res = 'z';
	iCluige.iSortedDictionary.insert(&placeholder_dico, "test", "a");
	utils_char_from_parsed(&res, &placeholder_dico, "test");
	if(res != 'a')
	{
		printf("FAILED --- should be 'a'  | utils_char_from_parsed 4\n ");
	}
	iCluige.iSortedDictionary.pre_delete_SortedDictionary(&placeholder_dico);
}


static void test_utils_str_from_parsed()
{
	SortedDictionary placeholder_dico;
	iCluige.iSortedDictionary.sorted_dictionary_alloc(&placeholder_dico, VT_POINTER, VT_POINTER, 3);
	iCluige.iSortedDictionary.set_compare_keys_func(&placeholder_dico, iCluige.iDeque.default_compare_string_func);
	char* res = "azertyuiop";
	utils_str_from_parsed(&res, &placeholder_dico, "test");
	if(0 != strcmp(res, "azertyuiop"))
	{
		printf("FAILED --- should be \"azertyuiop\"  | utils_str_from_parsed 1\n ");
	}

	res = "z";
	utils_str_from_parsed(&res, &placeholder_dico, "test");
	if(0 != strcmp(res, "z"))
	{
		printf("FAILED --- should be \"z\"  | utils_str_from_parsed 2\n ");
	}

	res = "a";
	iCluige.iSortedDictionary.insert(&placeholder_dico, "test", "\"poiuytrez\"");
	utils_str_from_parsed(&res, &placeholder_dico, "test");
	if(0 != strcmp(res, "poiuytrez"))
	{
		printf("FAILED --- should be \"poiuytrez\"  | utils_str_from_parsed 3\n ");
	}

	res = "z";
	iCluige.iSortedDictionary.insert(&placeholder_dico, "test", "\"azertyui\"");
	utils_str_from_parsed(&res, &placeholder_dico, "test");
	if(0 != strcmp(res, "azertyui"))
	{
		printf("FAILED --- should be \"azertyui\"  | utils_str_from_parsed 4\n ");
	}
	iCluige.iSortedDictionary.pre_delete_SortedDictionary(&placeholder_dico);
}

static void test_Node_instanciate()
{
	SortedDictionary* fcties = &(iCluige.iNode.node_factories);
	Checked_Variant cv_fcty = iCluige.iSortedDictionary.get(fcties, "Node");
	if(!(cv_fcty.valid))
	{
		printf("FAILED --- should be valid  | test_Node_instanciate 0\n ");
	}
	NodeFactory* fcty = (NodeFactory*)(cv_fcty.v.ptr);
	if((fcty->instanciate) == NULL)
	{
		printf("FAILED --- should be a function  | test_Node_instanciate 1\n ");
	}
	SortedDictionary placeholder_dico;
	iCluige.iSortedDictionary.sorted_dictionary_alloc(&placeholder_dico, VT_POINTER, VT_POINTER, 3);
	iCluige.iSortedDictionary.set_compare_keys_func(&placeholder_dico, iCluige.iDeque.default_compare_string_func);

//	Node* res = iCluige.iNode.new_Node();
//	iCluige.iNode.deserialize_dico(res, &placeholder_dico);
//	Node* res = fcty->instanciate(&placeholder_dico); ::must assert(missing name)

	//Node* res2 = iCluige.iNode.new_Node();
	iCluige.iSortedDictionary.insert(&placeholder_dico, "name", "\"azertyuiop\"");
	//iCluige.iNode.deserialize_dico(res2, &placeholder_dico);
	Node* res2 = fcty->instanciate(&placeholder_dico);
	if(res2 == NULL || 0 != strcmp(res2->name, "azertyuiop"))
	{
		printf("FAILED --- should be \"azertyuiop\"  | test_Node_instanciate 2\n ");
	}
	iCluige.iSortedDictionary.pre_delete_SortedDictionary(&placeholder_dico);
//	res->delete_Node(res);//calls free(res);
	res2->delete_Node(res2);//calls free(res2);
}

static void test_Node2D_instanciate()
{
	SortedDictionary* fcties = &(iCluige.iNode.node_factories);
	Checked_Variant cv_fcty = iCluige.iSortedDictionary.get(fcties, "Node2D");
	if(!(cv_fcty.valid))
	{
		printf("FAILED --- should be valid  | test_Node2D_instanciate 0\n ");
	}
	NodeFactory* fcty = (NodeFactory*)(cv_fcty.v.ptr);
	if((fcty->instanciate) == NULL)
	{
		printf("FAILED --- should be a function  | test_Node2D_instanciate 1\n ");
	}

	SortedDictionary placeholder_dico;
	iCluige.iSortedDictionary.sorted_dictionary_alloc(&placeholder_dico, VT_POINTER, VT_POINTER, 3);
	iCluige.iSortedDictionary.set_compare_keys_func(&placeholder_dico, iCluige.iDeque.default_compare_string_func);
	iCluige.iSortedDictionary.insert(&placeholder_dico, "name", "\"test_Node2D_instanciate\"");

//	Node2D* res = iCluige.iNode2D.new_Node2D();
//	iCluige.iNode2D.deserialize_dico(res, &placeholder_dico);
	Node2D* res = (Node2D*)(fcty->instanciate(&placeholder_dico)->_sub_class);
	res->_this_Node->delete_Node(res->_this_Node);//calls free(res) and recursiv

	iCluige.iSortedDictionary.insert(&placeholder_dico, "visible", "false");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "position", "Vector2(2.265, -3.2)");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "name", "\"a 1 23 4567890bcdefghijklmnopqrst\"");
//	Node2D* res2 = iCluige.iNode2D.new_Node2D();
//	iCluige.iNode2D.deserialize_dico(res2, &placeholder_dico);
	Node2D* res2 = (Node2D*)(fcty->instanciate(&placeholder_dico)->_sub_class);
	if(0 != strcmp(res2->_this_Node->name, "a 1 23 4567890bcdefghijklmnopqrst"))
	{
		printf("FAILED --- should be \"a 1 23 4567890bcdefghijklmnopqrst\"  | test_Node2D_deserialize_dico 2\n ");
	}
	if(res2->visible)
	{
		printf("FAILED --- should be false  | test_Node2D_deserialize_dico 3\n ");
	}
	float gap = fabs(res2->position.x - 2.265);
	if(gap > .0001)
	{
		printf("FAILED --- should be 2.265  | test_Node2D_deserialize_dico 4\n ");
	}
	gap = fabs(res2->position.y - -3.2);
	if(gap > .0001)
	{
		printf("FAILED --- should be -3.2  | test_Node2D_deserialize_dico 5\n ");
	}
	iCluige.iSortedDictionary.pre_delete_SortedDictionary(&placeholder_dico);
	res2->_this_Node->delete_Node(res2->_this_Node);//calls free(res2) and recursiv
}

static void test_SpriteText_instanciate()
{
	SortedDictionary* fcties = &(iCluige.iNode.node_factories);
	Checked_Variant cv_fcty = iCluige.iSortedDictionary.get(fcties, "Label");
	if(!(cv_fcty.valid))
	{
		printf("FAILED --- SpriteText not in factories  | test_SpriteText_instanciate 0\n ");
	}
	NodeFactory* fcty = (NodeFactory*)(cv_fcty.v.ptr);
	if((fcty->instanciate) == NULL)
	{
		printf("FAILED --- uninitialized SpriteText factory function  | test_SpriteText_instanciate 1\n ");
	}

	SortedDictionary placeholder_dico;
	iCluige.iSortedDictionary.sorted_dictionary_alloc(&placeholder_dico, VT_POINTER, VT_POINTER, 4);
	iCluige.iSortedDictionary.set_compare_keys_func(&placeholder_dico, iCluige.iDeque.default_compare_string_func);

//	must assert / seg fault
//	SpriteText* res = iCluige.iSpriteText.new_SpriteText();
//	iCluige.iSpriteText.deserialize_dico(res, &placeholder_dico);
//	res->_this_Node2D->_this_Node->delete_Node(res->_this_Node2D->_this_Node);//calls free(res) and recursiv

	iCluige.iSortedDictionary.insert(&placeholder_dico, "aaaaaaaaaa", "fake to test");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "text", "\"un es\"sai\n de te\"xte\n\nmultiligne\"");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "offset", "Vector2(-49.3, 42)");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "visible", "false");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "position", "Vector2(2.265, -3.2)");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "name", "\"a sprite text\"");
//	SpriteText* res2 = iCluige.iSpriteText.new_SpriteText();
	//iCluige.iSpriteText.deserialize_dico(res2, &placeholder_dico);
	Node* res2_n = fcty->instanciate(&placeholder_dico);
	Node2D* res2_n2d = (Node2D*)(res2_n->_sub_class);
	SpriteText* res2 = (SpriteText*)(res2_n2d->_sub_class);
	if(0 != strcmp(res2->_this_Node2D->_this_Node->name, "a sprite text"))
	{
		printf("FAILED --- should be \"a sprite text\"  | test_SpriteText_instanciate 2\n ");
	}
	if(res2->_this_Node2D->visible)
	{
		printf("FAILED --- should be false  | test_SpriteText_instanciate 3\n ");
	}
	float gap = fabs(res2->_this_Node2D->position.x - 2.265);
	if(gap > .0001)
	{
		printf("FAILED --- should be 2.265  | test_SpriteText_instanciate 4\n ");
	}
	gap = fabs(res2->_this_Node2D->position.y - -3.2);
	if(gap > .0001)
	{
		printf("FAILED --- should be -3.2  | test_SpriteText_instanciate 5\n ");
	}
	gap = fabs(res2->offset.x - -49.3);
	if(gap > .0001)
	{
		printf("FAILED --- should be -49.3  | test_SpriteText_instanciate 6\n ");
	}
	gap = fabs(res2->offset.y - 42);
	if(gap > .0001)
	{
		printf("FAILED --- should be 42  | test_SpriteText_instanciate 7\n ");
	}
	if(0 != strcmp(res2->text, "un es\"sai\0 de te\"xte\0\0multiligne"))
	{
		printf("FAILED --- should be \"un es\"sai...\"  | test_SpriteText_instanciate 8\n ");
	}
	iCluige.iSortedDictionary.pre_delete_SortedDictionary(&placeholder_dico);
	res2->_this_Node2D->_this_Node->delete_Node(res2->_this_Node2D->_this_Node);//calls free(res2) and recursiv
}

static void test_SpriteSVG_instanciate()
{
	SortedDictionary* fcties = &(iCluige.iNode.node_factories);
	Checked_Variant cv_fcty = iCluige.iSortedDictionary.get(fcties, "Sprite2D");
	if(!(cv_fcty.valid))
	{
		printf("FAILED --- SpriteSVG not in factories  | test_SpriteSVG_instanciate\n ");
	}
	NodeFactory* fcty = (NodeFactory*)(cv_fcty.v.ptr);
	if((fcty->instanciate) == NULL)
	{
		printf("FAILED --- uninitialized SpriteSVG factory function  | test_SpriteSVG_instanciate\n ");
	}

	SortedDictionary placeholder_dico;
	iCluige.iSortedDictionary.sorted_dictionary_alloc(&placeholder_dico, VT_POINTER, VT_POINTER, 7);
	iCluige.iSortedDictionary.set_compare_keys_func(&placeholder_dico, iCluige.iDeque.default_compare_string_func);

//	must assert / seg fault
//	SpriteSVG* res = iCluige.iSpriteText.new_SpriteSVG();
//	iCluige.iSpriteSVG.deserialize_dico(res, &placeholder_dico);
//	res->_this_Node2D->_this_Node->delete_Node(res->_this_Node2D->_this_Node);//calls free(res) and recursiv

	iCluige.iSortedDictionary.insert(&placeholder_dico, "scale", "Vector2(-1.45, .66)");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "zzzzzz", "fake to test");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "svg_file_path", "assets/stunjam2023eyes.svg");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "offset", "Vector2(-49.3, 42)");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "name", "\"a sprite svg\"");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "visible", "false");
	iCluige.iSortedDictionary.insert(&placeholder_dico, "position", "Vector2(2.265, -3.2)");
//	SpriteSVG* res2 = iCluige.iSpriteSVG.new_SpriteSVG();
//	iCluige.iSpriteSVG.deserialize_dico(res2, &placeholder_dico);
	Node* res2_n = fcty->instanciate(&placeholder_dico);
	Node2D* res2_n2d = (Node2D*)(res2_n->_sub_class);
	SpriteSVG* res2 = (SpriteSVG*)(res2_n2d->_sub_class);
	//SpriteSVG* res2 = (SpriteSVG*)(fcty->instanciate(&placeholder_dico)->_sub_class);
	if(0 != strcmp(res2->_this_Node2D->_this_Node->name, "a sprite svg"))
	{
		printf("FAILED --- should be \"a sprite svg\"  | test_SpriteSVG_instanciate 1\n ");
	}
	if(res2->_this_Node2D->visible)
	{
		printf("FAILED --- should be false  | test_SpriteSVG_instanciate 2\n ");
	}
	float gap = fabs(res2->_this_Node2D->position.x - 2.265);
	if(gap > .0001)
	{
		printf("FAILED --- should be 2.265  | test_SpriteSVG_instanciate 3\n ");
	}
	gap = fabs(res2->_this_Node2D->position.y - -3.2);
	if(gap > .0001)
	{
		printf("FAILED --- should be -3.2  | test_SpriteSVG_instanciate 4\n ");
	}
	gap = fabs(res2->offset.x - -49.3);
	if(gap > .0001)
	{
		printf("FAILED --- should be -49.3  | test_SpriteSVG_instanciate 5\n ");
	}
	gap = fabs(res2->offset.y - 42);
	if(gap > .0001)
	{
		printf("FAILED --- should be 42  | test_SpriteSVG_instanciate 6\n ");
	}
	gap = fabs(res2->scale.x - -1.45);
	if(gap > .0001)
	{
		printf("FAILED --- should be -1.45  | test_SpriteSVG_instanciate 7\n ");
	}
	gap = fabs(res2->scale.y - .66);
	if(gap > .0001)
	{
		printf("FAILED --- should be .66  | test_SpriteSVG_instanciate 8\n ");
	}
	Path2D* path = (Path2D*)(iCluige.iDeque.at(&(res2->paths), 0).ptr);
	Vector2* point0 = (Vector2*)(iCluige.iDeque.at(&(path->_points), 0).ptr);
	utils_breakpoint_trick(point0, false);

	iCluige.iSortedDictionary.pre_delete_SortedDictionary(&placeholder_dico);
	res2->_this_Node2D->_this_Node->delete_Node(res2->_this_Node2D->_this_Node);//calls free(res2) and recursiv
}

static void test_FileLineReader()
{
	FileLineReader flr;
	iCluige.iFileLineReader.fileLineReader_alloc(&flr, 100);
	bool ok = iCluige.iFileLineReader.open_file_start_reader(&flr, "no");
	if(ok)
	{
		printf("FAILED --- should be flase  | test_FileLineReader 1\n ");
	}
	ok = iCluige.iFileLineReader.open_file_start_reader(&flr, "assets/test_corbeau.txt");
	if(!ok)
	{
		printf("FAILED --- should be true  | test_FileLineReader 2\n ");
	}
	ok = iCluige.iFileLineReader.feof(&flr, 0);
	if(ok)
	{
		printf("FAILED --- should be flase  | test_FileLineReader 3\n ");
	}
	const char* line = iCluige.iFileLineReader.get_line(&flr, 0);
	if(strcmp("Maître corbeau, sur un arbre perché,\n", line))
	{
		printf("FAILED --- should be \"Maître corbeau, sur un arbre perché,\n\"  | test_FileLineReader 4\n ");
	}
	//printf(line);
	int i = 1;
	while(!iCluige.iFileLineReader.feof(&flr, i))
	{
		line = iCluige.iFileLineReader.get_line(&flr, i);
		//printf(line);
		i++;
	}
	iCluige.iFileLineReader.forget_lines_before(&flr, i-3);//line # i is preserved
	//line = iCluige.iFileLineReader.get_line(&flr, i-4);//must assert
	//printf("\n-------------\n");
	for(int c = i-3; c < i; c++)
	{
		line = iCluige.iFileLineReader.get_line(&flr, c);
		//printf(line);
	}
	line = iCluige.iFileLineReader.get_line(&flr, i+1);
	if(line != NULL)
	{
		printf("FAILED --- should be NULL  | test_FileLineReader 5\n ");
	}
	line = iCluige.iFileLineReader.get_line(&flr, i+2);
	if(line != NULL)
	{
		printf("FAILED --- should be NULL  | test_FileLineReader 5.2\n ");
	}
	iCluige.iFileLineReader.close_file(&flr);

	//other file
	//printf("\n++++++++++++++++\n");
	ok = iCluige.iFileLineReader.open_file_start_reader(&flr, "assets/azerty.tscn");//"test_tscn_parser.tscn");//
	if(!ok)
	{
		printf("FAILED --- should be true  | test_FileLineReader 6\n ");
	}
	i = 0;
	while(!iCluige.iFileLineReader.feof(&flr, i))
	{
		line = iCluige.iFileLineReader.get_line(&flr, i);
		//printf(line);
		iCluige.iFileLineReader.forget_lines_before(&flr, i);
		i++;
	}
	iCluige.iFileLineReader.close_file(&flr);
	iCluige.iFileLineReader.pre_delete_FileLineReader(&flr);
	//printf("\n end FileLineReader test \n");
}

static void test_TscnParser()
{
	TscnParser parser;
	iCluige.iTscnParser.tscn_parser_alloc(&parser, "assets/test_TscnParser.tscn");//"autre_instancieur.tscn");//"test_tscn_parser.tscn");//"main.tscn = avec instanced = todo later");//
//	bool ok = parser.read_line(&parser);
//	ok = parser.read_line(&parser);
//	ok = parser.ignore_non_node(&parser);
//	ok = parser.node(&parser);
//	ok = parser.node(&parser);
	bool ok = parser.parse_scene(&parser);
	char* dbg = iCluige.iPackedScene.debug_recrusive(parser.scene_root, NULL);
//	utils_cluige_printf(0, 0, dbg);
	if(!ok)
	{
		printf("FAILED --- should be true  | test_TscnParser %d\n ", 1);
	}
	if(dbg == NULL)
	{
		printf("FAILED --- should be not null  | test_TscnParser %d\n ", 2);
	}
	utils_breakpoint_trick(&ok, false);
	utils_breakpoint_trick(dbg, false);
//	printf("%s\n\n", dbg);
	if(false)
	{ //don't re-generate unless wanted evolution in those test results
		FILE* bkp = fopen("assets/test_TscnParser__wanted_res.txt", "w");
		fprintf(bkp, dbg);
		fclose(bkp);
	}
	iCluige.iTscnParser.pre_delete_TscnParser(&parser);
	FileLineReader wanted_res_flr;
	iCluige.iFileLineReader.fileLineReader_alloc(&wanted_res_flr, 200);
	iCluige.iFileLineReader.open_file_start_reader(&wanted_res_flr, "assets/test_TscnParser__wanted_res.txt");
	int i = 0;
	char sub_dbg[200];
	int dbg_cursor = 0;
	while(!iCluige.iFileLineReader.feof(&wanted_res_flr, i))
	{
		const char* wanted_line = iCluige.iFileLineReader.get_line(&wanted_res_flr, i);
		size_t line_len = strcspn(dbg + dbg_cursor, "\n") + 1;
		assert(line_len < 199);
		strncpy(sub_dbg, dbg + dbg_cursor, line_len);
		*(sub_dbg + line_len) = '\0';
		if(strcmp(wanted_line, sub_dbg) != 0)
		{
			utils_breakpoint_trick(sub_dbg, true);
			printf("FAILED --- parsing inconsistant with last known in test_TscnParser__wanted_res.txt line %d  | test_TscnParser \n ", i+1);
			printf("\t%s \t\tshould be \n\t%s\n", sub_dbg, wanted_line);
		}
		iCluige.iFileLineReader.forget_lines_before(&wanted_res_flr, i);
		dbg_cursor += line_len;
		i++;
	}
	iCluige.iFileLineReader.close_file(&wanted_res_flr);
	iCluige.iFileLineReader.pre_delete_FileLineReader(&wanted_res_flr);
	iCluige.iPackedScene.pre_delete_PackedScene(parser.scene_root);
	free(parser.scene_root);
	free(dbg);
}

static const Node* test_node_against_packed_scene(const Node* n, const PackedScene* ps)
{
	bool found;
	const char* ps_type = ps->type;
	if(strcmp(ps_type, "Node") == 0)
	{
		if(strcmp(ps->name, n->name) != 0)
		{
			return n;
		}
	}
	const Node2D* n_2D = (const Node2D*)(n->_sub_class);
	if(strncmp(n->_class_name, "NodeNode2D", 10) == 0)
	{
		bool ps_visible;
		found = utils_bool_from_parsed(&ps_visible, &(ps->dico_node), "visible");
		if(found)
		{
			if(ps_visible != n_2D->visible)
			{
				return n;
			}
		}
		Vector2 ps_pos;
		found = utils_vector2_from_parsed(&ps_pos, &(ps->dico_node), "position");
		if(found)
		{
			if(iCluige.iVector2.distance_squared_to(&ps_pos, &(n_2D->position)) > iCluige.EPSILON)
			{
				return n;
			}
		}
	}
	if(strncmp(n->_class_name, "NodeNode2DSpriteText", 10) == 0)
	{
		const SpriteText* n_SprtTxt = (const SpriteText*)(n_2D->_sub_class);
		Vector2 ps_offset;
		found = utils_vector2_from_parsed(&ps_offset, &(ps->dico_node), "offset");
		if(found)
		{
			if(iCluige.iVector2.distance_squared_to(&ps_offset, &(n_SprtTxt->offset)) > iCluige.EPSILON)
			{
				return n;
			}
		}
		char* ps_txt;
		found = utils_str_from_parsed(&ps_txt, &(ps->dico_node), "text");
		if(found)
		{
			int first_line_len = strlen(n_SprtTxt->text);
			if(strncmp(ps_txt, n_SprtTxt->text, first_line_len) != 0)
			{
				return n;
			}
		}
	}
	else if(strncmp(n->_class_name, "NodeNode2DSpriteSVG", 10) == 0)
	{
		const SpriteSVG* n_SprtSVG = (const SpriteSVG*)(n_2D->_sub_class);
		Vector2 ps_offset;
		found = utils_vector2_from_parsed(&ps_offset, &(ps->dico_node), "offset");
		if(found)
		{
			if(iCluige.iVector2.distance_squared_to(&ps_offset, &(n_SprtSVG->offset)) > iCluige.EPSILON)
			{
				return n;
			}
		}
		Vector2 ps_scale;
		found = utils_vector2_from_parsed(&ps_scale, &(ps->dico_node), "scale");
		if(found)
		{
			if(iCluige.iVector2.distance_squared_to(&ps_scale, &(n_SprtSVG->scale)) > iCluige.EPSILON)
			{
				return n;
			}
		}
	}
	utils_breakpoint_trick(ps, 00=="warning : found type is not (yet) tested in PackedScene/Node");
	return NULL;
}

static const Node* test_node_against_packed_scene_tree(const Node* n, const PackedScene* ps)
{
	const Node* ok = test_node_against_packed_scene(n, ps);
	if(ok != NULL)
	{
		return ok;
	}
	int nb_chd =iCluige.iDeque.size(&(ps->children));
	for(int i = 0; i < nb_chd; i++)
	{
		const PackedScene* child_ps = (const PackedScene*)(iCluige.iDeque.at(&(ps->children), i).ptr);
		const Node* child_nde = iCluige.iNode.get_child(n , i);
		const Node* ook = test_node_against_packed_scene_tree(child_nde, child_ps);
		if(ook != NULL)
		{
			return ook;
		}
	}
	return NULL;
}

static void test_pksc_instanciate()
{
	TscnParser parser;
	iCluige.iTscnParser.tscn_parser_alloc(&parser, "assets/test_pksc_instanciate.tscn");
	bool ok = parser.parse_scene(&parser);
	utils_breakpoint_trick(&ok, false);
//	char* dbg = iCluige.iPackedScene.debug_recrusive(parser.scene_root, NULL);
	PackedScene* ps = parser.scene_root;
	Node* my_game_root_node = iCluige.iPackedScene.instanciate(ps);
	iCluige.iNode.add_child(iCluige.public_root_2D, my_game_root_node);
	iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);

//	Node2D* zzzzzzz = (Node2D*)(my_game_root_node->_sub_class);
//	iCluige.iNode2D.move_local(zzzzzzz, (Vector2){ 1.f, 1.f });

//	PackedScene* pps = iCluige.iPackedScene.get_packed_node(ps, "UnLabel");
//	SortedDictionary* ppd = &(pps->dico_node);
//	Checked_Variant got = iCluige.iSortedDictionary.get(ppd, "text");
//	char* got_val = (char*)(got.v.ptr);
//	got_val[1] = 'W';

//	Node* nn = iCluige.iNode.get_node(my_game_root_node, "Un _ = Sprite2D");
//	Node2D* dd = (Node2D*)(nn->_sub_class);
//	SpriteText* tt = (SpriteText*)(dd->_sub_class);
////	iCluige.iNode2D.move_local(dd, (Vector2){ 1.f, 1.f });
//	tt->offset.x++;

//	Node* nn = iCluige.iNode.get_node(my_game_root_node, "Un _ = Sprite2D/UnSousSprite2D/UnNode2D");
//	Node2D* dd = (Node2D*)(nn->_sub_class);
////	iCluige.iNode2D.move_local(dd, (Vector2){ -1.f, -1.f });
//	dd->visible = !(dd->visible);

//	Node* nn = iCluige.iNode.get_node(my_game_root_node, "unLabelFourbe");//UnAutreLabel");
//	Node2D* dd = (Node2D*)(nn->_sub_class);
//	SpriteText* tt = (SpriteText*)(dd->_sub_class);
//	char* got_val = tt->text;
//	got_val[1] = 'W';

	const Node* diff = test_node_against_packed_scene_tree(my_game_root_node, ps);

	if(diff != NULL)
	{
		char* pp = iCluige.iNode.get_path_mallocing(diff);
		printf("FAILED --- instanced Node %s different from PackedScene  | test_pksc_instanciate\n ", pp);
		free(pp);
	}

	iCluige.iPackedScene.pre_delete_PackedScene(ps);
	iCluige.iTscnParser.pre_delete_TscnParser(&parser);
}


void tscn_parser_all_tests()
{
	printf("\n ----------------------------------------------------   -- start of tscn_parser tests\n");
	printf("\nTest utils_*_from_parsed methods -----------------------------------------------------------------------------\n");
	test_utils_bool_from_parsed();
	test_utils_char_from_parsed();
	test_utils_str_from_parsed();

	printf("\nTest parsing methods -----------------------------------------------------------------------------\n");
	test_FileLineReader();
	test_TscnParser();

	printf("\nTest instanciate methods -----------------------------------------------------------------------------\n");
	SortedDictionary parse_placeholder;
	iCluige.iSortedDictionary.sorted_dictionary_alloc(&parse_placeholder, VT_POINTER, VT_POINTER, 10);
	iCluige.iSortedDictionary.set_compare_keys_func(&parse_placeholder, iCluige.iDeque.default_compare_string_func);
	iCluige.iSortedDictionary.insert(&parse_placeholder, "name", "O_Racine");
//	Node* my_root = iCluige.iNode.new_Node();
//	iCluige.iNode.deserialize_dico(my_root, &parse_placeholder);
	SortedDictionary* fcties = &(iCluige.iNode.node_factories);
	Checked_Variant cv_fcty = iCluige.iSortedDictionary.get(fcties, "Node");
	NodeFactory* fcty = (NodeFactory*)(cv_fcty.v.ptr);
	Node* my_root = fcty->instanciate(&parse_placeholder);
	utils_breakpoint_trick(my_root, false);//to prevent warning my_root not used

	test_Node_instanciate();
	test_Node2D_instanciate();
	test_SpriteText_instanciate();
	test_SpriteSVG_instanciate();
	test_pksc_instanciate();

	printf("\n ----------------------------------------------------	  end of tscn_parser tests --\n");
}


