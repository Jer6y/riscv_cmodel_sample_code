#ifndef __RISCV_PRINTF_H
#define __RISCV_PRINTF_H

#include <stdarg.h>
#include <sbi/debug_console.h>
#include "string.h"

static inline int riscv_putc(int byte)
{
	sbi_debug_console_write_byte(byte);
	return (byte);
}

static inline int riscv_puts(const char* str)
{
	int size = strlen(str);
	for(int i=0;i<size;i++)
		riscv_putc(str[i]);
	riscv_putc('\n');
        return size;
}


static inline int riscv_printf(const char* fmt, ...)
{
	char buffer[512];
  	va_list arg;
        va_start(arg, fmt);
        int done = vsnprintf(buffer, 512, fmt, arg);  // 将格式化的内容(字符串)保存在buffer中
  	va_end(arg);
	int size = strlen(buffer);
        for(int i=0;i<size;i++)
		riscv_putc(buffer[i]);
  	return done;
}

#endif
