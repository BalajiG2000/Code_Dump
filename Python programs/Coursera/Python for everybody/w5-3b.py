# EXERCISE 3a WITH TRY/EXCEPT USED


# Write a program to prompt the user for hours and rate per hour using input to compute gross pay.
# Pay the hourly rate for the hours up to 40 and 1.5 times the hourly rate for all hours worked above 40 hours.
# Use 45 hours and a rate of 10.50 per hour to test the program (the pay should be 498.75).
# You should use input to read a string and float() to convert the string to a number.
# Do not worry about error checking the user input - assume the user types numbers properly.

hrs = input('Enter Hours:')
rate = input('Enter Rate:')

try:
    fhrs = float(hrs)
    frate = float(rate)
except:
    print('ERROR, Please Use Numerical Input')
    quit()

if fhrs > 40:
    reg = 40 * frate
    incd = (fhrs -40) * (frate * 1.5)
    pay = reg + incd
else:
    pay = fhrs * frate

print('Pay:',pay)
