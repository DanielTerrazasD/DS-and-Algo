/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                              Data Structures                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: BinaryTree.cpp                                                    **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** BinaryTree.cpp description.                                             **/
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

#include <iostream>
#include <queue>
#include <stack>

#include "BinaryTree.hpp"

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

/************************************ Node ***********************************/
Node::Node(int x)
{
    data = x;
    right_child = left_child = nullptr;
}


/******************************** Binary Tree ********************************/
BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
    DeleteTree(root);
}

void BinaryTree::DeleteTree(Node* ptr)
{
    if (ptr != nullptr)
    {
        DeleteTree(ptr->left_child);
        DeleteTree(ptr->right_child);
        delete ptr;
    }
}

Node* BinaryTree::Create(int pre[], int in[], int start, int end)
{
    Node* tmp;
    static int preorder_index = 0;
    int inorder_index;

    if (start > end) return nullptr;

    tmp = new Node(pre[preorder_index]);
    preorder_index++;

    for (int i = start; i <= end; i++)
    {
        if (tmp->data == in[i])
        {
            inorder_index = i;
        }
    }

    tmp->left_child = Create(pre, in, start, inorder_index - 1);
    tmp->right_child = Create(pre, in, inorder_index + 1, end);

    return tmp;
}

void BinaryTree::RecursiveInorderTraversal(Node* ptr)
{
    if (ptr != nullptr)
    {
        RecursiveInorderTraversal(ptr->left_child);
        std::cout << ptr->data << " ";
        RecursiveInorderTraversal(ptr->right_child);
    }
}
void BinaryTree::RecursivePreoderTraversal(Node* ptr)
{
    if (ptr != nullptr)
    {
        std::cout << ptr->data << " ";
        RecursivePreoderTraversal(ptr->left_child);
        RecursivePreoderTraversal(ptr->right_child);
    }
}
void BinaryTree::RecursivePostorderTraversal(Node* ptr)
{
    if (ptr != nullptr)
    {
        RecursivePostorderTraversal(ptr->left_child);
        RecursivePostorderTraversal(ptr->right_child);
        std::cout << ptr->data << " ";
    }
}

void BinaryTree::RecursiveLevelorderTraversal(Node* ptr, int level)
{
    if (ptr == nullptr) return;

    if (level == 1)
    {
        std::cout << ptr->data << " ";
    }
    else if (level > 1)
    {
        RecursiveLevelorderTraversal(ptr->left_child, level - 1);
        RecursiveLevelorderTraversal(ptr->right_child, level - 1);
    }
}

void BinaryTree::Create(int preorder[], int preorder_size, int inorder[], int inorder_size)
{
    int start, end;

    if (root != nullptr) return;
    if (preorder_size != inorder_size) return;

    start = 0;
    end = inorder_size - 1;

    root = Create(preorder, inorder, start, end);
}

void BinaryTree::RecursiveInorderTraversal(void)
{
    std::cout << "Inorder: ";
    RecursiveInorderTraversal(root);
    std::cout << std::endl;
}

void BinaryTree::RecursivePreoderTraversal(void)
{
    std::cout << "Preorder: ";
    RecursivePreoderTraversal(root);
    std::cout << std::endl;
}

void BinaryTree::RecursivePostorderTraversal(void)
{
    std::cout << "Postorder: ";
    RecursivePostorderTraversal(root);
    std::cout << std::endl;
}

void BinaryTree::RecursiveLevelorderTraversal(void)
{
    int height = GetHeight();
    std::cout << "Levelorder: ";

    for (int level = 1; level <= height; level++)
    {
        RecursiveLevelorderTraversal(root, level);
    }

    std::cout << std::endl;
}

void BinaryTree::IterativeInorderTraversal(void)
{
    std::stack<Node*> stk;
    Node* ptr = root;

    if (root == nullptr) return;
    std::cout << "Inorder: ";
    
    while (ptr != nullptr || !stk.empty())
    {
        if (ptr == nullptr)
        {
            ptr = stk.top();
            stk.pop();
            std::cout << ptr->data << " ";
            ptr = ptr->right_child;
        }
        else
        {
            stk.push(ptr);
            ptr = ptr->left_child;
        }
    }

    std::cout << std::endl;
}

void BinaryTree::IterativePreoderTraversal(void)
{
    std::stack<Node*> stk;
    Node* ptr = root;

    if (root == nullptr) return;
    std::cout << "Preorder: ";
    
    while (ptr != nullptr || !stk.empty())
    {
        if (ptr == nullptr)
        {
            ptr = stk.top();
            stk.pop();
            ptr = ptr->right_child;
        }
        else
        {
            std::cout << ptr->data << " ";
            stk.push(ptr);
            ptr = ptr->left_child;
        }
    }

    std::cout << std::endl;
}

void BinaryTree::IterativePostorderTraversal(void)
{
    std::stack<Node*> stk;
    Node* ptr = root;

    if (root == nullptr) return;
    std::cout << "Postorder: ";
    
    while (ptr != nullptr || !stk.empty())
    {
        if (ptr == nullptr)
        {
            ptr = stk.top();
            stk.pop();

            if (ptr->right_child != nullptr && !stk.empty() && stk.top() == ptr->right_child)
            {
                stk.pop();
                stk.push(ptr);
                ptr = ptr->right_child;
            }
            else
            {
                std::cout << ptr->data << " ";
                ptr = nullptr;
            }
        }
        else
        {
            if (ptr->right_child != nullptr)
                stk.push(ptr->right_child);
            stk.push(ptr);
            ptr = ptr->left_child;
        }
    }

    std::cout << std::endl;
}

void BinaryTree::IterativeLevelorderTraversal(void)
{
    Node* ptr;
    std::queue<Node*> q;

    if (root == nullptr) return;
    std::cout << "Levelorder: ";

    q.push(root);
    while (!q.empty())
    {
        ptr = q.front();
        q.pop();

        std::cout << ptr->data << " ";

        if (ptr->left_child != nullptr)
            q.push(ptr->left_child);
        if (ptr->right_child != nullptr)
            q.push(ptr->right_child);
    }
}

int BinaryTree::GetHeight(void)
{
    return GetHeight(root);
}

int BinaryTree::GetCount(void)
{
    return GetCount(root);
}

int BinaryTree::GetLeafNodes(void)
{
    return GetLeafNodes(root);
}

int BinaryTree::GetHeight(Node* ptr)
{
    int left_subtree_height = 0;
    int right_subtree_height = 0;

    if (ptr == nullptr)
        return 0;

    left_subtree_height = GetHeight(ptr->left_child);
    right_subtree_height = GetHeight(ptr->right_child);

    if (left_subtree_height > right_subtree_height)
        return left_subtree_height + 1;
    else
        return right_subtree_height + 1;
}

int BinaryTree::GetCount(Node* ptr)
{
    int left_subtree_count = 0;
    int right_subtree_count = 0;

    if (ptr == nullptr)
        return 0;

    left_subtree_count = GetCount(ptr->left_child);
    right_subtree_count = GetCount(ptr->right_child);

    return left_subtree_count + right_subtree_count + 1;
}

int BinaryTree::GetLeafNodes(Node* ptr)
{
    int leaf_nodes_count = 0;

    if (ptr == nullptr)
        return 0;

    leaf_nodes_count = GetLeafNodes(ptr->left_child);
    leaf_nodes_count += GetLeafNodes(ptr->right_child);

    if (ptr->left_child == nullptr && ptr->right_child == nullptr)
        return leaf_nodes_count + 1;
    return leaf_nodes_count;
}



/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/