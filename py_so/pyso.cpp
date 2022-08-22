#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "cppadd.h"

namespace py = pybind11;

// 此处module 名字需要和cmakelist里的库名一致

PYBIND11_MODULE(pysoadd, m)
{
    //pyadd 就是包装的c++类名，左边是c++的名字，右边是python的方法名，右边可以随便改
    py::class_<ws::cppadd>(m, "pyadd")
        .def(py::init()) // 默认构造函数
        .def(py::init<float, float>()) // 重载的构造函数
        //重载同名方法需要用此方式cast,当然构造函数重载不需要 文档:https://pybind11.readthedocs.io/en/stable/classes.html#overloaded-methods
        .def("sum", static_cast<float (ws::cppadd::*)()>(&ws::cppadd::sum), " member a + b") // 分别是方法返回值，括号里是参数以及对应的c++方法名
        .def("sum", static_cast<float (ws::cppadd::*)(float &_a, float &_b)>(&ws::cppadd::sum), " sum a+b");

}