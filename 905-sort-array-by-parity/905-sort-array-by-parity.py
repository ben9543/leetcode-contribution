class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        count=0
        for i in range(0, len(nums)):
            if nums[i]%2 == 0: # If even
                temp = nums[count]
                nums[count] = nums[i]
                nums[i] = temp
                count+=1
        return nums
        