/*****************************************************************************/
/** Copyright (c) 2021, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                                Algorithms                               **/
/** ----------------------------------------------------------------------- **/
/** FILE: QuickSort.cpp                                                     **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** QuickSort.cpp description.                                              **/
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

#include "QuickSort.hpp"

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

void Swap(int* a, int* b);

/*****************************************************************************/
/**                            Function Definitions                         **/
/*****************************************************************************/

void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/********************************* Quick Sort ********************************/
void QuickSort(std::vector<int> &array)
{
    if (array.size() <= 1) return;
    QuickSort(array, 0, ((int)array.size()) - 1);
}

void QuickSort(std::vector<int> &array, int left, int right)
{
    int partition_index;

    if (left < right)
    {
        partition_index = Partition(array, left, right);

        QuickSort(array, left, partition_index - 1);
        QuickSort(array, partition_index + 1, right);
    }
}

int Partition(std::vector<int> &array, int left, int right)
{
    int pivot = array[right];
    int i = left - 1, j;

    for (j = left; j < right; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            Swap(&array[i], &array[j]);
        }
    }

    Swap(&array[i + 1], &array[right]);
    return i + 1;
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/