#ifndef __SMF_G_ARRAY_H__
#define __SMF_G_ARRAY_H__

#if !defined (__SMF_GLIB_H_INSIDE__) && !defined (SMF_GLIB_COMPILATION)
#	error "Only <glib.h> can be included directly."
#endif

#include <glib/gtypes.h>

struct _GPtrArray
{
	gpointer *pdata;
	guint	    len;
};

typedef struct _GPtrArray GPtrArray;

typedef gint(*GCompareFunc)(gconstpointer a,
                            gconstpointer b);


/**
 *
 * @return
 *
 * @see https://developer.gnome.org/glib/stable/glib-Pointer-Arrays.html#g-ptr-array-new
 */
GPtrArray *g_ptr_array_new(void);


/**
 *
 * @param array
 * @param free_seg
 * @return
 *
 * @see https://developer.gnome.org/glib/stable/glib-Pointer-Arrays.html#g-ptr-array-free
 */
gpointer *g_ptr_array_free(GPtrArray *array,
                           gboolean free_seg);

void
g_ptr_array_add(GPtrArray *array,
                gpointer data);


gpointer
g_ptr_array_index(GPtrArray *array,
                  guint index_);

gboolean
g_ptr_array_remove(GPtrArray *array,
                   gpointer data);


gpointer
g_ptr_array_remove_index(GPtrArray *array,
                         guint index_);

void
g_ptr_array_sort(GPtrArray *array,
                 GCompareFunc compare_func);

#endif /* __SMF_G_ARRAY_H__ */
