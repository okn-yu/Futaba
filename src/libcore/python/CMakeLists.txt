if (CMAKE_DEBUG_MSG)
    message("Start /src/libcore/python/CMake")
endif ()

pybind11_add_module(futaba_py SHARED main.cpp vec3_py.cpp image_py.cpp pixel_py.cpp ray_py.cpp)

target_include_directories(futaba_py PRIVATE ${CMAKE_SOURCE_DIR}/ext/pybind11/include)
target_include_directories(futaba_py PRIVATE ${CMAKE_SOURCE_DIR}/ext/stb)
target_include_directories(futaba_py PRIVATE ${CMAKE_SOURCE_DIR}/include)

# futaba-coreを経由してimage.cppなどの実際のオブジェクトファイルとのリンクする
target_link_libraries(futaba_py PRIVATE futaba-core)