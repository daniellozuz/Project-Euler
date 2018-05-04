'''
ProjectEuler
Problem 95 : Amicable chains
'''

MAX = 1000000

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

def precompute_amicables(number):
    '''Returns a list of tuples: (number tested, sum of proper divisors), up to number'''
    amicables = [(0, 0), (1, 0)]
    for n in range(2, number + 1):
        amicables.append((n, sum(proper_divisors(n))))
    return amicables

def traverse(amic, first, visited):
    '''Returns the length of traversed chain'''
    if visited[-1] == 0 or visited[-1] >= MAX:
        return -50000
    if amic[visited[-1]][1] == first:
        return 1
    if amic[visited[-1]][1] in visited[:-1]:
        return -50000
    return 1 + traverse(amic, first, visited + [amic[visited[-1]][1]])

def test():
    amic = precompute_amicables(MAX)
    print(amic)
    print(traverse(amic, 220, [220]))
    print(traverse(amic, 284, [284]))
    print(traverse(amic, 5, [5]))
    print(traverse(amic, 12496, [12496]))

def solution():
    amic = precompute_amicables(MAX)
    print(amic)
    best = 0
    for n in range(1, MAX):
        length = traverse(amic, n, [n])
        if length > best:
            best = length
            print("Starting number: " + str(n) + " Length: " + str(length))



if __name__ == '__main__':
    import timeit
    print(timeit.timeit("solution()", setup="from __main__ import solution", number=1))
    