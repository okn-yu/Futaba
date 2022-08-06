if (CMAKE_DEBUG_MSG)
    message("Start /src/futaba/CMake.")
endif ()

add_executable(futaba futaba.cpp)
#target_include_directories(futaba PRIVATE ${PROJECT_SOURCE_DIR}include)
target_link_libraries(futaba PRIVATE futaba-core)


