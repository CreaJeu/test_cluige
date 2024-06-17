#include <stdio.h>
#include <cluige.h>
#include <float.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

// WRITE #define IN_CAMERA_TEST if you want to test the camera
// WRITE #define IN_TEST  if you want to test node new functions


#define IN_CAMERA_TEST

#ifdef IN_TEST
static void test_get_child_0()
{
    int index = 0;
    Node* temp = iCluige.iNode.get_child(iCluige.private_root_2D, index);
    if(strcmp(temp->name,iCluige.private_root_2D->children->name) == 0)
    {
        printf("SUCCESS-------------test_get_child_0");
    }
    else{
        printf("FAILED-------------test_get_child_0");
    }
     printf("\n");
}
static void test_get_child_1()
{
    int index = 1;
    Node* temp = iCluige.iNode.get_child(iCluige.private_root_2D, index);
    if(strcmp(temp->name,iCluige.private_root_2D->children->next_sibling->name) == 0)  //take the second child in private_root_2D
    {
        printf("SUCCESS-------------test_get_child_1");
    }
    else{
        printf("FAILED-------------test_get_child_1");
    }
     printf("\n");
}
static void test_get_child_2()
{
    int index = 0;
    Node* temp = iCluige.iNode.get_child(iCluige.private_root_2D, index);
    if(temp == iCluige.private_root_2D->children)  //take the second child in private_root_2D
    {
        printf("SUCCESS-------------test_get_child_2");
    }
    else{
        printf("FAILED-------------test_get_child_2");
    }
     printf("\n");
}

static void test_get_child_3()
{
    int index = 500;
    Node* temp = iCluige.iNode.get_child(iCluige.private_root_2D, index);
    if(temp == NULL)  //take the second child in private_root_2D
    {
        printf("SUCCESS-------------test_get_child_3");
    }
    else{
        printf("FAILED-------------test_get_child_3");
    }
     printf("\n");
}

static void test_get_child_4()
{
    int index = -1;
    Node* temp = iCluige.iNode.get_child(iCluige.public_root_2D, index);
    if(temp == iCluige.public_root_2D->children->next_sibling)  //take the second child in private_root_2D
    {
        printf("SUCCESS-------------test_get_child_4");
    }
    else{
        printf("FAILED-------------test_get_child_4");
    }
     printf("\n");
}

static void test_get_node_abs0()
{
    char* node_path = "/public_root_2D/test1";
    Node* res = iCluige.iNode.get_node(NULL,node_path);
    if (res == NULL)
    {
        printf("FAILED-------------test_get_node_0");
    }
    else
    {
        printf("SUCCESS-------------%s  -- test1", res->name);
    }
    printf("\n");

}

static void test_get_node_abs1()
{
    char* node_path = "/public_root_2D/test1/child_test1";
    Node* res = iCluige.iNode.get_node(NULL,node_path);
    if (res == NULL)
    {
        printf("FAILED-------------test_get_node_1");
    }
    else
    {
        printf("SUCCESS-------------%s  -- child_test1", res->name);
    }
    printf("\n");

}
static void test_get_node_abs2()
{
    char* node_path = "/public_root_2D/sib_test1";
    Node* res = iCluige.iNode.get_node(NULL,node_path);
    if (res == NULL)
    {
        printf("FAILED-------------test_get_node_2");
    }
    else
    {
        printf("SUCCESS-------------%s  -- sib_test1", res->name);
    }
    printf("\n");
}
static void test_get_node_abs3()
{
char* node_path = "/public_root_2D/sib_test1/child_test1";
    Node* res = iCluige.iNode.get_node(NULL,node_path);
    if (res != NULL)
    {
        printf("FAILED-------------%s",res->name);
    }
    else
    {
        printf("SUCCESS------------- invalid path returned NULL test_getnode_abs3");
    }
    printf("\n");
}


