class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr=float("-inf")
        m=float("-inf")
        for i in nums:
            curr=max(i,i+curr)
            m=max(curr,m)
        return m
