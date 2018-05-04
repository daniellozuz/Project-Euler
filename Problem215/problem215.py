'''
ProjectEuler
Problem 215 : Crack-free Walls
'''

def arrangements(number, elements):
    '''Returns a list of possible decompositions of number into a sum of elements'''
    decompositions = [[]]
    for ele in elements:
        if number >= ele:
            for arr in arrangements(number - ele, elements):
                if sum(arr) + ele == number:
                    decompositions.append([ele] + arr)
    return decompositions

def cracks(bricks):
    '''Returns a list of crack locations, given bricks forming a level'''
    crack_locations = []
    location = 0
    for brik in bricks:
        location += brik
        if location != sum(bricks):
            crack_locations.append(location)
    return crack_locations

def test():
    #print(arrangements(8, [2, 3]))
    #print(arrangements(5, [2, 3]))
    #print(arrangements(15, [2, 3]))
    #print(arrangements(32, [2, 3]))
    #print(len(arrangements(32, [2, 3])))
    #print(cracks([2, 2, 3, 4]))
    #print(cracks([2, 2]))
    #print(cracks([2]))
    print(W(9, 3) == 8)
    print(W(10, 4) == 18)

def W(width, length):
    '''Calculates the number of ways of forming a crack-free width by length wall'''
    possible_next_levels_list = []
    levels = arrangements(width, [2, 3])[1:]
    # Generate a list of level-level dependencies
    for l0 in levels:
        possible_next_levels = []
        for l1 in levels:
            if set(cracks(l0)) & set(cracks(l1)) == set():
                possible_next_levels.append(l1)
        possible_next_levels_list.append(possible_next_levels)
    # Calculate the number of ways of forming a wall (level by level)
    previous_amounts = [1 for i in range(len(levels))]
    for j in range(length - 2):
        amounts = [0 for i in range(len(levels))]
        for i in range(len(levels)):
            for l in possible_next_levels_list[i]:
                amounts[levels.index(l)] += 1 * previous_amounts[i]
        previous_amounts = amounts[:]
    # Check the result
    total = 0
    for i, amount in enumerate(amounts):
        total += amount * len(possible_next_levels_list[i])
    return total


test()
print(W(22, 10))
