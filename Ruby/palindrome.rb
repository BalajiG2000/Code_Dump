# Palindrome Algorithm

# Sample Input : Enter the number: 292
# Output : The 292 is a palindrome

puts "Enter the number"
num=gets.chomp.to_i

temp=num
sum = 0

while num!=0  #implementation of while loop
    rem=num%10
    num=num/10
    sum=sum*10+rem
end

if(temp==sum)
    puts "The #{temp} is a palindrome"
else
    puts "The #{temp} is not a palindrome"
end
