//
// Created by okn-yu on 2022/08/07.
//

#include <futaba/python/python.h>
#include <futaba/core/image.h>

FTB_PY_EXPORT(image) {
    py::class_<Image>(m, "Image")
            .def(py::init<int, int>())
            .def("read_pixel", &Image::read_pixel)
            .def("write_pixel", &Image::write_pixel)
            .def("png_output", &Image::png_output);
}