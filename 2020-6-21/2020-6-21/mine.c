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
	srand((unsigned long)time(NULL));   //种随机数种子种子

	char Board[ROW][COL];
	char Mine[ROW][COL];

	InitBoard(Board, ROW, COL,'*');     //初始化两个棋盘
	InitBoard(Mine, ROW, COL,'0');


	SetMine(Mine, ROW, COL);            //设置雷的分布

	int count = (ROW-2)*(COL-2) - MINE;      //除了雷之外方块的个数
	while (count>0)          
	{
		system("cls");      //清屏
		int x = 0;
		int y = 0;
		ShowBoard(Board, ROW, COL);         //向用户展示棋盘
		printf("请输入你要扫的坐标：\n");
		scanf("%d %d", &x, &y);
		if (x<1 || x>10 || y<1 || y>10){
			printf("你输入的坐标有误，请重新输入！\n");
			Sleep(1000);            
			continue;
		}
		else if (Board[x][y] != '*'){
			printf("此坐标已被重复输入，请重新输入！\n");
			Sleep(1000);
			continue;
		}
		else if(Mine[x][y] == '0'){
			char num = GetMine(Mine, x, y);            //获得周围雷的个数
			Board[x][y] = num;
			count--;
		}
		else {
			printf("你输入的[%d][%d]地方有雷！\n",x,y);
			break;
		}
	}
	char *result = NULL;
	if (count > 0){        //代表是因为扫到雷了跳出了while循环而不是因为全部扫完了count减到0了
		result = "## 啊哦！你被炸死了！o( ╥ ﹏ ╥ )o ##\n";
		Sleep(1000);
		printf("\n");
	}
	else{
		result = "## 扫雷结束！恭喜！你赢啦！(*^▽^*) ##\n";
		Sleep(1000);
	}
	printf("####################################\n");
	printf("%s", result);
	printf("####################################\n");
	ShowBoard(Mine, ROW, COL);
}