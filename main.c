#include "game.h"

void game() {
	//定义棋盘
	char InnerBoard[ROWS][COLS] = { 0 };
	char OutBoard[ROWS][COLS] = { 0 };

	//初始化棋盘
	char ichar = '0';
	char ochar = '#';
	IniBoard(InnerBoard, ichar);
	IniBoard(OutBoard, ochar);

	//打印棋盘
	DisplayBoard(OutBoard, ROW, COL);

	//布雷
	SetMine(InnerBoard, ROW, COL);
	//DisplayBoard(InnerBoard, ROW, COL);

	//排雷
	FindMine(InnerBoard, OutBoard, ROW, COL);
}

void menu() {
	printf("*****************************\n");
	printf("*******1.来玩嘛大哥哥~ ******\n");
	printf("*******----------------******\n");
	printf("*******0.我不玩了！！! ******\n");
	printf("*****************************\n");
}

int main() {
	int uipt;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("你想选什么呀~：>");
		scanf("%d", &uipt);
		switch (uipt) {
		case 0:
			printf("杂鱼~杂鱼~不敢玩游戏的杂鱼~\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("选错了呢~杂鱼~\n");
			break;
		}
	} while (uipt);
	return 0;
}