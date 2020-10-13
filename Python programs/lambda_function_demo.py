#without usinfg lambda's
def add(x,y):
    return x+y
print(add(1,3))

nums=[1,2,3,4,5]
def is_greater_than_two(x):
    return x > 2
more_than_two=filter(is_greater_than_two,nums)
print(list(more_than_two))

#using lambda's
p=lambda x,y:x+y
print(p(1,3))

more_than_2=filter(lambda x:x > 2,[1,2,3,4,5])
print(list(more_than_2))

li = [5, 7, 22, 97, 54, 62, 77, 23, 73, 61] 
final_list = list(filter(lambda x:(x%2 != 0), li))
final_list2 = list(map(lambda x: x*2 , li))  
print(final_list,final_list2)

from functools import reduce
li = [5, 8, 10, 20, 50, 100] 
sum = reduce((lambda x, y: x + y), li) 
print(sum)

nums =[i for i in range(2,50)] 
for i in range(2, 8): 
    nums = list(filter(lambda x: x == i or x % i, nums))
print(nums)



