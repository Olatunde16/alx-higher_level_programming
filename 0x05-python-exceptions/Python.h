#ifndef Py_PYTHON_H
#define Py_PYTHON_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PY_MAJOR_VERSION 3
#define PY_MINOR_VERSION 8
#define PY_MICRO_VERSION 10

typedef struct _object PyObject;

PyObject* Py_BuildValue(const char*, ...);
PyObject* PyDict_New(void);
PyObject* PyDict_SetItem(PyObject*, PyObject*, PyObject*);
PyObject* PyImport_ImportModule(const char*);
PyObject* PyLong_FromLong(long);


#define Py_INCREF(obj)   ((obj)->ob_refcnt++)
#define Py_DECREF(obj)   \
    if (--(obj)->ob_refcnt == 0) \
        PyFinalizeEx()

void Py_Initialize(void);
void Py_Finalize(void);
void Py_FinalizeEx(void);
void print_python_float(PyObject *p);
void print_python_bytes(PyObject *p);


#endif /* Py_PYTHON_H */
