cmake_minimum_required(VERSION 3.16.3)
project (StudentSystem)

#Target
add_executable(MyStudentSystem MyStudentSystem.cpp
                src/Operations.cpp
                src/Base.cpp
                src/DisplayOperations.cpp)
target_include_directories(MyStudentSystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
