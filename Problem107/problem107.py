'''
ProjectEuler
Problem 107 : Minimal network
'''

def load_network():
    '''Loads a network from .txt file'''
    f = open("network.txt", "r")
    network = []
    for line in f:
        nums = line[:-1].split(',')
        numbers = []
        for n in nums:
            if n != '-':
                numbers.append(int(n))
            else:
                numbers.append('-')
        network.append(numbers)
    return network

def saving(starting_network, network):
    '''Returns the saving performed by removing redundant edges in a given network'''
    sum1 = 0
    sum2 = 0
    for r in range(len(network)):
        for c in range(len(network)):
            if starting_network[r][c] != '-':
                sum1 += starting_network[r][c]
            if network[r][c] != '-':
                sum2 += network[r][c]
    return (sum1 - sum2) // 2

def test():
    starting_network = load_network()
    network = minimize(starting_network)
    print(saving(starting_network, network))

def minimize(starting_network):
    '''Returns a minimized network'''
    network = [['-' for r in range(len(starting_network))] for c in range(len(starting_network))]
    clique = set()
    while clique != set(range(len(starting_network))):
        smallest = 9999
        conn = [-1, -1]
        for r in range(len(starting_network)):
            for c in range(len(starting_network)):
                if clique == set() or\
                        (network[r][c] == '-' and\
                        (r in clique or c in clique) and\
                        (r not in clique or c not in clique)):
                    if starting_network[r][c] != '-' and starting_network[r][c] < smallest:
                        smallest = starting_network[r][c]
                        conn = [r, c]
        network[conn[0]][conn[1]] = starting_network[conn[0]][conn[1]]
        network[conn[1]][conn[0]] = starting_network[conn[0]][conn[1]]
        clique.update(set([conn[0], conn[1]]))
    return network

def show(network):
    '''Prints network in pleasant format'''
    for row in range(len(network)):
        print(network[row])

def solution():
    starting_network = load_network()
    network = minimize(starting_network)
    print(saving(starting_network, network))

if __name__ == '__main__':
    import timeit
    print(timeit.timeit("solution()", setup="from __main__ import solution", number=1))
