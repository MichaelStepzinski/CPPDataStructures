//
// Author: Michael Stepzinski
// Date: 2/12/24
// Purpose: Unit test the Linked List module 
//

#include "pch.h"
#include "DataStructures/LinkedList.h"

TEST(DefaultConstructor, Req001) {
    LinkedList<int> list{};

    EXPECT_EQ(0, list.GetSize());
}

TEST(CopyConstructor, Req001) {
    LinkedList<int> list1{};

    list1.AddNode(2);
    list1.AddNode(6);
    list1.AddNode(4);
    list1.AddNode(3);

    LinkedList<int> list2{ list1 };

    EXPECT_EQ(4, list2.GetSize());
    EXPECT_EQ(3, list2[3]);
}

TEST(GetSize, Req001) {
    LinkedList<int> list{};

    EXPECT_EQ(0, list.GetSize());

    list.AddNode(2);
    list.AddNode(31);

    EXPECT_EQ(2, list.GetSize());
}

TEST(AddNodeToEnd, Req001) {
    LinkedList<int> list{};

    list.AddNode(2);

    EXPECT_EQ(1, list.GetSize());
    EXPECT_EQ(2, list[0]);
}

TEST(AddNodeAtIndex, Req001) {
    LinkedList<int> list{};

    list.AddNode(2);
    list.AddNode(1);
    list.AddNode(3, 0);

    EXPECT_EQ(3, list.GetSize());
    EXPECT_EQ(2, list[0]);
    EXPECT_EQ(3, list[1]);
    EXPECT_EQ(1, list[2]);
}

TEST(AddNodeAtIndex, Req002) {
    LinkedList<int> list{};

    EXPECT_ANY_THROW(list.AddNode(1, -1));
    EXPECT_ANY_THROW(list.AddNode(1, 0));
    EXPECT_ANY_THROW(list.AddNode(1, 1));

    list.AddNode(2);

    EXPECT_NO_THROW(list.AddNode(1, 0));
    EXPECT_NO_THROW(list.AddNode(1, 1));
}

TEST(RemoveNodeFromEnd, Req001) {
    LinkedList<int> list{};

    list.AddNode(2);
    list.AddNode(1);
    list.AddNode(3);

    EXPECT_EQ(3, list.RemoveNode());
}

TEST(RemoveNodeFromEnd, Req002) {
    LinkedList<int> list{};

    EXPECT_ANY_THROW(list.RemoveNode());
}

TEST(RemoveNodeAtIndex, Req001) {
    LinkedList<int> list{};

    list.AddNode(2);
    list.AddNode(1);

    EXPECT_EQ(1, list.RemoveNode(1));
    EXPECT_EQ(1, list.GetSize());

    list.AddNode(1);
    list.AddNode(4);
    list.AddNode(5);

    EXPECT_EQ(5, list.RemoveNode(3));
}

TEST(RemoveNodeAtIndex, Req002) {
    LinkedList<int> list{};

    list.AddNode(2);
    list.AddNode(1);

    EXPECT_ANY_THROW(list.RemoveNode(2));
}

TEST(BracketOperator, Req001) {
    LinkedList<int> list1{};

    list1.AddNode(2);
    list1.AddNode(6);
    list1.AddNode(4);
    list1.AddNode(3);

    EXPECT_EQ(4, list1[2]);
}

TEST(BracketOperator, Req002) {
    LinkedList<int> list1{};

    list1.AddNode(2);
    list1.AddNode(6);
    list1.AddNode(4);
    list1.AddNode(3);

    EXPECT_ANY_THROW(list1[-1]);
    EXPECT_ANY_THROW(list1[4]);
}