'''
ProjectEuler
Problem 156 : Counting Digits
'''

def s_of_d(digit, limit):
    '''Computes s(d) stated in a problem'''
    occs = 0
    total = 0
    n = 0
    difference = 0
    while n < limit:
        if difference < -10000001 and n % 10**6 == 0:
            occs += str(n)[:-6].count(digit) * 10**6 + 6 * 10**5
            n += 10**6
            difference = occs - n
        elif difference < -100001 and n % 10**4 == 0:
            occs += str(n)[:-4].count(digit) * 10**4 + 4 * 10**3
            n += 10**4
            difference = occs - n
        elif difference < -1001 and n % 10**2 == 0:
            occs += str(n)[:-2].count(digit) * 10**2 + 2 * 10**1
            n += 10**2
            difference = occs - n
        elif difference > 10000001 and n % 10**6 == 0:
            occs += str(n)[:-6].count(digit) * 10**6 + 6 * 10**5
            n += 10**6
            difference = occs - n
        elif difference > 100001 and n % 10**4 == 0:
            occs += str(n)[:-4].count(digit) * 10**4 + 4 * 10**3
            n += 10**4
            difference = occs - n
        elif difference > 1001 and n % 10**2 == 0:
            occs += str(n)[:-2].count(digit) * 10**2 + 2 * 10**1
            n += 10**2
            difference = occs - n
        else:
            occs += str(n).count(digit)
            difference = occs - n
            if n == occs:
                total += n
            n += 1
    return total

def solution():
    MAX = 100000000000
    total = 0
    for digit in str('123456789'):
        total += s_of_d(digit, MAX)
    print(total)


if __name__ == '__main__':
    import timeit
    print(timeit.timeit("solution()", setup="from __main__ import solution", number=1))
