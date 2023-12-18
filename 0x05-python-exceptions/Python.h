#ifndef Py_PYTHON_H
#define Py_PYTHON_H

/* Include standard C headers */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Python version information */
#define PY_MAJOR_VERSION 3
#define PY_MINOR_VERSION 8
#define PY_MICRO_VERSION 10

/* Object structures and types */
typedef struct _object PyObject;

/* Function declarations for Python API */
PyObject* Py_BuildValue(const char*, ...);
PyObject* PyDict_New(void);
PyObject* PyDict_SetItem(PyObject*, PyObject*, PyObject*);
PyObject* PyImport_ImportModule(const char*);
PyObject* PyLong_FromLong(long);

/* Macros for common operations */
#define Py_INCREF(obj)   ((obj)->ob_refcnt++)
#define Py_DECREF(obj)   \
    if (--(obj)->ob_refcnt == 0) \
        PyFinalizeEx()

/* Python initialization and finalization */
void Py_Initialize(void);
void Py_Finalize(void);
void Py_FinalizeEx(void);

/* ... More declarations ... */

#endif /* Py_PYTHON_H */
