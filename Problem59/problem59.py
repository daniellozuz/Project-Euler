'''
ProjectEuler
Problem 59 : XOR decryption
'''

def load_cipher():
    '''Returns cipher from .txt file as a string'''
    string = ''
    f = open("cipher.txt", "r")
    for n in f.read()[:-1].split(','):
        string += chr(int(n))
    return string

def encr(message, password):
    '''Returns a message encrypted with password'''
    encrypted = ''
    length = len(password)
    for i in range(len(message)):
        encrypted += chr(ord(message[i]) ^ ord(password[i % length]))
    return encrypted

def show_message(message):
    '''Prints message in readable format (special characters printed as %)'''
    new_message = ''
    for m in message:
        if m.isalpha():
            new_message += m
        else:
            new_message += ' '
    print(new_message)

def count_common_words(message):
    '''Counts how many of common English words appear in message'''
    total = 0
    words = ['the', 'be', 'and', 'of', 'a', 'in', 'to', 'have', 'it', 'I',
             'that', 'for', 'you', 'he', 'with', 'on', 'do', 'say', 'this', 'they']
    words = [' ' + w + ' ' for w in words]
    for word in words:
        if word in message:
            total += 1
    return total

def char_range(c1, c2):
    '''Generates the characters from 'c1' to 'c2', inclusive'''
    for c in range(ord(c1), ord(c2) + 1):
        yield chr(c)

def test():
    print(ord('A'))
    print(chr(65))
    print(True ^ True)
    print(ord('A') ^ ord('X'))
    print('x' == "x")
    show_message('Daniel.Zuziak')
    print(count_common_words('To be or not to be') == 2)
    show_message(load_cipher())

def solution():
    START = 'a'
    STOP = 'z'
    MIN_HITS = 5
    cipher = load_cipher()
    for c1 in char_range(START, STOP):
        for c2 in char_range(START, STOP):
            for c3 in char_range(START, STOP):
                decrypted_cipher = encr(cipher, c1 + c2 + c3)
                if count_common_words(decrypted_cipher) >= MIN_HITS:
                    total = 0
                    show_message(decrypted_cipher)
                    print(decrypted_cipher)
                    for c in decrypted_cipher:
                        total += ord(c)
                    print(total)


solution()
