def twosum(nums, target):
    num_dict = {}

    for i,num in enumerate(nums):
        compliment = target - num

        if compliment in num_dict:
            return [num_dict[compliment], i]
        num_dict[num] = i
    return []



# def threesum(nums):
#     nums.sort()
#     result = []

#     for i in range(len(nums) - 2):
#         if(i>0 and nums[i] == nums[i-1]): 
#             continue
#         j = i+1
#         k  = len(nums)-1

#         while(j<k):
#             total = nums[i] +  nums[j] + nums[k]
#             if total == 0:
#                 result.append([nums[i], nums[j], nums[k]])
#                 j+=1
#                 k-=1
#                 while( j < k & nums[j]== nums[j+1] ):
#                     j+= 1
#                 while( j< k & nums[k] == nums[k-1]):
#                     k -=1
#             elif(total < 0):
#                 j+=1
#             else:
#                 k-=1
#     return result




def threesum(nums):
    nums.sort()
    result = []

    for i in range(len(nums) - 2):
        if(i>0 and nums[i]== nums[i-1]):
            continue
        j = i+1
        k = len(nums) -1

        while(j<k):
            total = nums[i] + nums[j] + nums[k]
            if total == 0:
                result.append([nums[i], nums[j], nums[k]])
                j+=1
                k-=1
                while(j<k & nums[j]==nums[j+1]):
                    j+=1
                while(j<k & nums[k]==nums[k-1]):
                    k-=1

            elif(total<0):
                j+=1
            else:
                k-=1
    return result








nums = [-1, 0, 1, 2, -1, -4]
print(threesum(nums))