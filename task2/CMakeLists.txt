cmake_minimum_required(VERSION 3.0)

project(myproject)

make_directory(${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

make_directory(${CMAKE_CURRENT_SOURCE_DIR}/lib)

execute_process(
                  COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/A/preparing.py
                  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/A
               )

add_executable(C ${CMAKE_CURRENT_SOURCE_DIR}/C/main.h ${CMAKE_CURRENT_SOURCE_DIR}/C/main.cpp)

include_directories(
           ${CMAKE_CURRENT_SOURCE_DIR} 
           ${CMAKE_CURRENT_SOURCE_DIR}/A 
           ${CMAKE_CURRENT_SOURCE_DIR}/B 
           ${CMAKE_CURRENT_SOURCE_DIR}/C
)

add_subdirectory(B)

target_link_libraries(C SegmentTree)

find_package(GTest REQUIRED)

add_executable(CTest ${CMAKE_CURRENT_SOURCE_DIR}/C/main_test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/C/test.cpp)

target_link_libraries(CTest SegmentTree)
target_link_libraries(CTest gtest)
target_link_libraries(CTest ${GTEST_LIBRARIES} pthread)

enable_testing()
