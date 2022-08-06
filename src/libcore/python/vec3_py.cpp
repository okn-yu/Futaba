//
// Created by okn-yu on 2022/08/03.
//

/*
 * 参考URL:
*  https://www.qoosky.io/techs/796befc92e
 * https://pybind11.readthedocs.io/en/stable/advanced/classes.html
 */

#include <futaba/python/python.h>
#include <futaba/core/vec3.h>

FTB_PY_EXPORT(vec3) {
    py::class_<Vec3>(m, "Vec3")
            .def(py::init<>())
            .def(py::init<float, float, float>())
            .def(py::init<float>())

            .def_readwrite("elements", &Vec3::elements)

            .def("length", &Vec3::length)
            .def("squared_length", &Vec3::squared_length)

            .def(py::self + py::self)
            .def(-py::self)
            .def(py::self += py::self)
            .def(py::self -= py::self)
            .def(py::self *= py::self)
            .def(py::self *= float())
            .def(py::self /= py::self)
            .def(py::self /= float())

            .def(py::self + py::self)
            .def(float() + py::self)
            .def(py::self + float())

            .def(py::self - py::self)
            .def(float() - py::self)
            .def(py::self - float())

            .def(py::self * py::self)
            .def(float() * py::self)
            .def(py::self * float())

            .def(py::self / py::self)
            .def(float() / py::self)
            .def(py::self / float())

            .def("equal", &operator==, py::is_operator()) // PythonではC++のようにVec1==Vec2とは実行できない
            .def("dot", &dot, "")
            .def("cross", &cross)  // Vec3.cross(v1, v2)のようにクラス経由で呼び出すことに注意
            .def("rotation_x", &rotation_x)
            .def("rotation_y", &rotation_y)
            .def("rotation_z", &rotation_z)
            .def("unit_vec", &unit_vec)
            .def("orthonormal_basis", &orthonormal_basis)
            .def("world_2_local", &world_2_local)
            .def("local_2_world", &local_2_world);
}