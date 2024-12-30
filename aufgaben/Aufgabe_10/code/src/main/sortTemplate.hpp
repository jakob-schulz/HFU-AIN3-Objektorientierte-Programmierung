#include "position.hpp"

namespace oopTutorium
{
    template <typename T>
    bool compare(T a, T b)
    {
        return a > b;
    }

    template <>
    bool compare<char>(char a, char b)
    {
        if (std::tolower(a) == std::tolower(b)) // if both chars are the same
        {
            return a < b; // returns true if a is upper case and b is lower case
        }
        return std::tolower(a) > std::tolower(b);
    }

    template <typename T>
    void sort(T *array, int size)
    {
        for (int i = 1; i < size; ++i)
        {
            T key = array[i];
            int j = i - 1;
            while (j >= 0 && compare(array[j], key))
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }
}
