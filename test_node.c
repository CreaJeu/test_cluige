#include <stdio.h>
#include <cluige.h>
#include <float.h>


//TEST nde_get_child

static void ready()
{

    Node* temp = iCluige.iNode.get_child(iCluige.private_root_2D, 0);
    iCluige.iNode.print_tree_pretty(iCluige.private_root_2D);
    printf("\n\n");
    printf("%s",temp->name);
    printf("\n\n");
    iCluige.iNode.print_tree_pretty(temp);
}


static void test_null_get_child()
{
    int index = 0;
    Node* temp = iCluige.iNode.get_child(NULL, index);
    if(temp == NULL )
    {
        printf("SUCCESS-------------NULL");
    }
    else{
        printf("FAILED-------------NULL");
    }
    printf("\n");
}
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
    int index = 5;
    Node* temp = iCluige.iNode.get_child(iCluige.private_root_2D, index);
    if(temp == NULL)  //take the second child in private_root_2D
    {
        printf("SUCCESS-------------test_get_child_1");
    }
    else{
        printf("FAILED-------------test_get_child_1");
    }
     printf("\n");
}
static void test_get_node_abs0()
{
    char node_path[200] = "/public_root_2D/test1";
    Node* res = iCluige.iNode.get_node(NULL,&node_path);
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
    char node_path[200] = "/public_root_2D/test1/child_test1";
    Node* res = iCluige.iNode.get_node(NULL,&node_path);
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
    char node_path[200] = "/public_root_2D/sib_test1";
    Node* res = iCluige.iNode.get_node(NULL,&node_path);
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
char node_path[200] = "/public_root_2D/sib_test1/child_test1";
    Node* res = iCluige.iNode.get_node(NULL,&node_path);
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
    char node_path[200] = "test1";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,&node_path);
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
    char node_path[200] = "test1/child_test1";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,&node_path);
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
    char node_path[200] = "sib_test1";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,&node_path);
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
    char node_path[200] = ".";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,&node_path);
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
    char node_path[200] = "..";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D->children,&node_path);
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
    char node_path[200] = "../..";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D->children->children,&node_path);
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
    char node_path[200] = "test4";
    Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,&node_path);
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


int main()
{
    //SetConsoleOutputCP(CP_UTF8);

    //init
	cluige_init();//makes all roots, set all functions pointers, etc.

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

    //test_get_node_abs0();
    //test_get_node_abs1();
    //test_get_node_abs2();
    //test_get_node_abs3();

    //test_get_node_not_abs0();
    //test_get_node_not_abs1();
    //test_get_node_not_abs2();
    //test_get_node_not_abs3();
    //test_get_node_not_abs4();
    test_get_node_not_abs5();
    test_get_node_not_abs6();
    printf("\nTest get_child() method ----------------------------------------------------------------------------- \n");
    test_null_get_child(); //tests for get_child "method"
    test_get_child_0();
    test_get_child_1();
    test_get_child_2();
    printf("\nTest remove_child() method ----------------------------------------------------------------------------- \n");
    //test_remove_child_0();//can't test both at the same time
    //test_remove_child_1()

    printf("\nTest get_path() method -----------------------------------------------------------------------------\n");
    char* p = iCluige.iNode.get_path_mallocing(iCluige.public_root_2D->children);
    printf("\n%s", p);
    //p = iCluige.iNode.get_path_mallocing(iCluige.public_root_2D);
    printf("\n%s", p);
    //p = iCluige.iNode.get_path_mallocing(iCluige.public_root_2D->children->next_sibling);
    printf("\n%s", p);
    p = iCluige.iNode.get_path_mallocing(iCluige.public_root_2D->children->children);
    printf("\n%s", p);
    free(p);

    printf("\nTest queue_free() method -----------------------------------------------------------------------------\n");
    iCluige.iNode.queue_free(iCluige.public_root_2D->children->children);
    iCluige.iNode.queue_free(iCluige.public_root_2D->children);
    iCluige.iNode.empty_dq_free();


    printf("Finishing...\n");
    return cluige_finish();
}

