//
// Created by okn-yu on 2022/07/31.
//

#ifndef PRACTICEPATHTRACING_PYTHON_H
#define PRACTICEPATHTRACING_PYTHON_H

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

/*
 * pybind11関連のマクロ
 * 該当する関数の個別の実装はfutaba/libcore/python/XX.cppに記載する
 * pybind11へのbind処理はfutaba/libcore/python/main.cppで一括処理する
 * ここで定義されているマクロは上記の実装を簡潔にするために利用される
 */

namespace py = pybind11;

/*
 * headerファイルをincludeしなくてもプロトタイプ宣言があれば.oファイルは作成できる
 * 最終的に.oファイル同士をリンクすれば問題なく利用できる
 * つまりheaderファイルは別ファイルの実装を呼び出すのに一般的ではあるが、必須ではない
 */

#define FTB_PY_DECLARE(Name) extern void python_export_##Name(py::module &m)
#define FTB_PY_EXPORT(Name) void python_export_##Name(py::module &m)
#define FTB_PY_IMPORT(Name) python_export_##Name(m)
#define FTB_PY_IMPORT_SUBMODULE(Name) python_export_##Name(Name)

#endif //PRACTICEPATHTRACING_PYTHON_H
