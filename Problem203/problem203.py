'''
ProjectEuler
Problem 203 : Squarefree Binomial Coefficients
'''

def create_pascal_triangle(size):
    '''Returns representation of Pascal's triangle of the given size.'''
    triangle = [[1]]
    for r in range(size-1):
        next_row = []
        next_row.append(1)
        for i in range(len(triangle[r]) - 1):
            next_row.append(triangle[r][i] + triangle[r][i+1])
        next_row.append(1)
        triangle.append(next_row)
    return triangle

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

def generate_primes_squared(limit):
    '''Yields primes squared up to limit.'''
    number = 2
    while number**2 <= limit:
        if is_prime(number):
            yield number**2
        number += 1

def get_distinct_numbers(list_of_lists):
    '''Returns a set of numbers in list of lists.'''
    numbers = set()
    for a_list in list_of_lists:
        for element in a_list:
            numbers.add(element)
    return list(numbers)

def test():
    print(create_pascal_triangle(1))
    print(create_pascal_triangle(2))
    print(create_pascal_triangle(3))
    print(max(max(create_pascal_triangle(51))))
    print((max(max(create_pascal_triangle(51))))**0.25)

def solution():
    '''This would be much faster with factorization of numbers.'''
    triangle = create_pascal_triangle(51)
    distinct_numbers = sorted(get_distinct_numbers(triangle), reverse=True)
    for prime_squared in generate_primes_squared(max(distinct_numbers)):
        for number in distinct_numbers[:]:
            if number < prime_squared:
                break
            if number % prime_squared == 0:
                distinct_numbers.remove(number)
                print("Removed", number, "with", prime_squared)
    print("Squarefree numbers:", distinct_numbers)
    print("Solution:", sum(distinct_numbers))


if __name__ == '__main__':
    import timeit
    print(timeit.timeit("solution()", setup="from __main__ import solution", number=1))
