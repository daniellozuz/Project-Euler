'''
ProjectEuler
Problem 154 : Exploring Pascal's pyramid
'''

def precompute25(limit):
    '''Returns amount of 2's and 5's constituting a number's factorial up to limit (inclusive)'''
    result = [(0, 0)]
    fives = 0
    twos = 0
    for number in range(1, limit + 1):
        div5 = 5
        while div5 <= limit:
            if number % div5 == 0:
                fives += 1
            div5 *= 5
        div2 = 2
        while div2 <= limit:
            if number % div2 == 0:
                twos += 1
            div2 *= 2
        result.append((twos, fives))
    return result

def solution():
    size = 4000
    amount = 0
    magnitude = 12
    factors = precompute25(size)
    last2, last5 = factors[size]
    for a in range(0, size // 3 + 2):
        for b in range(0, size + 1):
            c = size - a - b
            if c >= a and c >= 0 and b > a:
                if last2 >= factors[a][0] + factors[b][0] + factors[c][0] + magnitude and\
                        last5 >= factors[a][1] + factors[b][1] + factors[c][1] + magnitude:
                    amount += 1
    print("Divisible:", amount)


if __name__ == '__main__':
    import timeit
    print(timeit.timeit("solution()", setup="from __main__ import solution", number=1))
