#include <iostream>

#include "graph.h"

int main()
{
	// 创建8个点的图
	Graph graph(8);

	// 连接点
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

	// 初始分区
	graph.move_to_a({ 0,1,2,3 });

	// 显示图
	graph.show();

	std::cout << std::endl;

	// 进行kl
	std::cout << "最多优化: " << graph.kl() << std::endl;

	// 显示图
	graph.show();

	return 0;
}