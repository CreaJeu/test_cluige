//#include <stdlib.h> //already in cluige.h
//#include <stddef.h> //already in cluige.h
#include <cluige.h>
#include "common_test.h"
#include "node_test.h"



static void test_get_child_0()
{
	int index = 0;
	Node* temp = iCluige.iNode.get_child(iCluige.public_root_2D, index);
	if(strcmp(temp->name,iCluige.public_root_2D->children->name) == 0)
	{
		//printf("success-------------test_get_child_0");
	}
	else{
		printf("-----FAILED--------test_get_child_0\n");
	}
	//printf("\n");
}

static void test_get_child_1()
{
	int index = 1;
	Node* temp = iCluige.iNode.get_child(iCluige.public_root_2D, index);
	if(strcmp(temp->name,iCluige.public_root_2D->children->next_sibling->name) == 0)  //take the second child in private_root_2D
	{
		//printf("success-------------test_get_child_1");
	}
	else{
		printf("-----FAILED--------test_get_child_1\n");
	}
	//printf("\n");
	//reverse order
	temp = iCluige.iNode.get_child(iCluige.public_root_2D, -2);
	if(strcmp(temp->name,iCluige.public_root_2D->children->next_sibling->name) == 0)
	{
		//printf("success-------------test_get_child_0r");
	}
	else{
		printf("-----FAILED--------test_get_child_0r - found : %s\n", temp->name);
	}
	//printf("\n");
}

static void test_get_child_2()
{
	int index = 0;
	Node* temp = iCluige.iNode.get_child(iCluige.public_root_2D, index);
	if(temp == iCluige.public_root_2D->children)  //take the second child in private_root_2D
	{
		//printf("success-------------test_get_child_2");
	}
	else{
		printf("-----FAILED--------test_get_child_2\n");
	}
	//printf("\n");
	temp = iCluige.iNode.get_child(iCluige.public_root_2D, -1);
	if(temp == iCluige.public_root_2D->children->next_sibling->next_sibling)  //take the second child in private_root_2D
	{
		//printf("success-------------test_get_child_2r");
	}
	else{
		printf("-----FAILED--------test_get_child_2r - found : %s\n", temp->name);
	}
	//printf("\n");
}

//now an assert
//static void test_get_child_3()
//{
//	int index = 500;
//	Node* temp = iCluige.iNode.get_child(iCluige.private_root_2D, index);
//	if(temp == NULL)  //take the second child in private_root_2D
//	{
//		printf("SUCCESS-------------test_get_child_3");
//	}
//	else{
//		printf("\nFAILED-------------test_get_child_3\n");
//	}
//	 printf("\n");
//}

//now tested in 0 and 2
//static void test_get_child_4()
//{
//	int index = -1;
//	Node* temp = iCluige.iNode.get_child(iCluige.public_root_2D, index);
//	if(temp == iCluige.public_root_2D->children->next_sibling)  //take the second child in private_root_2D
//	{
//		printf("SUCCESS-------------test_get_child_4");
//	}
//	else{
//		printf("-----FAILED--------test_get_child_4\n");
//	}
//	 printf("\n");
//}

static void test_get_node_abs0()
{
	char* node_path = "/public_root_2D/test1";
	Node* res = iCluige.iNode.get_node(NULL,node_path);
	if (res == NULL)
	{
		printf("-----FAILED--------test_get_node_0\n");
	}
	else
	{
		//printf("success-------------%s  -- test1", res->name);
	}
	//printf("\n");

}

static void test_get_node_abs1()
{
	char* node_path = "/public_root_2D/test1/child_test1";
	Node* res = iCluige.iNode.get_node(NULL,node_path);
	if (res == NULL)
	{
		printf("-----FAILED--------test_get_node_1\n");
	}
	else
	{
		//printf("success-------------%s  -- child_test1", res->name);
	}
	//printf("\n");

}

static void test_get_node_abs2()
{
	char* node_path = "/public_root_2D/sib_test1";
	Node* res = iCluige.iNode.get_node(NULL,node_path);
	if (res == NULL)
	{
		printf("-----FAILED--------test_get_node_2\n");
	}
	else
	{
		//printf("success-------------%s  -- sib_test1", res->name);
	}
	//printf("\n");
}

static void test_get_node_abs3()
{
char* node_path = "/public_root_2D/sib_test1/child_test1";
	Node* res = iCluige.iNode.get_node(NULL,node_path);
	if (res != NULL)
	{
		printf("-----FAILED--------%s test_get_node_abs3\n",res->name);
	}
	else
	{
		//printf("success------------- invalid path returned NULL test_getnode_abs3");
	}
	//printf("\n");
}


