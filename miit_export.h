
#ifndef MIIT_EXPORT_H
#define MIIT_EXPORT_H

#ifdef MIIT_STATIC_DEFINE
#  define MIIT_EXPORT
#  define MIIT_NO_EXPORT
#else
#  ifndef MIIT_EXPORT
#    ifdef miit_EXPORTS
        /* We are building this library */
#      define MIIT_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define MIIT_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef MIIT_NO_EXPORT
#    define MIIT_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef MIIT_DEPRECATED
#  define MIIT_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MIIT_DEPRECATED_EXPORT
#  define MIIT_DEPRECATED_EXPORT MIIT_EXPORT MIIT_DEPRECATED
#endif

#ifndef MIIT_DEPRECATED_NO_EXPORT
#  define MIIT_DEPRECATED_NO_EXPORT MIIT_NO_EXPORT MIIT_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MIIT_NO_DEPRECATED
#    define MIIT_NO_DEPRECATED
#  endif
#endif

#endif /* MIIT_EXPORT_H */
