#include <iostream>

#include "graph.h"

int main()
{
	// ����8�����ͼ
	Graph graph(8);

	// ���ӵ�
	graph.connect(0, 1);
	graph.connect(1, 5);
	graph.connect(4, 5);
	graph.connect(0, 4);
	graph.connect(0, 5);
	graph.connect(1, 4);
	graph.connect(2, 5);
	graph.connect(2, 3);
	graph.connect(3, 7);
	graph.connect(6, 7);
	graph.connect(2, 6);
	graph.connect(2, 7);
	graph.connect(3, 6);

	// ��ʼ����
	graph.move_to_a({ 0,1,2,3 });

	// ��ʾͼ
	graph.show();

	std::cout << std::endl;

	// ����kl
	std::cout << "����Ż�: " << graph.kl() << std::endl;

	// ��ʾͼ
	graph.show();

	return 0;
}