#include "FirstTask.h"

int Numbers[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
int PublicPassword = 1111;
const int StuffPassword = 3228;

int EnteredStuffPassword = 0;
int ShiftOfStuffPassword = 0;

uint16_t Row = 1;

int EnteredValue = -1;

const uint16_t Numbers7Seg[10] = {
	126, //0b0000000001111110, aka 0
	48,  //0b0000000000110000, aka 1
	109, //0b0000000001101101, aka 2
	121, //0b0000000001111001, aka 3
	51,  //0b0000000000110011, aka 4
	91,  //0b0000000001011011, aka 5
	95,  //0b0000000001011111, aka 6
	112, //0b0000000001110000, aka 7
	127, //0b0000000001111111, aka 8
	123  //0b0000000001111011  aka 9
};

const int NumbersNumPad[4][4] = {
	{1,  2,  3, -1},
	{4,  5,  6, -1},
	{7,  8,  9, -1},
	{10, 0, 11, -1},
};

void FirstTask()
{
	int InputedNumber = -1;
	int Counter = 0;
	
  while (1)
  {
		HAL_GPIO_TogglePin(GPIOB, Row);		
		InputedNumber = EnteredValue;
	
		ChangePasswordFromTerminal();
		
		if (InputedNumber != -1)
		{
			if (InputedNumber == 10)
			{
				// *
				int length = GetEnteredPasswordLength();
				WriteCOM("OK");
				
				ClearDisplay();
				if (length == 4)
				{
					ValidatePublicPassword();
				} else {					
					if (length == 8)
					{
						ChangePublicPassword();
					} else {
						WriteCOM("ERROR");
						LightRedLED();
					}
				}
				
				ClearNumbers();
				
			} else {
				if (InputedNumber == 11)
				{
					// #
					WriteCOM("CANCEL");
					ClearNumbers();		
					LightYellowLED();					
				} else {
					// Number
					ShiftNumbers();
					if (EnteredStuffPassword == 1)
					{
						ShiftOfStuffPassword++;
						if (ShiftOfStuffPassword > 4)
						{
							EnteredStuffPassword = 0;
							ShiftOfStuffPassword = 0;
							HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET);		
							HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
						}
					}
					Numbers[7] = InputedNumber;
					CheckStuffPassword();
				}
			}
			
			EnteredValue = -1;
		}
		
		DisplayNumber(Counter);
		Counter++;
		if (Counter > 3)
		{
			Counter = 0;
		}
		
		HAL_GPIO_TogglePin(GPIOB, Row);
		Row = Row << 1;
		if (Row > 8)
		{
			Row = 1;
		}
  }
}

void ChangePasswordFromTerminal()
{
	char buff[4];
	char symbol[1];

	ReadCOM(symbol, 10);
	if (symbol[0] == '*')
	{
		WriteCOM("Enter stuff password:");
		ReadCOM(buff, 5000);
		char temp[4];
		sprintf(temp, "%d", StuffPassword);
		if (strcmp(buff, temp) == 0)
		{
			buff[0] = '-';
			buff[1] = '-';
			buff[2] = '-';
			buff[3] = '-';
			
			WriteCOM("Enter new public password:");
			
			ReadCOM(buff, 5000);
			if (isdigit(buff[0]) && isdigit(buff[1]) && isdigit(buff[2]) && isdigit(buff[3]))
			{
				PublicPassword = atoi(buff);		
				WriteCOM("Public password changed!");
			}
			else
			{
				WriteCOM("Incorrect public password.");
			}
		}
		else
		{
			WriteCOM("Wrong stuff password.");
		}
		
		symbol[0] = '1';
		buff[0] = '-'; buff[1] = '-'; buff[2] = '-'; buff[3] = '-';
	}
}

void CheckStuffPassword()
{
	int enteredStuffPassword = Numbers[4] * 1000 + Numbers[5] * 100 + Numbers[6] * 10 + Numbers[7];
	if (enteredStuffPassword == StuffPassword)
	{
		EnteredStuffPassword = 1;
		ShiftOfStuffPassword = 0;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET);		
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
		
		WriteCOM("Entered stuff password.");
	}
}


void ChangePublicPassword()
{	
	WriteCOM("Change public password:");
	if (EnteredStuffPassword == 1)
	{
		PublicPassword = Numbers[4] * 1000 + Numbers[5] * 100 + Numbers[6] * 10 + Numbers[7];
		WriteCOM("Public password changed!");	
		LightGreenLED();
		
	} else {
		WriteCOM("ERROR");
		LightRedLED();
	}
}

void ValidatePublicPassword()
{
	int enteredPassword = Numbers[4] * 1000 + Numbers[5] * 100 + Numbers[6] * 10 + Numbers[7];
	
	if (enteredPassword == PublicPassword)
	{
		WriteCOM("Entered public password.");
		LightGreenLED();
	} else {
		WriteCOM("ERROR");
		LightRedLED();
	}
}

int GetEnteredPasswordLength()
{
	int length = 0;
	
	for (int i = 0; i < 8; i++)
	{
		if (Numbers[i] != -1)
		{
			length++;
		}
	}
	
	return length;
}

void LightRedLED()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
}

void LightGreenLED()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
}

void LightYellowLED()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET);
}

void ClearDisplay()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
}


void ClearNumbers()
{
	EnteredStuffPassword = 0;
	ShiftOfStuffPassword = 0;

	for(int i = 0; i < 8; i++)
	{
		Numbers[i] = -1;
	}
	
	ClearDisplay();
}

void ShiftNumbers()
{
	for(int i = 0; i < 7; i++)
	{
		Numbers[i] = Numbers[i + 1];
	}
}
void ReadInput(int col)
{
	int rowNumber = log2(Row);
	
	EnteredValue = NumbersNumPad[rowNumber][col];
}

void DisplayNumber(int number)
{
		ClearDisplay();
	
	if ((Numbers[7 - number] >= 0 && Numbers[7 - number] <= 9))
	{
		HAL_GPIO_TogglePin(GPIOA, Numbers7Seg[Numbers[7 - number]]);
		
		switch(number)
		{
			case 0:
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_12);
				break;
			case 1:
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_11);
				break;
			case 2:
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
				break;
			case 3:
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
				break;
		}
	}
	
	HAL_Delay(1);
}

