'''
ProjectEuler
Problem 17 : Number letter counts
'''

NAMES = {
    '1'    : 'one',
    '2'    : 'two',
    '3'    : 'three',
    '4'    : 'four',
    '5'    : 'five',
    '6'    : 'six',
    '7'    : 'seven',
    '8'    : 'eight',
    '9'    : 'nine',
    '10'   : 'ten',
    '11'   : 'eleven',
    '12'   : 'twelve',
    '13'   : 'thirteen',
    '14'   : 'fourteen',
    '15'   : 'fifteen',
    '16'   : 'sixteen',
    '17'   : 'seventeen',
    '18'   : 'eighteen',
    '19'   : 'nineteen',
    '20'   : 'twenty',
    '30'   : 'thirty',
    '40'   : 'forty',
    '50'   : 'fifty',
    '60'   : 'sixty',
    '70'   : 'seventy',
    '80'   : 'eighty',
    '90'   : 'ninety',
    '100'  : 'hundred',
    '1000' : 'thousand'
}

def pronounce(number):
    '''Returns a string representing a number written out in words'''
    if number == 0:
        return ''
    elif number == 1000:
        string = 'one ' + NAMES[str(number)]
        number = 0
    elif number <= 20 or number == 1000:
        string = NAMES[str(number)]
        number = 0
    elif number >= 100:
        string = NAMES[str(number//100)] + ' hundred '
        number -= 100 * (number//100)
        if number > 0:
            string += 'and '
    else:
        string = NAMES[str(10 * (number//10))] + ' '
        number -= 10 * (number//10)
    return string + pronounce(number)

def test():
    print(pronounce(156))
    print(pronounce(1000))
    print(pronounce(100))

def solution():
    letters = 0
    for n in range(1, 1001):
        letters += len(pronounce(n).replace(' ', ''))
    print(str(letters) + " letters used")


if __name__ == '__main__':
    solution()
