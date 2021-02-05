#ifndef __SMF_G_TYPES_H__
#define __SMF_G_TYPES_H__

#if !defined (__SMF_GLIB_H_INSIDE__) && !defined (GLIB_COMPILATION)
#error "Only <glib.h> can be included directly."
#endif

#include <stdbool.h>
#if !defined (TRUE)
#	define TRUE true
#endif

#if !defined (FALSE)
#	define FALSE false
#endif

typedef int gboolean;
typedef unsigned int guint;
typedef int gint;
typedef void *gpointer;
typedef const void *gconstpointer;

#endif /* __SMF_G_TYPES_H__ */
