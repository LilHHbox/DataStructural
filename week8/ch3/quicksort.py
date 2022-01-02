
def quick_sort(nums: list, left: int, right: int) -> None:
	if left < right:
		i = left
		j = right
		# 取第一个元素为枢轴量
		pivot = nums[left]
		while i != j:
			# 交替扫描和交换
			# 从右往左找到第一个比枢轴量小的元素，交换位置
			while j > i and nums[j] > pivot:
				j -= 1
			if j > i:
				# 如果找到了，进行元素交换
				nums[i] = nums[j]
				i += 1
			# 从左往右找到第一个比枢轴量大的元素，交换位置
			while i < j and nums[i] < pivot:
				i += 1
			if i < j:
				nums[j] = nums[i]
				j -= 1
		# 至此完成一趟快速排序，枢轴量的位置已经确定好了，就在i位置上（i和j)值相等
		nums[i] = pivot
		# 以i为枢轴进行子序列元素交换
		quick_sort(nums, left, i-1)
		quick_sort(nums, i+1, right)
