//#include <stdlib.h> //already in cluige.h
//#include <stddef.h> //already in cluige.h
#include <cluige.h>
#include "common_test.h"
#include "camera_test.h"



SpriteSVG* godot_svg;
Node2D* playerNode2D;

char  area[MAX_SIZE];


struct _PlayerScript
{
	Script* this_Script;
	int move_speed;
};
typedef struct _PlayerScript PlayerScript;
PlayerScript* newPlayer(Node* this_Node);
static void process_Player(Script* this_Script, float elapsed_seconds);




PlayerScript* newPlayer(Node* this_Node)
{
	Script* new_Script = iCluige.iScript.new_Script(this_Node);
	PlayerScript* newPlayer = iCluige.checked_malloc(sizeof(PlayerScript));

	newPlayer->this_Script = new_Script;
	newPlayer->move_speed = 10;


	new_Script->node = this_Node;
	new_Script->process = process_Player;
	new_Script->_sub_class = newPlayer;
	this_Node->script = new_Script;


	return newPlayer;
}


static void process_Player(Script* this_Script, float elapsed_seconds)
{
	PlayerScript* thisPlayer =
		(PlayerScript*)(this_Script->_sub_class);
	struct iiInput* iii = &iCluige.iInput;

	Camera2D* curr_cam = iCluige.iCamera2D.current_camera;


	//iCluige.iNode2D.move_local(godot_svg->_this_Node2D, (Vector2){0,1});
	if(iii->is_action_just_pressed(UP))
	{
		iCluige.iNode2D.move_local(playerNode2D, (Vector2){0,-thisPlayer->move_speed});
	}
	if(iii->is_action_just_pressed(DOWN))
	{
		iCluige.iNode2D.move_local(playerNode2D, (Vector2){0,thisPlayer->move_speed});
	}
	if(iii->is_action_just_pressed(LEFT))
	{
		iCluige.iNode2D.move_local(playerNode2D, (Vector2){-thisPlayer->move_speed,0});
	}
	if(iii->is_action_just_pressed(RIGHT))
	{
		iCluige.iNode2D.move_local(playerNode2D, (Vector2){thisPlayer->move_speed,0});
	}
	if(iii->is_action_just_pressed(ZOOM))
	{
		iCluige.iCamera2D.set_zoom(curr_cam,(Vector2){0.25, 0.25});
	}
	if(iii->is_action_just_pressed(ROT_90))
	{
		iCluige.iCamera2D.set_zoom(curr_cam,(Vector2){2,2});
	}
	if(iii->is_action_just_pressed(ROT_180))
	{
		float angle = iCluige.iCamera2D.get_rotation_degrees(curr_cam);
		iCluige.iCamera2D.set_rotation_degrees(curr_cam,angle += 10);
	}
	if(iii->is_action_just_pressed(ROT_45))
	{
		float angle = iCluige.iCamera2D.get_rotation_degrees(curr_cam);
		iCluige.iCamera2D.set_rotation_degrees(curr_cam,angle -= 10);
	}
//	if(iii->is_action_just_pressed(ROT_270))
//	{
//		curr_cam->rotation_radians = 3 * PI / 2;
//	}

	//DEBUG
	static char debug_str[100];
	sprintf(debug_str, "%.2f,%.2f,%.2f,%.2f",
		 iCluige.iCamera2D.current_camera->_tmp_limited_offseted_global_position.x,
		 iCluige.iCamera2D.current_camera->_tmp_limited_offseted_global_position.y,
		 godot_svg->_this_Node2D->position.x,
		 godot_svg->_this_Node2D->position.y);
//	static char strPositionXPlayer[50], strPositionYPlayer[50], strPositionXSprite[50], strPositionYSprite[50]
//	,strPosXCal[50], strPosYCal[50],strPosXCaliInter[50] ,strPosYCalInter[50];

//	sprintf(strPositionXPlayer,"%.2f",iCluige.iCamera2D.current_camera->_tmp_limited_offseted_global_position.x);
//	sprintf(strPositionYPlayer,"%.2f",iCluige.iCamera2D.current_camera->_tmp_limited_offseted_global_position.y);
//	sprintf(strPositionXSprite,"%.2f",godot_svg->_this_Node2D->position.x);
//	sprintf(strPositionYSprite,"%.2f",godot_svg->_this_Node2D->position.y);
	/*
	sprintf(strPosXCal,"%.2f",iCluige.iCamera2D.res_x_1);
	sprintf(strPosYCal,"%.2f",iCluige.iCamera2D.res_y_1);

	sprintf(strPosXCaliInter,"%.2f",iCluige.iCamera2D.res_x_2);
	sprintf(strPosYCalInter,"%.2f",iCluige.iCamera2D.res_y_2);
*/

//	static char* debug_str = malloc(MAX_SIZE * sizeof(char));
//	strcpy(debug_str, "");
//	strcat(debug_str,strPositionXPlayer);
//	strcat(debug_str, ",");
//	strcat(debug_str,strPositionYPlayer);
//	strcat(debug_str, ",");
//	strcat(debug_str,strPositionXSprite);
//	strcat(debug_str, ",");
//	strcat(debug_str,strPositionYSprite);
//	strcat(debug_str, ",");
//	strcat(debug_str,strPosXCal);
//	strcat(debug_str, ",");
//	strcat(debug_str,strPosYCal);
//	strcat(debug_str, ",");
//	strcat(debug_str,strPosXCaliInter);
//	strcat(debug_str, ",");
//	strcat(debug_str,strPosYCalInter);
//	printf(debug_str);


	int last_sib_i = iCluige.iNode.get_child_count(playerNode2D->_this_Node) - 1;
	Node* testnde = iCluige.iNode.get_child(playerNode2D->_this_Node, last_sib_i);
	Node2D* test2D = (Node2D*) (testnde->_sub_class);
	SpriteText* test_sprite_text = (SpriteText*) (test2D->_sub_class);
	if(!str_equals(debug_str, test_sprite_text->text))
	{
		iCluige.iSpriteText.set_text(test_sprite_text,debug_str);
	}
	//free(debug_str);



}



