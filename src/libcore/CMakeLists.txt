if (CMAKE_DEBUG_MSG)
    message("Start /src/libcore/CMake")
endif ()

set(INC_DIR "../../include/futaba/core")

if (FTB_PYTHON_ENABLE)
    add_subdirectory(python)
endif()

add_library(futaba-core SHARED
        ${INC_DIR}/vec3.h
        #${INC_DIR}/ray.h
        #${INC_DIR}/util.h
        util.cpp # 当然だがヘッダファイルutil.hだけでなく実装本体のutil.cppも指定しないと実行できない
        image.cpp
        )

target_include_directories(futaba-core PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(futaba-core PUBLIC ${CMAKE_SOURCE_DIR}/ext/stb)

set_target_properties(futaba-core PROPERTIES LINKER_LANGUAGE CXX)

