//#include <stdlib.h> //already in cluige.h
//#include <stddef.h> //already in cluige.h
#include <cluige.h>
#include "common_test.h"
#include "transition.h"

//graphical tests
#include "tree_test.h"
#include "recursive_tscn_test.h"
#include "camera_test.h"

//re-declared because extern in .h (like static in c++)
//int UP;
//...
int NEXT;
//int JUMP;

TestStep* allSteps;

struct _TransitionScript
{
	Script* this_Script;
	int next;
	Node2D* help_Node2D;
	SpriteText* help_SpriteText;
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

		if(allSteps[this_Transition->next].started == NULL)
		{
			iCluige.iNode.queue_free(this_Script->node);
			iCluige.quit_asked = true;
		}
		else if(!*(allSteps[this_Transition->next].started))
		{
			iCluige.iNode2D.hide(this_Transition->help_Node2D);
			allSteps[this_Transition->next].inputs();
			allSteps[this_Transition->next].launch();
		}
		else
		{
			allSteps[this_Transition->next].finish();
			this_Transition->next++;
			iCluige.iSpriteText.set_text(this_Transition->help_SpriteText,
					allSteps[this_Transition->next].help_text);
			iCluige.iNode2D.show(this_Transition->help_Node2D);
		}
	}
}

TransitionScript* newTransition(Node* this_Node)
{
	Script* new_Script = iCluige.iScript.new_Script();
	iCluige.iNode.set_script(this_Node, new_Script);
	TransitionScript* newTransition = iCluige.checked_malloc(sizeof(TransitionScript));

	newTransition->this_Script = new_Script;
	newTransition->next = 0;

	new_Script->process = process_Transition;
	new_Script->_sub_class = newTransition;

	SpriteText* help_SpriteText = iCluige.iSpriteText.new_SpriteText();
	Node2D* help_Node2D = help_SpriteText->_this_Node2D;
	Node* help_Node = help_Node2D->_this_Node;
	newTransition->help_Node2D = help_Node2D;
	newTransition->help_SpriteText = help_SpriteText;
	iCluige.iSpriteText.set_text(help_SpriteText,
			allSteps[0].help_text);
	iCluige.iNode.add_child(this_Node, help_Node);
	iCluige.iNode2D.set_local_position(help_Node2D, (Vector2){ 6, 4 });
	return newTransition;
}

void init_transition()
{
	const int NB_TESTS = 3;
	allSteps = iCluige.checked_malloc((NB_TESTS + 1) * sizeof(TestStep));
	//never freed, because app-long life
	int c = 0;
	allSteps[c++] = make_tree_test_step();
	allSteps[c++] = make_camera_test_step();
	allSteps[c++] = make_recursive_tscn_test_step();
	allSteps[c++] = (TestStep){ NULL, NULL, NULL, NULL,
"\
 ~ End of last test ~\n\
 \n\
 Exit : N"
	};
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

