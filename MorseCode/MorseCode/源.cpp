#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef struct ms {
	char data[1005];
	int nr;
	struct ms *next;
}msc;

typedef struct {
	int date[1005];
	int top;
}Sq;
Sq st;
ms* head;
int jiandin[1005];
int a[11][11];
char b[10][10];
int h = 3; //设置血量
int k = 0;
int r, n, e, d, col, row;

void map() {
	int i, j;
	srand((unsigned)time(NULL));
	for (i = 0; i <= 10; i++) {
		for (j = 0; j <= 10; j++) {
			a[i][j] = rand() % (2 - 0);
		}
	}
	r = rand() % 9 + 1;
	n = rand() % 9 + 1;
	e = rand() % 9 + 1;
	d = rand() % 9 + 1;
	col = r;
	row = n;
}// 制作地图表以及伤害值

void draw() {
	system("cls");
	printf("操作指南：\n“W”“A”“S”“D”可控制上下左右移动，从.出发穿越暗礁抵达求救地点方块。\n重新开始游戏按K \n总血量为3，碰到暗礁扣一血，海域探险GO~！\n");//操作介绍
	for (int i = 0; i<10; i++) {
		for (int j = 0; j<10; j++) {
			printf("%c ", b[i][j]);
		}	printf("\n");
	}
	printf("\n当前剩余血量%d ", h);
	if (h<0)
		printf("\n快点按K重新开始，不许你作死了！");
}//地图显示

void move(char m) {
	if (m == 'w' || m == 'W') {
		if (col <= 0) { printf("\n越界!"); }
		else {
			col -= 1;
			h = h - a[col - 1][row];
			b[col][row] = '.';
			draw();
			if (h <= 0) printf("\n GAME OVER!You are died!");
		}
	}
	if (m == 's' || m == 'S') {
		if (col >= 9) { printf("\n越界!"); }
		else {
			col += 1;
			h = h - a[col + 1][row];
			b[col][row] = '.';
			draw();
			if (h <= 0) printf("\n GAME OVER!You are died!");
		}
	}
	if (m == 'a' || m == 'A') {
		if (row <= 0) { printf("\n越界!"); }
		else {
			row -= 1;
			h = h - a[col][row - 1];
			b[col][row] = '.';
			draw();
			if (h <= 0) printf("\n GAME OVER!You are died!");
		}
	}
	if (m == 'd' || m == 'D') {
		if (row >= 9) { printf("\n越界!"); }
		else {
			row += 1;
			h = h - a[col][row + 1];
			b[col][row] = '.';
			draw();
			if (h <= 0) printf("\n GAME OVER!You are died!");
		}
	}
	if ((b[e][d] == '.') && (h>0)) {
		b[e][d] = 1;
		draw();
		printf("\nWell Down! You Win!!");
	}
}//键盘控制方向及伤害计算

void kbc() {
	while (true) {
		if (kbhit())
		{
			char ch = getch();
			if (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd' || ch == 'W' || ch == 'A' || ch == 'S' || ch == 'D')
			{
				move(ch);
				k = 0;
			}
			if ((b[9][9] == 1) || (h <= 0)) {
				printf("\n重新开始请按K");
			}
			if (ch == 'k' || ch == 'K') {
				k += 1;
				h = 3;
				col = 0; row = 0;
				break;
			}

		}
	}//接收键盘操作
}

void MorseCode() {//摩斯密码表
	head = new ms;
	head->next = NULL;
	ms* p;
	ms* q;
	q = head;
	strcpy(head->data, ".-");
	head->nr = 'A';
	p = new ms; strcpy(p->data, "-..."); p->nr = 'B'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "-.-."); p->nr = 'C'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "-.."); p->nr = 'D'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "."); p->nr = 'E'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "..-."); p->nr = 'F'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "--."); p->nr = 'G'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "...."); p->nr = 'H'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, ".."); p->nr = 'I'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, ".---"); p->nr = 'J'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "-.-"); p->nr = 'K'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, ".-.."); p->nr = 'L'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "--"); p->nr = 'M'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "-."); p->nr = 'N'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "---"); p->nr = 'O'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, ".--."); p->nr = 'P'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "--.-"); p->nr = 'Q'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, ".-."); p->nr = 'R'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "..."); p->nr = 'S'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "-"); p->nr = 'T'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "..-"); p->nr = 'U'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "...-"); p->nr = 'V'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, ".--"); p->nr = 'W'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "-..-"); p->nr = 'X'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "-.--"); p->nr = 'Y'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "--."); p->nr = 'Z'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "-----"); p->nr = '0'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, ".----"); p->nr = '1'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "..---"); p->nr = '2'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "...--"); p->nr = '3'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "....-"); p->nr = '4'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "....."); p->nr = '5'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "-...."); p->nr = '6'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "--..."); p->nr = '7'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "---.."); p->nr = '8'; q->next = p; q = q->next;
	p = new ms; strcpy(p->data, "----."); p->nr = '9'; q->next = p; q = NULL;
}
void Push(char *s) {
	ms* p;
	p = new ms;
	p = head;
	st.top = -1;
	if (st.top == 1004)
		return;
	for (int i = 0; i<36; i++) {
		if (!strcmp(s, p->data)) {
			++(st.top);
			st.date[st.top] = p->nr;
			break;
		}
		else p = p->next;
	}
}

void Pop(int i) {//鉴定输入
	if (st.top == -1)
		return;
	else {
		jiandin[i] = st.date[st.top];
		--(st.top);
		printf("%c", jiandin[i]);
	}
}
void translate_morse_code(char *s) {//输入摩斯密码转换
	char tmp[6];
	int len;
	int x, y, p;
	int i = 0;
	len = strlen(s);
	y = 0;
	for (x = 0; x<len + 1; x++) {
		if (s[x] == '_' || s[x] == '.' ||
			s[x] == '-' || s[x] == '*') {
			if (y == 0) p = x;
			if (s[x] == '_') s[x] = '-';
			else if (s[x] == '*') s[x] = '.';
			y++;
		}
		else {
			memcpy(tmp, s + p, y);
			tmp[y] = '\0';
			Push(tmp);
			Pop(i); i++;
			y = 0;
		}
	}
}

int main() {
	char buf[512];
	MorseCode();
	printf("摩斯密码发明于1837年。摩斯密码在早期无线电上举足轻重，是每个无线电通讯者所必须知的。现代社会虽然已经弃之不用，但是其广泛作用影响至今。例如SOS为国际求救通用语就出自摩斯密码的'*** --- ***'\n");
	printf("输入EXIT离开:\n");
	while (1) {
		printf("请输入需要翻译的摩斯密码，以'.' , '-' , '_' , '*'等输入\nMorse Code:\n");
		fgets(buf, 512, stdin);
		if (!memcmp(buf, "EXIT", 4)) return 0;
		printf("------------------------\n");
		translate_morse_code(buf);
		printf("\n------------------------\n");
		if (jiandin[0] == 'S' && jiandin[1] == 'O' && jiandin[2] == 'S') {
			while (k = 1) {
				int i, j;
				map();
				for (i = 0; i<10; i++) {
					for (j = 0; j<10; j++) {
						b[i][j] = '*';
					}
				}//制作起始地图
				b[r][n] = '.';//显示起始位置
				b[e][d] = 4;//显示终点位置
				draw();//显示起始地图
				kbc();//接受键盘操作
			}
		}
	}
	return 0;
}