if (CMAKE_DEBUG_MSG)
    message("Start /src/sensors/CMake")
endif ()

set(INC_DIR "../../include/futaba/core")

add_library(futaba-sensor SHARED
        camera.cpp
        pinhole_camera.cpp
        )

# futaba-coreを参照するfutabaもincludeを参照するためPUBLICを指定
# futabaはstbは参照しないためPRIVATEを指定
target_include_directories(futaba-sensor PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(futaba-sensor PRIVATE ${CMAKE_SOURCE_DIR}/ext/stb)

set_target_properties(futaba-sensor PROPERTIES LINKER_LANGUAGE CXX)

# パスの取り扱いに注意
# https://theolizer.com/cpp-school3/cpp-school3-12/
# CMAKE_CURRENT_BINARY_DIR:現在処理している CMakeLists.txt があるフォルダのフルパス
# CMAKE_CURRENT_SOURCE_DIE:現在処理している CMakeLists.txt に対応するビルド・フォルダのフルパス
file(COPY ${CMAKE_CURRENT_BINARY_DIR}/libfutaba-sensor.so DESTINATION ${PYTHON_LIBRARY_PATH})

