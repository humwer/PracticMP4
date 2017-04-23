// Tree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct inf 
{ // Объявляем данные которыми обладает член генеалогического древа
	char Num[50];
	char Name[20];
	char Surname[20];
	char Year[12];
	struct inf *l, *r, *c;
};

typedef struct inf *ptrinf; // Создаём синоним структуры inf

class Tree {
public:
	ptrinf search(ptrinf Tree, char Num[]) 
	{ // функция поиска необходимого корня
		if (Tree != NULL)
		{
			search(Tree->r, Num);
			if (strcmp(Tree->Num, Num) == 0)
			{
				printf("Имя: %s", Tree->Name);
				printf(" | Порядковый номер: %s", Tree->Num);
				printf("\n    Добавление матери...\n");
				Tree->l = add();
				printf("\n    Добавление отца...\n");
				Tree->r = add();
				return Tree;
			}
			search(Tree->l, Num);
		}
	};

	ptrinf add() 
	{ // функция добавления данных
		char Num[50];
		char Name[20];
		char Surname[20];
		char Year[12];
		ptrinf inf2 = new inf;
		inf2->r = NULL;
		inf2->l = NULL;
		printf("Введите номер: ");
		scanf("%s", &Num);
		printf("Введите имя: ");
		scanf("%s %s", &Name, &Surname);
		printf("Введите дату рождения: ");
		scanf("%s", &Year);
		strcpy(inf2->Num, Num);
		strcpy(inf2->Year, Year);
		strcpy(inf2->Name, Name);
		strcpy(inf2->Surname, Surname);
		return inf2;
	};

	void show(ptrinf Tree) 
	{ // функция вывода древа
		if (!Tree) return;
		show(Tree->l);
		printf(" %s | Имя: %s %s - [Дата рождения: %s]\n", Tree->Num, Tree->Name, Tree->Surname, Tree->Year);
		show(Tree->r);
	};
};

void main() 
{
	Tree x;
	ptrinf root, p1;
	system("chcp 1251");
	printf("    Создайте корень генеалогического дерева\n");
	root = x.add();
	int input;
	char Num[10];
	while (1) 
	{
		system("cls");
		printf("1. Добавить лист к генеалогическому дереву\n");
		printf("2. Вывести всю введённую информацию\n");
		printf("3. Выход\n");
		scanf("%d", &input);
		switch (input) 
		{
		case 1:
			system("cls");
			printf("Введите номер листа, к которому хотите обратиться: ");
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


