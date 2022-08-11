//
// Created by okn-yu on 2022/07/31.
//

#include <iostream>
#include <futaba/futaba.h>
#include <futaba/python/python.h>

/*
 * ヘッダファイルを利用する代わりとしてマクロを用いてプロトタイプ宣言を行う
 */

FTB_PY_DECLARE(aggregate);

FTB_PY_DECLARE(hit);

FTB_PY_DECLARE(pinhole_camera);

FTB_PY_DECLARE(sphere);

/*
 * futaba_pyはCMakeのtargetにも同名の指定が必要
 */
PYBIND11_MODULE(librender_py, m) {

    /*
     * ここではモジュールの属性を指定している
     * >>> import futaba_python
     * >>> dir(futaba_python)
     * ['FTB_AUTHORS', 'FTB_VERSION', 'FTB_VERSION_MAJOR', 'FTB_VERSION_MINOR', 'FTB_VERSION_PATCH', 'FTB_YEAR', 'Vec3', '__doc__', '__file__', '__loader__', '__name__', '__package__', '__spec__', '__version__']
     * >>> futaba_python.__version__
     * '1.1.1'
     * >>> futaba_python.__name__
     * 'futaba.core'
     * >>> futaba_python.FTB_VERSION
     * '1.1.1'
     * >>> futaba_python.FTB_VERSION_MAJOR
     * 1
     * >>> futaba_python.FTB_VERSION_MINOR
     * 1
     * >>> futaba_python.FTB_VERSION_PATCH
     * 1
     * >>> futaba_python.FTB_YEAR
     * '2022'
     * >>> futaba_python.FTB_AUTHORS
     * 'okn-yu'
     */

    m.attr("__name__") = "librender_python";
    m.attr("__version__") = FTB_VERSION;
    m.attr("FTB_VERSION") = FTB_VERSION;
    m.attr("FTB_VERSION_MAJOR") = FTB_VERSION_MAJOR;
    m.attr("FTB_VERSION_MINOR") = FTB_VERSION_MINOR;
    m.attr("FTB_VERSION_PATCH") = FTB_VERSION_PATCH;
    m.attr("FTB_YEAR") = FTB_YEAR;
    m.attr("FTB_AUTHORS") = FTB_AUTHORS;

    FTB_PY_IMPORT(aggregate);
    FTB_PY_IMPORT(hit);
    FTB_PY_IMPORT(pinhole_camera);
    FTB_PY_IMPORT(sphere);

}
