#include "mine.h"

void Menu()
{
	printf("####################################\n");
	printf("#########欢迎来到扫雷小游戏#########\n");
	printf("#####1.Start             2.Quit#####\n");
	printf("####################################\n");
	printf("Please enter your select=>");
}

int main()
{
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		Menu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("游戏开始，快来排雷吧！\n");
			Game();
			break;
		case 2:
			quit = 1;
			printf("再见！欢迎下次来玩...\n");
			break;
		default:
			printf("Enter Error！Please enter again!\n");
			break;
		}
	}
	system("pause");
	return 0;
}