'''
ProjectEuler
Problem 22 : Names scores
'''


def load_names():
    '''Returns a list of names loaded from a .txt file'''
    f = open("names.txt", "r")
    names = f.read()[1:-2].split('","')
    names.sort()
    return names

def score(name, position):
    '''Returns a score associated with given name and position'''
    value = 0
    for letter in name:
        value += ord(letter) - ord('A') + 1
    return value * position


def solution():
    names = load_names()
    total_score = 0
    for i in range(len(names)):
        total_score += score(names[i], i + 1)
    print("Total score is: " + str(total_score))


solution()
