# pybind 学习
> 封装cpp动态库 到 py 和 c接口的一个简单demo

### 构建c++ 库

进入cpp_so目录


```bash
mkdir build && cd build && cmake .. && make
```

### c++链接c++库测试

```
g++ add_test.cpp -o add_test_c -Lbuild -lcppadd

./add_test
```

### 编译python库

进入py_so目录

```bash
mkdir build && cd build && cmake .. && make
```

### 测试
编译完成会获得一个`{pack-name}.cpython-{python_version}-{system-info}.so`（这个名字是在cmakelist中set_target_properties 步骤设置的）
在这个so的同级目录 输入python 就可以使用`{pack-name}` 来导入包 
例如so名称为`pysoadd.cpython-310-x86_64-linux-gnu.so`

```python
#在so同一层
import pysoadd
```

因为此python so 实际是c++动态库的一个接口，具体实现还是需要c++实现，可以ldd查看此so，是需要依赖`libcppadd.so`的

```bash
$ ldd pysoadd.cpython-310-x86_64-linux-gnu.so 
        linux-vdso.so.1 (0x00007ffcbb1d8000)
        libcppadd.so => ./libcppadd.so (0x00007f1d0b851000)
        libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f1d0b655000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f1d0b63a000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f1d0b448000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f1d0b2f9000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f1d0b8e9000)
```

因此需要将cpp的so加入到`LD_LIBRARY_PATH`中才能正常使用，可以修改`LD_LIBRARY_PATH` 或者将so拷贝到python so 的同级目录


### 补充 

实际使用可以将build过程添加到setup.py中安装到python环境内