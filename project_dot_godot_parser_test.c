//#include <stdlib.h> //already in cluige.h
//#include <stddef.h> //already in cluige.h
#include <cluige.h>
#include <assert.h>
//#include <math.h>
#include "project_dot_godot_parser_test.h"


static void test__comment()
{
	ProjectDotGodotParser pdgp;
	iCluige.iProjectDotGodotParser.project_dot_godot_parser_alloc(&pdgp, "assets/project.godot");
	bool ok = pdgp._comment(&pdgp);
	if(!ok)
	{
		printf("FAILED --- should be true | %s %d\n ",
			__FUNCTION__, 0);
		utils_breakpoint_trick(&ok, true);
	}
	const char* wanted_str = "; Engine configuration file.\n";
	const char* read_str = pdgp._dbg_curr_line(&pdgp);
	if(!str_equals(read_str, wanted_str))
	{
		printf("FAILED --- unexpected '%s' instead of '%s' | %s %d\n ", read_str, wanted_str,
			__FUNCTION__, 1);
		utils_breakpoint_trick(&ok, true);
	}
	iCluige.iProjectDotGodotParser.pre_delete_ProjectDotGodotParser(&pdgp);
}

static void test__blank_line()
{
	ProjectDotGodotParser pdgp;
	iCluige.iProjectDotGodotParser.project_dot_godot_parser_alloc(&pdgp, "assets/project.godot");
	bool ok = pdgp._comment(&pdgp);
	while(ok)
	{
		pdgp._current_line_i++;
		ok = pdgp._comment(&pdgp);
	}
	ok = pdgp._blank_line(&pdgp);
	if(!ok)
	{
		printf("FAILED --- should be true | %s %d\n ",
			__FUNCTION__, 0);
		utils_breakpoint_trick(&ok, true);
	}
	const char* wanted_str = "\n";
	const char* read_str = pdgp._dbg_curr_line(&pdgp);
	if(!str_equals(read_str, wanted_str))
	{
		printf("FAILED --- unexpected '%s' instead of '%s' | %s %d\n ", read_str, wanted_str,
			__FUNCTION__, 1);
		utils_breakpoint_trick(&ok, true);
	}
	iCluige.iProjectDotGodotParser.pre_delete_ProjectDotGodotParser(&pdgp);
}

static void test__section()
{
	ProjectDotGodotParser pdgp;
	iCluige.iProjectDotGodotParser.project_dot_godot_parser_alloc(&pdgp, "assets/project.godot");
	bool ok = pdgp._section(&pdgp);
	while(!ok)
	{
		pdgp._current_line_i++;
		ok = pdgp._section(&pdgp);
	}
	if(!ok)
	{
		printf("FAILED --- should be true | %s %d\n ",
			__FUNCTION__, 0);
		utils_breakpoint_trick(&ok, true);
	}
	const char* wanted_str = "[accessibility]\n";
	const char* read_str = pdgp._dbg_curr_line(&pdgp);
	if(!str_equals(read_str, wanted_str))
	{
		printf("FAILED --- unexpected '%s' instead of '%s' | %s %d\n ", read_str, wanted_str,
			__FUNCTION__, 1);
		utils_breakpoint_trick(&ok, true);
	}
	iCluige.iProjectDotGodotParser.pre_delete_ProjectDotGodotParser(&pdgp);
}

static void test__ignored()
{
	ProjectDotGodotParser pdgp;
	iCluige.iProjectDotGodotParser.project_dot_godot_parser_alloc(&pdgp, "assets/project.godot");
	bool ok = pdgp._ignored(&pdgp);
	while(ok)
	{
		pdgp._current_line_i++;
		ok = pdgp._ignored(&pdgp);
	}
	if(ok)
	{
		printf("FAILED --- should be false | %s %d\n ",
			__FUNCTION__, 0);
		utils_breakpoint_trick(&ok, true);
	}
	const char* wanted_str = "config_version=5\n";
	const char* read_str = pdgp._dbg_curr_line(&pdgp);
	if(!str_equals(read_str, wanted_str))
	{
		printf("FAILED --- unexpected '%s' instead of '%s' | %s %d\n ", read_str, wanted_str,
			__FUNCTION__, 1);
		utils_breakpoint_trick(&ok, true);
	}
	pdgp._current_line_i++;
	ok = pdgp._ignored(&pdgp);
	while(ok)
	{
		pdgp._current_line_i++;
		ok = pdgp._ignored(&pdgp);
	}
	if(ok)
	{
		printf("FAILED --- should be false | %s %d\n ",
			__FUNCTION__, 2);
		utils_breakpoint_trick(&ok, true);
	}
	wanted_str = "general/accessibility_support=2\n";
	read_str = pdgp._dbg_curr_line(&pdgp);
	if(!str_equals(read_str, wanted_str))
	{
		printf("FAILED --- unexpected '%s' instead of '%s' | %s %d\n ", read_str, wanted_str,
			__FUNCTION__, 3);
		utils_breakpoint_trick(&ok, true);
	}
	iCluige.iProjectDotGodotParser.pre_delete_ProjectDotGodotParser(&pdgp);
}

