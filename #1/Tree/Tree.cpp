// Tree.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct inf 
{ // ��������� ������ �������� �������� ���� ���������������� �����
	char Num[50];
	char Name[20];
	char Surname[20];
	char Year[12];
	struct inf *l, *r, *c;
};

typedef struct inf *ptrinf; // ������ ������� ��������� inf

class Tree {
public:
	ptrinf search(ptrinf Tree, char Num[]) 
	{ // ������� ������ ������������ �����
		if (Tree != NULL)
		{
			search(Tree->r, Num);
			if (strcmp(Tree->Num, Num) == 0)
			{
				printf("���: %s", Tree->Name);
				printf(" | ���������� �����: %s", Tree->Num);
				printf("\n    ���������� ������...\n");
				Tree->l = add();
				printf("\n    ���������� ����...\n");
				Tree->r = add();
				return Tree;
			}
			search(Tree->l, Num);
		}
	};

	ptrinf add() 
	{ // ������� ���������� ������
		char Num[50];
		char Name[20];
		char Surname[20];
		char Year[12];
		ptrinf inf2 = new inf;
		inf2->r = NULL;
		inf2->l = NULL;
		printf("������� �����: ");
		scanf("%s", &Num);
		printf("������� ���: ");
		scanf("%s %s", &Name, &Surname);
		printf("������� ���� ��������: ");
		scanf("%s", &Year);
		strcpy(inf2->Num, Num);
		strcpy(inf2->Year, Year);
		strcpy(inf2->Name, Name);
		strcpy(inf2->Surname, Surname);
		return inf2;
	};

	void show(ptrinf Tree) 
	{ // ������� ������ �����
		if (!Tree) return;
		show(Tree->l);
		printf(" %s | ���: %s %s - [���� ��������: %s]\n", Tree->Num, Tree->Name, Tree->Surname, Tree->Year);
		show(Tree->r);
	};
};

void main() 
{
	Tree x;
	ptrinf root, p1;
	system("chcp 1251");
	printf("    �������� ������ ���������������� ������\n");
	root = x.add();
	int input;
	char Num[10];
	while (1) 
	{
		system("cls");
		printf("1. �������� ���� � ���������������� ������\n");
		printf("2. ������� ��� �������� ����������\n");
		printf("3. �����\n");
		scanf("%d", &input);
		switch (input) 
		{
		case 1:
			system("cls");
			printf("������� ����� �����, � �������� ������ ����������: ");
			scanf("%s", Num);
			p1 = x.search(root, Num);
			break;
		case 2:
			system("cls");
			x.show(root);
			getch();
			break;
		case 3:
			return;
		}
	}
	return;
};


