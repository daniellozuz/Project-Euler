'''
ProjectEuler
Problem 127 : abc-hits
'''

from math import sqrt

def gcd(a, b):
    '''Returns greatest common divisor of the two numbers a and b'''
    if b == 0:
        return a
    return gcd(b, a % b)

def dpf(number):
    '''Returns a set of distinct prime factors of the given number'''
    factors = set()
    divisor = 2
    while number > 1:
        if number % divisor == 0:
            number //= divisor
            factors.add(divisor)
        else:
            divisor += 1
            if divisor > sqrt(number):
                factors.add(number)
                break
    return factors

def product(numbers):
    '''Returns a product of all numbers in a given list'''
    product = 1
    for n in numbers:
        product *= n
    return product

def hit(a, b, c):
    '''Checks whether a triplet of a, b, c is an abc-hit'''
    return gcd(a, b) == 1 and gcd(b, c) == 1 and gcd(a, c) == 1 and\
           product(set(list(dpf(c)))) < c and\
           product(set(list(dpf(b)) + list(dpf(c)))) < c and\
           product(set(list(dpf(a)) + list(dpf(b)) + list(dpf(c)))) < c

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

def gen_num_from_pf(pfs, limit):
    '''Generates all numbers below limit, prime factors of which are listed in pfs'''
    if pfs == []:
        return [1]
    else:
        nums_so_far = set([product(pfs)])
        prev = set()
        while nums_so_far != prev:
            prev = set(list(nums_so_far))
            for p in pfs:
                for n in list(nums_so_far):
                    if n * p < limit:
                        nums_so_far.add(n * p)
    return list(nums_so_far)

def combinations(numbers):
    '''Returns a list of possible divisions of numbers into three lists'''
    containers = []
    for v in vectors(len(numbers)):
        container = [[], [], []]
        for i in range(len(numbers)):
            container[v[i]].append(numbers[i])
        containers.append(container)
    return containers

def vectors(length):
    '''Returns a list of vectors (elements: 0 1 2) of given length'''
    result = []
    if length == 1:
        return [[0], [1], [2]]
    else:
        for v in vectors(length - 1):
            result.append([0] + v)
            result.append([1] + v)
            result.append([2] + v)
    return result

def make_sets(so_far , limit, primes):
    '''Returns lists of lists of primes which product does not exceed limit'''
    results = [[]]
    for p in primes:
        if p not in so_far and (so_far == [] or p > max(so_far)):
            if p * product(so_far) >= limit:
                break
            for ele in make_sets(so_far + [p], limit, primes):
                results.append([p] + ele)
    return results

def observations():
    '''Because GCD of all numbers in a triple is equal to 1 it means that they are coprime.
    Thus they share no common divisors (dpf(a), dpf(b) and dpf(c) are disjoint sets of primes)'''
    MAX = 100
    amount = 0
    sums = 0
    for a in range(1, MAX):
        for b in range(a + 1, MAX):
            c = a + b
            if c < MAX and hit(a, b, c):
                amount += 1
                sums += c
                print((a, b, c, amount, sums))
                print((dpf(a), dpf(b), dpf(c)))

def test():
    for n in range(15):
        print(("X", n, dpf(n)))
    print(dpf(968))
    print(vectors(4))
    print(gen_num_from_pf([7, 11], 1000))
    print(gen_num_from_pf([2, 3, 5], 1000))
    observations()
    print(make_sets([], 25, [2, 3, 5, 7, 11, 13, 17, 19, 23]))
    print(gen_num_from_pf([2], 100))

def solution():
    LIMIT = 120000
    amount = 0
    sums = 0
    primes = []
    for n in range(LIMIT):
        if is_prime(n):
            primes.append(n)
    sets = make_sets([], LIMIT, primes)
    for s in sets:
        if len(s) > 1:
            for comb in combinations(s):
                al = gen_num_from_pf(comb[0], LIMIT)
                bl = gen_num_from_pf(comb[1], LIMIT)
                cl = gen_num_from_pf(comb[2], LIMIT)
                for a in al:
                    for b in bl:
                        for c in cl:
                            if a < b and a + b == c and hit(a, b, c):
                                amount += 1
                                sums += c
                                print((a, b, c, amount, sums))


if __name__ == '__main__':
    import timeit
    print(timeit.timeit("solution()", setup="from __main__ import solution", number=1))
