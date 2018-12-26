#include "TTree.h"

TTree::TTree()
{ //конструктор
	first = 0;
	f = 0;
}

void TTree::Add(Point p)
{ //добавить точку
	if (first == 0)
	{
		first = new Node(p, 1, 1);
	}
	else
	{
		Node* i = new Node();
		for (i = first; i->next != 0; i = i->next) {}
		i->next = new Node(p, i->number + 1, i->mn + 1);
	}
}

void TTree::Draw(Graphics^g)
{ //рисовать дерево
	Pen^ pen = gcnew Pen(Color::Black);
	for (Node* i = first; i != 0; i = i->next)
	{
		i->Draw(g);
	}
	for (Adjacencies*j = f; j != 0; j = j->next)
	{
		j->Draw(g, pen);
	}
}

Node* TTree::Hit(Point p)
{ //попадание точки
	for (Node* i = first; i != 0; i = i->next)
	{
		if (i->Hit(p))
		{
			return i;
		}
	}	
}
Adjacencies* TTree::AddAdj(Node* t1, Node* t2, int v)
{ //добавить ребро 
	int k = 0;
	Adjacencies* i = new Adjacencies();
	if (f == 0)
	{
		f = new Adjacencies(t1, t2, v);
		return f;
	}
	else
	{		
		for (i = f; i->next != 0; i = i->next) {k++;}
		i->next = new Adjacencies(t1, t2, v);		
	}
	return i->next;
}

void TTree::Sort()
{ //сортировка ребер по увеличению val	
	bool flag = false;
	Adjacencies* ptr = new Adjacencies();
	Adjacencies* tmp = new Adjacencies();
	Adjacencies* prev = new Adjacencies();
	if (f)
	{
		do
		{
			flag = false;
			ptr = f;
			while (ptr->next)
			{
				if (ptr->val > ptr->next->val)
				{
					if (ptr == f)
					{
						tmp = ptr;
						ptr = tmp->next;
						tmp->next = ptr->next;
						ptr->next = tmp;
						f = ptr;
						flag = true;
					}
					else
					{
						tmp = ptr;
						ptr = tmp->next;
						tmp->next = ptr->next;
						ptr->next = tmp;
						prev->next = ptr;
						flag = true;
					}
				}
				prev = ptr;
				ptr = ptr->next;
			}
		} while (flag);			
	}	
}

TTree* TTree::Task()
{ //задание	
	TTree* newt;
	newt = new TTree();
	newt->f = newt->f->operator= (f);
	Adjacencies*dop = new Adjacencies();
	dop = f;
	f->Task();
	for (Adjacencies*i = f->next; i != 0; i = i->next)
	{
		if (!i->Task())
			continue;
		else
		{			
			newt->Add(i);
			dop = i;
			for (Adjacencies* k = f; k != 0; k = k->next)
			{
				if (k->val < i->val)
					k->Task();
				else
					continue;
			}
		}
	}	
	return newt;		
}

void TTree::Add(Adjacencies* t)
{ //рисовать ребра
	Adjacencies*i = new Adjacencies();
	for (i = f; i->next != 0; i = i->next) {}
	i ->next = i->next->operator=(t);
}

void TTree::DrawAdj(Graphics^ g)
{ //добавить ребро в мин ост дерево
	Pen^ pen = gcnew Pen(Color::Red);
	for (Adjacencies* i = f; i != 0; i = i->next)
	{
		i->Draw(g, pen);
	}
}


