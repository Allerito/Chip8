#include <cstring>
#include <fstream>
#include <iostream>
#include "../include/chip8.h"

// Constructor
Chip8::Chip8()
{
    unsigned char chip8_fontset[80] =
    {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    programCounter = 0x200; // 0x000 to 0x1FF is reserved for interpreter

    // Resetting registers
    I = 0;
    stackPointer = 0;
    soundTimer = 0;
    delayTimer = 0;

    // Clear registers, stack and memory
    memset(V, 0, sizeof(V));
    memset(stack, 0, sizeof(stack));
    memset(memory, 0, sizeof(memory));

    drawFlag = false;

    // Load fontset from 0 to 80
    for (int i = 0; i < 80; i++)
    {
        memory[i] = chip8_fontset[i];
    }

    // Resetting display and keypad
    memset(display, 0, sizeof(display));
    memset(keypad, 0, sizeof(keypad));
}

// Function to load ROM, with path to ROM given as argument
bool Chip8::loadRom(std::string rom_path)
{
    std::ifstream f(rom_path, std::ios::binary | std::ios::in);
    if (!f.is_open())
    {
        return false;
    }

    // Load in memory from 0x200(512) onwards
    char c;
    int j = 512;
    for (int i = 0x200; f.get(c); i++)
    {
        if (j >= 4096)
        {
            return false; // File size too big memory space over so exit
        }
        memory[i] = (uint8_t) c;
        j++;
    }
    return true;
}

bool Chip8::getDrawFlag()
{
    return drawFlag;
}

void Chip8::setDrawFlag(bool flag)
{
    drawFlag = flag;
}

int Chip8::getDisplayValue(int i)
{
    return display[i];
}

void Chip8::setKeypadValue(int index, int val)
{
    keypad[index] = val;
}

// Destructor
Chip8::~Chip8()
{}