static void test_get_node_not_abs0()
{
	char* node_path = "test1";
	Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,node_path);
	if (res == NULL)
	{
		printf("-----FAILED--------test_get_node_not_abs0\n");
	}
	else
	{
		//printf("success-------------%s  -- test1", res->name);
	}
	//printf("\n");
}

static void test_get_node_not_abs1()
{
	char* node_path = "test1/child_test1";
	Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,node_path);
	if (res == NULL)
	{
		printf("-----FAILED--------test_get_node_not_abs1\n");
	}
	else
	{
		//printf("success-------------%s  -- child_test1", res->name);
	}
	//printf("\n");
}

static void test_get_node_not_abs2()
{
	char* node_path = "sib_test1";
	Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,node_path);
	if (res == NULL)
	{
		printf("-----FAILED--------test_get_node_not_abs2\n");
	}
	else
	{
		//printf("success-------------%s  -- sib_test1", res->name);
	}
	//printf("\n");
}

static void test_get_node_not_abs3()//get current node
{
	char* node_path = ".";
	Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,node_path);
	if (res == NULL)
	{
		printf("-----FAILED--------test_get_node_not_abs3\n");
	}
	else
	{
		//printf("success-------------%s  -- public_root_2D", res->name);
	}
	//printf("\n");
}

static void test_get_node_not_abs4()//get parent node
{
	char* node_path = "..";
	Node* res = iCluige.iNode.get_node(iCluige.public_root_2D->children,node_path);
	if (res == NULL)
	{
		printf("-----FAILED--------test_get_node_not_abs4\n");
	}
	else
	{
		//printf("success-------------%s  -- public_root_2D", res->name);
	}
	//printf("\n");
}

static void test_get_node_not_abs5()//get grand parent node
{
	char* node_path = "../..";
	Node* res = iCluige.iNode.get_node(iCluige.public_root_2D->children->children,node_path);
	if (res == NULL)
	{
		printf("-----FAILED--------test_get_node_not_abs5\n");
	}
	else
	{
		//printf("success-------------%s  -- public_root_2D", res->name);
	}
	//printf("\n");
}

static void test_get_node_not_abs6()
{
	char* node_path = "test4";
	Node* res = iCluige.iNode.get_node(iCluige.public_root_2D,node_path);
	if (res == NULL)
	{
		//printf("success-------------test_get_node_not_abs6");
	}
	else
	{
		printf("-----FAILED--------%s  -- test4\n", res->name);
	}
	//printf("\n");
}

static void test_get_node_not_abs7()
{
	char* node_path = "../sib_test1";
	Node* res = iCluige.iNode.get_node(iCluige.public_root_2D->children,node_path);
	if (res == NULL)
	{
		printf("-----FAILED--------test_get_node_not_abs7\n");
	}
	else
	{
		//printf("success-------------%s  -- sib_test1", res->name);
	}
	//printf("\n");
}

static void test_get_node_not_abs8()
{
	char* node_path = "testsdazaza";
	Node* res = iCluige.iNode.get_node(iCluige.public_root_2D->children,node_path);
	if (res == NULL)
	{
		//printf("success-------------test_get_node_not_abs8");
	}
	else
	{
		printf("-----FAILED--------%s  -- testsdazaza\n", res->name);
	}
	//printf("\n");
}

static void test_get_node_not_abs9()
{
	char* node_path = "/public_root_2D/exist_not";

	Node* res = iCluige.iNode.get_node(iCluige.public_root_2D->children,node_path);
	if (res == NULL)
	{
		//printf("success-------------test_get_node_not_abs9");
	}
	else
	{
		printf("-----FAILED--------%s  -- %s | test_get_node_not_abs9\n", res->name, node_path);
	}
	//printf("\n");
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
	if (res == 3)
	{
		//printf("success-------------%i\n", res);

	}
	else
	{
		printf("-----FAILED--------%i -- 2 | test_get_child_count_0\n", res);
	}
}

static void test_get_child_count_1()
{
	int res = iCluige.iNode.get_child_count(iCluige.public_root_2D->children);
	if (res == 1)
	{
		//printf("success-------------%i\n", res);

	}
	else
	{
		printf("-----FAILED--------%i -- 1 | test_get_child_count_1\n", res);
	}
}

