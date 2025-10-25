#pragma once

////////////////////////////////////////////////////////////////////////
// @brief �ڵ���
// @details locked: �Ƿ�����
// @details is_in_a: �Ƿ���A������
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

