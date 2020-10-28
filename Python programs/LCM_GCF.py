#take two number's from user
num1=int(input("enter 1st number: "))
num2=int(input("enter 2nd number: "))

greater=max(num1,num2)    #taking the largest number
for i in range(greater,num1*num2+1):    # iterating from greater to the product of num1 and num2
    if i % num1 == 0 and i % num2 == 0 :
        lcm=i
        break
print(f"LCM of {num1} and {num2} is",lcm)

lower=min(num1,num2)    #find the lowest value
for i in range(2,lower):    #In each iteration, we check if our number perfectly divides both the input numbers. If so, we store the number as H.C.F. At the completion of the loop, we end up with the largest number that perfectly divides both the numbers.
    if num1 % i == 0 and num2 % i == 0 :
        gcf=i
print(f"GCF of {num1} and {num2} is",gcf)
