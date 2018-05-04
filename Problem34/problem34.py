'''
ProjectEuler
Problem 34 : Digit factorials
'''

from math import factorial

def is_curious(number):
    '''Checks whether a number is equal to the sum of factorials of its digits'''
    if number <= 2:
        return False
    num_string = str(number)
    result = 0
    for d in num_string:
        result += factorial(int(d))
    return result == number


MAX = 100000 # Just a few
for n in range(MAX):
    if is_curious(n):
        print(n)
