#ifndef __SMF_G_MESSAGES_H__
#define __SMF_G_MESSAGES_H__

#if !defined (__SMF_GLIB_H_INSIDE__) && !defined (SMF_GLIB_COMPILATION)
#	error "Only <glib.h> can be included directly."
#endif

typedef enum
{
  /* log flags */
  G_LOG_FLAG_RECURSION          = 1 << 0,
  G_LOG_FLAG_FATAL              = 1 << 1,

  /* GLib log levels */
  G_LOG_LEVEL_ERROR             = 1 << 2,       /* always fatal */
  G_LOG_LEVEL_CRITICAL          = 1 << 3,
  G_LOG_LEVEL_WARNING           = 1 << 4,
  G_LOG_LEVEL_MESSAGE           = 1 << 5,
  G_LOG_LEVEL_INFO              = 1 << 6,
  G_LOG_LEVEL_DEBUG             = 1 << 7,

  G_LOG_LEVEL_MASK              = ~(G_LOG_FLAG_RECURSION | G_LOG_FLAG_FATAL)
} GLogLevelFlags;

#if !defined (g_message)
#	define g_message(...) do{}while(false)
#endif
#if !defined (g_debug)
#	define g_debug(...) do{}while(false)
#endif
#if !defined (g_warning)
#	define g_warning(...) do{}while(false)
#endif
#if !defined (g_error)
#	define g_error(...) do{}while(false)
#endif
#if !defined (g_critical)
#	define g_critical(...) do{}while(false)
#endif

#endif /* __SMF_G_MESSAGES_H__ */