void inputs_camera()
{
	UP = iCluige.iInput.add_action("UP");
	iCluige.iInput.bind_key(UP, 'z');
	iCluige.iInput.bind_key(UP, 'Z');

	LEFT = iCluige.iInput.add_action("LEFT");
	iCluige.iInput.bind_key(LEFT, 'q');
	iCluige.iInput.bind_key(LEFT, 'Q');

	RIGHT = iCluige.iInput.add_action("RIGHT");
	iCluige.iInput.bind_key(RIGHT, 'd');
	iCluige.iInput.bind_key(RIGHT, 'D');

	DOWN = iCluige.iInput.add_action("DOWN");
	iCluige.iInput.bind_key(DOWN, 's');
	iCluige.iInput.bind_key(DOWN, 'S');


	ZOOM = iCluige.iInput.add_action("ZOOM");
	iCluige.iInput.bind_key(ZOOM, 't');
	iCluige.iInput.bind_key(ZOOM, 'T');

	ROT_90 = iCluige.iInput.add_action("ROT_90");
	iCluige.iInput.bind_key(ROT_90, 'j');
	iCluige.iInput.bind_key(ROT_90, 'J');

	ROT_180 = iCluige.iInput.add_action("ROT_180");
	iCluige.iInput.bind_key(ROT_180, 'k');
	iCluige.iInput.bind_key(ROT_180, 'K');

	ROT_45 = iCluige.iInput.add_action("ROT_45");
	iCluige.iInput.bind_key(ROT_45, 'l');
	iCluige.iInput.bind_key(ROT_45, 'L');

//	ROT_270 = iCluige.iInput.add_action("ROT_270");
//	iCluige.iInput.bind_key(ROT_270, 'm');
//	iCluige.iInput.bind_key(ROT_270, 'M');
}


static void create_area(int size)
{
	 if (size < 1 || (size * (size + 1)) >= MAX_SIZE)
	{
		// Handle invalid size or size exceeding the buffer limit
		snprintf(area, MAX_SIZE, "Error: Invalid size or size exceeds buffer limit.\n");
		return;
	}

	// Build the rectangle string
	char *ptr = area;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
			{
				*ptr++ = '#'; // Border
			} else {
				*ptr++ = ' '; // Inside
			}
		}
		*ptr++ = '\n'; // Add a newline at the end of each row
	}
	*ptr = '\0'; // Null-terminate the string
}