static void test_get_node_not_abs0()
{
    char* node_path = "test1";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,node_path);
    if (res == NULL)
    {
        printf("FAILED-------------test_get_node_not_abs1");
    }
    else
    {
        printf("SUCCESS-------------%s  -- test1", res->name);
    }
    printf("\n");
}

static void test_get_node_not_abs1()
{
    char* node_path = "test1/child_test1";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,node_path);
    if (res == NULL)
    {
        printf("FAILED-------------test_get_node_not_abs1");
    }
    else
    {
        printf("SUCCESS-------------%s  -- child_test1", res->name);
    }
    printf("\n");
}
static void test_get_node_not_abs2()
{
    char* node_path = "sib_test1";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,node_path);
    if (res == NULL)
    {
        printf("FAILED-------------test_get_node_not_abs2");
    }
    else
    {
        printf("SUCCESS-------------%s  -- sib_test1", res->name);
    }
    printf("\n");
}

static void test_get_node_not_abs3()//get current node
{
    char* node_path = ".";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,node_path);
    if (res == NULL)
    {
        printf("FAILED-------------test_get_node_not_abs3");
    }
    else
    {
        printf("SUCCESS-------------%s  -- public_root_2D", res->name);
    }
    printf("\n");
}

static void test_get_node_not_abs4()//get parent node
{
    char* node_path = "..";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D->children,node_path);
    if (res == NULL)
    {
        printf("FAILED-------------test_get_node_not_abs4");
    }
    else
    {
        printf("SUCCESS-------------%s  -- public_root_2D", res->name);
    }
    printf("\n");
}
static void test_get_node_not_abs5()//get grand parent node
{
    char* node_path = "../..";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D->children->children,node_path);
    if (res == NULL)
    {
        printf("FAILED-------------test_get_node_not_abs5");
    }
    else
    {
        printf("SUCCESS-------------%s  -- public_root_2D", res->name);
    }
    printf("\n");
}
static void test_get_node_not_abs6()
{
    char* node_path = "test4";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,node_path);
    if (res == NULL)
    {
        printf("SUCCESS-------------test_get_node_not_abs6");
    }
    else
    {
        printf("FAILED-------------%s  -- test4", res->name);
    }
    printf("\n");
}
static void test_get_node_not_abs7()
{
    char* node_path = "../sib_test1";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D->children,node_path);
    if (res == NULL)
    {
        printf("FAILED-------------test_get_node_not_abs7");
    }
    else
    {
        printf("SUCCESS-------------%s  -- sib_test1", res->name);
    }
    printf("\n");
}
static void test_get_node_not_abs8()
{
    char* node_path = "testsdazaza";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D->children,node_path);
    if (res == NULL)
    {
        printf("SUCCESS-------------test_get_node_not_abs8");
    }
    else
    {
        printf("FAILED-------------%s  -- testsdazaza", res->name);
    }
    printf("\n");
}

static void test_get_node_not_abs9()
{
    char* node_path = "/public_root_2D/exist_not";

    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D->children,node_path);
    if (res == NULL)
    {
        printf("SUCCESS-------------test_get_node_not_abs9");
    }
    else
    {
        printf("FAILED-------------%s  -- %s", res->name, node_path);
    }
    printf("\n");
}


/*
static void test_remove_child_0()
{
    iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
    printf("\n");
    iCluige.iNode.remove_child(iCluige.public_root_2D, iCluige.public_root_2D->children);
    iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
    printf("\n");
}
static void test_remove_child_1()
{
    iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
    printf("\n");
    iCluige.iNode.remove_child(iCluige.public_root_2D, iCluige.public_root_2D->children->next_sibling);
    iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
    printf("\n");
}
static void test_remove_child_2()
{
    iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
    printf("\n");
    iCluige.iNode.remove_child(iCluige.public_root_2D, NULL);
    iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
    printf("\n");
}
static void test_remove_child_3()
{
    iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
    printf("\n");
    iCluige.iNode.remove_child(iCluige.public_root_2D, iCluige.public_root_2D);
    iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
    printf("\n");
}

*/

