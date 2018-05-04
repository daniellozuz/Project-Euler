'''
ProjectEuler
Problem 28 : Number spiral diagonals
'''

def diagonals(size):
    '''Returns a list of numbers laying on diagonals of a spiral of given size'''
    numbers = [1]
    for i in range(3, size + 1, 2):
        numbers.extend([i**2 - 3*(i - 1), i**2 - 2*(i - 1), i**2 - (i - 1), i**2])
    return numbers

SIZE = 1001
print(sum(diagonals(SIZE)))
