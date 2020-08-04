/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                               Project Name                              **/
/** ----------------------------------------------------------------------- **/
/** FILE: connect.cpp                                                      **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** connect.cpp description.                                               **/
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

#include "connect.h"
#include "connect_config.h"

/*****************************************************************************/
/**                                   Macros                                **/
/*****************************************************************************/

/*****************************************************************************/
/**                                 Data Types                              **/
/*****************************************************************************/

typedef enum
{
    SIG_CONNECT_TO_INTERNET,
    SIG_CONNECT_TO_SERVER,
    SIG_CONNECT_TO_APP,
    // ...
    NUMBER_OF_CONN_SIGNALS,
}t_connect_signals_enum;

typedef t_in_module_signal t_connect_signal;

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

void connect_to_internet(t_data data);
void connect_to_server(t_data data);
void connect_to_app(t_data data);

static t_connect_signal connection_signals[NUMBER_OF_CONN_SIGNALS] =
{
    {SIG_NAME_CONNECT_TO_INTERNET, connect_to_internet},
    {SIG_NAME_CONNECT_TO_SERVER, connect_to_server},
    {SIG_NAME_CONNECT_TO_APP, connect_to_app}
};

/*****************************************************************************/
/**                            Function Definitions                         **/
/*****************************************************************************/

void connection_handle(t_signal_data data)
{
    for (int i = 0; i < NUMBER_OF_CONN_SIGNALS; ++i)
    {
        if (data.function_name == connection_signals[i].name)
        {
            connection_signals[i].function(data.content);
            break;
        }
    }
}

void connect_to_internet(t_data data)
{
    std::cout << "Connected to internet" << std::endl;
    std::cout << "Info: " << data.data_content << std::endl;
}

void connect_to_server(t_data data)
{
    std::cout << "Connected to server" << std::endl;
    std::cout << "Info: " << data.data_content << std::endl;
}

void connect_to_app(t_data data)
{
    std::cout << "Connected to app" << std::endl;
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
