#pragma once
#include"Node.h"
using namespace System::Drawing;
using namespace System;

class Adjacencies
{
	Node* one; //��������� �� ������ �������
	Node* two; //��������� �� ������ �������
	Adjacencies* next; //��������� �� ��������� �����
	int val; //�������� �����
public:
	Adjacencies(); //�����������
	Adjacencies(Node*, Node*, int); //����������� � ����������
	void Draw(Graphics^ g, Pen^ pen); //���������
	bool Task(); //�������
	Adjacencies* operator=(Adjacencies*); //��������=

	friend class TTree;
};

