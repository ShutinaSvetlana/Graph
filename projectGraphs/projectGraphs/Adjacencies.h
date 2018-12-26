#pragma once
#include"Node.h"
using namespace System::Drawing;
using namespace System;

class Adjacencies
{
	Node* one; //указатель на первую вершину
	Node* two; //указатель на вторую вершину
	Adjacencies* next; //указатель на следующее ребро
	int val; //значение ребра
public:
	Adjacencies(); //конструктор
	Adjacencies(Node*, Node*, int); //конструктор с параметром
	void Draw(Graphics^ g, Pen^ pen); //отрисовка
	bool Task(); //задание
	Adjacencies* operator=(Adjacencies*); //оператор=

	friend class TTree;
};

