#include "../include/chip8.h"
#include <iostream>

int main() {
    Chip8 chip8;
    chip8.loadRom(".\\roms\\BRIX");
    exit(0);
}