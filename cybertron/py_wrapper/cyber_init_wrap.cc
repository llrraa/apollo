/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <Python.h>
#include <string.h>

#include "cybertron/py_wrapper/py_init.h"

static PyObject *cyber_py_init(PyObject *self, PyObject *args) {
  bool is_init = apollo::cybertron::py_init();
  if (is_init) {
    Py_RETURN_TRUE;
  } else {
    Py_RETURN_FALSE;
  }
}

static PyObject *cyber_py_ok(PyObject *self, PyObject *args) {
  bool is_ok = apollo::cybertron::py_ok();
  if (is_ok) {
    Py_RETURN_TRUE;
  } else {
    Py_RETURN_FALSE;
  }
}

static PyObject *cyber_py_shutdown(PyObject *self, PyObject *args) {
  apollo::cybertron::py_shutdown();
  return Py_None;
}

static PyObject *cyber_py_is_shutdown(PyObject *self, PyObject *args) {
  bool is_shutdown = apollo::cybertron::py_is_shutdown();
  if (is_shutdown) {
    Py_RETURN_TRUE;
  } else {
    Py_RETURN_FALSE;
  }
}

static PyObject *cyber_py_waitforshutdown(PyObject *self, PyObject *args) {
  apollo::cybertron::py_waitforshutdown();
  return Py_None;
}

/////////////////////////////////////////////////////////////////////
//// global for whole page, init module
/////////////////////////////////////////////////////////////////////
static PyMethodDef _cyber_init_methods[] = {
    // global fun
    {"py_init", cyber_py_init, METH_NOARGS, ""},
    {"py_ok", cyber_py_ok, METH_NOARGS, ""},
    {"py_shutdown", cyber_py_shutdown, METH_NOARGS, ""},
    {"py_is_shutdown", cyber_py_is_shutdown, METH_NOARGS, ""},
    {"py_waitforshutdown", cyber_py_waitforshutdown, METH_NOARGS, ""},

    {NULL, NULL, 0, NULL} /* sentinel */
};

/// Init function of this module
PyMODINIT_FUNC init_cyber_init(void) {
  AINFO << "init _cyber_init";
  Py_InitModule("_cyber_init", _cyber_init_methods);
}