static void test_get_child_count_2()
{
	int res = iCluige.iNode.get_child_count(iCluige.public_root_2D->children->next_sibling);
	if (res == 0)
	{
		//printf("success-------------%i\n", res);

	}
	else
	{
		printf("-----FAILED--------%i -- 0 | test_get_child_count_2\n", res);
	}
}

static void test_is_ancestor_of0()
{
	bool res = iCluige.iNode.is_ancestor_of(iCluige.public_root_2D->children->children, iCluige.public_root_2D);
	if (res)
	{
		//printf("success-------------\n");
	}
	else
	{
		printf("-----FAILED--------should be true  | test_is_ancestor_of0\n");
	}
}

static void test_is_ancestor_of1()
{
	bool res = iCluige.iNode.is_ancestor_of(iCluige.public_root_2D->children->children, iCluige.public_root_2D->children);
	if (res)
	{
		//printf("success-------------\n");
	}
	else
	{
		printf("-----FAILED--------should be true  | test_is_ancestor_of1\n");
	}
}

static void test_is_ancestor_of2()
{
	bool res = iCluige.iNode.is_ancestor_of(iCluige.public_root_2D->children->children, iCluige.public_root_2D->children->next_sibling);
	if (!res)
	{
		//printf("success-------------\n");
	}
	else
	{
		printf("-----FAILED--------should be false  | test_is_ancestor_of2\n");
	}
}

static void test_is_ancestor_of3()
{
	bool res = iCluige.iNode.is_ancestor_of(iCluige.public_root_2D->children, iCluige.public_root_2D->children->children);
	if (!res)
	{
		//printf("success-------------\n");
	}
	else
	{
		printf("-----FAILED--------should be false  | test_is_ancestor_of3\n");
	}
}

static void test_is_ancestor_of4()
{
	bool res = iCluige.iNode.is_ancestor_of(iCluige.public_root_2D->children->next_sibling, iCluige.public_root_2D->children->children);
	if (!res)
	{
		//printf("success-------------\n");
	}
	else
	{
		printf("-----FAILED--------should be false  | test_is_ancestor_of4\n");
	}
}

static void test_remove()
{
	Node* nodes[8];
	char* names[8] = {"keep1", "keep2", "remove1", "keep3", "keep4", "sub0", "sub1", "sub2"};
	for(int i=0; i<8; i++)
	{
		nodes[i] = iCluige.iNode.new_Node();
		iCluige.iNode.set_name(nodes[i],names[i]);
		if(i<5)
		{
			iCluige.iNode.add_child(iCluige.public_root_2D, nodes[i]);
		}
		else
		{
			iCluige.iNode.add_child(nodes[2], nodes[i]);
		}

	}
//	iCluige.iNode.print_tree_pretty(iCluige._private_root_2D);

	int count;
	for(int i=5; i<8; i++)
	{
		iCluige.iNode.remove_child(nodes[2], nodes[i]);
		count = iCluige.iNode.get_child_count(nodes[2]);
		int wanted_count = 3 - (i - 4);
		if (count != wanted_count)
		{
			printf("-----FAILED--------should be %i, is %i | test_remove sub%i\n", wanted_count, count, wanted_count);
		}
//		iCluige.iNode.print_tree_pretty(iCluige._private_root_2D);
	}

	iCluige.iNode.remove_child(iCluige.public_root_2D, nodes[2]);
	count = iCluige.iNode.get_child_count(iCluige.public_root_2D);
	if (count != 7)
	{
		printf("-----FAILED--------should be 7, is %i | test_remove1\n", count);
	}
//	iCluige.iNode.print_tree_pretty(iCluige._private_root_2D);

	for(int i=4; i>=3; i--)
	{
		iCluige.iNode.remove_child(iCluige.public_root_2D, nodes[i]);
	}
	count = iCluige.iNode.get_child_count(iCluige.public_root_2D);
	if (count != 5)
	{
		printf("-----FAILED--------should be 5, is %i | test_remove2\n", count);
	}
//	iCluige.iNode.print_tree_pretty(iCluige._private_root_2D);

	for(int i=0; i<2; i++)
	{
		iCluige.iNode.remove_child(iCluige.public_root_2D, nodes[i]);
	}
	count = iCluige.iNode.get_child_count(iCluige.public_root_2D);
	if (count != 3)
	{
		printf("-----FAILED--------should be 3, is %i | test_remove3\n", count);
	}
	//tree is back like before this function
//	iCluige.iNode.print_tree_pretty(iCluige._private_root_2D);
}