static void test__param_value()
{
	ProjectDotGodotParser pdgp;
	iCluige.iProjectDotGodotParser.project_dot_godot_parser_alloc(&pdgp, "assets/project.godot");
	bool ok = pdgp._ignored(&pdgp);
	while(ok)
	{
		pdgp._current_line_i++;
		ok = pdgp._ignored(&pdgp);
	}

	//case key=unquoted
	ok = pdgp._param(&pdgp);
	if(!ok)
	{
		printf("FAILED --- should be true | %s %d\n ",
			__FUNCTION__, 0);
		utils_breakpoint_trick(&ok, true);
	}
	char* dbg_dic = iCluige.iSortedDictionary.debug_str_str(&(pdgp._dico_params));
	char* wanted_str = "/config_version = 5\n - nb elems : 1";
	if(!str_equals(dbg_dic, wanted_str))
	{
		printf("FAILED --- unexpected '%s' instead of '%s' | %s %d\n ", dbg_dic, wanted_str,
			__FUNCTION__, 1);
		utils_breakpoint_trick(&ok, true);
	}
	free(dbg_dic);
	iCluige.iSortedDictionary.erase(&(pdgp._dico_params), "/config_version");
//	dbg_dic = iCluige.iSortedDictionary.debug_str_str(&(pdgp._dico_params));

	//case key=quoted
	pdgp._current_line_i = 17;
	ok = pdgp._param(&pdgp);
	if(!ok)
	{
		printf("FAILED --- should be true | %s %d\n ",
			__FUNCTION__, 2);
		utils_breakpoint_trick(&ok, true);
	}
	dbg_dic = iCluige.iSortedDictionary.debug_str_str(&(pdgp._dico_params));
	wanted_str = "/config/name = \"bigDotGodot\"\n - nb elems : 1";
	if(!str_equals(dbg_dic, wanted_str))
	{
		printf("FAILED --- unexpected '%s' instead of '%s' | %s %d\n ", dbg_dic, wanted_str,
			__FUNCTION__, 3);
		utils_breakpoint_trick(&ok, true);
	}
	free(dbg_dic);
	iCluige.iSortedDictionary.erase(&(pdgp._dico_params), "/config/name");
//	dbg_dic = iCluige.iSortedDictionary.debug_str_str(&(pdgp._dico_params));

	//case key=quoted multi-line
	pdgp._current_line_i = 21;
	ok = pdgp._param(&pdgp);
	if(!ok)
	{
		printf("FAILED --- should be true | %s %d\n ",
			__FUNCTION__, 4);
		utils_breakpoint_trick(&ok, true);
	}
	dbg_dic = iCluige.iSortedDictionary.debug_str_str(&(pdgp._dico_params));
	wanted_str =
"/config/description = \"une descr éàçÎ'\n\
deuxième ligne guillemet : \\\"\n\
troisième ligne sans eol\"\n\
 - nb elems : 1";

	if(!str_equals(dbg_dic, wanted_str))
	{
		printf("FAILED --- unexpected '%s' instead of '%s' | %s %d\n ", dbg_dic, wanted_str,
			__FUNCTION__, 5);
		utils_breakpoint_trick(&ok, true);
	}
	free(dbg_dic);
	iCluige.iSortedDictionary.erase(&(pdgp._dico_params), "/config/description");

	//case key=bracketed multi-line
	iCluige.iFileLineReader.forget_lines_before(pdgp._file_line_reader, 21);
	pdgp._current_line_i = 57;
	ok = pdgp._param(&pdgp);
	if(!ok)
	{
		printf("FAILED --- should be true | %s %d\n ",
			__FUNCTION__, 6);
		utils_breakpoint_trick(&ok, true);
	}
	dbg_dic = iCluige.iSortedDictionary.debug_str_str(&(pdgp._dico_params));
	wanted_str =
"/gdscript/warnings/directory_rules = {\n\
\"\": 0,\n\
\"res://addons\": 0\n\
}\n\
 - nb elems : 1";

	if(!str_equals(dbg_dic, wanted_str))
	{
		printf("FAILED --- unexpected '%s' instead of '%s' | %s %d\n ", dbg_dic, wanted_str,
			__FUNCTION__, 7);
		utils_breakpoint_trick(&ok, true);
	}
	free(dbg_dic);
	iCluige.iSortedDictionary.erase(&(pdgp._dico_params), "/gdscript/warnings/directory_rules");

	//case non-param should be false
	iCluige.iFileLineReader.forget_lines_before(pdgp._file_line_reader, 57);
	pdgp._current_line_i = 67;
	ok = pdgp._param(&pdgp);
	if(ok)
	{
		printf("FAILED --- should be false | %s %d\n ",
			__FUNCTION__, 8);
		utils_breakpoint_trick(&ok, true);
	}
	pdgp._current_line_i = 68;
	ok = pdgp._param(&pdgp);
	if(ok)
	{
		printf("FAILED --- should be false | %s %d\n ",
			__FUNCTION__, 9);
		utils_breakpoint_trick(&ok, true);
	}

	iCluige.iProjectDotGodotParser.pre_delete_ProjectDotGodotParser(&pdgp);
}

