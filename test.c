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
    uint8_t master_key[DATA_SIZE] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};

    PrintMessage(master_key, "Master key: ");

    uint8_t message[DATA_SIZE] = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};

    PrintMessage(message, "Message:    ");

    uint8_t encrypted[DATA_SIZE];

    AESEncrypt(encrypted, message, master_key);

    PrintMessage(encrypted, "Encrypted:  ");

    return 0;
}
