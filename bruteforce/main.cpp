#define CATCH_CONFIG_RUNNER
#include "bruteforce.h"
#include "catch.hpp"

int main(int argc, char* argv[]) {
    int result = Catch::Session().run(argc, argv);
    return result;
}
