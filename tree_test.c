//#include <stdlib.h> //already in cluige.h
//#include <stddef.h> //already in cluige.h
#include <cluige.h>
#include "common_test.h"
#include "tree_test.h"

int nb_cumul_enter_tree = 0;
int nb_cumul_ready = 0;
int nb_cumul_exit_tree = 0;
int test_tree_step = 0;

int genealogy_nb_enter_tree = 0;
int genealogy_nb_ready = 0;

struct _MonsterScript
{
	Script* this_Script;
	int monster_id;
	int nb_enter_tree;
	int nb_ready;
	int nb_exit_tree;
	int last_seen_test_tree_step;
};
static void process_Monster(Script* this_Script, float elapsed_seconds);
static void enter_tree_Monster(Script*);
static void ready_Monster(Script*);
static void exit_tree_Monster(Script*);

struct _GenealogyMonsterScript
{
	Script* this_Script;
	int monster_id;
	int nb_enter_tree;
	int nb_ready;
};
static void enter_tree_GenealogyMonster(Script*);
static void ready_GenealogyMonster(Script*);

struct _MonitorScript
{
	Script* this_Script;
};
static void process_Monitor(Script* this_Script, float elapsed_seconds);

struct _MonsterScript* new_Monster(Node* this_Node)
{
	Script* new_Script = iCluige.iScript.new_Script(this_Node);
	struct _MonsterScript* new_monster = iCluige.checked_malloc(sizeof(struct _MonsterScript));

	new_monster->this_Script = new_Script;
	new_monster->nb_enter_tree = 0;
	new_monster->nb_ready = 0;
	new_monster->nb_exit_tree = 0;
	new_monster->last_seen_test_tree_step = 0;

	new_Script->process = process_Monster;
	new_Script->enter_tree = enter_tree_Monster;
	new_Script->ready = ready_Monster;
	new_Script->exit_tree = exit_tree_Monster;
	new_Script->_sub_class = new_monster;
	this_Node->script = new_Script;
	return new_monster;
}

struct _GenealogyMonsterScript* new_GenealogyMonster(Node* this_Node)
{
	Script* new_Script = iCluige.iScript.new_Script(this_Node);
	struct _GenealogyMonsterScript* new_monster = iCluige.checked_malloc(sizeof(struct _GenealogyMonsterScript));

	new_monster->this_Script = new_Script;
	new_monster->nb_enter_tree = 0;
	new_monster->nb_ready = 0;

	new_Script->enter_tree = enter_tree_GenealogyMonster;
	new_Script->ready = ready_GenealogyMonster;
	new_Script->_sub_class = new_monster;
	this_Node->script = new_Script;
	return new_monster;
}

struct _MonitorScript* new_Monitor(Node* this_Node)
{
	Script* new_Script = iCluige.iScript.new_Script(this_Node);
	struct _MonitorScript* new_monitor = iCluige.checked_malloc(sizeof(struct _MonitorScript));

	new_monitor->this_Script = new_Script;

	new_Script->process = process_Monitor;
	new_Script->_sub_class = new_monitor;
	this_Node->script = new_Script;
	return new_monitor;
}

static void enter_tree_Monster(Script* this_Script)
{
	struct _MonsterScript* this_Monster =
		(struct _MonsterScript*)(this_Script->_sub_class);
	nb_cumul_enter_tree++;
	this_Monster->nb_enter_tree = nb_cumul_enter_tree;
}
static void ready_Monster(Script* this_Script)
{
	struct _MonsterScript* this_Monster =
		(struct _MonsterScript*)(this_Script->_sub_class);
	nb_cumul_ready++;
	this_Monster->nb_ready = nb_cumul_ready;
}
static void exit_tree_Monster(Script* this_Script)
{
	struct _MonsterScript* this_Monster =
		(struct _MonsterScript*)(this_Script->_sub_class);
	nb_cumul_exit_tree++;
	this_Monster->nb_exit_tree = nb_cumul_exit_tree;
}

