# Author: Lilbox
# Time:2021/12/22 18:31

count=1
while count<=10:
    player=int(input('请输入你的猜拳：（0表示石头，1表示剪刀，2表示布）'))
    import random
    computer=random.randint(0,2)
if player<0 or player>2:
   print('傻逼重新输')
   pass
elif player==0 and computer == 1:
     print('计算机出的是剪刀\n你赢了')
     pass
elif player==1 and computer==2:
     print('计算机出的是布\n你赢了')
     pass
elif player==2 and computer==0:
     print('计算机出的是石头\n你赢了')
     pass
elif player==computer:
     print('平手')
     pass
else:
     print('你输了')
count+=1



def printbookinfo():
    books=[]#存储所有图书信息
    id=input('请输入编号：每项以空格分隔')
    bookname=input('请输入书名：每项以空格分隔')
    bookpos=input('请输入位置：每项以空格分隔')
idlist=id.split('')
namelist=bookname.split('')
postlist=bookpos.split('')

bookinfo=zip(idlist,namelist,postlist)
for bookitem in bookinfo:
'''
遍历图书信息进行存储
'''
    dictinfo={'编号':bookitem[0],'书名':bookitem[1],'位置':bookitem[2]}
    books.append(dictinfo)
    pass
for item in books:
    print(item)
    pass
pass
printbookinfo()
