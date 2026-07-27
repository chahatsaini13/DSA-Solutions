def twosum(nums, target):
    length = len(nums)
    for i in range(length):
        for j in range(i + 1, length):
            if nums[i] + nums[j] == target:
                return [i, j]

n = 
[2,7,11,15]
t = 9
print(twosum(n, t))
        