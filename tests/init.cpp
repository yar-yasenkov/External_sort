
#include <catch.hpp>
#include "external_sort.h"
#include "natural_merge_sort.h"
using namespace std;
SCENARIO("init_merge_sort", "[INIT]"){
        Simple_Merging_Sort("spisok.txt");
	bool mark=true;

	REQUIRE(mark);
}

SCENARIO("init_natural_merge_sort", "[INIT2]"){
        //Natural_Merging_Sort("spisok2.txt");
	bool mark=true;
	REQUIRE(mark);
}
