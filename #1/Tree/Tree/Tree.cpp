// Tree.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct inf { // ��������� ������ �������� �������� ���� ���������������� �����
	char Num[10];
	char Name[20];
	char Surname[20];
	char Year[12];
	struct inf *l;
	struct inf *r;
};

typedef struct inf *ptrinf; // ������ ������� ��������� inf

class Tree {
public:
	ptrinf Search(ptrinf Tree, char Num[]) { // ������� ������ ������������ �����
		if (!Tree) return 0;
		Search(Tree->l, Num);
		if (strcmp(Tree->Num, Num) == 0)
		{
			printf("���: ");
			printf(Tree->Name);
			printf(" | ���������� �����: ");
			printf(Tree->Num);
			return Tree;
		}
		Search(Tree->r, Num);
	};

	ptrinf add() { // ������� ���������� ������
		char Num[10];
		char Name[20];
		char Surname[20];
		char Year[12];
		ptrinf inf2 = new inf;
		printf("������� �����: ");
		scanf("%s", &Num);
		printf("������� ���: ");
		scanf("%s", &Name);
		printf("������� �������: ");
		scanf("%s", &Surname);
		printf("������� ���� ��������: ");
		scanf("%s", &Year);
		strcpy(inf2->Num, Num);
		strcpy(inf2->Year, Year);
		strcpy(inf2->Name, Name);
		strcpy(inf2->Surname, Surname);
		inf2->r = NULL;
		inf2->l = NULL;
		return inf2;
	};

	void show(ptrinf Tree) { // ������� ������ �����
		if (!Tree) return;
		show(Tree->l);
		printf(" %s | ���: %s %s - [���� ��������: %s]\n", Tree->Num, Tree->Name, Tree->Surname, Tree->Year);
		show(Tree->r);
	};
};

void main() {
	Tree x;
	ptrinf Root, p1;
	system("chcp 1251");
	printf("    �������� ������ ���������������� ������\n");
	Root = x.add();
	int input;
	char Num[10];
	while (1) {
		system("cls");
		printf("1. �������� ���� � ���������������� ������\n");
		printf("2. ������� ��� �������� ����������\n");
		printf("3. �����\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			system("cls");
			printf("������� ����� �����, � �������� ������ ����������: ");
			scanf("%s", Num);
			p1 = x.Search(Root, Num);
			printf("\n    ���������� ������...\n");
			p1->l = x.add();
			printf("\n    ���������� ����...\n");
			p1->r = x.add();
			break;
		case 2:
			system("cls");
			x.show(Root);
			getch();
			break;
		case 3:
			return;
		}
	}
	return;
};


