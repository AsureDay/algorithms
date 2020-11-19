#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"
#include "dublicates.h"
//TODO посмотреть как добавить catch в cMake
int main(int argc, char** argv) {
    int result = Catch::Session().run(argc, argv);
    return result;
}
