'''
ProjectEuler
Problem 89 : Roman numerals
'''

NUMERALS = {
    'I' : 1,
    'V' : 5,
    'X' : 10,
    'L' : 50,
    'C' : 100,
    'D' : 500,
    'M' : 1000
}

def load_literals():
    '''Reads file roman.txt and returns a list of roman literals as strings'''
    romans = []
    f = open("roman.txt", 'r')
    for line in f:
        romans.append(line[:-1])
    return romans

def to_arabic(roman):
    '''Converts roman numerals into an arabic number'''
    arabic = 0
    i = 0
    while i < len(roman):
        if i < len(roman) - 1 and subtractive(roman[i], roman[i + 1]):
            arabic += interpret(roman[i], roman[i + 1])
            i += 1
        else:
            arabic += NUMERALS[roman[i]]
        i += 1
    return arabic

def subtractive(num1, num2):
    '''Checks whether the two given numbers are a subtractive group'''
    result = num1 == 'I' and num2 == 'V' or\
             num1 == 'I' and num2 == 'X' or\
             num1 == 'X' and num2 == 'L' or\
             num1 == 'X' and num2 == 'C' or\
             num1 == 'C' and num2 == 'D' or\
             num1 == 'C' and num2 == 'M'
    return result

def interpret(num1, num2):
    '''Returns a value of a subtractive group'''
    return NUMERALS[num2] - NUMERALS[num1]

def to_roman(arabic):
    '''Returns a string representation of arabic number in roman numerals'''
    if arabic == 0:
        return ''
    roman = ''
    if arabic >= 1000:
        roman += 'M' * (arabic//1000)
        arabic -= 1000 * (arabic//1000)
    elif arabic >= 900:
        roman += 'CM'
        arabic -= 900
    elif arabic >= 500:
        roman += 'D'
        arabic -= 500
    elif arabic >= 400:
        roman += 'CD'
        arabic -= 400
    elif arabic >= 100:
        roman += 'C' * (arabic//100)
        arabic -= 100 * (arabic//100)
    elif arabic >= 90:
        roman += 'XC'
        arabic -= 90
    elif arabic >= 50:
        roman += 'L'
        arabic -= 50
    elif arabic >= 40:
        roman += 'XL'
        arabic -= 40
    elif arabic >= 10:
        roman += 'X' * (arabic//10)
        arabic -= 10 * (arabic//10)
    elif arabic >= 9:
        roman += 'IX'
        arabic -= 9
    elif arabic >= 5:
        roman += 'V'
        arabic -= 5
    elif arabic >= 4:
        roman += 'IV'
        arabic -= 4
    else:
        roman += 'I' * arabic
        arabic = 0
    return roman + to_roman(arabic)

def test():
    print(to_arabic('MMMCCXX') == 3220)
    print(to_arabic('MMCMCCXXIX') == 3129)
    print(to_arabic('I') == 1)
    print(to_arabic('XLIX') == 49)
    print("-" * 20)
    print(to_roman(1002))
    print(to_roman(1002) == 'MII')
    print(to_roman(1994))
    print(to_roman(1994) == 'MCMXCIV')
    print(to_roman(1767))
    print(to_roman(1767) == 'MDCCLXVII')
    print(to_roman(19))
    print(to_roman(19) == 'XIX')
    print(to_roman(49))
    print(to_roman(49) == 'XLIX')

def solution():
    roman = load_literals()
    saved = 0
    for r in roman:
        print(r + " = " + str(to_arabic(r)) + " = " + to_roman(to_arabic(r)) +\
              " Saved: " + str(len(r) - len(to_roman(to_arabic(r)))))
        saved += len(r) - len(to_roman(to_arabic(r)))
    print("Saved characters: " + str(saved))


if __name__ == '__main__':
    solution()
