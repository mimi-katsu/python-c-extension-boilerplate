#include <stdio.h>
#include <Python.h>

// Function 1: A simple 'hello world' function
static PyObject *helloworld(PyObject *self, PyObject *args)
{
    printf("Hello World\n");
    return Py_None;
}

static PyObject *argtest(PyObject *self, PyObject *args)
{
    int num;
    char *s;
    PyArg_ParseTuple(args, "is", &num, &s);                              // Parse the arguments passed in. "is" means the first argument is an int type(i) and the second is a string(s). Assign them to addresses
    printf("Test num: %d\nTest Str: %s\n", num, s);

    return Py_None;
}



static PyMethodDef myMethods[] = {                                        // define the methods contained within the module
    { "helloworld", helloworld, METH_NOARGS, "Prints Hello World" },      // function name in python, Pyobject struct, call with no args, Python docstring
    {"argtest", argtest, METH_VARARGS, "display multiple arguments"},     // function name in python, Pyobject struct, call with args, docstring
    { NULL, NULL, 0, NULL }                                               // signal the end of the methods definitions
};

static struct PyModuleDef myModule = {                                    // Define module characteristics
    PyModuleDef_HEAD_INIT,                                                // Always init with this firstm, dont know what it does
    "myModule",                                                           // Name of python module
    "Test Module for learning to create Python modules in C.",            // Python Docstring
    -1,                                                                   // "size of per-interpreter state of the module, or -1 if the module keeps state in global variables." I dont know what that means.
    myMethods                                                             // Pointer to module method definitions
};

// Initializes our module using our above struct
PyMODINIT_FUNC PyInit_myModule(void)                                      // Define a function that returns PyMODINIT_FUNC type
{
    return PyModule_Create(&myModule);                                    // call PyModule_Create with referenve to Module
}
