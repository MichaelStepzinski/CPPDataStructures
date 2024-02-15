//
// Author: Michael Stepzinski
// Date: 2/14/24
// Purpose: Implement a stack data structure
//

#include "LinkedList.h"

template <typename T>
class Stack
{
private:
    LinkedList<T> m_stack{};
public:
    // Req 001 This function shall add data to the top of the stack
    void Push(const T& data)
    {
        m_stack.AddNodeToFront(data);
    }

    // Req 001 This function shall return the value of the first element in the stack
    // Req 002 This function shall throw an exception when the stack is empty
    T Peek()
    {
        if (m_stack.GetSize() == 0)
            throw - 1;
        return m_stack[0];
    }

    // Req 001 This function shall remove and return the first element in the stack
    // Req 002 This function shall throw an exception when the stack is empty
    T Pop()
    {
        if (m_stack.GetSize() == 0)
            throw - 1;
        return m_stack.RemoveNodeFromFront();
    }

    // Req 001 This function shall return the current size of the stack
    int Size()
    {
        return m_stack.GetSize();
    }
};