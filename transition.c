//#include <stdlib.h> //already in cluige.h
//#include <stddef.h> //already in cluige.h
#include <cluige.h>
#include "common_test.h"
#include "transition.h"

//graphical tests
#include "camera_test.h"


struct _TransitionScript
{
	Script* this_Script;
	int next;
	Node* helpSprite;
};
typedef struct _TransitionScript TransitionScript;


static void process_Transition(Script* this_Script, float elapsed_seconds)
{
	TransitionScript* this_Transition =
		(TransitionScript*)(this_Script->_sub_class);
//	Node* this_node = this_Script->node;
	struct iiInput* iii = &iCluige.iInput;

	if(iii->is_action_just_pressed(NEXT))
	{
		if(this_Transition->next == 0)
		{
			this_Transition->next++;
			iCluige.iNode.queue_free(this_Transition->helpSprite);
			inputs_camera();
			launch_camera();
		}
		else if(this_Transition->next == 1)
		{
			this_Transition->next++;
			end_camera_test();
		}
		else if(this_Transition->next == 2)
		{
			iCluige.iNode.queue_free(this_Script->node);
			iCluige.quit_asked = true;
		}
	}
//	if(iii->is_action_just_pressed(EXIT_ACTION))
//	{
//		iCluige.quit_asked = true;
//	}
}

TransitionScript* newTransition(Node* this_Node)
{
	Script* new_Script = iCluige.iScript.new_Script(this_Node);
	TransitionScript* newTransition = iCluige.checked_malloc(sizeof(TransitionScript));

	newTransition->this_Script = new_Script;
	newTransition->next = 0;

	new_Script->node = this_Node;
	new_Script->process = process_Transition;
	new_Script->_sub_class = newTransition;
	this_Node->script = new_Script;

	SpriteText* helpSpriteText = iCluige.iSpriteText.new_SpriteText();
	Node2D* helpNode2D = helpSpriteText->_this_Node2D;
	Node* helpNode = helpNode2D->_this_Node;
	newTransition->helpSprite = helpNode2D->_this_Node;
	iCluige.iSpriteText.set_text(helpSpriteText,
//		" ~ instructions ~\n Next phase : N\n eXit       : X\n");
		" ~ instructions ~\n Next phase : N\n");
//	Camera2D* cam = iCluige.iCamera2D.current_camera;
//	Node2D* camNde2D = cam->_this_Node2D;
	iCluige.iNode.add_child(this_Node, helpNode);
	iCluige.iNode2D.set_local_position(helpNode2D, (Vector2){ 6, 4 });
	return newTransition;
}

void init_transition()
{
	//gameroot node
	Node* transitionNode = iCluige.iNode.new_Node();
	iCluige.iNode.set_name(transitionNode, "Transition");
	iCluige.iNode.add_child(iCluige.public_root_2D, transitionNode);
	newTransition(transitionNode);// attach script to The Transition node

	NEXT = iCluige.iInput.add_action("NEXT");
	iCluige.iInput.bind_key(NEXT, 'n');
	iCluige.iInput.bind_key(NEXT, 'N');

//	EXIT_ACTION = iCluige.iInput.add_action("EXIT_ACTION");
//	iCluige.iInput.bind_key(EXIT_ACTION, 'x');
//	iCluige.iInput.bind_key(EXIT_ACTION, 'X');
}

