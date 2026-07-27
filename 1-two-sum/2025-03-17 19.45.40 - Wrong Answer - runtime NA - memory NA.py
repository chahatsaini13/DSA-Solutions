class Solution:  
    def twoSum(self, list1, target):  
        left = 0  
        right = len(list1) - 1  
          
        temSum = 0  
          
        while (left<right):  
            tempSum = list1[left] + list1[right]  
            if tempSum == target:  
                return list((left, right))  
            elif tempSum>target:  
                right -= 1  
            elif tempSum<target:  
                left += 1  
                  
        return list((-1, -1))  
           
list1 = [2,7,11,15]     
target = 9  
obj = Solution()  
print(obj.twoSum(list1, target))  