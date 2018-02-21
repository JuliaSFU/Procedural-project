
#ifndef __Program__
#define __Program__
namespace simple_shapes {

	// �������������
	struct rectangle {
		int x1, y1, x2, y2; // ������������� ���������� ������ �������� � ������� ������� �����
	};
	//����
	struct circle {
		int a, b, r; // ������������� ���������� ������ ����������, ������
	};


	// ���������, ���������� ��� ��������� ������
	struct shape {
		// �������� ����� ��� ������ �� �����
		enum color { RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE };
		color c;
		// �������� ������ ��� ������ �� �����
		enum key { RECTANGLE, CIRCLE };
		key k; 	   
		union { 
			rectangle r;
			circle t;
		};
	};

	// ��������� �� ������ ����������� ��������� ������
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