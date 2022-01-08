
def heapsort(list):
	if list!=None:
		if list==1:
			pass
		else:
			for start in range((len(list))//2,-1,-1):#顶层循环第一步，找到堆的根结点
				rootsort(list,start,len(list)-1)
			for end in range(len(list)-1,-1,-1):#顶层循环第二步，讲根结点依次提取并排序
					list[0],list[end]=list[end],list[0]
					end-=1
					rootsort(list,0,end)
	print (list)
def rootsort(list,root,end):#递归函数，对list做最大堆调整
	left=2*root #父结点的左结点
	right=left+1#父结点的右结点
	if left<=end and list[root]<list[left]:#控制左结点边界，判断父结点和左结点的大小
		largest=left#
	else:
		largest=root
	if right<=end and list[largest]<list[right]:#控制右结点边界，判断父结点、右结点和左结点的大小
		largest=right#
	if largest!=root:#如果计算出来的根结点不是初始设置值，则让根结点与初始值互换位置，直至函数满足这三个条件
		list[root],list[largest]=list[largest],list[root]
		rootsort(list,largest,end)#递归函数，终止条件是larger不变
