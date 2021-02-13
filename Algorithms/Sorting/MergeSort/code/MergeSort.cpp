/*****************************************************************************/
/** Copyright (c) 2021, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                                Algorithms                               **/
/** ----------------------------------------------------------------------- **/
/** FILE: MergeSort.cpp                                                     **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** MergeSort.cpp description.                                              **/
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

#include "MergeSort.hpp"

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

void MergeSort(std::vector<int> &array, int left, int right);
void Merge(std::vector<int> &array, int left, int mid, int right);

/*****************************************************************************/
/**                            Function Definitions                         **/
/*****************************************************************************/

/********************************* Merge Sort ********************************/
void MergeSort(std::vector<int> &array)
{
    if (array.size() <= 1) return;
    MergeSort(array, 0, ((int)array.size()) - 1);
}

void MergeSort(std::vector<int> &array, int left, int right)
{
    int mid = (left + right) / 2;

    if (left < right)
    {
        MergeSort(array, left, mid);
        MergeSort(array, mid + 1, right);
        Merge(array, left, mid, right);
    }
}

void IterativeMergeSort(std::vector<int> &array)
{
    int size = ((int)array.size());
    int p, left, mid, right;

    if (array.size() <= 1) return;

    for (p = 2; p <= size; p = p * 2)
    {
        for (int i = 0; (i + p - 1) < size; i = i + p)
        {
            left = i;
            right = i + p - 1;
            mid = (left + right) / 2;
            Merge(array, left, mid, right);
        }
    }

    if ((p / 2) < size)
    {
        Merge(array, 0, (p / 2) - 1, size - 1);
    }
}

void Merge(std::vector<int> &array, int left, int mid, int right)
{
    int size_l = mid - left + 1;        // size of left subarray
    int size_r = right - mid;           // size of right subarray
    int i = 0, j = 0, k = left;

    std::vector<int> left_subarray (size_l, 0);
    std::vector<int> right_subarray (size_r, 0);

    for (i = 0; i < size_l; i++)
    {
        left_subarray[i] = array[left + i];
    }

    for (j = 0; j < size_r; j++)
    {
        right_subarray[j] = array[mid + 1 + j];
    }

    i = j = 0;
    while (i < size_l && j < size_r)
    {
        if (left_subarray[i] < right_subarray[j])
        {
            array[k] = left_subarray[i];
            i++;
        }
        else
        {
            array[k] = right_subarray[j];
            j++;
        }

        k++;
    }

    while (i < size_l)
    {
        array[k] = left_subarray[i];
        i++; k++;
    }
    
    while (j < size_r)
    {
        array[k] = right_subarray[j];
        j++; k++;
    }
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/