'''
ProjectEuler
Problem 51 : Prime digit replacements
'''

from itertools import combinations
import functools

# 12*3*45

def prime_generator(limit):
    for number in range(limit):
        if is_prime(number):
            yield number

@functools.lru_cache(maxsize=32768, typed=False)
def is_prime(number):
    if number < 2:
        return False
    for divisor in range(2, number // 2 + 1):
        if number % divisor == 0:
            return False
    return True

def possible_star_positions(length):
    for i in range(1, length):
        for stars in combinations([n for n in range(length)], i):
            yield stars

def solution():
    import cProfile, pstats, io
    pr = cProfile.Profile()
    pr.enable()
    # ... do something ...
    
    best_count = 0
    for prime in prime_generator(13000):
        for star_positions in possible_star_positions(len(str(prime))):
            # print('Trying positions:', star_positions)
            count = 0
            for n in range(10):
                number = swap_with(str(prime), star_positions, n)
                # print('The swapped number:', number)
                if 0 in star_positions and n == 0:
                    pass
                    # print('Bad number')
                elif is_prime(int(number)):
                    # print('It is a prime!')
                    count += 1
            if count > best_count:
                print('New best count: ', count)
                print('Prime: ', prime, ' Stars: ', star_positions, ' Count: ', count)            
                best_count = count

    pr.disable()
    s = io.StringIO()
    sortby = 'cumulative'
    ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
    ps.print_stats()
    print(s.getvalue())
    

def swap_with(str_prime, star_positions, n):
    new_str_prime = []
    for index in range(len(str_prime)):
        if index not in star_positions:
            new_str_prime.append(str_prime[index])
        else:
            new_str_prime.append(str(n))
    return ''.join(new_str_prime)

if __name__ == '__main__':
    solution()
    possible_star_positions(4)
