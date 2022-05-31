#  Tips

(1) gets()
gets函数原型：char*gets(char*buffer);//读取字符到数组：gets(str);str为数组名。
gets函数功能：从键盘上输入字符，直至接受到换行符或EOF时停止，并将读取的结果存放在buffer指针所指向的字符数组
中。
读取的换行符被转换为null值，做为字符数组的最后一个字符，来结束字符串。
注意：gets函数由于没有指定输入字符大小，所以会无限读取，一旦输入的字符大于数组长度，就会发生内存越界，
从而造成程序崩溃或其他数据的错误。

(2)fgets()
fgets函数原型：char *fgets(char *s, int n, FILE *stream);//我们平时可以这么使用：
fgets(str, sizeof(str), stdin);
其中str为数组首地址，sizeof(str)为数组大小，stdin表示我们从键盘输入数据。
fgets函数功能：从文件指针stream中读取字符，存到以s为起始地址的空间里，直到读完N-1个字符，或者读完一行。
注意：调用fgets函数时，最多只能读入n-1个字符。读入结束后，系统将自动在最后加'\0'，并以str作为函数值返回。
借用教程实例，我把char str[100] 改为 char str[5]

(3)c 语言中每种数据类型的输出都有各自的占位符，下面是各种数据类型的输出占位符：
short/int : %d
int a = 1;
printf("这个整数是：%d", a);
long: %ld (long 是 int 得修饰，不能算是一种单独的数据类型，只是比 int 多了四个字节的存储空间)
long long : %lld
char : %c
float/double : %f float 默认是 6 位小数输出；可以在 %f 中控制；例如：%.2f：输出两位小数。
char *s(字符串) ：%s
unsigned: %u (signed:有符号类型， unsigned：无符号类型；默认都是有符号的)
八进制：%o 以 0 开头
十六进制：%x 以 0x 开头
int a = 10;
printf("a的八进制输出是：%o \n", a);//输出是12
printf("a的十六进制输出：%x \n", a);//输出是a
地址值/指针值：%p，* 取指针里地址指向的地方的值，& 取改值存储位置的地址值。
二进制的输出没有占位符，只能通过其他方法。
