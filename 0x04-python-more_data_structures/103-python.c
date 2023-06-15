#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - This prints the bytes information
 * @o: This is the python object
 * Return: no return
 */

void print_python_bytes(PyObject *o)
{
	char *string;
	long int size, o, limit;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(o))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = ((PyVarObject *)(o))->ob_size;
	string = ((PyBytesObject *)o)->ob_sval;

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", string);

	if (size >= 10)
		limit = 10;
	else
		limit = size + 1;

	printf("  first %ld bytes:", limit);

	for (i = 0; i < limit; i++)
		if (string[i] >= 0)
			printf(" %02x", string[i]);
		else
			printf(" %02x", 256 + string[i]);

	printf("\n");
}

/**
 * print_python_list - This prints the list information
 * @o: This is the python object
 * Return: no return
 */

void print_python_list(PyObject *o)
{
	long int size, i;
	PyListObject *list;
	PyObject *obj;

	size = ((PyVarObject *)(o))->ob_size;
	list = (PyListObject *)o;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", list->allocated);

	for (i = 0; i < size; i++)
	{
		obj = ((PyListObject *)p)->ob_item[i];
		printf("Element %ld: %s\n", i, ((obj)->ob_type)->tp_name);
		if (PyBytes_Check(obj))
			print_python_bytes(obj);
	}
}
