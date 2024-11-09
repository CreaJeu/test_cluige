#include <stdio.h>
#include <cluige.h>
#include <float.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "common_test.h"
#include "camera_test.h"

// WRITE use "Debug graphical" build target if you want to test graphical things like camera
// WRITE use "Debug printf" build target if you want to test non graphical things like node names
// WRITE but don't forget to recompile (not auto in code::blocks)

//#define IN_PRINTF_TEST  // use build targets instead, don't forget to recompile
//#define IN_GRAPHICAL_TEST  // use build targets instead, don't forget to recompile

#ifdef IN_PRINTF_TEST
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
#endif // IN_PRINTF_TEST

int main()
{
	//SetConsoleOutputCP(CP_UTF8);

	//init
	cluige_init();//makes all roots, set all functions pointers, etc.



	#ifdef IN_PRINTF_TEST
	make_all_tests();
	#endif // IN_PRINTF_TEST

	#ifdef IN_GRAPHICAL_TEST
	inputs_camera();
	launch_camera();
	cluige_run();
	#endif // IN_GRAPHICAL_TEST

	printf("Finishing...\n");
	return cluige_finish();
}

