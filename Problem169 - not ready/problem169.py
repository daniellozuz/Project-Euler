'''
ProjectEuler
Problem 169 : Exploring the number of different ways a number can be expressed as a sum of powers of 2
'''

'''
10
0 -> 1010 ok
1 -> 0210 ok
1 -> 1002 ok
2 -> 0202 ok
2 -> 0202  x
3 -> 0122 ok
3 -> 0122  x

try doing the same the other way round (start from 0122)
might turn out different for larger numbers
'''

def convert_number_to_array(number):
    '''Converts a number to its binary format represented as a list of digits.'''
    binary_number = bin(number)[2:]
    list_of_digits = []
    for digit in binary_number:
        list_of_digits.append(int(digit))
    return list_of_digits

def show_lists(lists):
    '''Representation of lists for debugging purposes.'''
    for a_list in lists:
        print(a_list)
    print(len(lists))

def show_results_up_to(number):
    '''Shows a list of possible results to the problem (up to 10 ** 9 -> expensive).'''
    lists = [convert_number_to_array(number)]
    new_lists = lists[:]
    previous_lists = []
    while previous_lists != lists:
        print('Number of lists increased to:', len(lists), 'by', len(lists) - len(previous_lists))
        show_lists(lists)
        previous_lists = lists[:]
        previous_new_lists = new_lists[:]
        new_lists = []
        for a_list in previous_new_lists:
            for i in range(len(a_list) - 1):
                new_list = a_list[:]
                if a_list[i] > 0 and a_list[i + 1] == 0:
                    new_list[i] -= 1
                    new_list[i + 1] += 2
                    if new_list not in lists + previous_new_lists + new_lists:
                        new_lists.append(new_list)
        lists.extend(new_lists)
    print('Done!')
    #show_lists(lists)


# Try interpreting what u get. Maybe some connection between the amount and position of 0's and 1's
def solution():
    show_results_up_to(552)
# I do not need to check all the lists, only the new ones! :)

if __name__ == '__main__':
    import timeit
    print(timeit.timeit("solution()", setup="from __main__ import solution", number=1))
