#include "mine.h"

void Menu()
{
	printf("####################################\n");
	printf("#########��ӭ����ɨ��С��Ϸ#########\n");
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
			printf("��Ϸ��ʼ���������װɣ�\n");
			Game();
			break;
		case 2:
			quit = 1;
			printf("�ټ�����ӭ�´�����...\n");
			break;
		default:
			printf("Enter Error��Please enter again!\n");
			break;
		}
	}
	system("pause");
	return 0;
}