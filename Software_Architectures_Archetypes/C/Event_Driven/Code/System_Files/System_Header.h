/*****************************************************************************/
/* Copyright (c) 2020, Daniel Terrazas                                       */
/* ------------------------------------------------------------------------- */
/*                                Project Name                               */
/* ------------------------------------------------------------------------- */
/* FILE: System_Header.h                                                     */
/* ------------------------------------------------------------------------- */
/* DESCRIPTION:                                                              */
/* System_Header.h description.                                              */
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
#ifndef FILE_SYSTEM_HEADER_H
#define FILE_SYSTEM_HEADER_H

/*****************************************************************************/
/*                                  Includes                                 */
/*****************************************************************************/

#include <stdint.h>

/*****************************************************************************/
/*                             Public Data Types                             */
/*****************************************************************************/

typedef enum
{
    STATUS_SUCCESS = 0,
    STATUS_FAIL,
    STATUS_INVALID_ARGUMENT,
    STATUS_NOT_INITIALIZED

}t_StatusCode;

/*****************************************************************************/
/*                               Public Macros                               */
/*****************************************************************************/

#define TRUE        (uint8_t)(1)
#define FALSE       (uint8_t)(0)

/*****************************************************************************/
/*                              Public Constants                             */
/*****************************************************************************/

/*****************************************************************************/
/*                              Public Variables                             */
/*****************************************************************************/

/*****************************************************************************/
/*                              Public Functions                             */
/*****************************************************************************/


#endif // FILE_SYSTEM_HEADER_H

/*****************************************************************************/
/* Revision Log:                                                             */
/* ------------------------------------------------------------------------- */
/* Created By:         Revision      Date:          Description:             */
/* ------------------------------------------------------------------------- */
/* Daniel Terrazas     0.0.0.1     3-Mar-2020      Initial Revision.         */
/* ------------------------------------------------------------------------- */
/*                                END OF FILE                                */
/*****************************************************************************/
