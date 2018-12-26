#pragma once
using namespace System::Drawing;
using namespace System;

class Node
{
	int number; //�������� �������
	Node *next; //��������� �������
	int x, y; //����������
	static int R; //������	
	int mn; //��-�� �������
public:
	Node(); //�����������
	Node(Point p,int, int); //����������� � ����������
	void Draw(Graphics^ g); //���������
	int GetNum(); //������� �����
	int Hit(Point); //��������� �����		

	friend class Adjacencies;
	friend class TTree;
};
