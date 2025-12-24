cmake_minimum_required(VERSION 3.10)
project(Figures2)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

find_package(fmt REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/source)

set(MAIN_SOURCE main.cpp)
set(TESTS_SOURCE tests.cpp)
set(LIB_SOURCES
    # source/ чет я забыл, что не добавлял .cpp файлы. Ну и ладно.
)

# add_library(figures STATIC ${LIB_SOURCES})
# target_include_directories(figures PUBLIC include)

add_executable(main ${MAIN_SOURCE})# ${LIB_SOURCES})
target_link_libraries(main PUBLIC fmt::fmt)# figures)

add_executable(tests ${TESTS_SOURCE})# ${LIB_SOURCES})
target_link_libraries(tests PUBLIC gtest_main fmt::fmt) # figures)

gtest_discover_tests(tests)
