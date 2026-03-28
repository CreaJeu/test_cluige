#include <cluige.h>
#include "tenth_of_screen.h"
#include "../../common_test.h"


Script* instantiate_TenthOfScreenScript(const SortedDictionary* parsed_params)
{
	//mallocs
	Script* new_Script = iCluige.iScript.new_Script();
	TenthOfScreenScript* new_TenthOfScreenScript = iCluige.checked_malloc(sizeof(TenthOfScreenScript));
	new_Script->_sub_class = new_TenthOfScreenScript;
//	new_TenthOfScreenScript->_this_Script = new_Script;

	//instantiate fields
	bool found = utils_float_from_parsed(&(new_TenthOfScreenScript->speed), parsed_params, "speed");
	if(!found)
	{
		new_TenthOfScreenScript->speed = 3;//default value from .gd
	}

	//plug virtual mehods
	new_TenthOfScreenScript->_delete_super = new_Script->delete_Script;
	new_Script->delete_Script = delete_TenthOfScreenScript;
	new_Script->process = process_TenthOfScreenScript;
	return new_Script;
}

void delete_TenthOfScreenScript(Script* this_Script)
{
	TenthOfScreenScript* this_TenthOfScreenScript =
			(TenthOfScreenScript*)(this_Script->_sub_class);
	//tmp memorize function pointer before calling free(this)
	void (*delete_super)(Script*) = this_TenthOfScreenScript->_delete_super;
	free(this_TenthOfScreenScript);
	this_Script->_sub_class = NULL;
	delete_super(this_Script);
}

void process_TenthOfScreenScript(Script* this_Script, float delta)
{
	TenthOfScreenScript* this_TenthOfScreenScript =
			(TenthOfScreenScript*)(this_Script->_sub_class);
	float dx = 0;
	float dy = 0;
	if(iCluige.iInput.is_action_just_pressed(UP))
	{
		dy -= this_TenthOfScreenScript->speed;
	}
	if(iCluige.iInput.is_action_just_pressed(DOWN))
	{
		dy += this_TenthOfScreenScript->speed;
	}
	if(iCluige.iInput.is_action_just_pressed(LEFT))
	{
		dx -= this_TenthOfScreenScript->speed;
	}
	if(iCluige.iInput.is_action_just_pressed(RIGHT))
	{
		dx += this_TenthOfScreenScript->speed;
	}
	Node2D* this_Node2D = (Node2D*)(this_Script->node->_sub_class);
	iCluige.iNode2D.move_local(this_Node2D, (Vector2){dx * delta, dy * delta});
}
