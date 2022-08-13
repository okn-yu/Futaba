if (CMAKE_DEBUG_MSG)
    message("Start /src/librender/python/CMake")
endif ()

pybind11_add_module(librender_py SHARED main.cpp aggregate_py.cpp camera_py.cpp hit_py.cpp sphere_py.cpp)

target_include_directories(librender_py PRIVATE ${CMAKE_SOURCE_DIR}/ext/pybind11/include)
target_include_directories(librender_py PRIVATE ${CMAKE_SOURCE_DIR}/ext/stb)
target_include_directories(librender_py PRIVATE ${CMAKE_SOURCE_DIR}/include)

# futaba-coreを経由してimage.cppなどの実際のオブジェクトファイルとのリンクする
target_link_libraries(librender_py PRIVATE futaba-core futaba-sensor)

message(${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS librender_py DESTINATION ${Python3_SITELIB})
