#  NULL指针
在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。赋为 NULL 
值的指针被称为空指针。

#  数组指针 指针数组(need further attention)
指针数组：表示的是一个由指针变量组成的数组，也就是说其中的元素都是指针变量。
数组指针：表示的是这是个指向数组的指针，那么该指针变量存储的地址就必须是数组的首地址，得是个指向行的地址，如 
a[2][3] 数组中的 a，a+1 等，不能是具体的指向列的地址，如 &a[0][1], &a[1][1] 这类地址。

# 传递指针给函数
能接受指针作为参数的函数，也能接受数组作为参数

# tips
指针的每一次递增，它其实会指向下一个元素的存储单元。
指针的每一次递减，它都会指向前一个元素的存储单元。
指针在递增和递减时跳跃的字节数取决于指针所指向变量数据类型长度，比如 int 就是 4 个字节。

数组名可以看成一个指针常量

用一个指向字符的指针数组来存储一个字符串列表

指针数组：表示的是一个由指针变量组成的数组，也就是说其中的元素都是指针变量。
 
数组指针：表示的是这是个指向数组的指针，那么该指针变量存储的地址就必须是数组的首地址，得是个指向行的地址，如 
a[2][3] 数组中的 a，a+1 等，不能是具体的指向列的地址，如 &a[0][1], &a[1][1] 这类地址。

a+1:数组元素的移动：首地址 + 一个数组元素的大小 
&a+1: 其实加的整个数组大小：首地址 + 数组长度*数组元素大小 

能接受指针作为参数的函数，也能接受数组作为参数

函数指针：*fun1==*&fun1==fun1==&fun1

C 语言不支持在调用函数时返回局部变量的地址，除非定义局部变量为 static 变量。

数组所占存储空间的内存：sizeof（数组名）
数组的大小：sizeof（数组名）/sizeof（数据类型）

优先级：()>[]>*

# 
int main()
{
   char a[5]={'A','B','C','D'};
   char (*p3)[5] = &a;
   char (*p4)[5] = a;
   return 0;
}
上面对p3 和p4 的使用，哪个正确呢？p3+1 的值会是什么？p4+1 的值又会是什么？毫无疑问，p3 和p4 
都是数组指针，指向的是整个数组。&a 是整个数组的首地址，a是数组首元素的首地址，其值相同但意义不同。在C 
语言里，赋值符号“=”号两边的数据类型必须是相同的，如果不同需要显示或隐式的类型转换。p3 
这个定义的“=”号两边的数据类型完全一致，而p4 
这个定义的“=”号两边的数据类型就不一致了。左边的类型是指向整个数组的指针，右边的数据类型是指向单个字符的指针。
在Visual C++6.0 上给出如下警告：warning C4047: 'initializing' : 'char (*)[5]' differs in 
levels of indirection from 'char *'。
还好，这里虽然给出了警告，但由于&a 和a 
的值一样，而变量作为右值时编译器只是取变量的值，所以运行并没有什么问题。不过我仍然警告你别这么用。

