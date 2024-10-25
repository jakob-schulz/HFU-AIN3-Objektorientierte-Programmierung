#include <cassert>
#include <iostream>
#include "sortFunction.hpp"

namespace oopTutorium
{
    void sort(int *numbers, int size)
    {
        for (int i = 1; i < size; ++i)
        {
            int key = numbers[i];
            int j = i - 1;
            while (j >= 0 && numbers[j] > key)
            {
                numbers[j + 1] = numbers[j];
                j = j - 1;
            }
            numbers[j + 1] = key;
        }
    }

    void sort(Position *positions, int size){
        for (int i = 1; i < size; ++i)
        {
            Position key = positions[i];
            int j = i - 1;
            while (j >= 0 && positions[j].compare(key) > 0)
            {
                positions[j + 1] = positions[j];
                j = j - 1;
            }
            positions[j + 1] = key;
        }
    }
}