if (CMAKE_DEBUG_MSG)
    message("Start /src/libcore/CMake")
endif ()

set(INC_DIR "../../include/futaba/core")

if (FTB_PYTHON_ENABLE)
    add_subdirectory(python)
endif()

add_library(futaba-core SHARED
        ${INC_DIR}/vec3.h
        util.cpp
        image.cpp
        )

# futaba-coreを参照するfutabaもincludeを参照するためPUBLICを指定
# futabaはstbは参照しないためPRIVATEを指定
target_include_directories(futaba-core PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(futaba-core PRIVATE ${CMAKE_SOURCE_DIR}/ext/stb)

set_target_properties(futaba-core PROPERTIES LINKER_LANGUAGE CXX)

