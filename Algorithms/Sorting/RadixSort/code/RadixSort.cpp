/*****************************************************************************/
/** Copyright (c) 2021, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                                Algorithms                               **/
/** ----------------------------------------------------------------------- **/
/** FILE: RadixSort.cpp                                                     **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** RadixSort.cpp description.                                              **/
/** ----------------------------------------------------------------------- **/
/**                                                                         **/
/** Permission is hereby granted, free of charge, to any person obtaining a **/
/** copy of this software and associated documentation files                **/
/** (the "Software") to deal in the Software without restriction, including **/
/** without limitation the rights to use, copy, modify, merge, publish,     **/
/** distribute, sublicense, and/or sell copies of the Software, and to      **/
/** permit persons to whom the Software is furnished to do so, subject to   **/
/** the following conditions:                                               **/
/**                                                                         **/
/** The above copyright notice and this permission notice shall be included **/
/** in all copies or substantial portions of the Software.                  **/
/**                                                                         **/
/** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS **/
/** OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF              **/
/** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  **/
/** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY    **/
/** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,    **/
/** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE       **/
/** SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                  **/
/**                                                                         **/
/*****************************************************************************/

/*****************************************************************************/
/**                               Preprocessors                             **/
/*****************************************************************************/

/*****************************************************************************/
/**                                  Includes                               **/
/*****************************************************************************/

#include "RadixSort.hpp"

/*****************************************************************************/
/**                                   Macros                                **/
/*****************************************************************************/

/*****************************************************************************/
/**                                 Data Types                              **/
/*****************************************************************************/

/*****************************************************************************/
/**                                 Constants                               **/
/*****************************************************************************/

/*****************************************************************************/
/**                                 Variables                               **/
/*****************************************************************************/

/*****************************************************************************/
/**                                  Classes                                **/
/*****************************************************************************/

class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

/*****************************************************************************/
/**                            Function Prototypes                          **/
/*****************************************************************************/

Node* Insert(Node* root, int data);
int GetMaxDigits(int number);

/*****************************************************************************/
/**                            Function Definitions                         **/
/*****************************************************************************/

int GetMaxDigits(int number)
{
    int count = 0;
    while (number > 0)
    {
        number /= 10;
        count++;
    }

    return count;
}

Node* Insert(Node* root, int data)
{
    Node* ptr = root;

    if (root == nullptr)
    {
        root = new Node(data);
    }
    else
    {
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }

        ptr->next = new Node(data);
    }

    return root;
}

/********************************* Radix Sort ********************************/
void RadixSort(std::vector<int> &array)
{
    const int decimals = 10;
    int digits = 0;
    int max, index, divider = 1;
    int i, j, k;
    size_t size = array.size();
    std::vector<Node*> bucket_array;
    Node* tmp;

    if (size <= 1) return;
    bucket_array.resize(decimals, nullptr);

    for (size_t i = 0; i < size; i++)
    {
        max = GetMaxDigits(array[i]);
        if (max > digits)
        {
            digits = max;
        }
    }

    for (int x = 0; x < digits; x++)
    {
        for (int y = 0; y < size; y++)
        {
            index = (array[y] / divider) % 10;
            bucket_array[index] = Insert(bucket_array[index], array[y]);
        }

        divider *= 10;
        i = j = k = 0;
        while (k < size)
        {
            if (bucket_array[i] != nullptr)
            {
                tmp = bucket_array[i]->next;
                array[j] = bucket_array[i]->data;
                delete bucket_array[i];
                bucket_array[i] = tmp;
                k++;
                j++;
            }
            else
            {
                i++;
            }
        }
    }
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/