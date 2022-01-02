# Author: Lilbox
# Time:2021/12/30 13:26

a=4
b=8
print(a|b)
print(a<<5)
#

num_a=int(input('请输入第一个整数'))
num_b=int(input('请输入另第一个整数'))

print(str(num_a)+'大于等于'+str(num_b) if num_a>=num_b else str(num_a)+'小于'+str(num_b))
r=range(10)
print(r)
print(list(r)

a=0
while a<5:
    a+=2
    pass
print(a)

# for item in 'abcdefg':
#     print(item)
#     pass
# for i in range(10):
#     print(i)
#     pass
#


sum=1+2+3+4+5
print('ddddd',sum)

for item in range(100,999):
     a=item//100
     b=(item-a*100)//10
     c=(item-a*100-b*10)
     if item==a**3+b**3+c**3:
         print(item)
         pass
     pass
for item in range(3):
    pwd=input('请输入密码：')
    if pwd =='888':
        print('密码正确')
        break
    else:
        print('密码不正确')
    pass
else:
    print('对不起叭叭叭')

for i in range(1,10):
    j = 0
    while j!=i:
        print('*',end='\t')
        j+=1
        pass
    print()
pass

j=0
for i in range(1,3):
    if(i==1):
      continue
      j+=1

      pass
    else:
       j-=1
       pass
#     pass
# print(j)
for i in range(5):
    for j in range(1,11):
        if j%2==0:
           continue
        print(j,end='\t')
    print()


lis=[1,'ll',5,6]
# print(lis[0])
# print(lis[-4])

print(lis.index(1,0,1))


pr
int(lis)
lis.append(50)
print(lis)
lis2=['ss','kk']
lis.extend(lis2)
print(lis)
lis.insert(1,90)
print(lis)
lis3=['切片','ppp']
lis[1:4:2]=lis3
# # print(lis)
#
# lis=[80,20,30,40,70,60,70,80,90,80,70,60]
# lis.sort()
# print(lis)
# lis.sort(reverse=True)
# print(lis)
# a=sorted(lis)
# print(a)


lis=[i*i for i in range(1,10)]
print(lis)


items=['Fruits','Book','Other']
prices=[96,85,74]

# lst=zip(items,prices)
# print(dict(lst))
# lis={items:prices for items,prices in zip(items,prices)}
# print(lis)
dic=dict({11:55})
print(dic)

# t=tuple((1,2,3,4,5))
# print(t)
# t=(1)
# print(type(t))
# t1=(1,)
# print(type(t1))

a=[]
print(type(a))
b=''
print(type(b))
c={}
print(type(c))
d=()
print(type(d))




t=(1,[4,5,6],7)
t[1].pop()
print(t)


for item


