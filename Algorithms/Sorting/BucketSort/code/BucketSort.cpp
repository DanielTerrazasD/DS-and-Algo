/*****************************************************************************/
/** Copyright (c) 2021, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                                Algorithms                               **/
/** ----------------------------------------------------------------------- **/
/** FILE: BucketSort.cpp                                                    **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** BucketSort.cpp description.                                             **/
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

#include "BucketSort.hpp"

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
    double data;
    Node* next;

    Node(double x)
    {
        data = x;
        next = nullptr;
    }
};

/*****************************************************************************/
/**                            Function Prototypes                          **/
/*****************************************************************************/

Node* InsertSorted(Node* root, double data);

/*****************************************************************************/
/**                            Function Definitions                         **/
/*****************************************************************************/

Node* InsertSorted(Node* root, double data)
{
    Node* aux_ptr, *ptr = root;
    Node* tmp;

    if (root == nullptr)
    {
        root = new Node(data);
    }
    else
    {
        if (data < ptr->data)
        {
            tmp = new Node(data);
            root = tmp;
            tmp->next = ptr;
        }
        else
        {
            while (ptr != nullptr && data > ptr->data)
            {
                aux_ptr = ptr;
                ptr = ptr->next;
            }

            tmp = new Node(data);
            tmp->next = ptr;
            aux_ptr->next = tmp;
        }
    }

    return root;
}

/******************************** Bucket Sort ********************************/
void BucketSort(std::vector<double> &array)
{
    const int decimals = 10;    // Fixed to the number of decimals
    size_t size = array.size();
    std::vector<Node*> bucket_array (decimals, nullptr);
    
    Node* ptr = nullptr;        // Temporary pointer.
    int index = 0;              // Index for bucket array.
    int k = 0;                  // Iterator.

    if (size <= 1) return;

    for (size_t i = 0; i < size; i++)
    {
        // Calculate corresponding index in the bucket array.
        index = (int)(array[i] / 0.1F);

        // Insert in sorted order
        bucket_array[index] = InsertSorted(bucket_array[index], array[i]);
    }

    for (int i = 0; i < decimals; i++)
    {
        while (bucket_array[i] != nullptr && k < size)
        {
            array[k++] = bucket_array[i]->data;
            ptr = bucket_array[i]->next;

            if (ptr == nullptr)
            {
                delete bucket_array[i];
                bucket_array[i] = nullptr;
            }
            else
            {
                delete bucket_array[i];
                bucket_array[i] = ptr;
            }
        }

        // If all the numbers have been sorted, then break.
        if (k >= size)
        {
            break;
        }
    }
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/