#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
char map[8][12] =
{
	{' ',' ',' ','#','#','#','#','#',' ',' ',' ',' '},
	{'#','#','#','#',' ',' ',' ','#',' ',' ',' ',' '},
	{'#','$','$','#','*','*',' ','#',' ',' ',' ',' '},
	{'#',' ','$','$','*',' ',' ','#','#','#','#','#'},
	{'#',' ','x','#',' ','#',' ','#',' ',' ',' ','#'},
	{'#',' ',' ','*',' ',' ',' ',' ',' ','*',' ','#'},
	{'#',' ',' ','#','#','#','#','#','#','#','$','#'},
	{'#','#','#','#',' ',' ',' ',' ',' ','#','#','#'}
};
char last_map[8][12];
int x = 4, y = 2;
int final1_x = 2, final1_y = 1;
int final2_x = 2, final2_y = 2;
int final3_x = 3, final3_y = 2;
int final4_x = 3, final4_y = 3;
int final5_x = 6, final5_y = 10;
void Print_Map()
{
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 12; ++j)
			printf("%c", map[i][j]);
		printf("\n");
	}
}
void Save_Map()
{
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 12; ++j)
			last_map[i][j] = map[i][j];
}
void Prompt()
{
	printf("Enter:");
}
void Restore_Map()
{
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 12; ++j) {
			map[i][j] = last_map[i][j];
			if (last_map[i][j] == 'x')
			{
				x = i; y = j;
			}
		}
}
void Print_Introduction()
{
	printf("//201250012\n");
	printf("WELCOME!\n");
	printf("GAME INTRODUCTION:\n");
	printf("\'x\'----present location\n");
	printf("\'*\'----block\n");
	printf("\'$\'----destination\n");
	printf("Press \'w\',\'a\',\'s\',\'d\' and \"ENTER\" to MOVE.\n");
	printf("Press \'q\' and \"ENTER\" to QUIT.\n");
	printf("Press \'b\' and \"ENTER\" to ROLLBACK.\n");
	printf("SALUTARY REMINDER: \n1. You can input whatever you want, ");
	printf("but this program can only receive the FIRST character you input!\n");
	printf("2. This program is CASE-INSENSITIVE!\n");
	printf("3. The ROLLBACK function can't be used continuously!\n");
	printf("4. Don't forget to press \"ENTER\" to confirm your input!\n");
	printf("5. SORRY! The interface is minimal, try to enlarge it!\n");
	printf("6. After you press \"ENTER\" for the first time, the introduction will disappear!\n");
	printf("HAVE FUN!\n");
}
int main()
{
	int count = 0;
	Print_Map();
	Print_Introduction();
	Prompt();
	while (true) {
		count++;
		char tmp = getchar();
		while (getchar() != '\n');//只读每行首字符
		bool final = false;
		int mem_x = x;
		int mem_y = y;
		switch (tmp)
		{
		case 'B':
		case 'b':
			Restore_Map();
			break;
		case 'W':
		case 'w':
			Save_Map();
			if (x == final1_x && y == final1_y 
				|| x == final2_x && y == final2_y
				|| x == final3_x && y == final3_y 
				|| x == final4_x && y == final4_y
				|| x == final5_x && y == final5_y)
				final = true;
			if (map[x - 1][y] == '*' && map[x - 2][y] == ' ') {
				map[x - 2][y] = '*';
				map[x - 1][y] = 'x';
				map[x][y] = ' ';
				x--;
			}
			else if (map[x - 1][y] == ' ') {
				map[x - 1][y] = 'x';
				map[x][y] = ' ';
				x--;
			}
			else if (map[x - 1][y] == '*' && map[x - 2][y] == '$') {
				map[x - 2][y] = '*';
				map[x - 1][y] = 'x';
				map[x][y] = ' ';
				x--;
			}
			else if (map[x - 1][y] == '$') {
				map[x - 1][y] = 'x';
				map[x][y] = ' ';
				x--;
			}
			if (x != mem_x && final)
				map[mem_x][y] = '$';
			break;
		case 'S':
		case 's':
			Save_Map();
			if (x == final1_x && y == final1_y || x == final2_x && y == final2_y)
				final = true;
			if (map[x + 1][y] == '*' && map[x + 2][y] == ' ') {
				map[x + 2][y] = '*';
				map[x + 1][y] = 'x';
				map[x][y] = ' ';
				x++;
			}
			else if (map[x + 1][y] == ' ') {
				map[x + 1][y] = 'x';
				map[x][y] = ' ';
				x++;
			}
			else if (map[x + 1][y] == '*' && map[x + 2][y] == '$') {
				map[x + 2][y] = '*';
				map[x + 1][y] = 'x';
				map[x][y] = ' ';
				x++;
			}
			else if (map[x + 1][y] == '$') {
				map[x + 1][y] = 'x';
				map[x][y] = ' ';
				x++;
			}
			if (x != mem_x && final)
				map[mem_x][y] = '$';
			break;
		case 'A':
		case 'a':
			Save_Map();
			if (x == final1_x && y == final1_y || x == final2_x && y == final2_y)
				final = true;
			if (map[x][y - 1] == '*' && map[x][y - 2] == ' ') {
				map[x][y - 2] = '*';
				map[x][y - 1] = 'x';
				map[x][y] = ' ';
				y--;
			}
			else if (map[x][y - 1] == ' ') {
				map[x][y - 1] = 'x';
				map[x][y] = ' ';
				y--;
			}
			else if (map[x][y - 1] == '*' && map[x][y - 2] == '$') {
				map[x][y - 2] = '*';
				map[x][y - 1] = 'x';
				map[x][y] = ' ';
				y--;
			}
			else if (map[x][y - 1] == '$') {
				map[x][y - 1] = 'x';
				map[x][y] = ' ';
				y--;
			}
			if (y != mem_y && final)
				map[x][mem_y] = '$';
			break;
		case 'D':
		case 'd':
			Save_Map();
			if (x == final1_x && y == final1_y || x == final2_x && y == final2_y)
				final = true;
			if (map[x][y + 1] == '*' && map[x][y + 2] == ' ') {
				map[x][y + 2] = '*';
				map[x][y + 1] = 'x';
				map[x][y] = ' ';
				y++;
			}
			else if (map[x][y + 1] == ' ') {
				map[x][y + 1] = 'x';
				map[x][y] = ' ';
				y++;
			}
			else if (map[x][y + 1] == '*' && map[x][y + 2] == '$') {
				map[x][y + 2] = '*';
				map[x][y + 1] = 'x';
				map[x][y] = ' ';
				y++;
			}
			else if (map[x][y + 1] == '$') {
				map[x][y + 1] = 'x';
				map[x][y] = ' ';
				y++;
			}
			if (y != mem_y && final)
				map[x][mem_y] = '$';
			break;
		case 'Q':
		case 'q':
			system("PAUSE");
			return 0;
		}
		if (map[final1_x][final1_y] == '*' 
			&& map[final2_x][final2_y] == '*'
			&& map[final3_x][final3_y] == '*'
			&& map[final4_x][final4_y] == '*'
			&& map[final5_x][final5_y] == '*') {
			system("CLS");
			Print_Map();
			printf("You finish this map with %d steps!\n", count);
			printf("Congratulations!\n");
			system("PAUSE");
			break;
		}
		if (mem_x == x && mem_y == y) {
			system("CLS");
			Print_Map();
			printf("You have to be familiar with the rules of the game!\n");
			printf("Try again!\n");
			Prompt();
		}
		else {
			system("CLS");//清屏
			Print_Map();
			Prompt();
		}
	}
}