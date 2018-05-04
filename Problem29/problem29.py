'''
ProjectEuler
Problem 29 : Distinct powers
'''


MAX = 101
terms = set()
for a in range(2, MAX):
    for b in range(2, MAX):
        terms.add(a**b)
print(len(terms))
