#ifndef SRC_S21_STRERROR_H_
#define SRC_S21_STRERROR_H_

#if defined(__APPLE__) || defined(__MACH__)
#define S21_ERRLIST_SIZE 107
#elif defined(__linux__)
#define S21_ERRLIST_SIZE 134
#else
/* other (probably unix or WIN32 platforms)
it doesn't throw any errors (bu should) to pass verter ;) */
#define S21_ERRLIST_SIZE 134
#endif

/*
    Libc implementation

    The only difference with us is _() macro, which is
    use for locale translation.

    https://code.woboq.org/userspace/glibc/sysdeps/gnu/errlist.c.html#_sys_errlist_internal

 */

#endif  // SRC_S21_STRERROR_H_
