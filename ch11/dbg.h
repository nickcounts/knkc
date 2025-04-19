#ifndef __dbg_h__
#define __dbg_h__

#include <errno.h>
#include <stdio.h>
#include <string.h>

#define TERM_RED "\033[31m"
#define TERM_GREEN "\033[32m"
#define TERM_YELLOW "\033[33m"
#define TERM_BLUE "\033[34m"
#define TERM_RESET "\033[0m"

#ifdef NDEBUG
#define debug(M, ...)
#else

#define debug(M, ...)                                                          \
  fprintf(stderr, "DEBUG %s:%d:%s: " M "\n", __FILE__, __LINE__, __FUNCTION__, \
          ##__VA_ARGS__)
#endif // NDEBUG

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...)                                                        \
  fprintf(stderr,                                                              \
          "[" TERM_RED "ERROR" TERM_RESET "] (%s:%d:%s: errno: %s) " M "\n",   \
          __FILE__, __LINE__, __FUNCTION__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...)                                                       \
  fprintf(stderr,                                                              \
          "[" TERM_YELLOW "WARN" TERM_RESET "] (%s:%d:%s: errno: %s) " M "\n", \
          __FILE__, __LINE__, __FUNCTION__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...)                                                       \
  fprintf(stderr, "[INFO] (%s:%d:%s:) " M "\n", __FILE__, __LINE__,            \
          __FUNCTION__, ##__VA_ARGS__)

#define check(A, M, ...)                                                       \
  if (!(A)) {                                                                  \
    log_err(M, ##__VA_ARGS__);                                                 \
    errno = 0;                                                                 \
    goto error;                                                                \
  }

#define sentinel(M, ...)                                                       \
  {                                                                            \
    log_err(M, ##__VA_ARGS__);                                                 \
    errno = 0;                                                                 \
    goto error;                                                                \
  }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...)                                                 \
  if (!(A)) {                                                                  \
    debug(M, ##__VA_ARGS__);                                                   \
    errno = 0;                                                                 \
    goto error;                                                                \
  }

#endif // !__dbg_h__
