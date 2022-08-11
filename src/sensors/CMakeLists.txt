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

