#pragma once
using namespace System::Drawing;
using namespace System;

class Node
{
	int number; //значение вершины
	Node *next; //следующая вершина
	int x, y; //координаты
	static int R; //радиус	
	int mn; //мн-во вершины
public:
	Node(); //конструктор
	Node(Point p,int, int); //конструктор с параметром
	void Draw(Graphics^ g); //рисование
	int GetNum(); //вернуть номер
	int Hit(Point); //попадание точки		

	friend class Adjacencies;
	friend class TTree;
};
