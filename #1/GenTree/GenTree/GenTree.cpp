// GenTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

	struct Fam {
		char Name[51];
		int Year;
		struct Fam *l, *r;
	};
	typedef struct Fam *PFam;
	PFam Search(PFam Tree, char Name[]) {
		if (!Tree) return 0;
		Search(Tree->l, Name);
		if (strcmp(Tree->Name, Name) == 0)
			return Tree;
		Search(Tree->r, Name);
	};
	PFam CreateLeaf() {
		char Name[40];
		int Year;
		PFam NewFam = new struct Fam;
		printf("Введите имя: ");
		scanf("%s", &Name);
		printf("Введите дату рождения: ");
		scanf("%d", &Year);
		strcpy(NewFam->Name, Name);
		NewFam->Year = Year;
		NewFam->l = NULL;
		NewFam->r = NULL;
		return NewFam;
	};
	void ShowAllLeafs(PFam Tree) {
		if (!Tree) return;
		ShowAllLeafs(Tree->l);
		printf("%s - %d\n", Tree->Name, Tree->Year);
		ShowAllLeafs(Tree->r);
	};
	void del(Fam *&Tree){
		if (Tree != NULL) //Пока не встретится пустое звено
		{
			del(Tree->l); //Рекурсивная функция прохода по левому поддереву
			del(Tree->r); //Рекурсивная функци для прохода по правому поддереву
			delete Tree; //Убиваем конечный элемент дерева
			Tree = NULL; //Может и не обязательно, но плохого не будет
		}
	}

	int main()
	{
		setlocale(LC_ALL, "Russian");
		PFam Root, p1;
		printf("    Создайте корень генеалогического дерева\n");
		Root = CreateLeaf();
		int input;
		char Name[40];
		while (1) {
			system("cls");
			printf("1. Добавить лист к генеалогическому дереву\n");
			printf("2. Вывести всю введённую информацию\n");
			printf("3. Выход\n");
			scanf("%d", &input);
			switch (input) {
			case 1:
				system("cls");
				printf("Введите имя листа, к которому хотите обратиться: ");
				scanf("%s", Name);
				p1 = Search(Root, Name);
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
				return 0;
			default:
				break;
			}
		}
		return 0;
	};