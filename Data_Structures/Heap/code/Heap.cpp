/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: Heap.cpp                                                          **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** Heap.cpp description.                                                   **/
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

#include "Heap.hpp"

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

/*****************************************************************************/
/**                            Function Prototypes                          **/
/*****************************************************************************/

/*****************************************************************************/
/**                            Function Definitions                         **/
/*****************************************************************************/

/************************************ Heap ***********************************/
Heap::Heap()
{

}

Heap::~Heap()
{

}

void Heap::Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Heap::HeapSort(std::vector<int> &v)
{
    int vector_size = static_cast<int>(v.size());
    int j, k;
    int tmp;

    for (int i = 1; i < vector_size; i++)
    {
        j = i;
        k = j % 2 == 0 ? (j / 2 - 1) : (j / 2);
        tmp = v[i];
        
        if (heap_type == MAX_HEAP_TYPE)
        {
            while (j > 0 && tmp > v[k])
            {
                v[j] = v[k];
                j = k;
                k = j % 2 == 0 ? (j / 2 - 1) : (j / 2);
            }

            v[j] = tmp;
        }
        else // MIN_HEAP_TYPE
        {
            while (j > 0 && tmp < v[k])
            {
                v[j] = v[k];
                j = k;
                k = j % 2 == 0 ? (j / 2 - 1) : (j / 2);
            }

            v[j] = tmp;
        }
    }
}

void Heap::Create(int array[], int size, t_heap_type type)
{

    if (array == nullptr) return;
    if (size <= 0) return;
    if (heap.size() != 0) return;

    heap_type = type;

    for (int i = 0; i < size; i++)
    {
        heap.emplace_back(array[i]);
    }

    // Heapsort:
    HeapSort(heap);
}

void Heap::Heapify(int array[], int size, t_heap_type type)
{

    if (array == nullptr) return;
    if (size <= 0) return;
    if (heap.size() != 0) return;

    int j, k;

    heap_type = type;

    for (int i = 0; i < size; i++)
    {
        heap.emplace_back(array[i]);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        j = i * 2 + 1;
        k = i;

        while (j <= size - 1)
        {
            if (heap_type == MAX_HEAP_TYPE)
            {
                 if (j < (size - 1) && heap[j] < heap[j + 1])
                    j++;

                if (heap [k] < heap[j])
                {
                    Swap(&heap[k], &heap[j]);
                    k = j;
                    j = j * 2 + 1;
                }
                else
                    break;
            }
            else // MIN_HEAP_TYPE
            {
                 if (j < (size - 1) && heap[j] > heap[j + 1])
                    j++;

                if (heap [k] > heap[j])
                {
                    Swap(&heap[k], &heap[j]);
                    k = j;
                    j = j * 2 + 1;
                }
                else
                    break;
            }
        }
    }
}

void Heap::Display(void)
{
    std::cout << "Heap: ";
    for (size_t i = 0; i < heap.size(); i++)
    {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

void Heap::Insert(int item)
{
    heap.emplace_back(item);
    HeapSort(heap);
}

int Heap::Delete(void)
{
    if (heap.size() <= 0) return -1;

    int result = heap.front();
    size_t size = heap.size();
    int i, j;

    heap.front() = heap.back();
    heap.pop_back();
    size = heap.size();

    if (size == 1)
    {
        return result;
    }
    else
    {
        i = 0;
        j = i * 2 + 1;

        while (j <= size - 1)
        {
            if (heap_type == MAX_HEAP_TYPE)
            {
                if (j < (size - 1) && heap[j] < heap[j + 1])
                    j++;

                if (heap[i] < heap[j])
                {
                    Swap(&heap[i], &heap[j]);
                    i = j;
                    j = i * 2 + 1;
                }
                else
                    break;
            }
            else // MIN_HEAP_TYPE
            {
                if (j < (size - 1) && heap[j] > heap[j + 1])
                    j++;

                if (heap[i] > heap[j])
                {
                    Swap(&heap[i], &heap[j]);
                    i = j;
                    j = i * 2 + 1;
                }
                else
                    break;
            }
        }
    }

    return result;
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/