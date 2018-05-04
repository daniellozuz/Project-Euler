'''
ProjectEuler
Problem 58 : Spiral primes
'''

def spiral(n):
    '''Creates a spiral of numbers with side length n (2 dimensional matrix)'''
    if n == 1:
        return [[1]]
    else:
        core = spiral(n - 2)
        layer = [ele for ele in range((n - 2)**2 + 1, n**2 + 1)]
        result = [[0 for ele in range(n)] for ele in range(n)]
        # Copy core into result
        for i in range(n - 2):
            for j in range(n - 2):
                result[i + 1][j + 1] = core[i][j]
        # Wrap layer around core
        x = 0
        for i in reversed(range(n-1)): # Right -> Top
            result[i][n - 1] = layer[x]
            x += 1
        for i in reversed(range(n-1)): # Top -> Left
            result[0][i] = layer[x]
            x += 1
        for i in range(1, n): # Left -> Bottom
            result[i][0] = layer[x]
            x += 1
        for i in range(1, n): # Bottom -> Right
            result[n - 1][i] = layer[x]
            x += 1
        return result

def show_spiral(s):
    '''Shows a 2d matrix representing a spiral in a formated way'''
    print('\n'.join([''.join(['{:4}'.format(item) for item in row]) for row in s]))

def no_primes(numbers):
    '''Returns the amount of primes in a list'''
    amount = 0
    for n in numbers:
        if is_prime(n):
            amount += 1
    return amount

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

def diagonals(s):
    '''Returns a list of numbers laying on diagonals of spiral s'''
    diag = []
    for i in range(len(s)):
        for j in range(len(s)):
            if i == j:
                diag.append(s[i][j])
            elif i == len(s) - j - 1:
                diag.append(s[i][j])
    return diag

def bad_solution():
    SIZE = 13
    numbers = [ele for ele in range(1, SIZE**2 + 1)]
    spirala = spiral(SIZE)
    show_spiral(spirala)
    whole = no_primes(numbers)
    diag = no_primes(diagonals(spirala))
    print("Number of primes in the whole spiral: " + str(whole))
    print("Number of primes on diagonals: " + str(diag))
    print("Ratio: " + str(int(100*diag/whole)) + "%")

def diagonal_primes_ratio(size):
    '''Prints ratios for consecutive spirals, stops when below 10%'''
    primes = 0
    for i in range(3, size + 1, 2):
        if is_prime(i**2):
            primes += 1
        if is_prime(i**2 - (i - 1)):
            primes += 1
        if is_prime(i**2 - 2*(i - 1)):
            primes += 1
        if is_prime(i**2 - 3*(i - 1)):
            primes += 1
        percentage = int(100*primes/(2*i - 1))
        if percentage < 10:
            print("Ratio: " + str(percentage) + "%")
            break


MAX = 29999
diagonal_primes_ratio(MAX)
