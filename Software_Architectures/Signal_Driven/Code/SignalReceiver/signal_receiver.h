/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                               Project Name                              **/
/** ----------------------------------------------------------------------- **/
/** FILE: signal_receiver.hpp                                               **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** signal_receiver.hpp description.                                        **/
/** ----------------------------------------------------------------------- **/
/**                                                                         **/
/** Permission is hereby granted, free of charge, to any person obtaining a **/
/** copy of this software and associated documentation files                **/
/** (the "Software") to deal in the Software without restriction, including **/
/** without limitation the rights * to use, copy, modify, merge, publish,   **/
/** distribute, sublicense, and/or sell* copies of the Software, and to     **/
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
#ifndef FILE_SIGNAL_RECEIVER_HPP
#define FILE_SIGNAL_RECEIVER_HPP

/*****************************************************************************/
/**                                  Includes                               **/
/*****************************************************************************/

#include <string>
#include <functional>

// Shared data by modules:
#include "connect_config.h"
#include "disconnect_config.h"
// ...

/*****************************************************************************/
/**                               Public Macros                             **/
/*****************************************************************************/

/*****************************************************************************/
/**                             Public Data Types                           **/
/*****************************************************************************/

typedef struct
{
    std::string data_content;
}t_data;

typedef struct
{
    std::string function_name;
    t_data content;
}t_signal_data;

typedef struct
{
    std::string name;
    std::function<void(t_signal_data)> function;
}t_signal;

typedef struct
{
    std::string name;
    std::function<void(t_data)> function;
}t_in_module_signal;

/*****************************************************************************/
/**                              Public Constants                           **/
/*****************************************************************************/

static const std::string SIGNAL_NAME_CONNECT = "sig_name_connect";
static const std::string SIGNAL_NAME_DISCONNECT = "sig_name_disconnect";
// ...

/*****************************************************************************/
/**                              Public Variables                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                              Public Functions                           **/
/*****************************************************************************/

void ProcessSignal(std::string signal_name, t_signal_data data);

/*****************************************************************************/
/**                               Public Classes                            **/
/*****************************************************************************/


#endif // FILE_SIGNAL_RECEIVER_HPP

/*****************************************************************************/
/** Revision Log:                                                           **/
/** ----------------------------------------------------------------------- **/
/** Created By:         Revision      Date:          Description:           **/
/** ----------------------------------------------------------------------- **/
/** Daniel Terrazas     0.0.0.1     3-Mar-2020      Initial Revision.       **/
/** ----------------------------------------------------------------------- **/
/**                                END OF FILE                              **/
/*****************************************************************************/
