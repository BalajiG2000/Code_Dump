# Write a program which repeatedly reads numbers untill the user enters "done".
# Once "done" is entered, print out total, count, and average of the numbers.
# If the user enters anything other than a number, detect the mistake using try and except and print an error message and skip to next number.

num = 0
tot = 0.0

while True:
    sval = input("Enter a Number: ")
    if sval == 'done':
        break

    try:
        fval = float(sval)
    except:
        print('Error: Data type different')
        continue

    print(fval)
    num = num + 1
    tot = tot + fval
print('ALL DONE')
print('Total:',tot,'Numbers:',num,'Average:',tot/num)