static void test_get_child_count_0()
{
    int res = iCluige.iNode.get_child_count(iCluige.public_root_2D);
    if (res == 2)
    {
        printf("SUCCESS-------------%i\n", res);

    }
    else
    {
        printf("FAILED-------------%i -- 2\n", res);
    }
}
static void test_get_child_count_1()
{
    int res = iCluige.iNode.get_child_count(iCluige.public_root_2D->children);
    if (res == 1)
    {
        printf("SUCCESS-------------%i\n", res);

    }
    else
    {
        printf("FAILED-------------%i -- 1\n", res);
    }
}
static void test_get_child_count_2()
{
    int res = iCluige.iNode.get_child_count(iCluige.public_root_2D->children->next_sibling);
    if (res == 0)
    {
        printf("SUCCESS-------------%i\n", res);

    }
    else
    {
        printf("FAILED-------------%i -- 0\n", res);
    }
}


static void test_is_ancestor_of0()
{
    bool res = iCluige.iNode.is_ancestor_of(iCluige.public_root_2D->children->children, iCluige.public_root_2D);
    if (res)
    {
        printf("SUCCESS-------------\n");
    }
    else
    {
        printf("FAILED-------------should be true  | test_is_ancestor_of0\n ");
    }
}
static void test_is_ancestor_of1()
{
    bool res = iCluige.iNode.is_ancestor_of(iCluige.public_root_2D->children->children, iCluige.public_root_2D->children);
    if (res)
    {
        printf("SUCCESS-------------\n");
    }
    else
    {
        printf("FAILED-------------should be true  | test_is_ancestor_of1\n ");
    }
}
static void test_is_ancestor_of2()
{
    bool res = iCluige.iNode.is_ancestor_of(iCluige.public_root_2D->children->children, iCluige.public_root_2D->children->next_sibling);
    if (!res)
    {
        printf("SUCCESS-------------\n");
    }
    else
    {
        printf("FAILED-------------should be false  | test_is_ancestor_of2\n ");
    }
}
static void test_is_ancestor_of3()
{
    bool res = iCluige.iNode.is_ancestor_of(iCluige.public_root_2D->children, iCluige.public_root_2D->children->children);
    if (!res)
    {
        printf("SUCCESS-------------\n");
    }
    else
    {
        printf("FAILED-------------should be false  | test_is_ancestor_of3\n ");
    }
}
static void test_is_ancestor_of4()
{
    bool res = iCluige.iNode.is_ancestor_of(iCluige.public_root_2D->children->next_sibling, iCluige.public_root_2D->children->children);
    if (!res)
    {
        printf("SUCCESS-------------\n");
    }
    else
    {
        printf("FAILED-------------should be false  | test_is_ancestor_of4\n ");
    }
}


