/*****************************************************************************/
/* Copyright (c) 2020, Daniel Terrazas                                       */
/* ------------------------------------------------------------------------- */
/*                                Project Name                               */
/* ------------------------------------------------------------------------- */
/* FILE: Queue.h                                                             */
/* ------------------------------------------------------------------------- */
/* DESCRIPTION:                                                              */
/* Queue.h description.                                                      */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Permission is hereby granted, free of charge, to any person obtaining a   */
/* copy of this software and associated documentation files (the "Software") */
/* to deal in the Software without restriction, including without limitation */
/* the rights * to use, copy, modify, merge, publish, distribute,            */
/* sublicense, and/or sell* copies of the Software, and to permit persons to */
/* whom the Software is furnished to do so, subject to the following         */
/* conditions:                                                               */
/*                                                                           */
/* The above copyright notice and this permission notice shall be included   */
/* in all copies or substantial portions of the Software.                    */
/*                                                                           */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS   */
/* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF                */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.    */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY      */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT */
/* OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  */
/* THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                */
/*                                                                           */
/*****************************************************************************/

/*****************************************************************************/
/*                               Preprocessors                               */
/*****************************************************************************/

// Guard to prevent recursive inclusion
#ifndef FILE_QUEUE_H
#define FILE_QUEUE_H

/*****************************************************************************/
/*                                  Includes                                 */
/*****************************************************************************/

#include "Queue_Config.h"

/*****************************************************************************/
/*                               Public Macros                               */
/*****************************************************************************/

/*****************************************************************************/
/*                             Public Data Types                             */
/*****************************************************************************/

/**
 * @brief QueueNode
 *          Holds the elements required to created a new node in the queue.
 * 
 *  Data: Modifiable data-type that stores the necessary data in each queue
 *          node.
 *  NextElement: Pointer to the NextElement (node) in the queue.
 */
typedef struct QueueNode
{
    t_QueueData Data;
    struct QueueNode* NextElement;

}t_QueueNode;

/**
 * @brief Queue object.
 *          Holds the elements required for a typical queue data structure.
 * 
 *  FrontElement: Pointer that holds the address of the FrontElement in the
 *                  queue.
 *  RearElement: Pointer that holds the address of the RearElement in the
 *                  queue.
 *  NodesNumber: Current NodesNumber already enqueued in the queue.
 *  MaxNumberOfNodes: MaxNumberOfNodes that the queue can support
 *                      ( Defined explicitly in each queue object definition;
 *                      e.g.: t_Queue Queue = {.MaxNumberOfNodes = 100}; ).
 */
typedef struct
{
    t_QueueNode* FrontElement;
    t_QueueNode* RearElement;
    t_QueueNodesNumber NodesNumber;
    const t_QueueNodesNumber MaxNumberOfNodes;

}t_Queue;

/*****************************************************************************/
/*                              Public Constants                             */
/*****************************************************************************/

/*****************************************************************************/
/*                              Public Variables                             */
/*****************************************************************************/

/*****************************************************************************/
/*                              Public Functions                             */
/*****************************************************************************/

/**
 * @brief Creates a Queue object.
 * 
 * @param Queue 
 * @return t_Queue* 
 */
t_Queue* CreateQueue(t_Queue* Queue);

/**
 * @brief Enqueue Data to a Queue object.
 * 
 * @param Queue 
 * @param Data 
 * @return t_StatusCode 
 */
t_StatusCode Enqueue(t_Queue* Queue, t_QueueData Data);

/**
 * @brief Dequeue Data from a Queue object.
 * 
 * @param Queue 
 * @return t_Data 
 */
t_QueueData Dequeue(t_Queue* Queue);

#endif // FILE_QUEUE_H

/*****************************************************************************/
/* Revision Log:                                                             */
/* ------------------------------------------------------------------------- */
/* Created By:         Revision      Date:          Description:             */
/* ------------------------------------------------------------------------- */
/* Daniel Terrazas     0.0.0.1     3-Mar-2020      Initial Revision.         */
/* ------------------------------------------------------------------------- */
/*                                END OF FILE                                */
/*****************************************************************************/