void launch_camera()
{


	//gameroot node
	Node2D* gameRootNode2D = iCluige.iNode2D.new_Node2D();
	Node* gameRootRootNode = gameRootNode2D->_this_Node;
	iCluige.iNode.set_name(gameRootRootNode, "Game");
	//iCluige.iNode2D.move_local(gameRootNode2D, (Vector2){15., 15.});
	iCluige.iNode.add_child(iCluige.public_root_2D, gameRootRootNode);



	//Box (area)

	create_area(30);
	SpriteText* areaSpriteText = iCluige.iSpriteText.new_SpriteText();
	Node* areaNode = areaSpriteText->_this_Node2D->_this_Node;
	iCluige.iNode.set_name(areaNode, "Area");
	iCluige.iSpriteText.set_text(areaSpriteText,area);
	iCluige.iNode2D.move_local(areaSpriteText->_this_Node2D, (Vector2){16, 16});
	iCluige.iNode.add_child(gameRootRootNode, areaNode);

	//Chest
	SpriteSVG* chestSprite = iCluige.iSpriteSVG.new_SpriteSVG();
	Node* chest_node = chestSprite->_this_Node2D->_this_Node;
	iCluige.iNode.set_name(chest_node, "Chest");
	iCluige.iSpriteSVG.parse_file(chestSprite,"assets/chest.svg");
	iCluige.iNode.add_child(gameRootRootNode,chest_node);
	iCluige.iNode2D.move_local(chestSprite->_this_Node2D, (Vector2){5, -150});

	/*
	//Title node
	SpriteText* titleSpriteText = iCluige.iSpriteText.new_SpriteText();
	Node* titleNode = titleSpriteText->_this_Node2D->_this_Node;
	iCluige.iNode.set_name(titleNode, "Title");
	iCluige.iSpriteText.set_text(titleSpriteText,
	"											   TEST FOR CAMERA2D NODE							  \n");
	iCluige.iNode.add_child(gameRootRootNode, titleNode);
	*/

	//Player node
	playerNode2D = iCluige.iNode2D.new_Node2D();
	Node* playerNode = playerNode2D->_this_Node;
	iCluige.iNode.set_name(playerNode, "Player");
	//iCluige.iNode2D.move_local(gameRootNode2D, (Vector2){2., 3.});
	iCluige.iNode.add_child(gameRootRootNode, playerNode);

	//Camera node

	Camera2D* camera = iCluige.iCamera2D.new_Camera2D();
	Node* camNode = camera->_this_Node2D->_this_Node;
	iCluige.iNode.set_name(camNode, "Camera");
	iCluige.iNode.add_child(playerNode,camNode);

	//positionning the camera on the parent node



	//Camera node 2 Test

	Camera2D* camera_test = iCluige.iCamera2D.new_Camera2D();
	Node* camNodeTest = camera_test->_this_Node2D->_this_Node;
	iCluige.iNode.set_name(camNodeTest, "Camera_test");
	iCluige.iNode.add_child(playerNode,camNodeTest);
	//positionning the camera on the parent node

	iCluige.iCamera2D.set_enabled(camera,false);
	//iCluige.iCamera2D.set_enabled(camera_test,false);
	//iCluige.iCamera2D.set_enabled(camera_test,true);
	camera_test->anchor_mode = 0;
	//camera_test->zoom = (Vector2){0.25,0.25};
	camera_test->ignore_rotation = false;
	//iCluige.iCamera2D.set_rotation(camera_test,-100.0);
	//camera_test->offset = (Vector2){-40,-40};
	//camera_test->limit_left = -30;
	//camera_test->limit_top = -30;






	godot_svg = iCluige.iSpriteSVG.new_SpriteSVG();

	// add to player the sprite node
	iCluige.iNode.add_child(playerNode, godot_svg->_this_Node2D->_this_Node);
	iCluige.iNode.set_name(godot_svg->_this_Node2D->_this_Node,"SpriteSVG2D");
	iCluige.iSpriteSVG.parse_file(godot_svg,"assets/minicat.svg");

	//iCluige.iNode.print_tree_pretty(gameRootRootNode);
	//printf("test");

	//iCluige.iNode2D.move_local(playerNode2D,(Vector2){-20., -20.});

	SpriteText* test = iCluige.iSpriteText.new_SpriteText();
	iCluige.iSpriteText.set_text(test, "");
	Node* test_node = test->_this_Node2D->_this_Node;




	iCluige.iNode.add_child(playerNode,test_node);

	newPlayer(playerNode);// attach script to The player node
}

void end_camera_test()
{
	iCluige.iCamera2D.make_current(iCluige.iCamera2D.default_camera);
	Node* game_root = iCluige.iNode.get_node(iCluige.public_root_2D, "Game");
	iCluige.iNode.queue_free(game_root);
}
