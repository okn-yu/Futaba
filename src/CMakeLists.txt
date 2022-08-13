if (CMAKE_DEBUG_MSG)
    message("Start /src/CMake")
endif ()

# futaba support libraries
add_subdirectory(libcore)
add_subdirectory(librender)
add_subdirectory(sensors)

# futaba executables
add_subdirectory(futaba)



