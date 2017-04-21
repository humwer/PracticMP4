// Tree.cpp: определяет точку входа для консольного приложения.
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
		printf("Имя: ");
		printf(Tree->Name);
		printf("| Порядковый номер: ");
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
	printf("Введите номер: ");
	scanf("%s", &Num);
	printf("Введите имя: ");
	scanf("%s", &Name);
	printf("Введите дату рождения: ");
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
	printf("    Создайте корень генеалогического дерева\n");
	Root = CreateLeaf();
	int input;
	char Num[10];
	while (1) {
		system("cls");
		printf("1. Добавить лист к генеалогическому дереву\n");
		printf("2. Вывести всю введённую информацию\n");
		printf("3. Выход\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			system("cls");
			printf("Введите номер листа, к которому хотите обратиться: ");
			scanf("%s", Num);
			p1 = Search(Root, Num);
			printf("\n    Добавление матери...\n");
			p1->l = CreateLeaf();
			printf("\n    Добавление отца...\n");
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


