'''
ProjectEuler
Problem 260 : Stone Game
'''

def solution():
    # Create every set possible and type associated with it
    MAX = 60
    every = []
    types = []
    amount = 0
    for a in range(MAX + 1):
        for b in range(a, MAX + 1):
            for c in range(b, MAX + 1):
                amount += 1
                every.append([a, b, c])
                types.append('X')
    types[0] = 'L'
    print(amount)

    for i in range(len(types)):
        if types[i] == 'L':
            print("working ", str(i))
            # Create all possible Wins and mark them in types
            # All 3 increment
            new_piles = every[i][:]
            while max(new_piles) < MAX:
                new_piles[0] += 1
                new_piles[1] += 1
                new_piles[2] += 1
                types[every.index(new_piles, i)] = 'W'
            # Only 1st increment
            new_piles = every[i][:]
            while new_piles[0] < MAX:
                new_piles[0] += 1
                totally_new_piles = sorted(new_piles[:])
                types[every.index(totally_new_piles, i)] = 'W'
            # Only 2nd increment
            new_piles = every[i][:]
            while new_piles[1] < MAX:
                new_piles[1] += 1
                totally_new_piles = sorted(new_piles[:])
                types[every.index(totally_new_piles, i)] = 'W'
            # Only 3rd increment
            new_piles = every[i][:]
            while new_piles[2] < MAX:
                new_piles[2] += 1
                totally_new_piles = sorted(new_piles[:])
                types[every.index(totally_new_piles, i)] = 'W'
            # 1st and 2nd increment
            new_piles = every[i][:]
            while max(new_piles) < MAX:
                new_piles[0] += 1
                new_piles[1] += 1
                totally_new_piles = sorted(new_piles[:])
                types[every.index(totally_new_piles, i)] = 'W'
            # 1st and 3rd increment
            new_piles = every[i][:]
            while max(new_piles) < MAX:
                new_piles[0] += 1
                new_piles[2] += 1
                totally_new_piles = sorted(new_piles[:])
                types[every.index(totally_new_piles, i)] = 'W'
            # 2nd and 3rd increment
            new_piles = every[i][:]
            while max(new_piles) < MAX:
                new_piles[1] += 1
                new_piles[2] += 1
                totally_new_piles = sorted(new_piles[:])
                types[every.index(totally_new_piles, i)] = 'W'
            # Find the next L to be
            if 'X' in types:
                types[types.index('X', i)] = 'L'

    total = 0
    for i in range(len(types)):
        if types[i] == 'L':
            print('-' * 30)
            print((every[i], types[i]))
            print("{0:16b}".format(every[i][0]))
            print("{0:16b}".format(every[i][1]))
            print("{0:16b}".format(every[i][2]))
            print("{0:16b}".format(every[i][2] ^ every[i][1] ^ every[i][0]))
            total += every[i][0] + every[i][1] + every[i][2]
    print(total)


if __name__ == '__main__':
    import timeit
    print(timeit.timeit("solution()", setup="from __main__ import solution", number=1))
