
#ifndef __Program__
#define __Program__
namespace simple_shapes {

	// прямоугольник
	struct rectangle {
		int x1, y1, x2, y2; // целочисленные координаты левого верхнего и правого нижнего углов
	};
	//круг
	struct circle {
		int a, b, r; // целочисленные координата центра окружности, радиус
	};


	// структура, обобщающая все имеющиеся фигуры
	struct shape {
		// значения цвета для каждой из фигур
		enum color { RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE };
		color c;
		// значения ключей для каждой из фигур
		enum key { RECTANGLE, CIRCLE };
		key k; 	   
		union { 
			rectangle r;
			circle t;
		};
	};

	// контейнер на основе одномерного линейного списка
	struct node
	{
		shape* data;
		node* next;
		node(shape* data, node* next);
	};

	struct container
	{
		node* head;
	};
	

} // end simple_shapes namespace
#endif