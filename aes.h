#pragma once

#include <stdint.h>

#define DATA_SIZE 16
#define STATE_ROW_SIZE 4
#define STATE_COL_SIZE 4
#define ROUND_COUNT 10

// the round that will trigger
extern uint8_t targeted_round;

void AESEncrypt(uint8_t ciphertext[DATA_SIZE], uint8_t plaintext[DATA_SIZE], uint8_t key[DATA_SIZE]);

void SubBytes(uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE]);
void ShiftRows(uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE]);
void MixColumns(uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE]);

void GetRoundKey(uint8_t roundkey[STATE_ROW_SIZE][STATE_COL_SIZE], uint8_t roundkeys[ROUND_COUNT + 1][STATE_ROW_SIZE][STATE_COL_SIZE], int round);
void AddRoundKey(uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE], uint8_t roundkey[STATE_ROW_SIZE][STATE_COL_SIZE]);

// Generate all roundkeys
void KeyGen(uint8_t roundkeys[ROUND_COUNT + 1][STATE_ROW_SIZE][STATE_COL_SIZE], uint8_t master_key[STATE_ROW_SIZE][STATE_COL_SIZE]);

// Fill the first column of a given round key
void ColumnFill(uint8_t roundkeys[ROUND_COUNT + 1][STATE_ROW_SIZE][STATE_COL_SIZE], int round);
// Fill the other 3 columns of a given round key
void OtherColumnsFill(uint8_t roundkeys[ROUND_COUNT + 1][STATE_ROW_SIZE][STATE_COL_SIZE], int round);

void MessageToState(uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE], uint8_t message[DATA_SIZE]);
void StateToMessage(uint8_t message[DATA_SIZE], uint8_t state[STATE_ROW_SIZE][STATE_COL_SIZE]);

void MCMatrixColumnProduct(uint8_t colonne[STATE_COL_SIZE]);

// Galois field (256) multiplication of two bytes
uint8_t GMul(uint8_t a, uint8_t b);

extern const uint8_t rcon[10];
extern const uint8_t sboxtab[256];
extern const uint8_t invsbox[256];
