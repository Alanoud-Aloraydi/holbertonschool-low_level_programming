#include "function_pointers.h"

/**
 * print_name - prints a name using a function pointer
 * @name: name to print
 * @f: function to format and print the name
 */
void print_name(char *name, void (*f)(char *))
{
    if (name && f)
    {
        f(name);
    }
}
