#include <stdio.h>

#include "aes.h"

#define DEBUG
#ifdef DEBUG
void PrintState(uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE])
{
    for (int j = 0; j < STATE_ROW_SIZE; ++j)
    {
        for (int i = 0; i < STATE_COL_SIZE; ++i)
            printf("0x%02x ", state[i][j]);
        puts("");
    }

    puts("");
}

void PrintMessage(uint8_t message[DATA_SIZE], char *text)
{
    if (text != NULL)
        printf("%s", text);

    for (uint8_t i = 0; i < DATA_SIZE; ++i)
        printf("%02x ", message[i]);

    puts("\n");
}
#else
void PrintState(uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE]) {}
void PrintMessage(uint8_t message[DATA_SIZE], char *text) {}
#endif

int main(void)
{
    // Le state est le message écrit en colonne
    uint8_t message[DATA_SIZE] = {0x1f, 0xc9, 0xe1, 0xb9, 0x9c, 0x80, 0x0a, 0x81, 0x01, 0x28, 0xb8, 0x03, 0x67, 0x3c, 0x0f, 0xeb};
    PrintMessage(message, "Message:    ");

    uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE];
    MessageToState(state, message);

    puts("State");
    PrintState(state);

    SubBytes(state);
    puts("SubBytes");
    PrintState(state);

    ShiftRows(state);
    puts("ShiftRows");
    PrintState(state);

    MixColumns(state);
    puts("MixColumns");
    PrintState(state);

    puts("============================");
    puts("MixColumns formulas");
    puts("\
|a'| = |02 03 01 01| |a|\n\
|b'|   |01 02 03 01| |b|\n\
|c'|   |01 01 02 03| |c|\n\
|d'|   |03 01 01 02| |d|");
    puts("\
Les + sont des XOR !\n\
a' = 02 * a + 03 * b + c + d\n\
b' = a + 02 * b + 03 * c + d\n\
c' = a + b + 02 * c + 03 * d\n\
d' = 03 * a + b + c + 02 * d");
    puts("============================");

    return 0;
}
