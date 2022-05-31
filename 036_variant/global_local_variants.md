#  全局变量和局部变量在内存中的区别

    全局变量保存在内存的全局存储区中，占用静态的存储单元；局部变量保存在栈中，只有在所在函数被调用时才动态地为变量分配存储单元。
    C语言经过编译之后将内存分为以下几个区域：
（1）栈（stack）：由编译器进行管理，自动分配和释放，存放函数调用过程中的各种参数、局部变量、返回值以及函数返回地址。操作方式类似数据结
构中的栈。
（2）堆（heap）：用于程序动态申请分配和释放空间。C语言中的malloc和free，C++中的new和delete均是在堆中进行的。正常情况下，程序员申
请的空间在使用结束后应该释放，若程序员没有释放空间，则程序结束时系统自动回收。注意：这里的“堆”并不是数据结构中的“堆”。
（3）全局（静态）存储区：分为DATA段和BSS段。DATA段（全局初始化区）存放初始化的全局变量和静态变量；BSS段（全局未初始化区）存放未初始
化的全局变量和静态变量。程序运行结束时自动释放。其中BBS段在程序执行之前会被系统自动清0，所以未初始化的全局变量和静态变量在程序执行之前
已经为0。
（4）文字常量区：存放常量字符串。程序结束后由系统释放。
（5）程序代码区：存放程序的二进制代码。
    显然，C语言中的全局变量和局部变量在内存中是有区别的。C语言中的全局变量包括外部变量和静态变量，均是保存在全局存储区中，占用永久性的
存储单元；局部变量，即自动变量，保存在栈中，只有在所在函数被调用时才由系统动态在栈中分配临时性的存储单元。

# 声明与定义
变量定义：用于为变量分配存储空间，还可为变量指定初始值。程序中，变量有且仅有一个定义。
变量声明：用于向程序表明变量的类型和名字。
定义也是声明，extern 声明不是定义。
定义也是声明：当定义变量时我们声明了它的类型和名字。
extern 声明不是定义：通过使用 extern 关键字声明变量名而不定义它。
[注意]
变量在使用前就要被定义或者声明。
在一个程序中，变量只能定义一次，却可以声明多次。
定义分配存储空间，而声明不会。