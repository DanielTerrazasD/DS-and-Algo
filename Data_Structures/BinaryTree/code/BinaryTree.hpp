/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: BinaryTree.hpp                                                    **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** BinaryTree.hpp description.                                             **/
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
#ifndef FILE_BINARY_TREE_HPP
#define FILE_BINARY_TREE_HPP

/*****************************************************************************/
/**                                  Includes                               **/
/*****************************************************************************/

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

class Node
{
public:
    Node* left_child;
    Node* right_child;
    int data;

    Node(int x);
};

class BinaryTree
{
private:
    Node* root;

    Node* Create(int pre[], int in[], int start, int end);
    void RecursiveInorderTraversal(Node* ptr);
    void RecursivePreoderTraversal(Node* ptr);
    void RecursivePostorderTraversal(Node* ptr);
    void RecursiveLevelorderTraversal(Node* ptr, int level);

    void DeleteTree(Node* ptr);

    int GetHeight(Node* ptr);
    int GetCount(Node* ptr);
    int GetLeafNodes(Node* ptr);

public:

    BinaryTree();
    ~BinaryTree();

    void Create(int preorder[], int preorder_size, int inorder[], int inorder_size);

    void RecursiveInorderTraversal(void);
    void RecursivePreoderTraversal(void);
    void RecursivePostorderTraversal(void);
    void RecursiveLevelorderTraversal(void);

    void IterativeInorderTraversal(void);
    void IterativePreoderTraversal(void);
    void IterativePostorderTraversal(void);
    void IterativeLevelorderTraversal(void);

    int GetHeight(void);
    int GetCount(void);
    int GetLeafNodes(void);
};

#endif // FILE_BINARY_TREE_HPP

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/