#pragma once

#include <vector>

class Node;
class Side;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief ͼ�࣬�����ڵ�ͱ�
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Graph
{
public:
	Graph(int n);
	~Graph();

	void connect(int n1, int n2);

	//@brief ��һЩ�ڵ��ƶ���A����
	void move_to_a(std::vector<int> nodes);
	void show();

	//@brief ���������ڵ�֮���������
	int cost(int n1, int n2) const;

	//@brief ����һ���ڵ��ƶ�������
	int delta(int n) const;

	bool is_all_locked() const;

	//@brief ����kl�������
	int kl();

private:
	std::vector<Node*> nodes;
	std::vector<Side*> sides;
};

