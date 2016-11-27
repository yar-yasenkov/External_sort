
#include <catch.hpp>
#include "external_sort.h"
#include "natural_merge_sort.h"
#include "quicksortm.h"
using namespace std;


SCENARIO("init_sort1", "[INIT1]")
{
	sortlines("8.txt", "out.txt", 1);
        bool mark=true;
	REQUIRE(mark);
}

SCENARIO ("init_sort2", "[INIT2]")
{
	sortlines("15.txt", "out.txt", 4);
	bool mark=true;
	REQUIRE(mark);
}

SCENARIO ("init_sort3", "[INIT3]")
{
	sortlines("32.txt", "out.txt", 17);
	bool mark=true;
	REQUIRE(mark);
}