static void process_Monster(Script* this_Script, float elapsed_seconds)
{
	static char msg[200];
	struct _MonsterScript* this_Monster =
		(struct _MonsterScript*)(this_Script->_sub_class);
	Node2D* this_Node2D = (Node2D*)(this_Script->node->_sub_class);
	SpriteText* this_SpriteText = (SpriteText*)(this_Node2D->_sub_class);
	if(this_Monster->last_seen_test_tree_step == test_tree_step)
	{
		return;
	}
	this_Monster->last_seen_test_tree_step = test_tree_step;
	int nb_passes = test_tree_step/2;
	int nb_old_adds = (nb_passes-1) * 4;
	int nb_removes = this_Monster->monster_id + (nb_passes-2) * 4 + 1;
	if(nb_removes < 0)
	{
		nb_removes = 0;
	}
	sprintf(msg,
"\
%s     : enter_tree=%02d , ready=%02d, exit_tree=%02d\n\
( should be  :            %02d         %02d            %02d )"
,
		this_Script->node->name,
		this_Monster->nb_enter_tree,
		this_Monster->nb_ready,
		this_Monster->nb_exit_tree,
		this_Monster->monster_id + nb_old_adds + 1,
		this_Monster->monster_id + 1,
		nb_removes);
	iCluige.iSpriteText.set_text(this_SpriteText, msg);
}

static void enter_tree_GenealogyMonster(Script* this_Script)
{
	struct _MonsterScript* this_Monster =
		(struct _MonsterScript*)(this_Script->_sub_class);
	genealogy_nb_enter_tree++;
	this_Monster->nb_enter_tree = genealogy_nb_enter_tree;
}

static void ready_GenealogyMonster(Script* this_Script)
{
	static char msg[200];
	struct _GenealogyMonsterScript* this_Monster =
		(struct _GenealogyMonsterScript*)(this_Script->_sub_class);
	Node2D* this_Node2D = (Node2D*)(this_Script->node->_sub_class);
	SpriteText* this_SpriteText = (SpriteText*)(this_Node2D->_sub_class);
	genealogy_nb_ready++;
	this_Monster->nb_ready = genealogy_nb_ready;
	CLUIGE_ASSERT(this_Monster->nb_enter_tree != 0, "FAILED : enter_tree should be called before ready");
	sprintf(msg,
"\
genealogy%d     : enter_tree=%02d , ready=%02d\n\
( should be  :              %02d         %02d )"
,
		this_Monster->monster_id,
		this_Monster->nb_enter_tree,
		this_Monster->nb_ready,
		this_Monster->monster_id + 1,
		4 - this_Monster->monster_id);
	iCluige.iSpriteText.set_text(this_SpriteText, msg);
}

static void process_Monitor(Script* this_Script, float elapsed_seconds)
{
	static Node* monsters[4];
	static Node* genealogy_monsters[4];
	Node* this_Node = this_Script->node;
	Node2D* this_Node2D = (Node2D*)(this_Node->_sub_class);
	SpriteText* this_SpriteText = (SpriteText*)(this_Node2D->_sub_class);
	struct iiInput* iii = &iCluige.iInput;
	if(iii->is_action_just_pressed(JUMP))
	{

		if(test_tree_step == 0)
		{
			test_tree_step++;
			StringBuilder sb;
			char* msg = iCluige.iStringBuilder.string_alloc(&sb, 1000);
			iCluige.iStringBuilder.append(&sb,
				"instructions\n   next sub-test : SPACE\n   next big test : N \n\n");
			for(int i=0; i<4; i++)
			{
				SpriteText* st = iCluige.iSpriteText.new_SpriteText();
				Node* n = st->_this_Node2D->_this_Node;
				char name[9];
				sprintf(name, "monster%d", i);
				iCluige.iNode.set_name(n, name);
				iCluige.iSpriteText.set_text(st, name);
				iCluige.iNode2D.move_local(st->_this_Node2D, (Vector2){24, -2 + (4*(i%2))});
				monsters[i] = n;
				struct _MonsterScript* m = new_Monster(n);
				m->monster_id = i;
				if(m->nb_enter_tree != 0)
				{
					iCluige.iStringBuilder.append(&sb,
							"FAIL ! monster%d.nb_enter_tree = %d, should be 0\n", i, m->nb_enter_tree);
				}
				if(m->nb_exit_tree != 0)
				{
					iCluige.iStringBuilder.append(&sb,
							"FAIL !  monster%d.nb_exit_tree = %d, should be 0\n", i, m->nb_exit_tree);
				}
				if(m->nb_ready != 0)
				{
					iCluige.iStringBuilder.append(&sb,
							"FAIL !      monster%d.nb_ready = %d, should be 0\n", i, m->nb_ready);
				}

				//genealogy monsters
				st = iCluige.iSpriteText.new_SpriteText();
				n = st->_this_Node2D->_this_Node;
				genealogy_monsters[i] = n;
				int g_x = 10;
				int g_y = 3;
				if(i == 0)
				{
					g_x = 1;
					g_y = 30;
				}
				else
				{
					iCluige.iNode.add_child(genealogy_monsters[i-1], n);
				}
				iCluige.iNode2D.hide(st->_this_Node2D);
				iCluige.iNode2D.move_local(st->_this_Node2D, (Vector2){g_x, g_y});
				struct _GenealogyMonsterScript* gm = new_GenealogyMonster(n);
				gm->monster_id = i;
			}
			Node* g_parent = iCluige.iNode.get_node(iCluige.public_root_2D, "Game_tree_test");
			iCluige.iNode.add_child(g_parent, genealogy_monsters[0]);
			if(strlen(msg) > 80)
			{
				iCluige.iNode2D.move_local(this_Node2D, (Vector2){42, 0});
				iCluige.iSpriteText.set_text(this_SpriteText, msg);
			}
			else
			{
				iCluige.iSpriteText.set_text(this_SpriteText,
"\
instructions                       monsters instanciated correctly, continue to add_child them\n\
   next sub-test : SPACE\n\
   next big test : N "
				);
			}
			free(msg);
		}
		else if((test_tree_step % 2) == 1)
		{

			test_tree_step++;
			Node* n = iCluige.iNode.get_node(iCluige.public_root_2D,
					"Game_tree_test/game>dummy0/game>dummy0>dummy0");
			iCluige.iNode.add_child(n, monsters[0]);
			iCluige.iNode.add_child(n, monsters[1]);
			n = iCluige.iNode.get_node(iCluige.public_root_2D,
					"Game_tree_test/game>dummy1/game>dummy1>dummy1");
			iCluige.iNode.add_child(n, monsters[2]);
			iCluige.iNode.add_child(n, monsters[3]);
			iCluige.iSpriteText.set_text(this_SpriteText,
"\
instructions                       -----------continue to remove_child them-------------------\n\
   next sub-test : SPACE\n\
   next big test : N "
			);
			for(int i=0; i<4; i++)
			{
				Node* gm = genealogy_monsters[i];
				Node2D* gm2D = (Node2D*)(gm->_sub_class);
				iCluige.iNode2D.show(gm2D);
			}
		}
		else
		{
			test_tree_step++;
			for(int i=0; i<4; i++)
			{
				Node* monster = monsters[i];
				Node* m_parent = monster->parent;
				iCluige.iNode.remove_child(m_parent, monster);
			}
			iCluige.iSpriteText.set_text(this_SpriteText,
"\
instructions                       continue to add_child them back (they should not be here) \n\
   next sub-test : SPACE\n\
   next big test : N "
			);
		}
	}
}