static void make_all_tests()
{
    printf("test");
    Node* node1 = iCluige.iNode.new_Node();
    iCluige.iNode.set_name(node1,"test1");

    Node* node2 = iCluige.iNode.new_Node();
    iCluige.iNode.set_name(node2,"child_test1");

    Node* node3 = iCluige.iNode.new_Node();
    iCluige.iNode.set_name(node3,"sib_test1");

    iCluige.iNode.add_child(iCluige.public_root_2D, node1);
    iCluige.iNode.add_child(iCluige.public_root_2D, node3);
    iCluige.iNode.add_child(node1, node2);
    iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
    printf("\n Test get_node() method ----------------------------------------------------------------------------- \n");

    test_get_node_abs0();
    test_get_node_abs1();
    test_get_node_abs2();
    test_get_node_abs3();

    test_get_node_not_abs0();
    test_get_node_not_abs1();
    test_get_node_not_abs2();
    test_get_node_not_abs3();
    test_get_node_not_abs4();
    test_get_node_not_abs5();
    test_get_node_not_abs6();
    test_get_node_not_abs7();
    test_get_node_not_abs8();
    test_get_node_not_abs9();
    printf("\nTest get_child() method ----------------------------------------------------------------------------- \n");
    test_get_child_0();
    test_get_child_1();
    test_get_child_2();
    test_get_child_3();
    test_get_child_4();

    //printf("\nTest remove_child() method ----------------------------------------------------------------------------- \n");
    //test_remove_child_0();//can't test both at the same time
    //test_remove_child_1()

    printf("\nTest get_path() method -----------------------------------------------------------------------------\n");

    iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
    char* p = iCluige.iNode.get_path_mallocing(iCluige.public_root_2D->children);
    printf("\n%s", p);
    free(p);
    p = iCluige.iNode.get_path_mallocing(iCluige.public_root_2D);
    printf("\n%s", p);
    free(p);
    p = iCluige.iNode.get_path_mallocing(iCluige.public_root_2D->children->next_sibling);
    printf("\n%s", p);
    free(p);
    p = iCluige.iNode.get_path_mallocing(iCluige.public_root_2D->children->children);
    printf("\n%s", p);
    free(p);




    printf("\nTest get_child_count() method -----------------------------------------------------------------------------\n");
    iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
    test_get_child_count_0();
    test_get_child_count_1();
    test_get_child_count_2();

    printf("\nTest is_ancestor_of() method -----------------------------------------------------------------------------\n");
    test_is_ancestor_of0();
    test_is_ancestor_of1();
    test_is_ancestor_of2();
    test_is_ancestor_of3();
    test_is_ancestor_of4();

    printf("\nTest queue_free() method -----------------------------------------------------------------------------\n");
    iCluige.iNode.queue_free(iCluige.public_root_2D->children->children);
    iCluige.iNode.queue_free(iCluige.public_root_2D->children->children);
    iCluige.iNode.queue_free(iCluige.public_root_2D->children);
    iCluige.iNode.queue_free(iCluige.public_root_2D);
    iCluige.iNode._do_all_queue_free();


}
#endif // IN_TEST



#ifdef IN_CAMERA_TEST
int UP;
int DOWN;
int LEFT;
int RIGHT;
int ZOOM;
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
    newPlayer->move_speed = 18;


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
        iCluige.iCamera2D.current_camera->zoom = (Vector2){0.5, 0.5};
    }

    //DEBUG
    char strPositionXPlayer[50], strPositionYPlayer[50], strPositionXSprite[50], strPositionYSprite[50]
    ,strPosXCal[50], strPosYCal[50],strPosXCaliInter[50] ,strPosYCalInter[50];

    sprintf(strPositionXPlayer,"%.2f",playerNode2D->position.x);
    sprintf(strPositionYPlayer,"%.2f",playerNode2D->position.y);
    sprintf(strPositionXSprite,"%.2f",godot_svg->_this_Node2D->position.x);
    sprintf(strPositionYSprite,"%.2f",godot_svg->_this_Node2D->position.y);
    /*
    sprintf(strPosXCal,"%.2f",iCluige.iCamera2D.res_x_1);
    sprintf(strPosYCal,"%.2f",iCluige.iCamera2D.res_y_1);

    sprintf(strPosXCaliInter,"%.2f",iCluige.iCamera2D.res_x_2);
    sprintf(strPosYCalInter,"%.2f",iCluige.iCamera2D.res_y_2);
*/

    char* debug_str = malloc(MAX_SIZE * sizeof(char));
    strcpy(debug_str, "");
    strcat(debug_str,strPositionXPlayer);
    strcat(debug_str, ",");
    strcat(debug_str,strPositionYPlayer);
    strcat(debug_str, ",");
    strcat(debug_str,strPositionXSprite);
    strcat(debug_str, ",");
    strcat(debug_str,strPositionYSprite);
    strcat(debug_str, ",");
    strcat(debug_str,strPosXCal);
    strcat(debug_str, ",");
    strcat(debug_str,strPosYCal);
    strcat(debug_str, ",");
    strcat(debug_str,strPosXCaliInter);
    strcat(debug_str, ",");
    strcat(debug_str,strPosYCalInter);
    printf(debug_str);



    Node* testnde = iCluige.iNode.get_child(playerNode2D->_this_Node,-1);
    Node2D* test2D = (Node2D*) (testnde->_sub_class);
    SpriteText* test_sprite_text = (SpriteText*) (test2D->_sub_class);
    iCluige.iSpriteText.set_text(test_sprite_text,debug_str);
    free(debug_str);


}



