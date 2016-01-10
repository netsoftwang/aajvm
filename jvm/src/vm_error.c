/*
 * vm_error.c (c) wzt 2012, 2013	http://www.cloud-sec.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wvm.h"
#include "log.h"
#include "trace.h"
#include "vm_error.h"

void jvm_warning(int flag, char *fmt, ...)
{
        va_list arg;
	char buf[1024];

        va_start(arg, fmt);
        vsprintf(buf, fmt, arg);
        va_end(arg);

        switch (flag) {
        case VM_ERROR_CLASS_FILE:
                printf("%s", buf);
                break;
        case VM_ERROR_MEMORY:
                printf("%s", buf);
                break;
	case VM_ERROR_INTERP:
                printf("%s", buf);
		break;
        default:
                printf("VM Error: Unkown flag.\n");
                break;
        }

	calltrace();
}

void jvm_error(int flag, char *fmt, ...)
{
        va_list arg;
	char buf[1024];

        va_start(arg, fmt);
        vsprintf(buf, fmt, arg);
        va_end(arg);

	switch (flag) {
	case VM_ERROR_CLASS_FILE:
                printf("%s", buf);
		break;
	case VM_ERROR_MEMORY:
                printf("%s", buf);
		break;
	case VM_ERROR_INTERP:
                printf("%s", buf);
		break;
	default:
		printf("VM Error: Unkown flag.\n");
		break;
	}

	calltrace();
	mmap_exit();
	calltrace_destroy();
	exit(0);
}
