#ifndef CHIP8_H
#define CHIP8_H

#include <cstdint>
#include <string>

class Chip8
{
    private:
        //CPU
        uint8_t V[16]; // 16 8 bit registers Vx where x ranges from 0 to F
        uint16_t I, programCounter;
        uint8_t stackPointer; // 16 bit register I,16 bit program counter, 8 bit stack pointer
        uint16_t stack[16]; // 16 16bit values can be stored in stack
        uint8_t delayTimer, soundTimer; // Delay and sound 8 bit registers

        //MEMORY
        uint8_t memory[4096]; // 4kb RAM

        //DISPLAY
        int display[64 * 32]; // 64*32 display

        //KEYPAD
        int keypad[16]; // Hexadecimal keypad

        //flags
        bool drawFlag; // If true, need to draw

    public:
        Chip8(); //constructor

        bool loadRom(std::string); // Returns false if any error occurs while loading

        bool getDrawFlag();

        void setDrawFlag(bool);

        int getDisplayValue(int);

        void setKeypadValue(int, int);

        ~Chip8(); // Destructor

        void singleCycle();

        int getNibble(int, int, int);
};

#endif