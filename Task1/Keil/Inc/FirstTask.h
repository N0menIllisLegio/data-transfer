
#ifndef FIRSTTASK
#define FIRSTTASK

#include "string.h"
#include "math.h"
#include "main.h"
#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"

void FirstTask(void);

void ChangePasswordFromTerminal(void);
void DisplayNumber(int number);
void ShiftNumbers(void);
void ClearNumbers(void);

void ClearDisplay(void);
void ReadInput(int col);

int  GetEnteredPasswordLength(void);
void ValidatePublicPassword(void);
void ChangePublicPassword(void);
void CheckStuffPassword(void);

void LightRedLED(void);
void LightGreenLED(void);
void LightYellowLED(void);
void ToggleAllLEDs(void);

#endif