static void test_queue_free()
{
//	iCluige.iNode.print_tree_pretty(iCluige.private_root_2D);
	iCluige.iNode.queue_free(iCluige.public_root_2D->children->children);
	iCluige.iNode.queue_free(iCluige.public_root_2D->children->children);//should do nothing neither crash
	int count = iCluige.iNode.get_child_count(iCluige.public_root_2D);
	for(int i = 0; i<count; i++)
	{
		Node* child_i = iCluige.iNode.get_child(iCluige.public_root_2D, i);
		iCluige.iNode.queue_free(child_i);
	}
	//iCluige.iNode.queue_free(iCluige.public_root_2D);
	iCluige.iNode._do_all_queue_free();
//	iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
	count = iCluige.iNode.get_child_count(iCluige.public_root_2D);
	if (count == 0)
	{
		//printf("success-------------\n");
	}
	else
	{
		printf("-----FAILED--------should be 0, remains %i children | test_queue_free\n", count);
	}
//	iCluige.iNode.print_tree_pretty(iCluige.private_root_2D);
}

void node_all_tests()
{
	printf("\n ----------------------------------------------------   -- start of Node tests\n");
	Node* node1 = iCluige.iNode.new_Node();
	iCluige.iNode.set_name(node1,"test1");

	Node* node2 = iCluige.iNode.new_Node();
	iCluige.iNode.set_name(node2,"child_test1");

	Node* node3 = iCluige.iNode.new_Node();
	iCluige.iNode.set_name(node3,"sib_test1");

	iCluige.iNode.add_child(iCluige.public_root_2D, node1);
	iCluige.iNode.add_child(iCluige.public_root_2D, node3);
	iCluige.iNode.add_child(node1, node2);
	//iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
	//printf("Test get_node() method ----------------------------------------------------------------------------- \n");

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
	//printf("Test get_child() method ----------------------------------------------------------------------------- \n");

	Node* node4 = iCluige.iNode.new_Node();
	iCluige.iNode.set_name(node4,"sib_test_last");
	iCluige.iNode.add_child(iCluige.public_root_2D, node4);

	//iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
	test_get_child_0();
	test_get_child_1();
	test_get_child_2();
	//test_get_child_3();//now an assert
	//test_get_child_4();

	//printf("\nTest remove_child() method ----------------------------------------------------------------------------- \n");
	//test_remove_child_0();//can't test both at the same time
	//test_remove_child_1()

	//printf("Test get_path() method -----------------------------------------------------------------------------\n");

	//iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
	StringBuilder sb;
	char* test_gpm = iCluige.iStringBuilder.string_alloc(&sb, 555);
	char* p = iCluige.iNode.get_path_mallocing(iCluige.public_root_2D->children);
	iCluige.iStringBuilder.append(&sb, "%s\n", p);
	free(p);
	p = iCluige.iNode.get_path_mallocing(iCluige.public_root_2D);
	iCluige.iStringBuilder.append(&sb, "%s\n", p);
	free(p);
	p = iCluige.iNode.get_path_mallocing(iCluige.public_root_2D->children->next_sibling);
	iCluige.iStringBuilder.append(&sb, "%s\n", p);
	free(p);
	p = iCluige.iNode.get_path_mallocing(iCluige.public_root_2D->children->children);
	iCluige.iStringBuilder.append(&sb, "%s\n", p);
	free(p);
	if(!str_equals(
		test_gpm,
"/public_root_2/test1\n\
/public_root_2\n\
/public_root_2/sib_test1\n\
/public_root_2/test1/child_test1\n\
"
		))
	{
		printf("-----FAILED-------- is :\n%s | test get_path_mallocing\n", test_gpm);
	}

	//printf("Test get_child_count() method -----------------------------------------------------------------------------\n");
	//iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
	test_get_child_count_0();
	test_get_child_count_1();
	test_get_child_count_2();

	//printf("Test is_ancestor_of() method -----------------------------------------------------------------------------\n");
	test_is_ancestor_of0();
	test_is_ancestor_of1();
	test_is_ancestor_of2();
	test_is_ancestor_of3();
	test_is_ancestor_of4();

	//printf("Test queue_free() method -----------------------------------------------------------------------------\n");
	test_remove();
	iCluige.iNode.print_tree_pretty(iCluige.public_root_2D);
	test_queue_free();//clears all public_root_2D children for a fresh start

	//printf(" ----------------------------------------------------      end of Node tests --\n");
}