static void inputs()
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



static void launch()
{


    //gameroot node
    Node2D* gameRootNode2D = iCluige.iNode2D.new_Node2D();
	Node* gameRootRootNode = gameRootNode2D->_this_Node;
	iCluige.iNode.set_name(gameRootRootNode, "Game");
	//iCluige.iNode2D.move_local(gameRootNode2D, (Vector2){15., 15.});
	iCluige.iNode.add_child(iCluige.public_root_2D, gameRootRootNode);



    //Box (area)
    create_area(140);
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
    iCluige.iSpriteSVG.parse_file(chestSprite,"chest.svg");
    iCluige.iNode.add_child(gameRootRootNode,chest_node);
    iCluige.iNode2D.move_local(chestSprite->_this_Node2D, (Vector2){5, -150});

	//Title node
	SpriteText* titleSpriteText = iCluige.iSpriteText.new_SpriteText();
	Node* titleNode = titleSpriteText->_this_Node2D->_this_Node;
	iCluige.iNode.set_name(titleNode, "Title");
    iCluige.iSpriteText.set_text(titleSpriteText,
    "                                               TEST FOR CAMERA2D NODE                              \n");
	iCluige.iNode.add_child(gameRootRootNode, titleNode);

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
    camera->offset = (Vector2){-90,-45};
    //positionning the camera on the parent node



    //Camera node 2 Test

	Camera2D* camera_test = iCluige.iCamera2D.new_Camera2D();
	Node* camNodeTest = camera_test->_this_Node2D->_this_Node;
	iCluige.iNode.set_name(camNodeTest, "Camera_test");
    iCluige.iNode.add_child(playerNode,camNodeTest);
    //positionning the camera on the parent node

    iCluige.iCamera2D.set_enabled(camera,false);
    iCluige.iCamera2D.set_enabled(camera_test,false);
    iCluige.iCamera2D.set_enabled(camera_test,true);
    //camera_test->zoom = (Vector2){1.5,1.5};

    //TODO use sprite text and message in it to debug


    godot_svg = iCluige.iSpriteSVG.new_SpriteSVG();

    // add to player the sprite node
    iCluige.iNode.add_child(playerNode, godot_svg->_this_Node2D->_this_Node);
    iCluige.iNode.set_name(godot_svg->_this_Node2D->_this_Node,"SpriteSVG2D");
	iCluige.iSpriteSVG.parse_file(godot_svg,"minicat.svg");

    iCluige.iNode.print_tree_pretty(gameRootRootNode);
    printf("test");

    //iCluige.iNode2D.move_local(playerNode2D,(Vector2){-20., -20.});

    SpriteText* test = iCluige.iSpriteText.new_SpriteText();
    Node* test_node = test->_this_Node2D->_this_Node;




    iCluige.iNode.add_child(playerNode,test_node);

	newPlayer(playerNode);// attach script to The player node




















}
#endif // IN_CAMERA_TEST
int main()
{
    //SetConsoleOutputCP(CP_UTF8);

    //init
	cluige_init();//makes all roots, set all functions pointers, etc.



    #ifdef IN_TEST
    make_all_tests();
    #endif // IN_TEST

    #ifdef IN_CAMERA_TEST
    inputs();
    launch();
    cluige_run();
    #endif // IN_CAMERA_TEST

    printf("Finishing...\n");
    return cluige_finish();
}

