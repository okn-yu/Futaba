if (CMAKE_DEBUG_MSG)
    message("Start /src/librender/CMake")
endif ()

set(INC_DIR "../../include/futaba/render")

if (FTB_PYTHON_ENABLE)
    add_subdirectory(python)
endif()