if (CMAKE_DEBUG_MSG)
    message("Start /src/libcore/python/CMake")
endif ()

pybind11_add_module(futaba_py SHARED main.cpp vec3_py.cpp ${CMAKE_SOURCE_DIR}/include/futaba/core/vec3.h)

target_include_directories(futaba_py PUBLIC ${CMAKE_SOURCE_DIR}/src/)
target_include_directories(futaba_py PUBLIC ${CMAKE_SOURCE_DIR}/ext/pybind11/include)
target_include_directories(futaba_py PUBLIC ${CMAKE_SOURCE_DIR}/include)