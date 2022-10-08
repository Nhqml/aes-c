#include <stdio.h>

#include "aes.h"

void PrintState(uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE])
{
    for (int i = 0; i < STATE_ROW_SIZE; ++i)
    {
        for (int j = 0; j < STATE_COL_SIZE; ++j)
            printf("0x%x ", state[i][j]);
        puts("");
    }
}

int main(void)
{
    uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE] = {
        {0xff, 0xab, 0x25, 0x00},
        {0x11, 0x33, 0x21, 0x99},
        {0xca, 0xfe, 0xba, 0xbe},
        {0xde, 0xad, 0xbe, 0xef}};

    PrintState(state);
    puts("");

    SubBytes(state);
    PrintState(state);
    puts("");

    ShiftRows(state);
    PrintState(state);
    puts("");

    return 0;
}
