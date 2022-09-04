#include <cstdio>
#include <cstdlib>

char map[6][9] =
	{
		{' ', ' ', '#', '#', '#', '#', ' ', ' ', ' '},
		{'#', '#', '#', ' ', ' ', '#', '#', '#', '#'},
		{'#', ' ', ' ', ' ', ' ', ' ', '*', ' ', '#'},
		{'#', ' ', '#', ' ', ' ', '#', '*', ' ', '#'},
		{'#', ' ', '$', ' ', '$', '#', 'x', ' ', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#'}};
char last_map[6][9];
int x = 4, y = 6;
int final1_x = 4, final1_y = 2;
int final2_x = 4, final2_y = 4;

void print_map()
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 9; ++j)
			printf("%c", map[i][j]);
		printf("\n");
	}
}

void save_map()
{
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 9; ++j)
			last_map[i][j] = map[i][j];
}

void prompt()
{
	printf("Enter: ");
}

void restore_map()
{
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 9; ++j)
		{
			map[i][j] = last_map[i][j];
			if (last_map[i][j] == 'x')
			{
				x = i;
				y = j;
			}
		}
}

void print_info()
{
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

void clear()
{
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
	system("CLS");
#elif defined(__linux) || defined(__linux__) || defined(linux)
	system("clear");
#endif
}

void pause()
{
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
	system("PAUSE");
#endif
}

int main()
{
	int count = 0;
	print_info();
	print_map();
	prompt();
	while (true)
	{
		count++;
		char tmp = getchar();
		while (getchar() != '\n')
			; // 只读每行首字符
		bool final = false;
		int mem_x = x;
		int mem_y = y;
		switch (tmp)
		{
		case 'B':
		case 'b':
			restore_map();
			break;
		case 'W':
		case 'w':
			save_map();
			if (x == final1_x && y == final1_y || x == final2_x && y == final2_y)
				final = true;
			if (map[x - 1][y] == '*' && map[x - 2][y] == ' ')
			{
				map[x - 2][y] = '*';
				map[x - 1][y] = 'x';
				map[x][y] = ' ';
				x--;
			}
			else if (map[x - 1][y] == ' ')
			{
				map[x - 1][y] = 'x';
				map[x][y] = ' ';
				x--;
			}
			else if (map[x - 1][y] == '*' && map[x - 2][y] == '$')
			{
				map[x - 2][y] = '*';
				map[x - 1][y] = 'x';
				map[x][y] = ' ';
				x--;
			}
			else if (map[x - 1][y] == '$')
			{
				map[x - 1][y] = 'x';
				map[x][y] = ' ';
				x--;
			}
			if (x != mem_x && final)
				map[mem_x][y] = '$';
			break;
		case 'S':
		case 's':
			save_map();
			if (x == final1_x && y == final1_y || x == final2_x && y == final2_y)
				final = true;
			if (map[x + 1][y] == '*' && map[x + 2][y] == ' ')
			{
				map[x + 2][y] = '*';
				map[x + 1][y] = 'x';
				map[x][y] = ' ';
				x++;
			}
			else if (map[x + 1][y] == ' ')
			{
				map[x + 1][y] = 'x';
				map[x][y] = ' ';
				x++;
			}
			else if (map[x + 1][y] == '*' && map[x + 2][y] == '$')
			{
				map[x + 2][y] = '*';
				map[x + 1][y] = 'x';
				map[x][y] = ' ';
				x++;
			}
			else if (map[x + 1][y] == '$')
			{
				map[x + 1][y] = 'x';
				map[x][y] = ' ';
				x++;
			}
			if (x != mem_x && final)
				map[mem_x][y] = '$';
			break;
		case 'A':
		case 'a':
			save_map();
			if (x == final1_x && y == final1_y || x == final2_x && y == final2_y)
				final = true;
			if (map[x][y - 1] == '*' && map[x][y - 2] == ' ')
			{
				map[x][y - 2] = '*';
				map[x][y - 1] = 'x';
				map[x][y] = ' ';
				y--;
			}
			else if (map[x][y - 1] == ' ')
			{
				map[x][y - 1] = 'x';
				map[x][y] = ' ';
				y--;
			}
			else if (map[x][y - 1] == '*' && map[x][y - 2] == '$')
			{
				map[x][y - 2] = '*';
				map[x][y - 1] = 'x';
				map[x][y] = ' ';
				y--;
			}
			else if (map[x][y - 1] == '$')
			{
				map[x][y - 1] = 'x';
				map[x][y] = ' ';
				y--;
			}
			if (y != mem_y && final)
				map[x][mem_y] = '$';
			break;
		case 'D':
		case 'd':
			save_map();
			if (x == final1_x && y == final1_y || x == final2_x && y == final2_y)
				final = true;
			if (map[x][y + 1] == '*' && map[x][y + 2] == ' ')
			{
				map[x][y + 2] = '*';
				map[x][y + 1] = 'x';
				map[x][y] = ' ';
				y++;
			}
			else if (map[x][y + 1] == ' ')
			{
				map[x][y + 1] = 'x';
				map[x][y] = ' ';
				y++;
			}
			else if (map[x][y + 1] == '*' && map[x][y + 2] == '$')
			{
				map[x][y + 2] = '*';
				map[x][y + 1] = 'x';
				map[x][y] = ' ';
				y++;
			}
			else if (map[x][y + 1] == '$')
			{
				map[x][y + 1] = 'x';
				map[x][y] = ' ';
				y++;
			}
			if (y != mem_y && final)
				map[x][mem_y] = '$';
			break;
		case 'Q':
		case 'q':
			pause();
			return 0;
		}
		if (map[final1_x][final1_y] == '*' && map[final2_x][final2_y] == '*')
		{
			clear();
			print_map();
			printf("You finish this map with %d steps!\n", count);
			printf("Congratulations!\n");
			pause();
			break;
		}
		if (mem_x == x && mem_y == y)
		{
			clear();
			print_map();
			printf("You have to be familiar with the rules of the game!\n");
			printf("Try again!\n");
			prompt();
		}
		else
		{
			clear();
			print_map();
			prompt();
		}
	}
}
