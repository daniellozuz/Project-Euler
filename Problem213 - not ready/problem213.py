'''
ProjectEuler
Problem 213 : Flea Circus
'''

import decimal

decimal.getcontext().prec = 100
decimal.getcontext().traps[decimal.FloatOperation] = 1
c = decimal.getcontext()
print(decimal.getcontext())
SIZE = 30
BELLS = 1
D = decimal.Decimal

def show(grid):
    '''Prints grid in pleasant format'''
    print('-' * 60, 'GRID', '-' * 60)
    print('\n'.join([' '.join(['{:.2f}'.format(item) for item in row]) for row in grid]))

def next_move(grid):
    '''Returns expected amounts of fleas after one bell'''
    new_grid = [[D(0) for i in range(SIZE)] for j in range(SIZE)]
    for r in range(SIZE):
        for c in range(SIZE):
            if 1 < r < SIZE-2 and 1 < c < SIZE-2:
                new_grid[r][c] += D(1)/D(4) * (grid[r-1][c] + grid[r+1][c] + grid[r][c-1] + grid[r][c+1])
            elif 0 < r < SIZE-1 and 0 < c < SIZE-1:
                if r == 1 and c == 1:
                    new_grid[r][c] += D(1)/D(3) * (grid[r-1][c] + grid[r][c-1]) + D(1)/D(4) * (grid[r+1][c] + grid[r][c+1])
                elif r == 1 and c == SIZE-2:
                    new_grid[r][c] += D(1)/D(3) * (grid[r-1][c] + grid[r][c+1]) + D(1)/D(4) * (grid[r+1][c] + grid[r][c-1])
                elif r == SIZE-2 and c == 1:
                    new_grid[r][c] += D(1)/D(3) * (grid[r+1][c] + grid[r][c-1]) + D(1)/D(4) * (grid[r-1][c] + grid[r][c+1])
                elif r == SIZE-2 and c == SIZE-2:
                    new_grid[r][c] += D(1)/D(3) * (grid[r+1][c] + grid[r][c+1]) + D(1)/D(4) * (grid[r-1][c] + grid[r][c-1])
                elif r == 1:
                    new_grid[r][c] += D(1)/D(3) * grid[r-1][c] + D(1)/D(4) * (grid[r+1][c] + grid[r][c-1] + grid[r][c+1])
                elif c == 1:
                    new_grid[r][c] += D(1)/D(3) * grid[r][c-1] + D(1)/D(4) * (grid[r+1][c] + grid[r-1][c] + grid[r][c+1])
                elif r == SIZE-2:
                    new_grid[r][c] += D(1)/D(3) * grid[r+1][c] + D(1)/D(4) * (grid[r-1][c] + grid[r][c-1] + grid[r][c+1])
                elif c == SIZE-2:
                    new_grid[r][c] += D(1)/D(3) * grid[r][c+1] + D(1)/D(4) * (grid[r+1][c] + grid[r][c-1] + grid[r-1][c])
            else:
                if r == 0 and c == 0:
                    new_grid[r][c] += D(1)/D(3) * (grid[r][c+1] + grid[r+1][c])
                elif r == 0 and c == SIZE-1:
                    new_grid[r][c] += D(1)/D(3) * (grid[r][c-1] + grid[r+1][c])
                elif r == SIZE-1 and c == 0:
                    new_grid[r][c] += D(1)/D(3) * (grid[r][c+1] + grid[r-1][c])
                elif r == SIZE-1 and c == SIZE-1:
                    new_grid[r][c] += D(1)/D(3) * (grid[r][c-1] + grid[r-1][c])
                elif r == 0 and c == 1:
                    new_grid[r][c] += D(1)/D(2) * grid[r][c-1] + D(1)/D(3) * grid[r][c+1] + D(1)/D(4) * grid[r+1][c]
                elif r == 0 and c == SIZE-2:
                    new_grid[r][c] += D(1)/D(2) * grid[r][c+1] + D(1)/D(3) * grid[r][c-1] + D(1)/D(4) * grid[r+1][c]
                elif r == 1 and c == 0:
                    new_grid[r][c] += D(1)/D(2) * grid[r-1][c] + D(1)/D(3) * grid[r+1][c] + D(1)/D(4) * grid[r][c+1]
                elif r == 1 and c == SIZE-1:
                    new_grid[r][c] += D(1)/D(2) * grid[r-1][c] + D(1)/D(3) * grid[r+1][c] + D(1)/D(4) * grid[r][c-1]
                elif r == SIZE-2 and c == 0:
                    new_grid[r][c] += D(1)/D(2) * grid[r+1][c] + D(1)/D(3) * grid[r-1][c] + D(1)/D(4) * grid[r][c+1]
                elif r == SIZE-2 and c == SIZE-1:
                    new_grid[r][c] += D(1)/D(2) * grid[r+1][c] + D(1)/D(3) * grid[r-1][c] + D(1)/D(4) * grid[r][c-1]
                elif r == SIZE-1 and c == 1:
                    new_grid[r][c] += D(1)/D(2) * grid[r][c-1] + D(1)/D(3) * grid[r][c+1] + D(1)/D(4) * grid[r-1][c]
                elif r == SIZE-1 and c == SIZE-2:
                    new_grid[r][c] += D(1)/D(2) * grid[r][c+1] + D(1)/D(3) * grid[r][c-1] + D(1)/D(4) * grid[r-1][c]
                elif r == 0:
                    new_grid[r][c] += D(1)/D(3) * (grid[r][c-1] + grid[r][c+1]) + D(1)/D(4) * grid[r+1][c]
                elif r == SIZE-1:
                    new_grid[r][c] += D(1)/D(3) * (grid[r][c-1] + grid[r][c+1]) + D(1)/D(4) * grid[r-1][c]
                elif c == 0:
                    new_grid[r][c] += D(1)/D(3) * (grid[r-1][c] + grid[r+1][c]) + D(1)/D(4) * grid[r][c+1]
                elif c == SIZE-1:
                    new_grid[r][c] += D(1)/D(3) * (grid[r-1][c] + grid[r+1][c]) + D(1)/D(4) * grid[r][c-1]
                else:
                    assert False, "Fatal error"
    return new_grid

