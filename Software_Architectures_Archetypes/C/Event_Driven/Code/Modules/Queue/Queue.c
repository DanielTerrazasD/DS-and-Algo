/*****************************************************************************/
/* Copyright (c) 2020, Daniel Terrazas                                       */
/* ------------------------------------------------------------------------- */
/*                                Project Name                               */
/* ------------------------------------------------------------------------- */
/* FILE: Queue.c                                                             */
/* ------------------------------------------------------------------------- */
/* DESCRIPTION:                                                              */
/* Queue.c description.                                                      */
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

/*****************************************************************************/
/*                                  Includes                                 */
/*****************************************************************************/

#include "Queue.h"

/*****************************************************************************/
/*                                   Macros                                  */
/*****************************************************************************/

/*****************************************************************************/
/*                                 Data Types                                */
/*****************************************************************************/

/*****************************************************************************/
/*                                 Constants                                 */
/*****************************************************************************/

/*****************************************************************************/
/*                                 Variables                                 */
/*****************************************************************************/

/*****************************************************************************/
/*                            Function Prototypes                            */
/*****************************************************************************/

/**
 * @brief Checks whether Queue is empty or not.
 * 
 * @param Queue 
 * @return uint8_t 
 */
uint8_t IsQueueEmpty(t_Queue* Queue);

/*****************************************************************************/
/*                            Function Definitions                           */
/*****************************************************************************/

/**
 * @brief Creates a Queue object.
 * 
 *  Initializes all the parameters of t_Queue.
 * 
 * @param Queue 
 * @return t_Queue* 
 */
t_Queue* CreateQueue(t_Queue* Queue)
{
    Queue->FrontElement = NULL;
    Queue->RearElement = NULL;
    Queue->NodesNumber = 0;

    return Queue;
}

/**
 * @brief Enqueue Data to a Queue object.
 * 
 *  Allocates memory for a new node and append it to the rear of the queue.
 *  returns t_StatusCode STATUS_SUCCESS if data was enqueued successfully,
 *  otherwise returns STATUS_FAIL.
 *  See System_Header.h for all the status codes.
 * 
 * @param Queue 
 * @param Data 
 * @return t_StatusCode 
 */
t_StatusCode Enqueue(t_Queue* Queue, t_QueueData Data)
{
    t_QueueNode* NewNode;
    t_StatusCode Status = STATUS_SUCCESS;


    if (Queue->NodesNumber < Queue->MaxNumberOfNodes)
    {
        NewNode = (t_QueueNode*)malloc(sizeof(t_QueueNode));
        
        if (NewNode != NULL)
        {
            NewNode->Data = Data;
            NewNode->NextElement = NULL;

            if (IsQueueEmpty(Queue))
            {
                Queue->FrontElement = NewNode;
            }
            else
            {
                Queue->RearElement->NextElement = NewNode;
            }

            Queue->RearElement = NewNode;
            Queue->NodesNumber += 1;
        }
        else
        {
            Status = STATUS_FAIL;
        }
    }
    else
    {
        Status = STATUS_FAIL;
    }

    return Status;
}

/**
 * @brief Dequeue Data from a Queue object.
 * 
 *  Frees memory of the FrontElement of the queue and returns its data.
 *  If queue is empty, function returns the QueueDataDefaults defined in
 *  Queue_Config.c
 * 
 * @param Queue 
 * @return t_QueueData 
 */
t_QueueData Dequeue(t_Queue* Queue)
{
    t_QueueData Data = QueueDataDefaults;
    t_QueueNode* TmpNode;

    if (!IsQueueEmpty(Queue))
    {
        Data = Queue->FrontElement->Data;
        TmpNode = Queue->FrontElement;
        Queue->FrontElement = Queue->FrontElement->NextElement;

        if (Queue->FrontElement == NULL)
        {
            Queue->RearElement = NULL;
        }

        free(TmpNode);
    }

    return Data;
}

/**
 * @brief Checks whether Queue is empty or not.
 * 
 * @param Queue 
 * @return uint8_t 
 */
uint8_t IsQueueEmpty(t_Queue* Queue)
{
    return (Queue->FrontElement == NULL);
}

/*****************************************************************************/
/* Revision Log:                                                             */
/* ------------------------------------------------------------------------- */
/* Created By:         Revision      Date:          Description:             */
/* ------------------------------------------------------------------------- */
/* Daniel Terrazas     0.0.0.1     3-Mar-2020      Initial Revision.         */
/* ------------------------------------------------------------------------- */
/*                                END OF FILE                                */
/*****************************************************************************/
