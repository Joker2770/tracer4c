/*************************************************************************
    > File Name: tracer.c
    > Author: Jintao Yang
    > Mail: 18608842770@163.com
    > Created Time: Thu Dec 29 16:56:58 2022
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

#include "tracer.h"

#include <string.h>
#include <time.h>

int g_current_dbg_level = LOG_LEVEL_DEBUG;

void log_fun(int level, const char *opt, const char *tag, int line, const char *func, const char *fmt, ...)
{
    if (level >= g_current_dbg_level)
    {
        char msg_buf[10 * 1024];
        memset(msg_buf, 0, sizeof(msg_buf));
        va_list ap;
        va_start(ap, fmt);
        time_t timep;
        struct tm *p = NULL;
        time(&timep);
        p = localtime(&timep);
        sprintf(msg_buf, "[%02d:%02d:%02d] %s/%s %s():(%d) ", p->tm_hour, p->tm_min, p->tm_sec, opt, tag, func, line);
        vsprintf(msg_buf + strlen(msg_buf), fmt, ap);
        fprintf(stderr, "%s\n", msg_buf);
        va_end(ap);
    }
}

void set_tracer_level(int level)
{
    g_current_dbg_level = level;
}
