/*****************************************************************************/
/** Copyright (c) 2020, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                               Project Name                              **/
/** ----------------------------------------------------------------------- **/
/** FILE: disconnect_config.h                                                  **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** disconnect_config.h description.                                           **/
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
#ifndef FILE_DISCONNECT_CONFIG_H
#define FILE_DISCONNECT_CONFIG_H

/*****************************************************************************/
/**                                  Includes                               **/
/*****************************************************************************/

#include <iostream>

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

const std::string SIG_NAME_DISCONNECT_FROM_INTERNET = "sig_disconnect_from_internet";
const std::string SIG_NAME_DISCONNECT_FROM_SERVER = "sig_disconnect_from_server";
const std::string SIG_NAME_DISCONNECT_FROM_APP = "sig_disconnect_from_app";

/*****************************************************************************/
/**                              Public Functions                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                               Public Classes                            **/
/*****************************************************************************/

#endif // FILE_DISCONNECT_CONFIG_H

/*****************************************************************************/
/** Revision Log:                                                           **/
/** ----------------------------------------------------------------------- **/
/** Created By:         Revision      Date:          Description:           **/
/** ----------------------------------------------------------------------- **/
/** Daniel Terrazas     0.0.0.1     3-Mar-2020      Initial Revision.       **/
/** ----------------------------------------------------------------------- **/
/**                                END OF FILE                              **/
/*****************************************************************************/