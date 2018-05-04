'''
ProjectEuler
Problem 55 : Lychrel numbers
'''

def is_palindromic(number):
    '''Checks whether a number is palindromic'''
    num_string = str(number)
    rev_num_string = num_string[::-1]
    return num_string == rev_num_string

def is_lychrel(number):
    '''Checks whether a given number is a Lychrel number'''
    LIMIT = 50
    for i in range(LIMIT):
        number += reverse(number)
        if is_palindromic(number):
            return False
    return True

def reverse(number):
    '''Returns a number with its digits in reverse order'''
    num_string = str(number)
    rev_num_string = num_string[::-1]
    return int(rev_num_string)

def test():
    print(is_palindromic(12321) == True)
    print(is_palindromic(123) == False)
    print(is_palindromic(1) == True)

def solution():
    MAX = 10000
    lychrels = 0
    for number in range(1, MAX):
        if is_lychrel(number):
            lychrels += 1
    print("There are " + str(lychrels) + " Lychrel numbers below " + str(MAX))


if __name__ == '__main__':
    solution()
