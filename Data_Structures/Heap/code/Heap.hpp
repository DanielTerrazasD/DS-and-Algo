/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: Heap.hpp                                                          **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** Heap.hpp description.                                                   **/
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

// Guard to prevent recursive inclusion
#ifndef FILE_HEAP_HPP
#define FILE_HEAP_HPP

/*****************************************************************************/
/**                                  Includes                               **/
/*****************************************************************************/

#include <iostream>
#include <vector>

/*****************************************************************************/
/**                               Public Macros                             **/
/*****************************************************************************/

/*****************************************************************************/
/**                             Public Data Types                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                              Public Constants                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                              Public Variables                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                              Public Functions                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                               Public Classes                            **/
/*****************************************************************************/

class Heap
{
public:
    typedef enum
    {
        MAX_HEAP_TYPE,
        MIN_HEAP_TYPE
    }t_heap_type;

private:

    std::vector<int> heap;
    t_heap_type heap_type;

    void HeapSort(std::vector<int> &v);
    void Swap(int* a, int* b);

public:

    Heap();
    ~Heap();

    void Create(int array[], int size, t_heap_type type);
    void Heapify(int array[], int size, t_heap_type type);
    void Display(void);
    void Insert(int item);
    int Delete(void);
};

#endif // FILE_HEAP_HPP

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/