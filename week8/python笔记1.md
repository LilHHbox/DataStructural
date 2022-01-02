#### print

 

//输出再显示器中

输出数字不加引号

输出字符串要加引号（加引号的意思是告诉计算机引号里面的东西不用理解，直接输出就行）

//输出在文件中

EX:

fp=open('D:\python代码\PycharmProjects/text.txt','a+')//文件不存在就创建文件，存在就再原文件后面追加

print('520',file=fp)

fp.close()

 

 

 

#### 转义字符

反斜杠+想要实现转移功能的首字母

(/，'，"这三中特殊类型的符号再字符串中时，要加个反斜杠转换含义）

//

/'

/"

 

 

/n    换行

/r    回车

/t    水平制表符

/b    退格

 

#### 变量

由三部分组成：

标识：对象存储的内存地址，使用内置函数id来获取

类型:通过函数type来获取

值

 

#### 浮点数精确计算

导入模块：

From decimal import Decimal

print(Decimal('1.1')+Decimal('2.2'))

 

数据类型转换：str() int() float()

age=20

print(float(age))

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

20.0

 

Input()//默认输入的是字符串类型

a=input('请输入一个加数')

b=input('请输入另一个加数')

print(a+b)

print(int(a)+int(b))

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

请输入一个加数2

请输入另一个加数3

23

5

 

#### 运算：

幂运算**

除法运算/

整除运算// 一正一负向下取整

print(2**3)

print(2//3)

print(2/3)

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

8

0

0.6666666666666666

 

print(8//-3)

print(-8//3)//一正一负向下取整

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

-3

-3

 

取余运算% 一正一负：被除数-除数*商

print(8%-3)

print(-8%3)

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

-1

1

 

a+=b  :  a=a+b

 

 

#### 比较运算符：

\>,<,>=,<=,== 对象的value的比较

is ,is not 对象的id做比较

a,b=10,20

print(a>b)

print(a is not b)

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

False

True

 

位运算符  将数据转成二进制进行计算

按位与& 按位或|

左移位运算符<< : 高位溢出舍弃，低位补0

右移位运算符>> : 低位溢出舍弃，高位补0

print(a|b)

print(a<<5)

 

算术运算>按位运算>比较运算>布尔运算

 

#### 对象的布尔值

python一切皆为对象，所有对象都有一个布尔值

以下对象的布尔值为False

False

数值0

None

空字符串

空列表 空元组 空字典 空集合

 

#### 多分支结构

if 条件表达式1

  语句1

elif 条件表达式2 

  语句2

elif 条件表达式N

  语句3

else

  …

条件表达式

是if…else…简写

语法结构：

   x  if  判断条件  else  y

运算规则：

   如果判断条件为true  输出x

​              为flase 输出y

num_a=int(input('请输入第一个整数'))

num_b=int(input('请输入另第一个整数'))

print(str(num_a)+'大于等于'+str(num_b) if num_a>=num_b else str(num_a)+'小于'+str(num_b))

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

请输入第一个整数5

请输入另第一个整数2

5大于等于2

 

#### 循环

range() 默认步长为1，默认从0开始

range(start,stop,step) 创建一个(start,stop)之间的整数序列，步长为step，默认步长为1，默认从0开始

r=range(10)//注意是0-9而不是0-10

print(r)

print(list(r))

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

range(0, 10)

[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

 

 

while 条件表达式：

​       循环体

a=0

While a<5:

​     a+=2

​     pass

print(a)

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

6

 

 

for 自定义变量 in 可迭代对象：

​       循环体 

for item in 'abcdefg':

   print(item)

   pass

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

a

b

c

d

e

f

g

 

break：退出大循环 后续代码都不执行

continue：用于结束此刻这个循环，通常与分支结构中的if一起使用

 

 

 

else和for，while搭配使用时： 如果没有碰到break，就执行else；

碰到break，就不执行else

 

For item in range(3):

   pwd=input('请输入密码：')

   If pwd =='888':

​    print('密码正确')

​    break

  else:

​    print('密码不正确')

else:

​     print('对不起叭叭叭')

 

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

请输入密码：1

密码不正确

请输入密码：1

密码不正确

请输入密码：1

密码不正确

对不起叭叭叭

 

 

 

For I in range(1,4):

   for j in range(1,5):

​      print('*',end='\t')//tab输出要用end 不换行输出

​      pass

   print()

   pass

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

\*    *    *    *    

\*    *    *    *    

\*    *    *    *    

 

 

 

二重循环中的break和continue只用于控制本层循环

 

For i in range(5):

   For j in range(1,11):

​       If j%2==0:

​         break

​       print(j)

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

1

1

1

1

1

For I in range(5):

   for j in range(1,11):

​     If j%2==0:

​       continue

​       print(j,end='\t')

   print()

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

1    3    5    7    9    

1    3    5    7    9    

1    3    5    7    9    

1    3    5    7    9    

1    3    5    7    9    