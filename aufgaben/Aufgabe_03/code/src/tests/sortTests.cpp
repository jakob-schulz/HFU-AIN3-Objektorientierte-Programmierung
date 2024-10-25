#include "../main/sortFunction.hpp"
#include <cassert>

namespace oopTutorium
{
    void test_sort(int *numbers, int size)
    {
        oopTutorium::sort(numbers, size);

        int *high = numbers + size;
        for(int *position = numbers; position < high - 1; position++)
        {
            assert(*position <= *(position + 1));
        }
    }

    void test_sort()
    {
        int testArray0[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        int size = 11;
        oopTutorium::test_sort(testArray0, size);
        int testArray1[] = {25123, 5254, 134513, 1512};
        size = 4;
        oopTutorium::test_sort(testArray1, size);
        int testArray2[] = {985, 2398547, 23857, 11, 11, 11, 23857, 3245, 3845};
        size = 9;
        oopTutorium::test_sort(testArray2, size);
        int testArray3[] = {0, -1, -2, -3, -4, -5, -5, -6, -7, -8, -9, -10};
        size = 12;
        oopTutorium::test_sort(testArray3, size);
    }

    void test_sort(Position *positions, int size)
    {
        oopTutorium::sort(positions, size);

        for(int position = 0; position < size-1; position++){
            assert(positions[position].compare(positions[position + 1]) <= 0);
        }
    }

    void test_sortPositions(){
        Position testArray0[] = {Position("X", 1, 1), Position("Y", 1 , 1), Position("X", 1, 2), Position("X", 2, 1), Position("A", 12 , 34), Position("Z", -43, -21)};
        oopTutorium::test_sort(testArray0, 6);
        Position testArray1[] = {Position("A", 0, 0), Position("A", 1 , 0), Position("A", 2, 0), Position("A", 3, 0), Position("A", 3 , 1), Position("A", 3, 2), Position("A", 4, 0)};
        oopTutorium::test_sort(testArray1, 7);
    }
}

int main()
{
    std::cout<<"starting sortFunction..."<<std::endl;
    oopTutorium::test_sort();
    oopTutorium::test_sortPositions();
    std::cout<<"...finished"<<std::endl;
    return 0;
}
