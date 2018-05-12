#include <stdio.h>
#include <python3.6m/Python.h>

#if PY_MAJOR_VERSION >= 3
#define IS_PY3k
#endif

static PyObject *
hello_greet (PyObject * self, PyObject * args)
{
  const char *input;
  if (!PyArg_ParseTuple (args, "s", &input))
    {
      return NULL;
    }
  printf ("%s", input);
  Py_RETURN_NONE;
}

static PyMethodDef HelloMethods[] = {
  {"greet", hello_greet, METH_VARARGS, "Greet the user"},
  {NULL, NULL, 0, NULL}
};


#ifdef IS_PY3k

static struct PyModuleDef hellomodule = {
  PyModuleDef_HEAD_INIT, "Hello", NULL, -1, HelloMethods
};

PyMODINIT_FUNC
PyInit_hello (void)
{
  return PyModule_Create (&hellomodule);
}

#else
PyMODINIT_FUNC
initHello (void)
{
  (void) Py_InitModule ("hello", HelloMethods);
}
#endif
