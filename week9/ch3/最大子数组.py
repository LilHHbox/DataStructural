def cross(A, low, mid, high):
    left_sum = -65536
    sum = 0
    max_left = max_right = 0
    # 找左边的最大数组
    i = mid
    while i >= low:
        sum += A[i]
        if sum > left_sum:
            left_sum = sum
            max_left = i
        i-=1
    right_sum = -65536
    sum = 0 # sum重新置为0
    # 找右边的最大数组
    j = mid+1
    while j <= high:
        sum += A[j]
        if sum > right_sum:
            right_sum = sum
            max_right = j
        j+=1
    return max_left,max_right,(left_sum+right_sum)

# 找子数组,返回值为该子数组的 最小索引，最大索引
def find_ma(A, low, high):
    if low == high:
        return low, high, A[low]
    mid = int((low+high)/2)
    left_low, left_high, left_sum = find_ma(A, low, mid)
    right_low, right_high, right_sum = find_ma(A, mid+1, high)
    cross_low, cross_high, cross_sum = cross(A, low, mid, high)
    if left_sum > right_sum and left_sum > cross_sum:
        return left_low, left_high, left_sum
    elif left_sum < cross_sum and right_sum < cross_sum:
        return cross_low, cross_high, cross_sum
    else:
        return right_low, right_high, right_sum
6