/*
author:ChiyoYuki
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int box[16][16], size = 4, ok;
const int MAX_NUM = 2048;

void MakeIt();
void MoveDown();
void MoveLeft();
void MoveRight();
void MoveUp();
int MoveIt();
void Print();
int WinOrLose();

int main()
{
	srand(time(NULL));
	MakeIt();
	MakeIt();
	while (1)
	{
		system("cls");
		Print();
		if (MoveIt() == 1)
		{
			if (WinOrLose()==1)
			{
				system("cls");
				printf("You Win!\n");
				break;
			}
			MakeIt();
			if (WinOrLose() == -1)
			{
				system("cls");
				printf("You lose.\n");
				break;
			}
		}
	}
	Print();
	printf("Please press any key to exit");
	_getch();
	return 0;
}

int WinOrLose()
{
	int i, j,lose=1;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (box[i][j] == 0) lose = 0;
			if (box[i][j] == MAX_NUM) return 1;
		}
	}
	for (i = 1; i < size; i++)
		{
			for (j = 1; j < size; j++)
			{
				if (box[i][j] == box[i - 1][j] || box[i][j] == box[i][j - 1])
				{
					lose = 0;
					break;
				}
			}
			if (lose == 0) break;
		}
		if (box[0][0] == box[0][1] || box[1][0]==box[0][0]) lose = 0;
	if (lose) return -1;
	else return 0;
}

int MoveIt()
{
	int dir=0;
	int i, j, k;
	ok = 0;
	printf("\nW/8=Up");
	printf("\nA/4=Left");
	printf("\nD/6=Right");
	printf("\nS/2=Down");
	while (dir != '2' && dir != '4' && dir != '6' && dir != '8' && dir != 'w' && dir != 'a' && dir != 's' && dir != 'd' && dir != 'W' && dir != 'A' && dir != 'S' && dir != 'D')
	{
		dir = _getch();
		if (dir == '2'||dir=='s'||dir=='S')
		{
			MoveDown();
			for (j = 0; j < size; j++)
			{
				for (i = size - 1; i > 0; i--)
				{
					if (box[i][j] != 0 && box[i][j] == box[i - 1][j])
					{
						box[i][j] *= 2;
						box[i - 1][j] = 0;
						ok = 1;
					}
				}
			}
			MoveDown();
		}
		else if (dir == '4' || dir == 'a' || dir == 'A')
		{
			MoveLeft();
			for (i = 0; i < size; i++)
			{
				for (j = 0; j < size - 1; j++)
				{
					if (box[i][j] != 0 && box[i][j] == box[i][j + 1])
					{
						box[i][j] *= 2;
						box[i][j + 1] = 0;
						ok = 1;
					}
				}
			}
			MoveLeft();
		}
		else if (dir == '6' || dir == 'd' || dir == 'D')
		{
			MoveRight();
			for (i = 0; i < size; i++)
			{
				for (j = size - 1; j > 0; j--)
				{
					if (box[i][j] != 0 && box[i][j] == box[i][j - 1])
					{
						box[i][j] *= 2;
						box[i][j - 1] = 0;
						ok = 1;
					}
				}
			}
			MoveRight();
		}
		else if (dir == '8' || dir == 'w' || dir == 'W')
		{
			MoveUp();
			for (j = 0; j < size; j++)
			{
				for (i = 0; i < size - 1; i++)
				{
					if (box[i][j] != 0 && box[i][j] == box[i + 1][j])
					{
						box[i][j] *= 2;
						box[i + 1][j] = 0;
						ok = 1;
					}
				}
			}
			MoveUp();
		}
	}
	return ok;
}

void MoveDown()
{
	int i, j, k;
	for (j = 0; j < size; j++)
	{
		for (i = size - 2; i >= 0; i--)
		{
			if (box[i][j] == 0)
			{
				continue;
			}
			for (k = i + 1; k < size; k++)
			{
				if (box[k][j] != 0)
				{
					break;
				}
				else
				{
					box[k][j] = box[k - 1][j];
					box[k - 1][j] = 0;
					ok = 1;
				}
			}
		}
	}
}

void MoveLeft()
{
	int i, j, k;
	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size; j++)
		{
			if (box[i][j] == 0)
			{
				continue;
			}
			for (k = j - 1; k >= 0; k--)
			{
				if (box[i][k] != 0)
				{
					break;
				}
				else
				{
					box[i][k] = box[i][k + 1];
					box[i][k + 1] = 0;
					ok = 1;
				}
			}
		}
	}
}

void MoveRight()
{
	int i, j, k;
	for (i = 0; i < size; i++)
	{
		for (j = size - 2; j >= 0; j--)
		{
			if (box[i][j] == 0)
			{
				continue;
			}
			for (k = j + 1; k < size; k++)
			{
				if (box[i][k] != 0)
				{
					break;
				}
				else
				{
					box[i][k] = box[i][k - 1];
					box[i][k - 1] = 0;
					ok = 1;
				}
			}
		}
	}
}

void MoveUp()
{
	int i, j, k;
	for (j = 0; j < size; j++)
	{
		for (i = 1; i < size; i++)
		{
			if (box[i][j] == 0)
			{
				continue;
			}
			for (k = i - 1; k >= 0; k--)
			{
				if (box[k][j] != 0)
				{
					break;
				}
				else
				{
					box[k][j] = box[k + 1][j];
					box[k + 1][j] = 0;
					ok = 1;
				}
			}
		}
	}
}

void MakeIt()
{
	int num = 0;
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (box[i][j] == 0) num++;
		}
	}
	if (num == 0) return;
	num = rand() % num + 1;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (box[i][j] == 0) num--;
			if (num == 0) break;
		}
		if (num == 0) break;
	}
	num = rand() % 3;
	if (num) box[i][j] = 2;
	else box[i][j] = 4;
}

void Print()
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		printf("\n");
		for (j = 0; j < size; j++)
		{
			if (box[i][j] != 0 && box[i][j] != MAX_NUM) printf("\033[1;32;40m%4d \033[m", box[i][j]);
			else if (box[i][j]) printf("\033[1;33;40m%4d \033[m", box[i][j]);
			else  printf("%4d ", box[i][j]);
		}
		printf("\n");
	}
}