#include <glib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct _GPtrArrayImplementation
{
	gpointer *storage;
	guint logical_size;
	guint physical_size;
	guint ref_count;
	
} GPtrArrayImplementation;

GPtrArray *g_ptr_array_new()
{
	GPtrArrayImplementation *array = (GPtrArrayImplementation *)malloc(sizeof(GPtrArrayImplementation));
	array->logical_size = 0;
	array->physical_size = 8;
	array->ref_count = 1;
	
	array->storage = (gpointer *) malloc(array->physical_size * sizeof(gpointer));
	memset(array->storage, 0, array->physical_size * sizeof(gpointer));
	return (GPtrArray *)array;
}

gpointer *g_ptr_array_free(GPtrArray *arrayInterface,
                           gboolean free_seg)
{
	GPtrArrayImplementation *array = (GPtrArrayImplementation *)arrayInterface;
	gpointer *storage = array->storage;
	
	if (free_seg)
	{
		free(array->storage);
		array->storage = storage = NULL;
		array->logical_size = array->physical_size = 0;
	}
	
	--array->ref_count;
	
	if (array->ref_count == 0)
	{
		free(array);
	}
	else
	{
		array->logical_size = 0;
	}
	
	return storage;
}

gpointer
g_ptr_array_index(GPtrArray *arrayInterface,
                  guint index_)
{
	GPtrArrayImplementation *array = (GPtrArrayImplementation *)arrayInterface;
	
	if (array->logical_size <= index_)
	{
		return NULL;
	}
	
	return array->storage[index_];
}

void
g_ptr_array_add(GPtrArray *arrayInterface,
                gpointer data)
{
	GPtrArrayImplementation *array = (GPtrArrayImplementation *)arrayInterface;
	
	if (array->logical_size == array->physical_size)
	{
		array->physical_size += 8;
		gpointer *new_storage = (gpointer *) malloc(
		                            array->physical_size * sizeof(gpointer)
		                        );
		memcpy(new_storage, array->storage, array->logical_size * sizeof(gpointer));
		free(array->storage);
		array->storage = new_storage;
	}
	
	array->storage[array->logical_size] = data;
	++array->logical_size;
}


gboolean
g_ptr_array_remove(GPtrArray *arrayInterface,
                   gpointer data)
{
	GPtrArrayImplementation *array = (GPtrArrayImplementation *)arrayInterface;
	
	for (guint a = 0; a < array->logical_size; ++a)
	{
		if (array->storage[a] == data)
		{
			for (guint b = a + 1; b < array->logical_size; ++b)
			{
				array->storage[b - 1] = array->storage[b];
			}
			
			--array->logical_size;
			return TRUE;
		}
	}
	
	return FALSE;
}

gpointer
g_ptr_array_remove_index_(GPtrArray *arrayInterface,
                          guint index_)
{
	GPtrArrayImplementation *array = (GPtrArrayImplementation *)arrayInterface;
	
	if (array->logical_size <= index_)
	{
		return NULL;
	}
	
	gpointer p = array->storage[index_];
	
	for (guint a = index_; a < array->logical_size - 1; ++a)
	{
		array->storage[a] = array->storage[a + 1];
	}
	
	--array->logical_size;
	return p;
}


void
g_ptr_array_sort(GPtrArray *arrayInterface,
                 GCompareFunc compare_func)
{
	GPtrArrayImplementation *array = (GPtrArrayImplementation *)arrayInterface;
	qsort(array->storage, array->logical_size, sizeof(gpointer), compare_func);
}

