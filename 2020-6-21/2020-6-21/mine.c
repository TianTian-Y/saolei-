#include"mine.h"

void InitBoard(char Board[][COL], int row, int col,char elem)
{
	int i = 0;
	for (; i < row; i++){
		int j = 0;
		for (; j < col; j++){
			Board[i][j] = elem;
		}
	}
}
void ShowBoard(char Board[][COL], int row, int col)
{
	int i = 1;
	printf("   ");
	for (; i <= col - 2; i++){
		printf(" %-2d|", i);
	}
	printf("\n");
	for (i = 1; i <= col - 2; i++){
		printf("%3s", "----");
	}
	printf("---\n");
	for (i = 1; i <= row - 2; i++){
		printf("%-2d|", i);
		int j = 1;
		for (; j <= col - 2; j++){
			printf(" %-2c|", Board[i][j]);
		}
		printf("\n");
		for (j = 1; j <= col - 2; j++){
			printf("%3s", "----");
		}
		printf("---\n");

	}

}
void SetMine(char Mine[][COL], int row, int col)
{
	int n = MINE;
	while (n){
		int x = rand() % (ROW - 2) + 1;
		int y = rand() % (COL - 2) + 1;
		if (Mine[x][y] == '1'){
			continue;
		}
		Mine[x][y] = '1';
		n--;
	}
}
char GetMine(char Mine[][COL], int x, int y)
{
	return Mine[x - 1][y + 1] + Mine[x - 1][y] + Mine[x - 1][y - 1] + \
		Mine[x][y + 1] + Mine[x][y - 1] + \
		Mine[x + 1][y + 1] + Mine[x + 1][y] + Mine[x + 1][y - 1] - 7 * '0';

}
void Game()
{
	srand((unsigned long)time(NULL));   //���������������

	char Board[ROW][COL];
	char Mine[ROW][COL];

	InitBoard(Board, ROW, COL,'*');     //��ʼ����������
	InitBoard(Mine, ROW, COL,'0');


	SetMine(Mine, ROW, COL);            //�����׵ķֲ�

	int count = (ROW-2)*(COL-2) - MINE;      //������֮�ⷽ��ĸ���
	while (count>0)          
	{
		system("cls");      //����
		int x = 0;
		int y = 0;
		ShowBoard(Board, ROW, COL);         //���û�չʾ����
		printf("��������Ҫɨ�����꣺\n");
		scanf("%d %d", &x, &y);
		if (x<1 || x>10 || y<1 || y>10){
			printf("������������������������룡\n");
			Sleep(1000);            
			continue;
		}
		else if (Board[x][y] != '*'){
			printf("�������ѱ��ظ����룬���������룡\n");
			Sleep(1000);
			continue;
		}
		else if(Mine[x][y] == '0'){
			char num = GetMine(Mine, x, y);            //�����Χ�׵ĸ���
			Board[x][y] = num;
			count--;
		}
		else {
			printf("�������[%d][%d]�ط����ף�\n",x,y);
			break;
		}
	}
	char *result = NULL;
	if (count > 0){        //��������Ϊɨ������������whileѭ����������Ϊȫ��ɨ����count����0��
		result = "## ��Ŷ���㱻ը���ˣ�o( �i �n �i )o ##\n";
		Sleep(1000);
		printf("\n");
	}
	else{
		result = "## ɨ�׽�������ϲ����Ӯ����(*^��^*) ##\n";
		Sleep(1000);
	}
	printf("####################################\n");
	printf("%s", result);
	printf("####################################\n");
	ShowBoard(Mine, ROW, COL);
}