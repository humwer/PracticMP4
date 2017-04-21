// Tree.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct Node {
	char Num[10];
	char Name[40];
	int Year;
	struct Node *l;
	struct Node *r;
};
typedef struct Node *PNode;

PNode Search(PNode Tree, char Num[]) {
	if (!Tree) return 0;
	Search(Tree->l, Num);
	if (strcmp(Tree->Num, Num) == 0)
	{
		printf("���: ");
		printf(Tree->Name);
		printf("| ���������� �����: ");
		printf(Tree->Num);
		return Tree;
	}
	Search(Tree->r, Num);
};

PNode CreateLeaf() {
	char Num[10];
	char Name[40];
	int Year;
	PNode NewNode = new Node;
	printf("������� �����: ");
	scanf("%s", &Num);
	printf("������� ���: ");
	scanf("%s", &Name);
	printf("������� ���� ��������: ");
	scanf("%d", &Year);
	strcpy(NewNode->Num, Num);
	strcpy(NewNode->Name, Name);
	NewNode->Year = Year;
	NewNode->l = NULL;
	NewNode->r = NULL;
	return NewNode;
};

void ShowAllLeafs(PNode Tree) {
	if (!Tree) return;
	ShowAllLeafs(Tree->l);
	printf("%s - %d\n", Tree->Name, Tree->Year);
	ShowAllLeafs(Tree->r);
};

void main() {
	PNode Root, p1;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("    �������� ������ ���������������� ������\n");
	Root = CreateLeaf();
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
			p1 = Search(Root, Num);
			printf("\n    ���������� ������...\n");
			p1->l = CreateLeaf();
			printf("\n    ���������� ����...\n");
			p1->r = CreateLeaf();
			break;
		case 2:
			system("cls");
			ShowAllLeafs(Root);
			getch();
			break;
		case 3:
			return;
		default:
			break;
		}
	}
	return;
};


