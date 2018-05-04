'''
ProjectEuler
Problem 21 : Amicable numbers
'''

def proper_divisors(number):
    '''Returns a list of proper divisors of number n (n > 1)'''
    divisors = []
    div = 1
    while div*div <= number:
        if number % div == 0:
            divisors.append(div)
            if div != 1 and div*div != number:
                divisors.append(int(number/div))
        div += 1
    return divisors

def amicable(number1, number2, precomputed_list):
    '''Checks whether the two given numbers are amicable using precomputed list'''
    return number1 == precomputed_list[number2][1] and number2 == precomputed_list[number1][1] and number1 != number2

def precompute_amicables(number):
    '''Returns a list of tuples: (number tested, sum of proper divisors), up to number'''
    amicables = [(0, 0), (1, 0)]
    for n in range(2, number + 1):
        amicables.append((n, sum(proper_divisors(n))))
    return amicables

def test():
    MAX = 10000
    precomputed = precompute_amicables(MAX)
    amicables = set()
    for n1 in range(1, MAX):
        for n2 in range(n1, MAX):
            if amicable(n1, n2, precomputed):
                print("A pair of amicable numbers: " + str(n1) + " : " + str(n2))
                amicables.add(n1)
                amicables.add(n2)
    print(amicables)
    print("Sum: " + str(sum(amicables)))


if __name__ == '__main__':
    import timeit
    print(timeit.timeit("test()", setup="from __main__ import test", number=1))
    