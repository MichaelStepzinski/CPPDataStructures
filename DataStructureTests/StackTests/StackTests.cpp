//
// Author: Michael Stepzinski
// Date: 2/14/24
// Purpose: Unit test the stack data structure
//

#include "pch.h"
#include "DataStructures/Stack.h"

TEST(Push, Req001) {
    Stack<int> stack{};

    stack.Push(2);
    EXPECT_EQ(stack.Peek(), 2);
    stack.Push(5);
    EXPECT_EQ(stack.Peek(), 5);
}

TEST(Peek, Req001) {
    Stack<int> stack{};

    stack.Push(2);
    stack.Push(5);
    stack.Push(6);
    EXPECT_EQ(stack.Peek(), 6);
}

TEST(Peek, Req002) {
    Stack<int> stack{};

    EXPECT_ANY_THROW(stack.Peek());
}

TEST(Pop, Req001) {
    Stack<int> stack{};

    stack.Push(2);
    stack.Push(1);

    EXPECT_EQ(stack.Pop(), 1);
    EXPECT_EQ(stack.Pop(), 2);
}

TEST(Pop, Req002) {
    Stack<int> stack{};

    EXPECT_ANY_THROW(stack.Pop());
}

TEST(Size, Req001) {
    Stack<int> stack{};

    EXPECT_EQ(stack.Size(), 0);

    stack.Push(2);
    stack.Push(1);

    EXPECT_EQ(stack.Size(), 2);
}
