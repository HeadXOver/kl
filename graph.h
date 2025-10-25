#pragma once

#include <vector>

class Node;
class Side;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 图类，包括节点和边
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Graph
{
public:
	Graph(int n);
	~Graph();

	void connect(int n1, int n2);

	//@brief 将一些节点移动到A集合
	void move_to_a(std::vector<int> nodes);
	void show();

	//@brief 计算两个节点之间的连接数
	int cost(int n1, int n2) const;

	//@brief 计算一个节点移动的增益
	int delta(int n) const;

	bool is_all_locked() const;

	//@brief 计算kl最大增益
	int kl();

private:
	std::vector<Node*> nodes;
	std::vector<Side*> sides;
};

