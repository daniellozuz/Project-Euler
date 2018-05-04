'''
ProjectEuler
Problem 98 : Anagramic squares
'''

from copy import copy
from math import sqrt

def load_words():
    '''Returns a list of words from .txt file'''
    f = open("words.txt", 'r')
    return f.read()[1:-1].split('","')

def find_anagrams(words):
    '''Returns all pairs of anagrams from a given list as a list of string tuples'''
    pairs = []
    for i1 in range(len(words)):
        for i2 in range(i1, len(words)):
            if is_anagram(words[i1], words[i2]):
                pairs.append((words[i1], words[i2]))
    return pairs

def is_anagram(word1, word2):
    '''Checks whether given words are anagrams'''
    return word1 != word2 and sorted(word1) == sorted(word2)

def make_associations(letters, firsts, forbidden):
    '''Returns a list of possible associations of numbers with letters (dictionaries)'''
    enums = []
    if len(letters) == 1:
        return [{letters[0] : n} for n in range(10) if n not in forbidden and not (n == 0 and (letters[0] in firsts))]
    else:
        for n in range(10):
            if n not in forbidden and not (n == 0 and (letters[0] in firsts)):
                for ele in make_associations(letters[1:], firsts, forbidden + [n]):
                    if ele != None:
                        enums.append(dict(list({letters[0] : n}.items()) + list(ele.items())))
        return enums

def word_value(word, d):
    '''Returns a value associated with given word according to given dictionary'''
    value = 0
    mult = 1
    for letter in reversed(word):
        value += mult * d[letter]
        mult *= 10
    return value

def is_square(number):
    '''Checks whether given number is a square of some positive integer'''
    return int(sqrt(number))**2 == number

def test():
    print(make_associations(['A'], ['A'], []))
    print(make_associations(['A', 'T', 'C'], ['A', 'C'], []))
    print(make_associations(['C', 'E', 'N', 'T', 'R'], ['C', 'R'], []))

def result():
    solution = 0
    words = load_words()
    anagrams = find_anagrams(words)
    for (word1, word2) in anagrams:
        dicts = make_associations(list(set(list(word1))), [word1[0], word2[0]], [])
        for d in dicts:
            val1 = word_value(word1, d)
            val2 = word_value(word2, d)
            if is_square(val1) and is_square(val2):
                if val1 > solution or val2 > solution:
                    solution = max(val1, val2)
    return solution


print(result())
