'''
ProjectEuler
Problem 79 : Passcode derivation
'''

keylog = ['319', '680', '180', '690', '129', '620', '762', '689', '762', '318',
          '368', '710', '720', '710', '629', '168', '160', '689', '716', '731',
          '736', '729', '316', '729', '729', '710', '769', '290', '719', '680',
          '318', '389', '162', '289', '162', '718', '729', '319', '790', '680',
          '890', '362', '319', '760', '316', '729', '380', '319', '728', '716']


def solution1():
    # Seems like the first number is 7 (found only in the first position of all keylogs)
    for n in range(70000000, 80000000):
        if satisfies_all(n, keylog):
            print("Found the passcode : " + str(n))
            break
        if n % 100000 == 0:
            print(n)

def solution2():
    # Instead of such a brute force approach I could try the following:
    #                       (319)                       (append)
    # 319                   (319, 680)                  (append)
    # 319680                (319, 680, 180)             (insert in every possible position) !#1
    # 318096180180                                      (try removing any if possible, one by one)
    # 319680                (319, 680, 180, 690)        (insert in every possible position) !#1
    # 316906908690                                      (try removing any if possible, one by one)
    # ... 

    # Improvement #1: Insert only if the current passcode does not satosfy a new key

    # I am not sure though of validity of such an algorithm (dependence on removal order?)
    # Probably needs to be run in reverse range, yields good results.
    number = ''
    keys_so_far = []
    for k in keylog:
        number = insert_appropriately(number, keys_so_far, k)
        keys_so_far.append(k)
        while number != remove_unnec(number, keys_so_far):
            number = remove_unnec(number, keys_so_far)
    print("Found the passcode : " + str(number))

def satisfies_one(number, key):
    '''Checks whether a number satisfies a given key.'''
    num_str = str(number)
    i = 0
    for c in key:
        while i < len(num_str):
            if num_str[i] == c:
                if c == key[-1]:
                    return True
                break
            i += 1
    return False

def satisfies_all(number, keys):
    '''Checks whether a number satisfies all the given keys.'''
    for key in keys:
        if not satisfies_one(number, key):
            return False
    return True

def insert_appropriately(number, keys_so_far, key):
    '''Returns new number, satisfying keys_so_far and including a new key. Needs to be simplified in the next step (remove unnecessary digits)'''
    if number == []:
        number += key
    elif not contains_any(number, key):
        number += key
    elif satisfies_all(number, keys_so_far + [key]):
        pass
    else:
        number = insert_in_every(number, key)
    return number

def contains_any(number, key):
    '''Checks whether a number contains any digits from a key.'''
    for k in key:
        if k in number:
            return True
    return False

def insert_in_every(number, key):
    new_number = ''
    for n in number:
        if n in key:
            new_number += key
        else:
            new_number += n
    return new_number

def remove_unnec(number, keys):
    '''Removes digits from number, preserving satisfaction of all the keys.'''
    for i in reversed(range(len(number))):
        new_number = number[:]
        new_number = delete_ith(new_number, i)
        if satisfies_all(new_number, keys):
            return new_number
    return number

def delete_ith(string, i):
    '''Deletes i-th character from a string.'''
    return string[:i] + string[i+1:]

def test():
    print(insert_appropriately('319', ['319'], '680'))
    print(insert_appropriately('319', ['319'], '129'))
    print(insert_appropriately('316980', ['319', '680', '690'], '690'))
    print(remove_unnec('3129129', ['319', '129']))
    print(remove_unnec('329129', ['319', '129']))
    print(remove_unnec('39129', ['319', '129']))
    print(remove_unnec('3129', ['319', '129']))
    print(delete_ith('1234', 0))


solution2()
