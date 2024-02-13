//
// Author: Michael Stepzinski
// Date: 2/12/24
// Purpose: Unit test the DArray (Dynamic Array) module
//

#include "pch.h"
#include "DArray/DArray.h"

TEST(DArrayConstructors, DArrayDefaultConstructorReq001)
{
    DArray<int> my_array;

    EXPECT_EQ(0, my_array.Size()); // Test that the array is initialized with a size of 0
}

TEST(DArrayConstructors, DArrayParameterizedConstructorReq001)
{
    DArray<double> my_array{1.1, 2.2, 3.3};

    EXPECT_EQ(1.1, my_array[0]); // Test that the array is initialized with the expected values
    EXPECT_EQ(2.2, my_array[1]);
    EXPECT_EQ(3.3, my_array[2]);
}

TEST(DArrayConstructors, DArrayParameterizedConstructorReq002)
{
    DArray<double> my_array{ 1.1, 2.2, 3.3 };

    EXPECT_EQ(3, my_array.Size()); // Test that the array size is initialized with the same number of values that there are
}

TEST(DArrayConstructors, DArrayCopyConstructorReq001)
{
    DArray<int> my_array{ 1, 2, 3 };
    DArray copy_array(my_array);

    EXPECT_EQ(1, copy_array[0]); // Test that the array is initialized with the expected values
    EXPECT_EQ(2, copy_array[1]);
    EXPECT_EQ(3, copy_array[2]);
}

TEST(DArrayConstructors, DArrayCopyConstructorReq002)
{
    DArray<int> my_array{ 1, 2, 3 };
    DArray copy_array(my_array);

    EXPECT_EQ(3, copy_array.Size()); // Test that the array is initialized with the expected size
}

TEST(DArrayConstructors, DArrayCopyConstructorReq003)
{
    int item1{ 1 };
    int item2{ 2 };
    DArray my_array{ &item1, &item2 };
    DArray copy_array(my_array);

    item1 = 2;

    EXPECT_EQ(2, *copy_array[0]); // Test that the values are shallow-copied (if they were deep copied, element 0 of copyArray would have value 1)
}

TEST(DArrayFunctions, DArrayPrintReq001)
{
    std::string expected_string{ "1 2 3" };

    std::stringstream buffer;
    std::streambuf* prev_cout_buffer = std::cout.rdbuf(buffer.rdbuf()); // redirect cout

    DArray<int> my_array{ 1, 2, 3 };

    my_array.Print();

    std::string text = buffer.str();
    
    int result = text.compare(expected_string);

    EXPECT_EQ(result, 1); // Test that the expected values are printed
}

TEST(DArrayFunctions, DArrayPushReq001)
{
    DArray<int> my_array{ 1, 2, 3 };

    my_array.Push(4);
    
    EXPECT_EQ(4, my_array[3]); // Test that the expected value is pushed
}

TEST(DArrayFunctions, DArrayPushReq002)
{
    DArray<int> my_array{ 1, 2, 3 };

    EXPECT_EQ(3, my_array.Size()); // Test that the size is as expected
    my_array.Push(4);
    EXPECT_EQ(4, my_array.Size()); // Test that the size changes to what is expected
}

TEST(DArrayFunctions, DArrayPopReq001)
{
    DArray<int> my_array{ 1, 2, 3 };

    EXPECT_EQ(3, my_array.Size()); // Test that the size is as expected
    my_array.Pop();
    EXPECT_EQ(2, my_array.Size()); // Test that the size changes to what is expected
}

TEST(DArrayFunctions, DArrayPopReq002)
{
    DArray<int> my_array{};

    EXPECT_ANY_THROW(my_array.Pop()); // Test that popping when empty throws an exception
}

TEST(DArrayFunctions, DArraySizeReq001)
{
    DArray<int> my_array{};

    EXPECT_EQ(0, my_array.Size()); // Test that the size is as expected
    my_array.Push(1);
    EXPECT_EQ(1, my_array.Size()); // Test that the size changes to what is expected
}

TEST(DArrayFunctions, DArrayOperatorBracketReq001)
{
    DArray<int> my_array{ 5 };

    EXPECT_EQ(5, my_array[0]); // Test that the expected value is returned
}

TEST(DArrayFunctions, DArrayOperatorBracketReq002)
{
    DArray<int> my_array;

    EXPECT_ANY_THROW(my_array[1]); // Test that indexing into invalid memory throws an exception
}