Node* generate_SpriteText(const char* node_name, Node* parent, const char* text, float x, float y)
{
	SpriteText* st = iCluige.iSpriteText.new_SpriteText();
	Node* n = st->_this_Node2D->_this_Node;
	iCluige.iNode.set_name(n, node_name);
	iCluige.iSpriteText.set_text(st, text);
	iCluige.iNode2D.move_local(st->_this_Node2D, (Vector2){x, y});
	iCluige.iNode.add_child(parent, n);
	return n;
}

void launch_tree_test()
{
//	iCluige.wanted_frame_seconds = 1.666;

	//gameroot node
	Node2D* gameRootNode2D = iCluige.iNode2D.new_Node2D();
	Node* gameRootRootNode = gameRootNode2D->_this_Node;
	iCluige.iNode.set_name(gameRootRootNode, "Game_tree_test");
	iCluige.iNode.add_child(iCluige.public_root_2D, gameRootRootNode);

	//instructions
	Node* monitor_sprite = generate_SpriteText("game>monitor", gameRootRootNode,
"\
instructions\n\
   next sub-test : SPACE\n\
   next big test : N ",
			1, 2);

	//dummy hierarchy
	Node* gd0 = generate_SpriteText("game>dummy0", gameRootRootNode,
			"game>dummy0", 1, 10);
	Node* gd1 = generate_SpriteText("game>dummy1", gameRootRootNode,
			"game>dummy1", 1, 18);
//	Node* gd00 =
	generate_SpriteText("game>dummy0>dummy0", gd0,
			"game>dummy0>dummy0", 18, -2);
//	Node* gd11 =
	generate_SpriteText("game>dummy1>dummy1", gd1,
			"game>dummy1>dummy1", 18, 2);

	new_Monitor(monitor_sprite);
}

void inputs_tree_test()
{
	JUMP = iCluige.iInput.add_action("JUMP");
	iCluige.iInput.bind_key(JUMP, ' ');
}

void end_tree_test()
{
	iCluige.iCamera2D.make_current(iCluige.iCamera2D.default_camera);
	Node* game_root = iCluige.iNode.get_node(iCluige.public_root_2D, "Game_tree_test");
	iCluige.iNode.queue_free(game_root);
}
