'''
ProjectEuler
Problem 47 : Distinct primes factors
'''

from math import sqrt, ceil


def prime_factors(number):
    '''Returns a list of prime factors of number n (with repetitions)'''
    factors = []
    while number > 1:
        for div in range(2, number + 1):
            if number % div == 0:
                factors.append(div)
                number //= div
                break
    return factors

def no_of_distinct(numbers):
    '''Returns number of distinct numbers in a list'''
    return len(list(set(numbers)))

def create_primes(max_n):
    '''Creates a list of primes up to n'''
    primes = []
    for number in range(2, max_n):
        if is_prime(number):
            primes.append(number)
    return primes

def is_prime(number):
    '''Checks whether a number n is a prime'''
    if number == 2 or number == 3:
        return True
    if number % 2 == 0 or number < 2:
        return False
    for i in range(3, int(number**0.5) + 1, 2):
        if number % i == 0:
            return False
    return True

def products(numbers, max):
    '''Returns a list of all possible numbers obtained from multiplying the given four numbers, the products being less than max.'''
    result = []
    e1 = 1
    part1 = numbers[0]**e1
    while part1 < max:
        e2 = 1
        part2 = part1 * numbers[1]**e2
        while part2 < max:
            e3 = 1
            part3 = part2 * numbers[2]**e3
            while part3 < max:
                e4 = 1
                part4 = part3 * numbers[3]**e4
                while part4 < max:
                    result.append(part4)
                    e4 += 1
                    part4 = part3 * numbers[3]**e4
                e3 += 1
                part3 = part2 * numbers[2]**e3
            e2 += 1
            part2 = part1 * numbers[1]**e2
        e1 += 1
        part1 = numbers[0]**e1
    return result


MAX = 150000
primes = create_primes(MAX)
print(primes)
print("Amount of primes: " + str(len(primes)))

amount = 0
fours = []
for i1 in range(0, len(primes)):
    for i2 in range(i1 + 1, len(primes)):
        if primes[i1]*primes[i2] > MAX:
            break
        for i3 in range(i2 + 1, len(primes)):
            if primes[i1]*primes[i2]*primes[i3] > MAX:
                break
            for i4 in range(i3 + 1, len(primes)):
                if primes[i1]*primes[i2]*primes[i3]*primes[i4] > MAX:
                    break
                fours.extend(products([primes[i1], primes[i2], primes[i3], primes[i4]], MAX))
                amount += 1
print(amount)
fours.sort()
print(fours)

prev = 0
streak = 1
for number in fours:
    if number == prev + 1:
        streak += 1
    else:
        streak = 1
    prev = number
    if streak == 4:
        print("Streak of 4 found!")
        print("The last one of them is: " + str(number))
