'''
ProjectEuler
Problem 62 : Cubic permutations
'''

def is_cube(number):
    '''Checks whether a number is a cube of an integer'''
    return int(round(number**(1. / 3))) ** 3 == number

def permutations(digits):
    '''Returns a list of all permutations of digits'''
    if len(digits) == 1:
        return digits
    per = []
    for d in digits:
        copy = list(digits[:])
        copy.remove(d)
        for perm in permutations(copy):
            per.append(d + perm)
    return per

def digit_occurences(numstr):
    '''Returns a list of numbers of digits in numstr'''
    digits = [0] * 10
    for d in numstr:
        digits[int(d)] += 1
    return digits

def solution():
    cubes = []
    occs = []
    for n in range(1, 50000):
        cubes.append(n**3)
        occ = digit_occurences(str(n**3))
        occs.append(occ)
        if occs.count(occ) == 5:
            for i in range(len(occs)):
                if occs[i] == occ:
                    print(cubes[i])
            break

def test():
    print(is_cube(2146689000) == True)
    print(is_cube(125) == True)
    print(is_cube(126) == False)
    print(permutations(str(1120)))
    print(set(permutations(str(1120))))


solution()
