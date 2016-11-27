
#include <catch.hpp>
#include "external_sort.h"
#include "natural_merge_sort.h"
using namespace std;
//SCENARIO("init_merge_sort", "[INIT]"){
//        Simple_Merging_Sort("spisok.txt", "out.txt", 512);
//	bool mark=true;

//	REQUIRE(mark);
//}

SCENARIO("init_natural_merge_sort", "[INIT1]"){
        Natural_Merging_Sort("8.txt", "out.txt", 512);
	bool mark=true;
	REQUIRE(mark);
}

/*
SCENARIO("init_natural_merge_sort", "[INIT2]"){
        Natural_Merging_Sort("15.txt", "out.txt", 512);
	bool mark=true;
	REQUIRE(mark);
}

SCENARIO("init_natural_merge_sort", "[INIT3]"){
        Natural_Merging_Sort("32.txt", "out.txt", 512);
	bool mark=true;
	REQUIRE(mark);
}*/
