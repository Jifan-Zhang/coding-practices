class Solution:
    def twoSum(self, nums, target: int):
        lst=[]
        for n in range(len(nums)):
            lst.append(nums[n])
        lst.sort()
        i=0;j=1
        while(lst[i]+lst[j]<target):
            i+=1;j+=1
        if(lst[i]+lst[j]==target):
            if(lst[i]==lst[j]):
                result=[nums.index(lst[i]),nums.index(lst[j],nums.index(lst[i])+1)]
            else:
                result=[nums.index(lst[i]),nums.index(lst[j])]
            result.sort()
            return(result)
            
            
        i-=1
        while(lst[i]+lst[j]!=target):
            if(lst[i]+lst[j]>target):
                i-=1
            elif(lst[i]+lst[j]<target):
                j+=1
        result=[nums.index(lst[i]),nums.index(lst[j])]
        result.sort()
        return(result)
