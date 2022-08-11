//
// Created by okn-yu on 2022/08/03.
//


#include <futaba/python/python.h>
#include <futaba/render/camera.h>

//FTB_PY_EXPORT(camera) {
//    py::class_<Camera>(m, "Camera")
//            .def(py::init<const Vec3, const Vec3, float, float, float>())
//            .def("shoot", &Camera::shoot);
//}

FTB_PY_EXPORT(pinhole_camera) {
    py::class_<Camera, PinholeCamera>(m, "PinholeCamera")
            .def(py::init<const Vec3, const Vec3, float, float, float>())
            .def("shoot", &Camera::shoot);
}