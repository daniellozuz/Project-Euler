'''
ProjectEuler
Problem 122 : Efficient exponentiation
'''

def next_sets(numbers, numsofar):
    '''Creates a list of possible next sets of numbers'''
    result = []
    for i1 in range(len(numbers)):
        if numbers[i1] <= 200: # Performance enhancement (we do not care about numbers above 200)
            for i2 in range(i1, len(numbers)):
                if numbers[i2] <= 200: # Performance enhancement (we do not care about numbers above 200)
                    if (numbers[i1]+numbers[i2]) not in numsofar: # Only fasters ways to get to a power are considered.
                        copy = numbers[:]
                        copy.append(numbers[i1] + numbers[i2])
                        copy = list(set(copy))
                        copy.sort()
                        if len(copy) == len(numbers) + 1 and copy not in result:
                            result.append(copy)
    return result

def create_full_level(numbers, numsofar):
    '''Creates a full level of sets of numbers'''
    level = []
    for l in numbers:
        level.extend(next_sets(l, numsofar))
    return remove_repetitions(level)

def remove_repetitions(lolon):
    '''Removes repetitions of lists in a list of lists'''
    new_lolon = []
    for lon in lolon:
        if lon not in new_lolon:
            new_lolon.append(lon)
    return new_lolon

def solution():
    level = [[1]]
    numbers = [1]
    previous_numbers = [1]
    total = 0
    #print(("Level:", level))
    #print(("Numbers so far:", numbers))
    for i in range(11):
        level = create_full_level(level, numbers)
        #print(("Level:", level))
        numbers = set()
        for lon in level:
            for n in lon:
                numbers.add(n)
        numbers = list(numbers)
        numbers.sort()
        print(("Numbers so far:", numbers))
        print(len(numbers))
        for n in numbers:
            if n <= 200:
                if n not in previous_numbers:
                    total += i + 1
        print(("Total:", total))
        previous_numbers = numbers


if __name__ == '__main__':
    import timeit
    print(timeit.timeit("solution()", setup="from __main__ import solution", number=1))
