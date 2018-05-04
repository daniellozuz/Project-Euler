'''
ProjectEuler
Problem 37 : Truncatable primes
'''

def is_prime(number):
    '''Checks whether a number is a prime'''
    if number == 2 or number == 3:
        return True
    if number % 2 == 0 or number < 2:
        return False
    for i in range(3, int(number**0.5) + 1, 2):
        if number % i == 0:
            return False
    return True

def is_truncatable_right(number):
    '''Checks whether a number is truncatable from the right'''
    while len(str(number)) > 1:
        number = int(str(number)[:-1])
        if not is_prime(number):
            return False
    return True

def is_truncatable_left(number):
    '''Checks whether a number is truncatable from the left'''
    while len(str(number)) > 1:
        number = int(str(number)[1:])
        if not is_prime(number):
            return False
    return True

def is_truncatable(number):
    '''Checks whether a number is truncatable from both sides'''
    return is_truncatable_left(number) and is_truncatable_right(number)

def solution():
    result = 0
    for number in range(11, 1000001):
        if is_prime(number):
            if is_truncatable(number):
                print(number)
                result += number
    print("The sum of truncatable primes found so far is: " + str(result))


if __name__ == '__main__':
    solution()
