#include "Adjacencies.h"


Adjacencies::Adjacencies()
{ //конструктор
	one = 0;
	next = 0;
	two = 0;
}

Adjacencies::Adjacencies(Node* t1, Node* t2, int v)
{ //конструктор с параметром
	one = t1;
	two = t2;
	val = v;
	next = 0;
}
void Adjacencies::Draw(Graphics^g, Pen^ pen)
{ //отрисовка	
	Font^ font = gcnew Font("Arial", 10);
	SolidBrush^ brush = gcnew SolidBrush(Color::Black);
	g->DrawLine(pen, one->x + Node::R, one->y, two->x - Node::R, two->y);
	int a = one->x + Node::R + ((two->x - Node::R) - (one->x + Node::R)) / 2;
	int b = one->y + (two->y - one->y) / 2;
	g->DrawString(Convert::ToString(val), font, brush, Point(a, b));
}

bool Adjacencies::Task()
{ //задание
	if (one->mn == two->mn)
		return false;
	else
	{
		if (one->mn < two->mn)
			two->mn = one->mn;
		else
			one->mn = two->mn;
	}	
	return true;
}

Adjacencies* Adjacencies::operator=(Adjacencies* tmp)
{ //оператор=
	Adjacencies* t = new Adjacencies();
	t->one=tmp->one;
	t->two=tmp->two;
	t->next = 0;
	t->val=tmp->val;
	return t;
}