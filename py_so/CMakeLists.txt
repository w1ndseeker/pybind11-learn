cmake_minimum_required(VERSION 3.10)

project(pysotest)

add_subdirectory(
  ${CMAKE_SOURCE_DIR}/pybind11
)

include_directories(${CMAKE_SOURCE_DIR}/../cpp_so) #只需要头文件

set(CPPADD ${CMAKE_SOURCE_DIR}/../cpp_so/build/libcppadd.so) #链接cpp编译出来的动态库

# 这里的库的名字决定了python import 的时候的名字，同时需要和pybind11中cpp里module的名字一致，不然import会找不到包
add_library(pysoadd
  MODULE
    pyso.cpp
  )

target_link_libraries(pysoadd
  PUBLIC
    ${CPPADD}
    pybind11::module
  )

# 注释掉下面 so名字就会变成libpysoadd.so 当然去掉后也不会影响import 但是加上的话一眼就知道了这是个python包
set_target_properties(pysoadd
  PROPERTIES
    PREFIX "${PYTHON_MODULE_PREFIX}"
    SUFFIX "${PYTHON_MODULE_EXTENSION}"
  )