def predict_empty_in_next_move(grid):
    '''Returns expected number of unoccupied squares'''
    amount = D(0)
    for r in range(SIZE):
        for c in range(SIZE):
            if 1 < r < SIZE-2 and 1 < c < SIZE-2:
                amount += (D(3)/D(4))**grid[r-1][c] * (D(3)/D(4))**grid[r+1][c] * (D(3)/D(4))**grid[r][c-1] * (D(3)/D(4))**grid[r][c+1]
            elif 0 < r < SIZE-1 and 0 < c < SIZE-1:
                if r == 1 and c == 1:
                    amount += (D(2)/D(3))**grid[r-1][c] * (D(2)/D(3))**grid[r][c-1] * (D(3)/D(4))**grid[r+1][c] * (D(3)/D(4))**grid[r][c+1]
                elif r == 1 and c == SIZE-2:
                    amount += (D(2)/D(3))**grid[r-1][c] * (D(2)/D(3))**grid[r][c+1] * (D(3)/D(4))**grid[r+1][c] * (D(3)/D(4))**grid[r][c-1]
                elif r == SIZE-2 and c == 1:
                    amount += (D(2)/D(3))**grid[r+1][c] * (D(2)/D(3))**grid[r][c-1] * (D(3)/D(4))**grid[r-1][c] * (D(3)/D(4))**grid[r][c+1]
                elif r == SIZE-2 and c == SIZE-2:
                    amount += (D(2)/D(3))**grid[r+1][c] * (D(2)/D(3))**grid[r][c+1] * (D(3)/D(4))**grid[r-1][c] * (D(3)/D(4))**grid[r][c-1]
                elif r == 1:
                    amount += (D(2)/D(3))**grid[r-1][c] * (D(3)/D(4))**grid[r+1][c] * (D(3)/D(4))**grid[r][c-1] * (D(3)/D(4))**grid[r][c+1]
                elif c == 1:
                    amount += (D(2)/D(3))**grid[r][c-1] * (D(3)/D(4))**grid[r+1][c] * (D(3)/D(4))**grid[r-1][c] * (D(3)/D(4))**grid[r][c+1]
                elif r == SIZE-2:
                    amount += (D(2)/D(3))**grid[r+1][c] * (D(3)/D(4))**grid[r-1][c] * (D(3)/D(4))**grid[r][c-1] * (D(3)/D(4))**grid[r][c+1]
                elif c == SIZE-2:
                    amount += (D(2)/D(3))**grid[r][c+1] * (D(3)/D(4))**grid[r+1][c] * (D(3)/D(4))**grid[r][c-1] * (D(3)/D(4))**grid[r-1][c]
            else:
                if r == 0 and c == 0:
                    amount += (D(2)/D(3))**grid[r][c+1] * (D(2)/D(3))**grid[r+1][c]
                elif r == 0 and c == SIZE-1:
                    amount += (D(2)/D(3))**grid[r][c-1] * (D(2)/D(3))**grid[r+1][c]
                elif r == SIZE-1 and c == 0:
                    amount += (D(2)/D(3))**grid[r][c+1] * (D(2)/D(3))**grid[r-1][c]
                elif r == SIZE-1 and c == SIZE-1:
                    amount += (D(2)/D(3))**grid[r][c-1] * (D(2)/D(3))**grid[r-1][c]
                elif r == 0 and c == 1:
                    amount += (D(1)/D(2))**grid[r][c-1] * (D(2)/D(3))**grid[r][c+1] * (D(3)/D(4))**grid[r+1][c]
                elif r == 0 and c == SIZE-2:
                    amount += (D(1)/D(2))**grid[r][c+1] * (D(2)/D(3))**grid[r][c-1] * (D(3)/D(4))**grid[r+1][c]
                elif r == 1 and c == 0:
                    amount += (D(1)/D(2))**grid[r-1][c] * (D(2)/D(3))**grid[r+1][c] * (D(3)/D(4))**grid[r][c+1]
                elif r == 1 and c == SIZE-1:
                    amount += (D(1)/D(2))**grid[r-1][c] * (D(2)/D(3))**grid[r+1][c] * (D(3)/D(4))**grid[r][c-1]
                elif r == SIZE-2 and c == 0:
                    amount += (D(1)/D(2))**grid[r+1][c] * (D(2)/D(3))**grid[r-1][c] * (D(3)/D(4))**grid[r][c+1]
                elif r == SIZE-2 and c == SIZE-1:
                    amount += (D(1)/D(2))**grid[r+1][c] * (D(2)/D(3))**grid[r-1][c] * (D(3)/D(4))**grid[r][c-1]
                elif r == SIZE-1 and c == 1:
                    amount += (D(1)/D(2))**grid[r][c-1] * (D(2)/D(3))**grid[r][c+1] * (D(3)/D(4))**grid[r-1][c]
                elif r == SIZE-1 and c == SIZE-2:
                    amount += (D(1)/D(2))**grid[r][c+1] * (D(2)/D(3))**grid[r][c-1] * (D(3)/D(4))**grid[r-1][c]
                elif r == 0:
                    amount += (D(2)/D(3))**grid[r][c-1] * (D(2)/D(3))**grid[r][c+1] * (D(3)/D(4))**grid[r+1][c]
                elif r == SIZE-1:
                    amount += (D(2)/D(3))**grid[r][c-1] * (D(2)/D(3))**grid[r][c+1] * (D(3)/D(4))**grid[r-1][c]
                elif c == 0:
                    amount += (D(2)/D(3))**grid[r-1][c] * (D(2)/D(3))**grid[r+1][c] * (D(3)/D(4))**grid[r][c+1]
                elif c == SIZE-1:
                    amount += (D(2)/D(3))**grid[r-1][c] * (D(2)/D(3))**grid[r+1][c] * (D(3)/D(4))**grid[r][c-1]
                else:
                    assert False, "Fatal error"
    return amount


grid = [[D(0) for i in range(SIZE)] for j in range(SIZE)]
grid[0][0] = D(1)
grid[0][2] = D(1)
print(predict_empty_in_next_move(grid))
for _ in range(BELLS-1):
    grid = next_move(grid)
show(grid)
print(predict_empty_in_next_move(grid))
print(D('2.5') ** (D(3)/D(2)))
print(D('2.5') ** D('1.5'))
print(D('2.5') ** D('1.5'))
print(c.power(D('2.5'), D('1.5')))
print(D(3)/D(2))
print(D('1.5'))
print((D(2)/D(3))**D(2))
