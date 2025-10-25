#include "side.h"

#include "node.h"

Side::Side(const Node& n1, const Node& n2) :node1(n1), node2(n2)
{
}

bool Side::is_cut()
{
	return node1.is_in_A() != node2.is_in_A();
}
