//#include <stdlib.h> //already in cluige.h
//#include <stddef.h> //already in cluige.h
#include <cluige.h>
#include "collisions_printf_test.h"


static void test_rect2_is_equal_approx()
{
	Rect2 a;
	Rect2 b;
	a = (Rect2){1.2, -49.3, 3.4, 5.6};
	iCluige.iRect2.rect2_alloc(&b, (Vector2){1.2, -49.3}, (Vector2){3.4-1.2, 5.6+49.3});
	bool test = iCluige.iRect2.is_equal_approx(&a, &b);
	if(!test)
	{
		printf("FAILED --- should be true | %s %d\n",
			__FUNCTION__, 0);
		CLUIGE_BREAKPOINT(&test, true);
	}
	b = (Rect2){1.2, -49.3, 3.4, 5.600000001};
	test = iCluige.iRect2.is_equal_approx(&b, &a);
	if(!test)
	{
		printf("FAILED --- should be true | %s %d\n",
			__FUNCTION__, 1);
		CLUIGE_BREAKPOINT(&test, true);
	}
	b = (Rect2){-999, 1.2, 3.4, 5.6};
	test = iCluige.iRect2.is_equal_approx(&a, &b);
	if(test)
	{
		printf("FAILED --- should be false | %s %d\n",
			__FUNCTION__, 2);
		CLUIGE_BREAKPOINT(&test, true);
	}
}

static void test_rect2_abs()
{
	Rect2 r;
	iCluige.iRect2.rect2_alloc(&r, (Vector2){0, -49.3},(Vector2){3.4, 5.6});
	Rect2 r_abs = iCluige.iRect2.abs(&r);
	bool test = iCluige.iRect2.is_equal_approx(&r, &r_abs);
	if(!test)
	{
		printf("FAILED --- should be true | %s %d\n",
			__FUNCTION__, 0);
		CLUIGE_BREAKPOINT(&test, true);
	}
	iCluige.iRect2.rect2_alloc(&r, (Vector2){-9999999, 0},(Vector2){0, 5.6});
	r_abs = iCluige.iRect2.abs(&r);
	test = iCluige.iRect2.is_equal_approx(&r, &r_abs);
	if(!test)
	{
		printf("FAILED --- should be true | %s %d\n",
			__FUNCTION__, 1);
		CLUIGE_BREAKPOINT(&test, true);
	}
	iCluige.iRect2.rect2_alloc(&r, (Vector2){20, 20},(Vector2){-10, -10});
	r_abs = iCluige.iRect2.abs(&r);
	iCluige.iRect2.rect2_alloc(&r, (Vector2){10, 10},(Vector2){10, 10});
	test = iCluige.iRect2.is_equal_approx(&r, &r_abs);
	if(!test)
	{
		printf("FAILED --- should be true | %s %d\n",
			__FUNCTION__, 2);
		CLUIGE_BREAKPOINT(&test, true);
	}
	iCluige.iRect2.rect2_alloc(&r, (Vector2){0, 0},(Vector2){-10, 10});
	r_abs = iCluige.iRect2.abs(&r);
	iCluige.iRect2.rect2_alloc(&r, (Vector2){-10, 0},(Vector2){10, 10});
	test = iCluige.iRect2.is_equal_approx(&r, &r_abs);
	if(!test)
	{
		printf("FAILED --- should be true | %s %d\n",
			__FUNCTION__, 3);
		CLUIGE_BREAKPOINT(&test, true);
	}
}

static void test_rect2_intersection()
{
	Rect2 rects[10] =
	{
		(Rect2){235, 192, 273, 230},
		(Rect2){ 98,  67, 120,  77},
		(Rect2){170, 124, 248, 182},
		(Rect2){161, 152, 183, 206},
		(Rect2){156, 233, 210, 269},
		(Rect2){196, 166, 234, 181},
		(Rect2){ 46,  89,  88, 147},
		(Rect2){ 28, 166,  64, 192},
		(Rect2){ 29, 148, 103, 206},
		(Rect2){120, 204, 142, 218}
	};
	bool wanted[10][10] =
	{
		{true,false,false,false,false,false,false,false,false,false},
		{false,true,false,false,false,false,false,false,false,false},
		{false,false,true,true,false,true,false,false,false,false},
		{false,false,true,true,false,false,false,false,false,false},
		{false,false,false,false,true,false,false,false,false,false},
		{false,false,true,false,false,true,false,false,false,false},
		{false,false,false,false,false,false,true,false,false,false},
		{false,false,false,false,false,false,false,true,true,false},
		{false,false,false,false,false,false,false,true,true,false},
		{false,false,false,false,false,false,false,false,false,true}
	};
	for(int lin=0; lin<10; lin++)
	{
		for(int col=0; col<10; col++)
		{
			Rect2Intersection inter = iCluige.iRect2.intersection(&(rects[lin]), &(rects[col]));
			if(inter.intersects != wanted[lin][col])
			{
				printf("FAILED --- wrong inter.intersects lin:%d col:%d | %s %d\n",
					lin, col, __FUNCTION__, 0);
				CLUIGE_BREAKPOINT(wanted, true);
			}
		}
	}
	Rect2 wanted_inter;
//						 170, 124, 248, 182);//2
//						 161, 152, 183, 206);//3
	wanted_inter = (Rect2){170, 152, 183, 182};
	Rect2Intersection inter = iCluige.iRect2.intersection(&(rects[2]), &(rects[3]));
	if(!iCluige.iRect2.is_equal_approx(&wanted_inter, &(inter.intersection)))
	{
		printf("FAILED --- wrong inter.intersection lin:%d col:%d | %s\n",
			2, 3, __FUNCTION__);
		CLUIGE_BREAKPOINT(wanted, true);
	}
//						 170, 124, 248, 182);//2
//						 196, 166, 234, 181);//5
	wanted_inter = (Rect2){196, 166, 234, 181};
	inter = iCluige.iRect2.intersection(&(rects[2]), &(rects[5]));
	if(!iCluige.iRect2.is_equal_approx(&wanted_inter, &(inter.intersection)))
	{
		printf("FAILED --- wrong inter.intersection lin:%d col:%d | %s\n",
			2, 5, __FUNCTION__);
		CLUIGE_BREAKPOINT(wanted, true);
	}
//						 28, 166, 64, 192);//7
//						 29, 148, 103, 206);//8
	wanted_inter = (Rect2){29, 166, 64, 192};
	inter = iCluige.iRect2.intersection(&(rects[7]), &(rects[8]));
	if(!iCluige.iRect2.is_equal_approx(&wanted_inter, &(inter.intersection)))
	{
		printf("FAILED --- wrong inter.intersection lin:%d col:%d | %s\n",
			7, 8, __FUNCTION__);
		CLUIGE_BREAKPOINT(wanted, true);
	}
	//intersection with itself:
//						 28, 166, 64, 192);
	wanted_inter = (Rect2){28, 166, 64, 192};
	inter = iCluige.iRect2.intersection(&(rects[7]), &(rects[7]));
	if(!iCluige.iRect2.is_equal_approx(&wanted_inter, &(inter.intersection)))
	{
		printf("FAILED --- wrong inter.intersection lin:%d col:%d | %s\n",
			7, 7, __FUNCTION__);
		CLUIGE_BREAKPOINT(wanted, true);
	}
}

void collisions_all_tests()
{
	printf(" ----------------------------------------------------   -- start of collisions tests\n");

	test_rect2_is_equal_approx();
	test_rect2_abs();
	test_rect2_intersection();

	//clear all
}
