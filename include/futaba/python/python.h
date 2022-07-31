//
// Created by okn-yu on 2022/07/31.
//

#ifndef PRACTICEPATHTRACING_PYTHON_H
#define PRACTICEPATHTRACING_PYTHON_H

#include <pybind11/pybind11.h>

namespace py = pybind11;

#define FUT_PY_EXPORT(Name) void python_export_##Name(py::module &m)

#endif //PRACTICEPATHTRACING_PYTHON_H
