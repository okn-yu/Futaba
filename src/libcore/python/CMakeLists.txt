if (CMAKE_DEBUG_MSG)
    message("Start /src/libcore/python/CMake")
endif ()

pybind11_add_module(futaba_py SHARED main.cpp vec3_py.cpp image_py.cpp pixel_py.cpp ray_py.cpp)
#pybind11_add_module(futaba_py MODULE main.cpp vec3_py.cpp image_py.cpp pixel_py.cpp ray_py.cpp)

target_include_directories(futaba_py PRIVATE ${CMAKE_SOURCE_DIR}/ext/pybind11/include)
target_include_directories(futaba_py PRIVATE ${CMAKE_SOURCE_DIR}/ext/stb)
target_include_directories(futaba_py PRIVATE ${CMAKE_SOURCE_DIR}/include)

# futaba-coreを経由してimage.cppなどの実際のオブジェクトファイルとのリンクする
target_link_libraries(futaba_py PUBLIC futaba-core)

pybind11_extension(futaba_py)
pybind11_strip(futaba_py)

# Pythonのサードパーティ用のライブラリにインストール
# インストールにはmakeとは別のmake installコマンドの実行が必要
# make futaba_py
# make install futaba_py
#add_dependencies(futaba_py futaba-core)
install(TARGETS futaba_py DESTINATION ${Python3_SITELIB})
