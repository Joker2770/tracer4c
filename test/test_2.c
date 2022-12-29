/*************************************************************************
    > File Name: test_2.c
    > Author: Jintao Yang
    > Mail: 18608842770@163.com 
    > Created Time: Thu Dec 29 20:00:14 2022
 ************************************************************************/

/**
MIT License

Copyright (c) 2022 Joker2770

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>
#include "../tracer_in_file.h"

#define TAG "test"

int main(int argc, char *argv[])
{
    set_tracer_name_prefix("log");
    LOG_DBG_F(TAG, "log_debug %d", LOG_LEVEL_DEBUG_F);
    LOG_INFO_F(TAG, "log_info %d", LOG_LEVEL_INFO_F);
    LOG_WARN_F(TAG, "log_warn");
    LOG_ERR_F(TAG, "log_err");

    set_tracer_level_f(LOG_LEVEL_INFO_F);

    LOG_DBG_F(TAG, "log_debug %d", LOG_LEVEL_DEBUG_F);
    LOG_INFO_F(TAG, "log_info %d", LOG_LEVEL_INFO_F);
    LOG_WARN_F(TAG, "log_warn");
    LOG_ERR_F(TAG, "log_err");
    return 0;
}