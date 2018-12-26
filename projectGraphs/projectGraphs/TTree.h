#pragma once
using namespace System::Drawing;
using namespace System;
#include"Adjacencies.h"

class TTree
{
	Node* first; //указатель на первую вершину
	Adjacencies* f; //указатель на первое ребро	
public:
	TTree(); //конструктор
	void Add(Point p); //добавить точку
	void Draw(Graphics^ g); //рисовать дерево
	Node* Hit(Point); //попадание точки
	Adjacencies* AddAdj(Node*, Node*, int); //добавить ребро 
	void Sort(); //сортировка ребер по увеличению val
	TTree* Task(); //задание
	void DrawAdj(Graphics^ g); //рисовать ребра
	void Add(Adjacencies*);	//добавить ребро в мин ост дерево
};

