cmake_minimum_required(VERSION 3.0)
project(Rocaloid)

if(NOT MSVC)
    #set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
else()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ox /GL")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()
#if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
#    add_definitions(-D_GLIBCXX_DEBUG)
#endif()
add_definitions(-D_FILE_OFFSET_BITS=64)

file(GLOB_RECURSE ROCALOID_SRC_SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.cpp")
add_executable(Rocaloid ${ROCALOID_SRC_SOURCES})

set_target_properties(Rocaloid PROPERTIES
    CXX_STANDARD 11
    POSITION_INDEPENDENT_CODE ON
)

if(NOT MSVC)
    target_link_libraries(Rocaloid PUBLIC m)  # Math library
endif()

add_subdirectory(lib/ooura-fft)
target_link_libraries(Rocaloid PUBLIC ooura-fft)
add_subdirectory(lib/SPTK-3.8-extracted)
target_link_libraries(Rocaloid PUBLIC SPTK)
add_subdirectory(lib/libWinTF8)
target_link_libraries(Rocaloid PUBLIC wintf8)
add_subdirectory(lib/libsndfile-1.0.25)
target_link_libraries(Rocaloid PUBLIC sndfile)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")  # Test subproject
    install(TARGETS Rocaloid
        RUNTIME DESTINATION "bin"
        LIBRARY DESTINATION "lib"
        ARCHIVE DESTINATION "lib"
    )
endif()

enable_testing()
add_subdirectory("tests")

