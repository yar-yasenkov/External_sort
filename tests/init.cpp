
#include <catch.hpp>
#include "external_sort.h"
using namespace std;
SCENARIO("init", "[INIT]"){
        Simple_Merging_Sort("spisok.txt");
	bool mark=true;

	REQUIRE(mark);
}
