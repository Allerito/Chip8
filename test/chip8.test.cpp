#define CATCH_CONFIG_MAIN
#include "../catch/catch.hpp"
#include "../include/chip8.h"

TEST_CASE("load_rom function")
{
    Chip8 chip8;
    REQUIRE(chip8.load_rom("invalid_path") == false); // Testing invalid path
    REQUIRE(chip8.load_rom("../images/brix.jpg") == false); // Testing rom size bigger than memory
    REQUIRE(chip8.load_rom("../roms/PONG") == true); // Testing normal case
}