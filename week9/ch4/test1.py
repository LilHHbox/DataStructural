# Author: Lilbox
# Time:2022/1/4 13:49
#
# # t=(1,[4,5,6],7)
# # for item in t:
# #     print(item)
#
# t={888,6,2,3,1,9,8,99,4189}
# t.add(11)
# print(t)
# t.update({555,'lll',13})
# print(t)
# t.remove(1)
# print(t)
# t.discard(2)
# print(t)
# t.pop()
# print(t)


# s1={10,20,30,40}
# s2={20,30,40,10}
# print(s1==s2)
# print(s1!=s2)
#
# s3={10,20,30,40,50,60}
# s4={10,20,30,40}
# print(s4.issubset(s3))
# print(s3.issubset(s4)
#
# #
# # se={i*i for i in range(10)}
# # print(se)
# a=[1]
# b=[1]
# print(id(a))
# print(id(b))

#
# s1='abcdefga'
# print(s1.center(20,'*'))
# print(s1.center(20,))
# print(s1.ljust(20,))
# print(s1.rjust(20,))
# print(s1.zfill(20))

# s1='a b c d e f g'
# s2='a,b,c,d,e,f,g'
# lis=s1.split()
# lis2=s2.split(sep=',')
# lis3=s2.split(sep=',',maxsplit=3)
# print(lis)
# print(lis2)
# print(lis3)

# s='hello,hzy,hzy,hzy'
# print(s.replace('hzy','ss'))
# # print(s)
# # print(s.replace('hzy','ss',2))
# lis=['a','b']
# print('A'.join(lis))

#
# #
# # s='aaaa,s'
# # b=s[1:4:]
# # print(b)
#
#
# # a='Lilbox'
# # b=15
# # c='chd'
# # print('我叫%s,我今年%d岁了,家住在%s'%(a,b,c))
# # print('我叫{},我今年{}岁了,家住在{}'.format(a,b,c))
# print('%10d'%99)
# print("%10.5f"%30.14159265)


#
# print('{:.3}'.format(3.14159265))
# print('{:.3f}'.format(3.14159265))
# print('{:10.3f}'.format(3.14159265))


#
# s='天天向上'
# print(s.encode(encoding='GBK'))
# print(s.encode(encoding='UTF-8'))
# byte=s.encode(encoding='GBK')
# print(byte.decode(encoding='GBK'))
#
# def fun(*args):
#     print(args)
#     pass
# fun(10)
# fun(10,20,30)
#
# def fun1(**args):
#     print(args)
#     pass
# fun1(a=10)
# fun1(a=10,b=20,c=30)

#
# try:
#     n1=10
#     n2=20
#     r=n1/n2
#     # print(r)
# except ZeroDivisionError:
#        print('除数为0')
# except ValueError:
#        print('不能将字符串转换为数字')
# except BaseException :
#        print('jj')
# else:
#      print('结果为:',r)
# finally:
#     print('无论是否产生异常，都会被执行代码')
#
# #encoding='utf-8'
# file=open('a.txt','r',encoding='utf-8')
# print(file.readlines())
# file.close()
x=1001
stre=str(x)
le=len(stre)
lis=[]
for i in range(le):
    lis.append((x//10**i)%10)
if(le%2==1):
    lis.remove(lis[(le-1)//2])
    le-=1
    if(le==2):
        if (lis[0] != lis[1]):
            print(False)
        else:
            print(True)

for j in range(le//2):
    if lis[j]!=lis[le-j-1]:
       print(False)
print(True)

# nums=[1,2,3]
#
# print(nums[0]==nums[-3])