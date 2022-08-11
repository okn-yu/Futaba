//
// Created by okn-yu on 2022/08/03.
//


#include <futaba/python/python.h>
#include <futaba/render/sphere.h>

FTB_PY_EXPORT(sphere) {
    py::class_<Sphere>(m, "Sphere")
            .def(py::init<Vec3, float>())
            .def("is_hittable", &Sphere::is_hittable);
}