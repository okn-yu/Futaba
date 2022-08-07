//
// Created by okn-yu on 2022/08/03.
//


#include <futaba/python/python.h>
#include <futaba/core/ray.h>

FTB_PY_EXPORT(ray) {
    py::class_<Ray>(m, "Ray")
            .def(py::init<Vec3, Vec3>())
            .def_readonly("origin", &Ray::origin)
            .def_readonly("direction", &Ray::direction)
            .def("__call__", &Ray::operator(), py::is_operator());
}