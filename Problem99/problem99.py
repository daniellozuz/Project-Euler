'''
ProjectEuler
Problem 99 : Largest exponential
'''

def load_numbers():
    '''Reads numbers from a file and returns a list of tuples: (base, exponent)'''
    f = open("base_exp.txt", "r")
    numbers = []
    for line in f:
        tmp = line[:-1].split(',')
        numbers.append((tmp[0], tmp[1]))
    return numbers

def result_len(base, exp):
    '''Returns a tuple: (an order of magnitude, base) of the result: base**exp'''
    base_order = len(str(base)) - 1
    total_order = base_order*exp
    b = base / 10**base_order
    mult = b
    for i in range(exp):
        b *= mult
        if b > 10:
            b /= 10
            total_order += 1
    return (total_order, b)

def test():
    print(result_len(632382, 518061)[0] > result_len(519432, 525806)[0])

def solution():
    numbers = load_numbers()
    best = (0, 0)
    line_number = 0
    for n in numbers:
        line_number += 1
        num = result_len(int(n[0]), int(n[1]))
        if num[0] > best[0]:
            print("Previous best: " + str(best))
            print("New best: " + str(num))
            print("Line: " + str(line_number))
            best = num
        if num[0] == best[0] and num[1] > best[1]:
            print("Previous best: " + str(best))
            print("New best: " + str(num))
            print("Line: " + str(line_number))
            best = num


if __name__ == '__main__':
    solution()
