#pragma once
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int *ram;

extern int accumulator;

extern int command;

extern int flag;

int sc_memoryInit(void);

int sc_memorySet(int address, int value);

int sc_memoryGet(int address, int *value);

int sc_memorySave(char *filename);

int sc_memoryLoad(char *filename);

int sc_regInit(void);

int sc_regSet(int reg, int value);

int sc_regGet(int reg, int *value);

int sc_accumulatorInit(void);

int sc_accumulatorSet(int value);

int sc_accumulatorGet(int *value);

int sc_icounterInit(void);

int sc_icounterSet(int value);

int sc_icounterGet(int *value);

int sc_commandEncode(int sign, int command, int operand, int *value);

int sc_commandDecode(int value, int *sign, int *command, int *operand);

int sc_commandValidate(int command);

void printCell(int address);

void printFlags(void);

void printDecodedCommand(int value);

void printAccumulator(void);

void printCounters(void);
