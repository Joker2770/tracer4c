/*************************************************************************
    > File Name: tracer_in_file.h
    > Author: Jintao Yang
    > Mail: 18608842770@163.com 
    > Created Time: Thu Dec 29 18:49:56 2022
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

#ifndef __TRACER_IN_FILE_H__
#define __TRACER_IN_FILE_H__

#include <stdio.h>
#include <stdarg.h>

enum
{
  LOG_LEVEL_NONE_F,
  LOG_LEVEL_DEBUG_F,
  LOG_LEVEL_INFO_F,
  LOG_LEVEL_WARN_F,
  LOG_LEVEL_ERROR_F,
  LOG_LEVEL_FATAL_F,
};

#ifdef __cplusplus
extern "C"
{
#endif
  void set_tracer_level_f(int level);
  void set_tracer_name_prefix(char *prefix);
  void log_fun_f(int level, const char *opt, const char *tag, int line, const char *func, const char *fmt, ...);
#ifdef __cplusplus
}
#endif

/*
 *@LOG_DBG
 */
#define LOG_DBG_F(tag, fmt, ...) \
  log_fun_f(LOG_LEVEL_DEBUG_F, "D", tag, __LINE__, __func__, fmt, ##__VA_ARGS__)

/*
 *@LOG_INFO
 */
#define LOG_INFO_F(tag, fmt, ...) \
  log_fun_f(LOG_LEVEL_INFO_F, "I", tag, __LINE__, __func__, fmt, ##__VA_ARGS__)

/*
 *@LOG_WARN
 */
#define LOG_WARN_F(tag, fmt, ...) \
  log_fun_f(LOG_LEVEL_WARN_F, "W", tag, __LINE__, __func__, fmt, ##__VA_ARGS__)

/*
 *@LOG_ERR
 */
#define LOG_ERR_F(tag, fmt, ...) \
  log_fun_f(LOG_LEVEL_ERROR_F, "E", tag, __LINE__, __func__, fmt, ##__VA_ARGS__)

/*
 *@LOG_FATAL
 */
#define LOG_FATAL_F(tag, fmt, ...) \
  log_fun_f(LOG_LEVEL_FATAL_F, "F", tag, __LINE__, __func__, fmt, ##__VA_ARGS__)

#endif
