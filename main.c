#include "game.h"

void game() {
	//��������
	char InnerBoard[ROWS][COLS] = { 0 };
	char OutBoard[ROWS][COLS] = { 0 };

	//��ʼ������
	char ichar = '0';
	char ochar = '#';
	IniBoard(InnerBoard, ichar);
	IniBoard(OutBoard, ochar);

	//��ӡ����
	DisplayBoard(OutBoard, ROW, COL);

	//����
	SetMine(InnerBoard, ROW, COL);
	//DisplayBoard(InnerBoard, ROW, COL);

	//����
	FindMine(InnerBoard, OutBoard, ROW, COL);
}

void menu() {
	printf("*****************************\n");
	printf("*******1.���������~ ******\n");
	printf("*******----------------******\n");
	printf("*******0.�Ҳ����ˣ���! ******\n");
	printf("*****************************\n");
}

int main() {
	int uipt;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("����ѡʲôѽ~��>");
		scanf("%d", &uipt);
		switch (uipt) {
		case 0:
			printf("����~����~��������Ϸ������~\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("ѡ������~����~\n");
			break;
		}
	} while (uipt);
	return 0;
}