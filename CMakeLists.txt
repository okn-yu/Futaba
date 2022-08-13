#----------
# 基本事項
#----------

# CMakeではソースコードのディレクトリとは別にビルド専用のディレクトリが作成される
# ビルド結果は全てビルド専用のディレクトリに出力される
# これによりソースコードのファイル群とビルド結果のファイル群が完全に分離されるのでメンテナンス性が向上される

# ビルドとコンパイルの違い:
# ビルドは実行ファイルの作成までを含む
# コンパイルはプログラムを機械語まで変換するプロセスを指す
# そのためコンパイルはビルドのプロセスの一部

#-------------
# CMakeの用語
#-------------

# target:
# ビルドには「複数の実行ファイルを作成する」「外部から呼び出されるためのライブラリファイルを作成する」「テストコードを実行する」などの複数の種類が存在する
# 上記のようにビルドを実行するゴールを指定したものがターゲット

# 代表的なターゲットは以下の3つ
#  実行ファイルの生成(add_executable)
#  ライブラリファイルの生成(add_library)
#  カスタムターゲットの実行(add_custom_target): 実行ファイルやライブラリファイルを生成しない

#----------------------
# CMakeの非推奨コマンド群
#----------------------

# include_directories
# add_definitions, add_compile_definitions, add_compile_options
# link_directories
# link_libraries

#----------------
# CMakeの参考URL
#----------------

# https://kamino.hatenablog.com/entry/cmake_tutorial1
# https://qiita.com/shohirose/items/45fb49c6b429e8b204ac
# https://qiita.com/shohirose/items/5b406f060cd5557814e9

#---------------------
# CXXのコンパイルの忘備録
#---------------------

# CMakeを記載するためにはC言語のコンパイルの手順を把握しておく必要がある

# オブジェクトファイル(XXX.o):
# コンパイラがプログラムを処理した結果生成される中間的なファイル
# オブジェクトファイル群をリンクすることで最終的に実行可能な実行ファイルが作成される

# まず「実行ファイルの作成」と「オブジェクトファイルの作成」と「静的ライブラリおよび共有ライブラリの作成」はすべてgccのコマンドは異なる
# g++では「オブジェクトリファイル（XXX.o）を作成するコマンド」と「ライブラリ（libXXX.soおよびlibXXX.a）を作成するコマンド」は異なる
# オブジェクトファイルとライブラリをリンクすることで実行ファイルが作成される

# 「プログラムファイル(XXX.cおよびXXX.cpp)」はコンパイルするとオブジェクトファイル(XXX.o)がそれぞれ独立して作成される
# そのため各プログラムファイル内で関数のIFはヘッダファイルで仮宣言して、プログラムファイルのスコープ内で独立して解決可能な状態にしておく必要がある

# 原則論としてはヘッダファイル（XXX.h）にはインタフェースのみが定義されていて、実装は別のプログラムファイル(XXX.cpp)に記載するのが望ましい
# 一般的には「呼び出されるincludeディレクトリ（XXX.h）」と「呼び出し元のプログラムファイル（XXX.cpp）」とは別のフォルダで管理されている
# そのためg++ではオブジェクトファイルの作成時にincludeディレクトリのパスを指定する必要がある
# そもそも論として「ヘッダファイルのXXX.h」はコンパイルしても、ヘッダファイルのオブジェクトファイル(XXX.o)は作成されない
# そのため.hのみからなるディレクトリ内にCMakeLists.txtは存在しない

# 一般的には「呼び出されるライブラリ(XXX.so or XXX.a)」は「呼び出し元のプログラムファイル(XXX.cpp)」とは別のフォルダで管理されている
# そのため実行ファイル作成時にはライブラリとリンクする必要があるため、ライブラリのパスを指定する必要がある

# -----------------
# CMake
# -----------------

#------------------------------
# プロジェクト名とプログラム言語を指定
#------------------------------

PROJECT(PracticePathTracing CXX)

#-------------------
# CMakeのバージョン確認
#-------------------

# 対応するcmakeの最小バージョンを指定する
# 指定を満たさない場合はエラーで終了する
# これはルートのCMakeListsにのみ記載する
cmake_minimum_required(VERSION 3.17)

#-----------------
# C++の標準仕様の指定
#-----------------

# C++の標準仕様の指定
# Vec3.hのarrayなどは初期化の仕方がC++11以降にしか対応していない
set(CMAKE_CXX_STANDARD 11)

#---------------------
# CMakeのオプションの設定
#---------------------

option(CMAKE_DEBUG_MSG "Enable CMake Debug Message" on)
option(FTB_PYTHON_ENABLE "Enable Python Intafece" on)

message("[OPTION] CMAKE_DEBUG_OPT: ${CMAKE_DEBUG_OPT} ")
message("[OPTION] FTB_PYTHON_ENABLE: ${FTB_PYTHON_ENABLE} ")

# message:デバッグ用途のためコンソールに出力する
if (CMAKE_DEBUG_MSG)
    message("Start /CMake")
endif ()

#----------------------
# Pybind11のパッケージ確認
#----------------------

if (FTB_PYTHON_ENABLE)
    # Pybind11の利用時には直接add_subdirectoryの指定が必要
    add_subdirectory(ext/pybind11)
    message("pybind11_FOUND: ${pybind11_FOUND}")
endif()

# 非推奨コマンド
# 定義したライン以降の全てのターゲットが指定したディレクトリをインクルードしてしまう
# んがっ、Mitsubaでは利用されている...!
# include_directories(${CMAKE_SOURCE_DIR}/include)

#---------------------
# Pythonパッケージの確認
#---------------------

# -DPYTHON_INCLUDE_DIR=$(python3 -c "from distutils.sysconfig import get_python_inc; print(get_python_inc())")  \
# -DPYTHON_LIBRARY=$(python3 -c "import distutils.sysconfig as sysconfig; print(sysconfig.get_config_var('LIBDIR'))")


if (FTB_PYTHON_ENABLE)
    # Python3関連のパスを取得
    # https://cmake.org/cmake/help/latest/module/FindPython3.html#module:FindPython3
    find_package (Python3 COMPONENTS Interpreter Development)
    message("Python3_FOUND: ${Python3_FOUND}")
    message("Python3_EXECUTABLE: ${Python3_EXECUTABLE}")
    message("Python3_SITE_LIB: ${Python3_SITELIB}")
    # Python関連のライブラリが依存する共有ライブラリの保存先
    set(PYTHON_LIBRARY_PATH /usr/local/lib/futaba/python)
    message("PYTHON_LIBRARY_PATH: ${PYTHON_LIBRARY_PATH}")
    # make install実行のタイミングでディレクトリを作成する
    install(DIRECTORY DESTINATION ${PYTHON_LIBRARY_PATH})
    # lddの検索先フォルダにPYTHON_LIBRARY_PATHを追加
    file(WRITE /etc/ld.so.conf.d/futaba.conf ${PYTHON_LIBRARY_PATH})

endif()

#----------------
# サブフォルダの登録
#----------------

add_subdirectory(src)

#add_custom_target(futaba-python)
#set_target_properties(futaba-python PROPERTIES FOLDER futaba-python)
#add_dependencies(futaba-python futaba_py)
#add_dependencies(futaba-python futaba-core)

# 最後にldconfigの実行が必要
#add_custom_command(TARGET mytarget POST_BUILD COMMAND ldconfig VERBATIM)

