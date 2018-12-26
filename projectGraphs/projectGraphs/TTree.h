#pragma once
using namespace System::Drawing;
using namespace System;
#include"Adjacencies.h"

class TTree
{
	Node* first; //��������� �� ������ �������
	Adjacencies* f; //��������� �� ������ �����	
public:
	TTree(); //�����������
	void Add(Point p); //�������� �����
	void Draw(Graphics^ g); //�������� ������
	Node* Hit(Point); //��������� �����
	Adjacencies* AddAdj(Node*, Node*, int); //�������� ����� 
	void Sort(); //���������� ����� �� ���������� val
	TTree* Task(); //�������
	void DrawAdj(Graphics^ g); //�������� �����
	void Add(Adjacencies*);	//�������� ����� � ��� ��� ������
};

