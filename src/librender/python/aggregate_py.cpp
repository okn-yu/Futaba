//
// Created by okn-yu on 2022/08/03.
//


#include <futaba/python/python.h>
#include <futaba/render/aggregate.h>

FTB_PY_EXPORT(aggregate) {
    py::class_<Aggregate>(m, "Aggregate")
            .def(py::init<>())
            .def(py::init<const std::vector<std::shared_ptr<Sphere>>>())
            .def("add", &Aggregate::add)
            .def("intersect", &Aggregate::intersect);
}