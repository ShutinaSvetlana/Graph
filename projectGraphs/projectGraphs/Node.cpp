#include "Node.h"
#include "math.h"

int Node::R = 15;

Node::Node() //�����������
{	
	next = 0;
	number = 0;
	x = -1;
	y = -1;
	mn = 0;
}

Node::Node(Point p,int num, int m) //����������� � ����������
{
	number = num;
	x = p.X;
	y = p.Y;
	mn = m;
	next = 0;	
}

int Node::GetNum() //������� �����
{
	return number;
}

void Node::Draw(Graphics^ g) //���������
{		
	Pen^ pen = gcnew Pen(Color::Black, 2);
	Font^ font = gcnew Font("Arial", 10);
	SolidBrush^ brush = gcnew SolidBrush(Color::Black);
	g->DrawEllipse(pen, x - R, y - R, 2 * R, 2 * R);
	g->DrawString(Convert::ToString(number), font, brush, Point(x - R, y - R / 2));
}

int Node::Hit(Point p) //��������� �����
{
	int d; //���������� �� ����� �� ������
	d = sqrt(pow((p.X - x), 2) + pow((p.Y - y), 2));
	if (d <= R)
	{
		return true; // ������
	}
	else
	{
		return false; // �� ������
	}
}



