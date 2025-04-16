#include "../include/chip8.h"
#include <iostream>

int main() {
    Chip8 chip8;

    if (!chip8.loadRom("..\\roms\\IBM Logo.ch8")) // Loading ROM provided as argument
    {
        std::cerr << "ROM could not be loaded. Possibly invalid path given\n";
        exit(1);
    }

    // Main loop
    while (true)
    {
        chip8.singleCycle();

        if (chip8.getDrawFlag())
        {
            chip8.setDrawFlag(false);
            uint32_t pixels[32 * 64];
            for (int i = 0; i < 32 * 64; i++)
            {
                if (chip8.getDisplayValue(i) == 0)
                {
                    pixels[i] = 0xFF000000;
                }
                else
                {
                    pixels[i] = 0xFFFFFFFF;
                }
            }
        }
    }

    exit(0);
}