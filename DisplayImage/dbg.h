#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define __output__ stdout

char *USER_ERR_MSG;

#define __debug(M, ...) fprintf(__output__, ":> " M "\n", ##__VA_ARGS__)


#define __clean_errno() (errno == 0 ? "None" : strerror(errno))

#define __log_err(M, ...) fprintf(__output__, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, __clean_errno(), ##__VA_ARGS__)

#define __log_warn(M, ...) fprintf(__output__, "[WARN] (%s:%d errno: %s)" M "\n", __FILE__, __LINE__, __clean_errno(), ##__VA_ARGS__)

#define __log_info(M, ...) fprintf(__output__, "[INFO] (%s:%d errno: %s)" M "\n", __FILE__, __LINE__, __clean_errno(), ##__VA_ARGS__)

#define __check(A, M, ...) if (!(A)){ __log_err(M, ##__VA_ARGS__); errno=0; USER_ERR_MSG = (char*) malloc(sizeof(char) * 1024); snprintf(USER_ERR_MSG, 1024, "%s", M); goto error; }

#define __sentinel(M, ...) { __log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define __check_mem(A) __check((A), "Out of memory.")

#define __check_debug(A, M, ...) if(!(A)) { __debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif


