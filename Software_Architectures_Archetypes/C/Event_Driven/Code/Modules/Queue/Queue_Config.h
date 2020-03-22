/*****************************************************************************/
/* Copyright (c) 2020, Daniel Terrazas                                       */
/* ------------------------------------------------------------------------- */
/*                                Project Name                               */
/* ------------------------------------------------------------------------- */
/* FILE: Queue_Config.h                                                      */
/* ------------------------------------------------------------------------- */
/* DESCRIPTION:                                                              */
/* Queue_Config.h description.                                               */
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
#ifndef FILE_QUEUE_CONFIG_H
#define FILE_QUEUE_CONFIG_H

/*****************************************************************************/
/*                                  Includes                                 */
/*****************************************************************************/

// System headers needed to compile this sw module.
#include <stdint.h>
#include <stdlib.h>

// Module headers needed to compile this sw module.
#include <System_Header.h>

/*****************************************************************************/
/*                               Public Macros                               */
/*****************************************************************************/

#define MAX_STRING_SIZE                 (uint8_t)(100)

/*****************************************************************************/
/*                             Public Data Types                             */
/*****************************************************************************/

typedef uint8_t t_QueueNodesNumber;

/**
 * @brief t_QueueData stores all the data used in each queue node.
 *          User-modifiable data type used to store data in queue nodes.
 *          
 *  If t_QueueData is modified, make sure to modify the
 *  QueueDataDefaults in Queue_Config.c
 */
typedef struct
{
    char DataName[MAX_STRING_SIZE];

}t_QueueData;

/*****************************************************************************/
/*                              Public Constants                             */
/*****************************************************************************/

/**
 * @brief Declaration of t_QueueData QueueDataDefaults to make it public.
 */
extern const t_QueueData QueueDataDefaults;

/*****************************************************************************/
/*                              Public Variables                             */
/*****************************************************************************/

/*****************************************************************************/
/*                              Public Functions                             */
/*****************************************************************************/


#endif // FILE_QUEUE_CONFIG_H

/*****************************************************************************/
/* Revision Log:                                                             */
/* ------------------------------------------------------------------------- */
/* Created By:         Revision      Date:          Description:             */
/* ------------------------------------------------------------------------- */
/* Daniel Terrazas     0.0.0.1     3-Mar-2020      Initial Revision.         */
/* ------------------------------------------------------------------------- */
/*                                END OF FILE                                */
/*****************************************************************************/
