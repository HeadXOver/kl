#include "graph.h"

#include "node.h"
#include "side.h"
#include "step.h"

#include <iostream>

Graph::Graph(int n)
{
	for (int i = 0; i < n; i++) nodes.push_back(new Node(i));
}

Graph::~Graph()
{
	for (int i = 0; i < nodes.size(); i++) delete nodes[i];
	for (int i = 0; i < sides.size(); i++) delete sides[i];
}

void Graph::connect(int n1, int n2)
{
	sides.push_back(new Side(*nodes[n1], *nodes[n2]));
}

void Graph::move_to_a(std::vector<int> ns)
{
	for (int i = 0; i < ns.size(); i++) nodes[i]->moveToA();
}

void Graph::show()
{
	std::cout << "Nodes:" << std::endl;
    for (int i = 0; i < nodes.size(); i++) std::cout << nodes[i]->name << std::endl;
    std::cout << "Sides:" << std::endl;
	for (int i = 0; i < sides.size(); i++) std::cout << sides[i]->node1.name << "----" << sides[i]->node2.name << std::endl;
	std::cout << "In A" << std::endl;
	for (int i = 0; i < nodes.size(); i++) if (nodes[i]->is_in_A()) std::cout << nodes[i]->name << std::endl;
	std::cout << "cut" << std::endl;
	for (int i = 0; i < sides.size(); i++) if (sides[i]->is_cut()) std::cout << sides[i]->node1.name << "----" << sides[i]->node2.name << std::endl;
}

int Graph::cost(int n1, int n2) const
{
	int cost = 0;
	for (int i = 0; i < sides.size(); i++)
		if ((sides[i]->node1.name == n1 && sides[i]->node2.name == n2) || (sides[i]->node1.name == n2 && sides[i]->node2.name == n1))
			cost++;
	return cost;
}

int Graph::delta(int n) const
{
	int delta = 0;
	for (int i = 0; i < sides.size(); i++)
		if (sides[i]->node1.name == n || sides[i]->node2.name == n)
			if (sides[i]->is_cut()) delta++;
    		else delta--;
	return delta;
}

bool Graph::is_all_locked() const
{
	for (int i = 0; i < nodes.size(); i++) if (!nodes[i]->isLocked()) return false;
	return true;
}

int Graph::kl()
{
	int delta_gm;
	int n1;
	int n2;
	std::vector<Step> steps;
	std::vector<int> gains;
	while (!is_all_locked()) {
		delta_gm = INT_MIN;
		for (int i = 0; i < nodes.size(); i++) {
			if (!nodes[i]->is_in_A() || nodes[i]->isLocked()) continue;

			for (int j = 0; j < nodes.size(); j++) {
				if (nodes[j]->is_in_A() || nodes[j]->isLocked()) continue;

				int delta_g = delta(i) + delta(j) - 2 * cost(i, j);
				if (delta_g > delta_gm) {
					delta_gm = delta_g;
					n1 = i;
					n2 = j;
				}
			}
		}

		nodes[n1]->moveToAnother();
		nodes[n2]->moveToAnother();
		nodes[n1]->lock();
		nodes[n2]->lock();
		steps.push_back({ n1, n2 });
		gains.push_back(delta_gm);
	}

	int best_step = 1;
	int sum_gain = gains[0];
	int best_gain = gains[0];

	for (int i = 1; i < steps.size(); i++) {
		sum_gain += gains[i];
		if (sum_gain > best_gain) {
			best_step = i + 1;
			best_gain = sum_gain;
		}
	}

	for (int i = steps.size() - 1; i >= best_step; i--) {
		nodes[steps[i].node1]->moveToAnother();
		nodes[steps[i].node2]->moveToAnother();
	}

	return best_gain;
}
