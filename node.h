#pragma once

////////////////////////////////////////////////////////////////////////
// @brief 节点类
// @details locked: 是否被锁定
// @details is_in_a: 是否在A集合中
////////////////////////////////////////////////////////////////////////
class Node
{
public:
    Node(int name);

    bool isLocked() const;
    void lock();
    void unlock();
    bool is_in_A() const;
    void moveToA();
    void moveToB();
    void moveToAnother();

public:
    const int name;

private:
    bool locked = false;
    bool is_in_a = false;
};

