#include "game.h"

void IniBoard(char Board[ROWS][COLS], char set) {
	for (int i = 1; i <= ROW; i++) {
		for (int j = 1; j <= COL; j++) {
			Board[i][j] = set;
		}
	}
}

void DisplayBoard(char Board[ROWS][COLS], int row, int col) {
	int i, j;
	printf("------*扫*雷*游*戏*-----\n");
	printf("  ");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
	}
	printf("\n");
	printf("  -----------------\n");

	for (i = 1; i <= row; i++) {
		printf("%d", i);
		printf("|");
		for (j = 1; j <= col; j++) {
			printf("%c", Board[i][j]);
			if (j < col)
				printf(" ");
		}
		printf("|\n");
	}
	printf("  -----------------\n");
}

void SetMine(char Board[ROWS][COLS], int row, int col) {
	int cnt = 10;
	while (cnt) {
		//生成雷
		int x = rand() % row + 1;
		int y = rand() % row + 1;

		if (Board[x][y] == '0') {
			Board[x][y] = '1';
			cnt--;
		}
	}
}

void FindMine(char InnerBoard[ROWS][COLS], char OutBoard[ROWS][COLS], int row, int col) {
	//输入坐标
	int x;
	int y;
	int cnt;
	int win = 0;
	do {
		printf("你想查一查哪个坐标呀~:> 比方说哦1 1~\n");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL) {
			if (InnerBoard[x][y] == '1') {
				printf("很遗憾呢~\n你被炸死了~！\n杂鱼~杂鱼~！!\n");
				DisplayBoard(InnerBoard, row, col);
				break;
			}
			else {
				cnt = GetMineCount(InnerBoard, x, y);
				OutBoard[x][y] = cnt + '0';
				DisplayBoard(OutBoard, row, col);
				win++;
			}
		}
		else {
			printf("连坐标都输不对\n杂鱼~杂鱼！\n");
		}
	} while (win <= (ROW * COL) - 10);
	if (win == (ROW * COL) - 10) {
		printf("呜..呜呜...大哥哥好..好..好厉害...\n");
	}
}
int GetMineCount(char InnerBoard[ROWS][COLS], int x, int y) {
	int cnt = 0;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (InnerBoard[i][j] == '1')
				cnt++;
		}
	}
	return cnt;
}