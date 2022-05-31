# 数组寻址方式
将二维数组当作参数的时候，必须指明所有维数大小或者省略第一维的，但是不能省略第二维或者更高维的大小，这是由编译器原理限制的。事实上，编
译器是这样处理数组的：
设有数组 int a[m][n]，如果要访问 a[i][j ]的值，编译器的寻址方式为：
&a[i][j]=&a[0][0]+i*sizeof(int)*n+j*sizeof(int); // 注意 n 为第二维的维数
# 传递数组给函数
void myFunction(int *param)
{
}
void myFunction(int param[10])
{
}
void myFunction(int param[])
{
}
# 关于 double 类型与 float 类型：
printf() 只会看到双精度数，printf 的 %f 格式总是得到 double，所以在 printf() 中使用 %f 跟 %lf
的输出显示效果是一样的。但是对于变量来说，double 类型比 float 类型的精度要高。double
精度更高，是指它存储的小数位数更多，但是输出默认都是 6 位小数，如果你想输出更多小数，可以自己控制，比如 %.10lf 就输出 10 位小数。
所以一般情况下 double 类型的占位符可以用 %lf。

# tips
字符数组的首地址可以用 arrgs ，&arrgs,来表示并且它们相等，
字符串指针&str和str是不同的,当遇到字符串指针时候要注意处理方式;str == str[0];str != &str;

函数的参数中 数组类型参数 int a[]本质是指针 可以直接换成 int *a;

char a[]="runoob"; // 这样赋值之后在结尾会自动加上'\0'。
char a1[]={'r','u','n','o','o','b'}; // 这样赋值是整整好好的6个空间不会自动加上'\0'
