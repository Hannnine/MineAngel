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
	printf("------*ɨ*��*��*Ϸ*-----\n");
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
		//������
		int x = rand() % row + 1;
		int y = rand() % row + 1;

		if (Board[x][y] == '0') {
			Board[x][y] = '1';
			cnt--;
		}
	}
}

void FindMine(char InnerBoard[ROWS][COLS], char OutBoard[ROWS][COLS], int row, int col) {
	//��������
	int x;
	int y;
	int cnt;
	int win = 0;
	do {
		printf("�����һ���ĸ�����ѽ~:> �ȷ�˵Ŷ1 1~\n");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL) {
			if (InnerBoard[x][y] == '1') {
				printf("���ź���~\n�㱻ը����~��\n����~����~��!\n");
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
			printf("�����궼�䲻��\n����~���㣡\n");
		}
	} while (win <= (ROW * COL) - 10);
	if (win == (ROW * COL) - 10) {
		printf("��..����...�����..��..������...\n");
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