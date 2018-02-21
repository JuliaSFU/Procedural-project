#include "stdafx.h"
#include <fstream>
#include "Program.h"

using namespace std;

namespace simple_shapes {

	shape *In(ifstream &ifdt);
	void Out(shape &s, ofstream &ofst);

	node::node(shape* data, node* next)
	{
		this->data = data;
		this->next = next;
	}

	// Инициализация контейнера
	void Init(container &c)
	{

		c.head = NULL;
	}
	// Очистка контейнера от элементов
	// (освобождение памяти)
	void Clear(container &c)
	{
		while (c.head != NULL)
		{
			node* forDelete = c.head;
			c.head = c.head->next;
			delete forDelete;
		}
	}
	// Ввод содержимого контейнера из указанного потока
	void In(container &c, ifstream &ifst)
	{
		while (!ifst.eof()) {
			node* last = NULL;
			node* temp = new node(In(ifst), NULL);
			if (c.head == NULL)
				c.head = temp;
			else {
			last = c.head;
			while (last->next != NULL) last = last->next;
			last->next = temp;
		}
	}
	}
	
	// Вывод содержимого контейнера в указанный поток
	void Out(container &c, ofstream &ofst)
	{
		ofst << "Container contains elements:" << endl;
		node* current = c.head;
		if (current == NULL)
			return;
		while (current != NULL)
		{
			Out(*(current->data), ofst);
			current = current->next;
		}
	}

	//ввода цвета фигуры
	void InColor(shape &s, int colorNumber)
	{
		switch (colorNumber)
		{
		case 1:
			s.c = shape::color::RED;
			break;
		case 2:
			s.c = shape::color::ORANGE;
			break;
		case 3:
			s.c = shape::color::YELLOW;
			break;
		case 4:
			s.c = shape::color::GREEN;
			break;
		case 5:
			s.c = shape::color::BLUE;
			break;
		case 6:
			s.c = shape::color::PURPLE;
			break;
		}
	}

	//вывод цвета фигуры
	void OutColor(shape &s, ofstream &ofst)
	{
		switch (s.c)
		{
		case shape::color::RED:
			ofst << "RED" << endl;
			break;
		case shape::color::ORANGE:
			ofst << "ORANGE" << endl;
			break;
		case shape::color::YELLOW:
			ofst << "YELLOW" << endl;
			break;
		case shape::color::GREEN:
			ofst << "GREEN" << endl;
			break;
		case shape::color::BLUE:
			ofst << "BLUE" << endl;
			break;
		case shape::color::PURPLE:
			ofst << "PURPLE" << endl;
			break;
		}
	}


	// Ввод параметров прямоугольника из файла
	void In(rectangle &r, ifstream &ifst)
	{
		ifst >> r.x1 >> r.y1 >> r.x2 >> r.y2;
	}
	// Вывод параметров прямоугольника в поток
	void Out(rectangle &r, ofstream &ofst) 
	{
		ofst << "It is Rectangle: x1 = " << r.x1
			<< ", y1 = " << r.y1
			<< ", x2 = " << r.x2
			<< ", y2 = " << r.y2 << ", color: ";
	}


	// Ввод параметров круга из потока
	void In(circle &t, ifstream &ifst)
	{
		ifst >> t.a >> t.b >> t.r;
	}
	// Вывод параметров круга в поток
	void Out(circle &t, ofstream &ofst)
	{
		ofst << "It is Circle: a = "
			<< t.a << ", b = " << t.b
			<< ", r = " << t.r << ", color: ";
	}


	

	// Ввод параметров обобщенной фигуры из файла
	shape* In(ifstream &ifst)
	{
		shape *sp;
		int k;
		int c;
		ifst >> k;
		switch (k) {
		case 1:
			sp = new
				shape;
			sp->k = shape::key::RECTANGLE;
			In(sp->r, ifst);
			ifst >> c;
			InColor(*sp, c);
			return sp;
		case 2:
			sp = new shape;
			sp->k = shape::key::CIRCLE;
			In(sp->t, ifst);
			ifst >> c;
			InColor(*sp, c);
			return sp;
		default:
			return 0;
		}
	}
	// Вывод параметров текущей фигуры в поток
	void Out(shape &s, ofstream &ofst)
	{
		switch (s.k) {
		case shape::key::RECTANGLE:
			Out(s.r, ofst);
			OutColor(s, ofst);
			break;
		case shape::key::CIRCLE:
			Out(s.t, ofst);
			OutColor(s, ofst);
			break;
		default:
			ofst << "Incorrect figure!"
				<< endl;
		}
	}

} // end simple_shapes namespace