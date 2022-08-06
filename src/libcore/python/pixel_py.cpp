//
// Created by okn-yu on 2022/08/03.
//


#include <futaba/python/python.h>
#include <futaba/core/pixel.h>

FTB_PY_EXPORT(rgb_pixel) {
    py::class_<Pixel, RGBPixel>(m, "RGBPixel")
            .def(py::init<>())
            .def(py::init<Color>())
            .def_readwrite("data", &RGBPixel::data);
}