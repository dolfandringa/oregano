#ifndef OREGANO_ECHO_H_
#define OREGANO_ECHO_H_

#include <glib.h>
#include <glib/gprintf.h>

void oregano_echo_static (const char *message) {
	g_printf ("[echo] %s\n", message);
}

void oregano_echo (const char *format, ...)
{
	va_list args;
	va_start (args, format);
	char *tmp = g_strdup_vprintf (format, args);
	va_end (args);
	oregano_echo_static (tmp);
	g_free (tmp);
}

#endif /* OREGANO_ECHO_H_ */