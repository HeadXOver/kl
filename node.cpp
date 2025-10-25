#include "node.h"

Node::Node(int name): name(name)
{
}

bool Node::isLocked() const
{
	return locked;
}

void Node::lock()
{
	locked = true;
}

void Node::unlock()
{
	locked = false;
}

bool Node::is_in_A() const
{
	return is_in_a;
}

void Node::moveToA() {
	is_in_a = true;
}

void Node::moveToB() {
	is_in_a = false;
}

void Node::moveToAnother()
{
    is_in_a = !is_in_a;
}
