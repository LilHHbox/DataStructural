# 列表

列表可以存取多个不同的元素

 

支持切片操作

 

索引：获取单个元素   

//正向索引0到N-1

​     //逆向索引-N到-1

 

lis=[1,'ll',5,6]//列表的正索引和负索引

print(lis[0])

print(lis[-4])

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

1

1

 

Index()//返回元素的索引 入宫存在N个相同的元素，值返回相同元素的第一个元素的索引

​       //不存在 则报错

​     //还可以在指定的start和stop之间进行查找

 

#### 切片：获取列表中多个元素

语法：

列表名[start:stop:step]

lis=[10,20,30,40,50,60,70]

print(lis[0:5:2])

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

0

[10, 30, 50]

 

#### 列表元素增删改

Append()：在列表末尾添加一个元素

Extend():在列表的末尾至少添加一个元素

Insert():在列表任意位置添加一个元素

切片：在列表任意位置至少添加一个元素（从该位置起都切掉 换成要添加的元素）

 

lis=[10,20,30,40,50,60,70,22,22,22]

print(lis)

lis.append(50)

print(lis)

lis2=['ss','kk']

lis.extend(lis2)

print(lis)

lis.insert(1,90)

print(lis)

lis3=['切片','ppp']

lis[1:4:2]=lis3//意思是把从索引为1开始到索引为4结束 步长为2中间的所有元素换为lis3的元素

print(lis)

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

[10, 20, 30, 40, 50, 60, 70, 22, 22, 22]

[10, 20, 30, 40, 50, 60, 70, 22, 22, 22, 50]

[10, 20, 30, 40, 50, 60, 70, 22, 22, 22, 50, 'ss', 'kk']

[10, 90, 20, 30, 40, 50, 60, 70, 22, 22, 22, 50, 'ss', 'kk']

[10, '切片', 20, 'ppp', 40, 50, 60, 70, 22, 22, 22, 50, 'ss', 'kk']

 

 

####  删除

Remove() 一次只删除一个元素

​        重复元素只删除第一个

​        元素不存在报错

Pop()删除一个指定索引位置上的元素

​     指定索引不存在报错

​     不指定索引删除列表中最后一个元素

切片 一次至少删除一个元素

clear()清空列表

del删除列表

lis=[10,20,30,40,50,60,70,80,90,80,70,60]

lis.remove(10)

lis.pop(2)

lis2=lis[1:8:2]//切片操作意味着产生一个新的列表 

print(lis)

print(lis2)

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

[20, 30, 50, 60, 70, 80, 90, 80, 70, 60]

[30, 60, 80, 80]

 

修改：用索引进行修改

 

 

 

#### 列表元素的排序操作

调用sort()方法，列表中的所有元素默认按照从小到大的顺序排列

Reverse=True进行降序排序

lis=[80,20,30,40,70,60,70,80,90,80,70,60]

lis.sort()//在原来基础上改变

print(lis)

lis.sort(reverse=True)

print(lis)

a=sorted(lis)//要产生一个新数组

print(a)

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

[20, 30, 40, 60, 60, 70, 70, 70, 80, 80, 80, 90]

[90, 80, 80, 80, 70, 70, 70, 60, 60, 40, 30, 20]

[20, 30, 40, 60, 60, 70, 70, 70, 80, 80, 80, 90]

 

 

 

#### 列表的生成

lis=[i*i for I in range(1,10)]//表示1到10里面的元素 乘以自己然后输出一个列表

print(lis)

D:\PycharmProjects\Scripts\python.exe D:/python代码/PycharmProjects/test.py

[1, 4, 9, 16, 25, 36, 49, 64, 81]

 