static void test__parse_whole()
{
	ProjectDotGodotParser pdgp;
	iCluige.iProjectDotGodotParser.project_dot_godot_parser_alloc(&pdgp, "assets/project.godot");
	bool ok = pdgp._parse_whole(&pdgp);
	if(!ok)
	{
		printf("FAILED --- should be true | %s %d\n ",
			__FUNCTION__, 0);
		utils_breakpoint_trick(&ok, true);
	}
	SortedDictionary* dic = &(pdgp._dico_params);
	int n = iCluige.iSortedDictionary.size(dic);
	if(n != 192)
	{
		printf("FAILED --- unexpected %d instead of 192 | %s %d\n ", n,
			__FUNCTION__, 1);
		utils_breakpoint_trick(&ok, true);
	}

//	char* dbg_dic = iCluige.iSortedDictionary.debug_str_str(&(pdgp._dico_params));
//	printf(dbg_dic);
//	free(dbg_dic);

	SortedDictionary* dic_in = &(pdgp._dico_inputs);
	char read_inputs[300];
	read_inputs[0] = '\0';
	StringBuilder sb;
	iCluige.iStringBuilder.connect_existing_string(&sb, read_inputs, 299);
	int d_n = iCluige.iSortedDictionary.size(dic_in);
	for(int i=0; i<d_n; i++)
	{
		Pair pair_i = iCluige.iSortedDictionary.at(dic_in, i);
		const char* key = (const char*)(pair_i.first.ptr);
		Deque* dq = (Deque*)(pair_i.second.ptr);
		int m = iCluige.iDeque.size(dq);
		if(m > 0)
		{
			iCluige.iStringBuilder.append(&sb,"%s : [", key);
		}
		for(int j=0; j<m; j++)
		{
			int64_t uni = iCluige.iDeque.at(dq, j).i64;
			iCluige.iStringBuilder.append(&sb,"  uni:%ld=%d ", uni, (int)uni);
		}
		if(m > 0)
		{
			iCluige.iStringBuilder.append(&sb,"]\n", key);
		}
	}
//	printf("\n%s\n\n", read_inputs);
	char* wanted_str =
"\
bra{ck}eted : [  uni:123=123 ]\n\
ui_copy : [  uni:67=67 ]\n\
ui_cut : [  uni:88=88 ]\n\
ui_down : [  uni:115=115 ]\n\
ui_focus_mode : [  uni:77=77 ]\n\
ui_paste : [  uni:86=86 ]\n\
ui_redo : [  uni:90=90   uni:89=89 ]\n\
ui_undo : [  uni:90=90 ]\n\
ui_up : [  uni:122=122 ]\n\
";
	if(!str_equals(read_inputs, wanted_str))
	{
		printf("FAILED --- unexpected \n%s\n instead of \n%s | %s %d\n ", read_inputs, wanted_str,
			__FUNCTION__, 2);
		utils_breakpoint_trick(read_inputs, true);
	}

	iCluige.iProjectDotGodotParser.pre_delete_ProjectDotGodotParser(&pdgp);
}

void project_dot_godot_parser_all_tests()
{
	printf("\n ----------------------------------------------------   -- start of project_dot_godot_parser tests\n");

	test__comment();
	test__blank_line();
	test__section();
	test__ignored();
	test__param_value();
	test__parse_whole();
	//test_run(); // in graph tests instead of printf tests

	//clear all
}


