'''
ProjectEuler
Problem 93 : Arithmetic expressions
'''


from itertools import combinations, product, permutations


digits = '123456789'
operations = '+-*/'
bracket_placements = ['dododod',
                      '(dod)odod',
                      'do(dod)od',
                      'dodo(dod)',
                      '(dodod)od',
                      'do(dodod)',
                      '(dod)o(dod)',
                      '((dod)od)od',
                      '(do(dod))od',
                      'do((dod)od)',
                      'do(do(dod))',]


def how_many_consecutive(numbers):
    expected = 1
    for number in numbers:
        if number == expected:
            expected += 1
        else:
            return expected - 1
    return expected - 1


def solve():
    solution = (0, (), [])
    for nums in combinations(digits, 4):
        integers = set()
        for digs in permutations(nums, 4):
            for bp in bracket_placements:
                for ops in product(operations, repeat=3):
                    equation = ''
                    i = 0
                    j = 0
                    for letter in bp:
                        if letter == 'd':
                            equation += digs[i]
                            i += 1
                        elif letter == 'o':
                            equation += ops[j]
                            j += 1
                        else:
                            equation += letter
                    try:
                        result = eval(equation)
                    except ZeroDivisionError:
                        pass
                    else:
                        if isinstance(result, int) or result.is_integer():
                            result = int(result)
                            if result > 0:
                                integers.add(result)
        integers = sorted(list(integers))
        consecutive = how_many_consecutive(integers)
        print(consecutive, nums, integers)
        if solution[0] < consecutive:
            solution = (consecutive, nums, integers)
    print("Result:", solution)


if __name__ == '__main__':
    import timeit
    print(timeit.timeit("solve()", setup="from __main__ import solve", number=1))
