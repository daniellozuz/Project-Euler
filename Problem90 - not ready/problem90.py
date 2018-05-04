'''
ProjectEuler
Problem 90 : Cube digit pairs
'''

def filter_sq(digits):
    '''Checks whether digits MIGHT satisfy conditions'''
    condition0 = [[0, 1], [0, 4], [2, 5], [8, 1]]
    for cond in condition0:
        if not cond[0] in digits and not cond[1] in digits:
            return False
    condition69 = [[0, 6, 9], [1, 6, 9], [3, 6, 9], [4, 6, 9]]
    for cond in condition69:
        if not cond[0] in digits and not cond[1] in digits and not cond[2] in digits:
            return False
    return True

def shed_order(arrs):
    '''Removes repetetive arrangements from a list'''
    helper = []
    new_arrs = []
    for arr in arrs:
        number = 0
        for dig in arr:
            number += 10**dig
        if number not in helper:
            helper.append(number)
            new_arrs.append(arr)
    return new_arrs

def filtered():
    '''Returns a list of filtered lists of numbers'''
    numbers = []
    for number in range(10**5, 10**6):
        digits = [int(n) for n in list(str(number))]
        if filter_sq(digits):
            numbers.append(digits)
    return numbers

def allows(n1, n2):
    '''Checks whether arrangements on both cubes satisfy conditions'''
    conditons = [[0, 1], [0, 4], [0, 9], [1, 6], [2, 5], [3, 6], [4, 9], [6, 4], [8, 1]]
    for cond in conditons:
        if cond[0] != 6 and cond[0] != 9 and cond[1] != 6 and cond[1] != 9:
            if not (cond[0] in n1 and cond[1] in n2 or cond[0] in n2 and cond[1] in n1):
                return False
        else:
            if cond[0] == 6 or cond[0] == 9:
                if not (cond[1] in n2 and (6 in n1 or 9 in n1) or cond[1] in n1 and (6 in n2 or 9 in n2)):
                    return False
            if cond[1] == 6 or cond[1] == 9:
                if not (cond[0] in n2 and (6 in n1 or 9 in n1) or cond[0] in n1 and (6 in n2 or 9 in n2)):
                    return False
    return True

def replace69(arrs):
    '''Replaces occurences of 6 with 9'''
    new_arrs = []
    for arr in arrs:
        digs = []
        for dig in arr:
            if dig == 6:
                digs.append(9)
            else:
                digs.append(dig)
        new_arrs.append(digs)
    return new_arrs

def test():
    print(replace69([[4, 5, 6, 7, 8, 9], [9, 8, 7, 6, 5, 5]]))

def solution():
    basic = filtered()
    #print(basic)
    print(len(basic))
    deordered = shed_order(replace69(basic))
    print(deordered)
    print(len(deordered))

    amount = 0
    for i1 in range(len(deordered)):
        for i2 in range(len(deordered)):
            if allows(deordered[i1], deordered[i2]):
                amount += 1
                print("Well done kurwa :)  -> ", deordered[i1], deordered[i2], amount)
            #else:
                #print("A tego sie nie da : -> ", deordered[i1], deordered[i2], amount)


solution()
