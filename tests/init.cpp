
#include <catch.hpp>
#include "external_sort.h"
#include "natural_merge_sort.h"
#include "quicksortm.h"
using namespace std;


SCENARIO("init_sort1", "[INIT1]")
{
	sortlines("8.txt", "out.txt", 1);
        bool mark=true;
	line s1,s2;
	ifstream input_sorted("sorted8.txt"); 
	ifstream input_result("out.txt");
	
	while (!input_result.eof())
	{
		input_sorted >> s1;
		input_result >> s2;
		if (s1.name != s2.name)
		  mark=false;
	}	
	REQUIRE(mark);
}

SCENARIO ("init_sort2", "[INIT2]")
{
	sortlines("15.txt", "out.txt", 1);
        bool mark=true;
	line s1,s2;
	ifstream input_sorted("sorted15.txt"); 
	ifstream input_result("out.txt");
	
	while (!input_result.eof())
	{
		input_sorted >> s1;
		input_result >> s2;
		if (s1.name != s2.name)
		  mark=false;
	}	
	REQUIRE(mark);
}

SCENARIO ("init_sort3", "[INIT3]")
{
	sortlines("32.txt", "out.txt", 1);
        bool mark=true;
	line s1,s2;
	ifstream input_sorted("sorted32.txt"); 
	ifstream input_result("out.txt");
	
	while (!input_result.eof())
	{
		input_sorted >> s1;
		input_result >> s2;
		if (s1.name != s2.name)
		  mark=false;
	}	
	REQUIRE(mark);
}
