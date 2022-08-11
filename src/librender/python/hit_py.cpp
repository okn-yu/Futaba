//
// Created by okn-yu on 2022/08/03.
//


#include <futaba/python/python.h>
#include <futaba/render/hit.h>

FTB_PY_EXPORT(hit) {
    py::class_<HitRecord>(m, "HitRecord")
            .def(py::init<>())
            .def_readwrite("hit_pos", &HitRecord::hit_pos)
            .def_readwrite("hit_normal", &HitRecord::hit_normal);
}