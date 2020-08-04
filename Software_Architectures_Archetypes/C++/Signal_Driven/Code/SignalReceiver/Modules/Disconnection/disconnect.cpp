/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                               Project Name                              **/
/** ----------------------------------------------------------------------- **/
/** FILE: disconnect.cpp                                                    **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** disconnect.cpp description.                                             **/
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

/*****************************************************************************/
/**                                  Includes                               **/
/*****************************************************************************/

#include <iostream>

#include "signal_receiver.h"

#include "disconnect.h"
#include "disconnect_config.h"

/*****************************************************************************/
/**                                   Macros                                **/
/*****************************************************************************/

/*****************************************************************************/
/**                                 Data Types                              **/
/*****************************************************************************/

typedef enum
{
    SIG_DISCONNECT_FROM_INTERNET,
    SIG_DISCONNECT_FROM_SERVER,
    SIG_DISCONNECT_FROM_APP,
    // ...
    NUMBER_OF_DISC_SIGNALS,
}t_disconnect_signals_enum;

typedef t_in_module_signal t_disconnect_signal;

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

void disconnect_from_internet(t_data data);
void disconnect_from_server(t_data data);
void disconnect_from_app(t_data data);

static t_disconnect_signal disconnection_signals[NUMBER_OF_DISC_SIGNALS] =
{
    {SIG_NAME_DISCONNECT_FROM_INTERNET, disconnect_from_internet},
    {SIG_NAME_DISCONNECT_FROM_SERVER, disconnect_from_server},
    {SIG_NAME_DISCONNECT_FROM_APP, disconnect_from_app}
};

/*****************************************************************************/
/**                            Function Definitions                         **/
/*****************************************************************************/

void disconnection_handle(t_signal_data data)
{
    for (int i = 0; i < NUMBER_OF_DISC_SIGNALS; ++i)
    {
        if (data.function_name == disconnection_signals[i].name)
        {
            disconnection_signals[i].function(data.content);
            break;
        }
    }
}

void disconnect_from_internet(t_data data)
{
    std::cout << "Disconnected from internet" << std::endl;
    std::cout << "Info: " << data.data_content << std::endl;
}

void disconnect_from_server(t_data data)
{
    std::cout << "Disconnected from server" << std::endl;
    std::cout << "Info: " << data.data_content << std::endl;
}

void disconnect_from_app(t_data data)
{
    std::cout << "Disconnected from app" << std::endl;
    std::cout << "Info: " << data.data_content << std::endl;
}

/*****************************************************************************/
/** Revision Log:                                                           **/
/** ----------------------------------------------------------------------- **/
/** Created By:         Revision      Date:          Description:           **/
/** ----------------------------------------------------------------------- **/
/** Daniel Terrazas     0.0.0.1     3-Mar-2020      Initial Revision.       **/
/** ----------------------------------------------------------------------- **/
/**                                END OF FILE                              **/
/*****************************************************************************/
