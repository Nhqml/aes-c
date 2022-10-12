#include <stdio.h>

#include "aes.h"

void PrintState(uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE])
{
    for (int i = 0; i < STATE_ROW_SIZE; ++i)
    {
        for (int j = 0; j < STATE_COL_SIZE; ++j)
            printf("0x%02x ", state[i][j]);
        puts("");
    }
}

int main(void)
{
    uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE] = {
        {0x19, 0xa0, 0x9a, 0xe9},
        {0x3d, 0xf4, 0xc6, 0xf8},
        {0xe3, 0xe2, 0x8d, 0x48},
        {0xbe, 0x2b, 0x2a, 0x08}};

    PrintState(state);
    puts("");

    // 0x19 0xa0 0x9a 0xe9
    // 0x3d 0xf4 0xc6 0xf8
    // 0xe3 0xe2 0x8d 0x48
    // 0xbe 0x2b 0x2a 0x08

    SubBytes(state);
    PrintState(state);
    puts("");

    // 0xd4 0xe0 0xb8 0x1e
    // 0x27 0xbf 0xb4 0x41
    // 0x11 0x98 0x5d 0x52
    // 0xae 0xf1 0xe5 0x30

    ShiftRows(state);
    PrintState(state);
    puts("");

    // 0xd4 0xe0 0xb8 0x1e
    // 0xbf 0xb4 0x41 0x27
    // 0x5d 0x52 0x11 0x98
    // 0x30 0xae 0xf1 0xe5

    MixColumns(state);
    PrintState(state);
    puts("");

    // 0x04 0xe0 0x48 0x28
    // 0x66 0xcb 0xf8 0x06
    // 0x81 0x19 0xd3 0x26
    // 0xe5 0x9a 0x7a 0x4c

    return 0;
}