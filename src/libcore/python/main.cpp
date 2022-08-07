//
// Created by okn-yu on 2022/07/31.
//

#include <iostream>
#include <futaba/futaba.h>
#include <futaba/python/python.h>

/*
 * ヘッダファイルを利用する代わりとしてマクロを用いてプロトタイプ宣言を行う
 */
FTB_PY_DECLARE(vec3);
FTB_PY_DECLARE(image);
FTB_PY_DECLARE(rgb_pixel);

/*
 * futaba_pyはCMakeのtargetにも同名の指定が必要
 */
PYBIND11_MODULE(futaba_py, m) {

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

    m.attr("__name__") = "futaba_python";
    m.attr("__version__") = FTB_VERSION;
    m.attr("FTB_VERSION") = FTB_VERSION;
    m.attr("FTB_VERSION_MAJOR") = FTB_VERSION_MAJOR;
    m.attr("FTB_VERSION_MINOR") = FTB_VERSION_MINOR;
    m.attr("FTB_VERSION_PATCH") = FTB_VERSION_PATCH;
    m.attr("FTB_YEAR") = FTB_YEAR;
    m.attr("FTB_AUTHORS") = FTB_AUTHORS;

    FTB_PY_IMPORT(vec3);
    FTB_PY_IMPORT(image);
    FTB_PY_IMPORT(rgb_pixel);
}