#define CATCH_CONFIG_MAIN
#include "../catch/src/catch2/catch_test_macros.hpp"
#include "../include/chip8.h"

TEST_CASE("loadRom function")
{
    Chip8 chip8;
    REQUIRE(chip8.loadRom("invalid_path") == false); // Testing invalid path
    REQUIRE(chip8.loadRom("../images/brix.jpg") == false); // Testing rom size bigger than memory
    REQUIRE(chip8.loadRom("../roms/PONG") == true); // Testing normal case
}