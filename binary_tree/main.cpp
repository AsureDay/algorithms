#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"
#include "binary_tree.h"
#include "test_time.h"

int main(int argc, char** argv) {

	testTime(100000,1000,100);
	int result = Catch::Session().run(argc, argv);
    return result;
}
