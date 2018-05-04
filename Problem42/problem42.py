'''
ProjectEuler
Problem 42 : Coded triangle numbers
'''

def load_words():
    '''Loads words from .txt file into an array of strings'''
    f = open("words.txt", "r")
    return f.read()[1:-2].split('","')

def word_value(word):
    '''Returns a value associated with a word string'''
    result = 0
    for letter in word:
        result += ord(letter) - ord('A') + 1
    return result

def is_triangle(number):
    '''Checks whether a number is a triangle number'''
    for i in range(1, 50):
        tn = ((i + 1)*i) // 2
        if tn == number:
            return True
    return False

def test():
    print(load_words())
    print(word_value('SKY'))
    print(word_value('YESTERDAY'))
    is_triangle(11)

def solution():
    words = load_words()
    triangles = 0
    for word in words:
        if is_triangle(word_value(word)):
            triangles += 1
    print("There are " + str(triangles) + " triangle numbers")


if __name__ == '__main__':
    solution()
