'''
ProjectEuler
Problem 54 : Poker hands
'''


def load_hands():
    '''Returns a list of poker hands from .txt file'''
    f = open("poker.txt", 'r')
    player1 = []
    player2 = []
    for line in f:
        player1.append(line[:-1].split(' ')[0:5])
        player2.append(line[:-1].split(' ')[5:10])
    return (player1, player2)

def full_house(hand):
    '''Checks whether a hand is a full house'''
    values = [v[0] for v in hand]
    return len(set(values)) == 2 and not four_of_a_kind(hand)

def one_pair(hand):
    '''Checks whether a hand is a one pair'''
    values = [v[0] for v in hand]
    return len(set(values)) == 4

def two_pairs(hand):
    '''Checks whether a hand is a two pairs'''
    values = [v[0] for v in hand]
    return len(set(values)) == 3 and not three_of_a_kind(hand)

def three_of_a_kind(hand):
    '''Checks whether a hand is a three of a kind'''
    values = [v[0] for v in hand]
    values.sort()
    return (values[0] == values[1] and values[1] == values[2]) or\
           (values[1] == values[2] and values[2] == values[3]) or\
           (values[2] == values[3] and values[3] == values[4])

def four_of_a_kind(hand):
    '''Checks whether a hand is a four of a kind'''
    values = [v[0] for v in hand]
    values.sort()
    return values[1] == values[2] and values[2] == values[3] and\
           (values[4] == values[2] or values[0] == values[2])

def flush(hand):
    '''Checks whether a hand is a flush'''
    return hand[0][1] == hand[1][1] and hand[0][1] == hand[2][1] and\
           hand[0][1] == hand[3][1] and hand[0][1] == hand[4][1]

def straight(hand):
    '''Checks whether a hand is a straight'''
    sequence = ['A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2']
    values = [v[0] for v in hand]
    for i in range(9):
        if set([s for s in sequence[i:i+5]]) == set(values):
            return True
    return False

def royal_flush(hand):
    '''Checks whether a hand is a royal flush'''
    return flush(hand) and set([v[0] for v in hand]) == set(['A', 'K', 'Q', 'J', 'T'])

def straight_flush(hand):
    '''Checks whether a hand is straight flush'''
    return straight(hand) and flush(hand)

def compare(hand1, hand2):
    '''Checks which hand wins (0 - draw, 1 - first, 2 - second)'''
    if royal_flush(hand1) and not royal_flush(hand2):
        return 1
    elif not royal_flush(hand1) and royal_flush(hand2):
        return 2
    elif royal_flush(hand1) and royal_flush(hand2):
        return 0
    else:
        if straight_flush(hand1) and not straight_flush(hand2):
            return 1
        elif not straight_flush(hand1) and straight_flush(hand2):
            return 2
        elif straight_flush(hand1) and straight_flush(hand2):
            return compare_straight_flushes(hand1, hand2)
        else:
            if four_of_a_kind(hand1) and not four_of_a_kind(hand2):
                return 1
            elif not four_of_a_kind(hand1) and four_of_a_kind(hand2):
                return 2
            elif four_of_a_kind(hand1) and four_of_a_kind(hand2):
                return compare_four_of_a_kind(hand1, hand2)
            else:
                if full_house(hand1) and not full_house(hand2):
                    return 1
                elif not full_house(hand1) and full_house(hand2):
                    return 2
                elif full_house(hand1) and full_house(hand2):
                    return compare_full_house(hand1, hand2)
                else:
                    if flush(hand1) and not flush(hand2):
                        return 1
                    elif not flush(hand1) and flush(hand2):
                        return 2
                    elif flush(hand1) and flush(hand2):
                        return compare_by_value(hand1, hand2)
                    else:
                        if straight(hand1) and not straight(hand2):
                            return 1
                        elif not straight(hand1) and straight(hand2):
                            return 2
                        elif straight(hand1) and straight(hand2):
                            return compare_by_value(hand1, hand2)
                        else:
                            if three_of_a_kind(hand1) and not three_of_a_kind(hand2):
                                return 1
                            elif not three_of_a_kind(hand1) and three_of_a_kind(hand2):
                                return 2
                            elif three_of_a_kind(hand1) and three_of_a_kind(hand2):
                                return compare_three_of_a_kind(hand1, hand2)
                            else:
                                if two_pairs(hand1) and not two_pairs(hand2):
                                    return 1
                                elif not two_pairs(hand1) and two_pairs(hand2):
                                    return 2
                                elif two_pairs(hand1) and two_pairs(hand2):
                                    return compare_two_pairs(hand1, hand2)
                                else:
                                    if one_pair(hand1) and not one_pair(hand2):
                                        return 1
                                    elif not one_pair(hand1) and one_pair(hand2):
                                        return 2
                                    elif one_pair(hand1) and one_pair(hand2):
                                        return compare_one_pair(hand1, hand2)
                                    else:
                                        return compare_by_value(hand1, hand2)

def compare_by_value(hand1, hand2):
    '''Compares hands by their value, used as a helper function in a few comparisons'''
    if hand1 == []:
        return 0
    exchange = {'A' : 14, 'K' : 13, 'Q' : 12, 'J' : 11, 'T' : 10, '9' : 9, '8' : 8, '7' : 7, '6' : 6, '5' : 5, '4' : 4, '3' : 3, '2' : 2}
    values1 = [exchange[v[0]] for v in hand1]
    values2 = [exchange[v[0]] for v in hand2]
    values1.sort()
    values2.sort()
    values1 = values1[::-1]
    values2 = values2[::-1]
    for i in range(5):
        if values1[i] > values2[i]:
            return 1
        elif values1[i] < values2[i]:
            return 2
    return 0

def compare_one_pair(hand1, hand2):
    '''Checks which of the pairs wins'''
    exchange = {'A' : 14, 'K' : 13, 'Q' : 12, 'J' : 11, 'T' : 10, '9' : 9, '8' : 8, '7' : 7, '6' : 6, '5' : 5, '4' : 4, '3' : 3, '2' : 2}
    values1 = [exchange[v[0]] for v in hand1]
    values1.sort()
    if values1[0] == values1[1] or values1[1] == values1[2]:
        pair1 = values1[1]
    else:
        pair1 = values1[3]
    values2 = [exchange[v[0]] for v in hand2]
    values2.sort()
    if values2[0] == values2[1] or values2[1] == values2[2]:
        pair2 = values2[1]
    else:
        pair2 = values2[3]
    if pair1 > pair2:
        return 1
    elif pair1 < pair2:
        return 2
    else:
        return compare_by_value(hand1, hand2)

def compare_two_pairs(hand1, hand2):
    '''Checks which of the two pairs wins'''
    exchange = {'A' : 14, 'K' : 13, 'Q' : 12, 'J' : 11, 'T' : 10, '9' : 9, '8' : 8, '7' : 7, '6' : 6, '5' : 5, '4' : 4, '3' : 3, '2' : 2}
    values1 = [exchange[v[0]] for v in hand1]
    values1.sort()
    values2 = [exchange[v[0]] for v in hand2]
    values2.sort()
    pair11 = values1[1]
    pair12 = values1[3]
    best1 = max(pair11, pair12)
    worst1 = min(pair11, pair12)
    pair21 = values2[1]
    pair22 = values2[3]
    best2 = max(pair21, pair22)
    worst2 = min(pair21, pair22)
    if best1 > best2:
        return 1
    elif best1 < best2:
        return 2
    else:
        if worst1 > worst2:
            return 1
        elif worst1 < worst2:
            return 2
        else:
            return compare_by_value(hand1, hand2)

def compare_three_of_a_kind(hand1, hand2):
    '''Checks which of the three of a kinds wins'''
    sequence = ['A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2']
    values1 = [v[0] for v in hand1]
    values1.sort()
    three1 = values1[2]
    values2 = [v[0] for v in hand2]
    values2.sort()
    three2 = values2[2]
    # Compare Threes
    for s in sequence:
        if three1 == s and not three2 == s:
            return 1
        elif not three1 == s and three2 == s:
            return 2
    return compare_by_value(hand1, hand2)

def compare_full_house(hand1, hand2):
    '''Checks which of the full houses wins'''
    sequence = ['A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2']
    values1 = [v[0] for v in hand1]
    values1.sort()
    if values1[0] == values1[2]:
        three1 = values1[0]
        pair1 = values1[4]
    else:
        three1 = values1[4]
        pair1 = values1[0]
    values2 = [v[0] for v in hand2]
    values2.sort()
    if values2[0] == values2[2]:
        three2 = values2[0]
        pair2 = values2[4]
    else:
        three2 = values2[4]
        pair2 = values2[0]
    # Compare Threes
    for s in sequence:
        if three1 == s and not three2 == s:
            return 1
        elif not three1 == s and three2 == s:
            return 2
    # Compare Pairs
    for s in sequence:
        if pair1 == s and not pair2 == s:
            return 1
        elif not pair1 == s and pair2 == s:
            return 2
    return 0

def compare_straight_flushes(hand1, hand2):
    '''Checks which of the flushes wins'''
    sequence = ['A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2']
    values1 = [v[0] for v in hand1]
    values2 = [v[0] for v in hand2]
    for s in sequence:
        if s in values1 and not s in values2:
            return 1
        elif not s in values1 and s in values2:
            return 2
    return 0

def compare_four_of_a_kind(hand1, hand2):
    '''Checks which of the four of a kind wins'''
    sequence = ['A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2']
    values1 = [v[0] for v in hand1]
    values1.sort()
    if values1[0] == values1[1]:
        four1 = values1[0]
        high1 = values1[4]
    else:
        four1 = values1[4]
        high1 = values1[0]
    values2 = [v[0] for v in hand2]
    values2.sort()
    if values2[0] == values2[1]:
        four2 = values2[0]
        high2 = values2[4]
    else:
        four2 = values2[4]
        high2 = values2[0]
    # Compare Fours
    for s in sequence:
        if four1 == s and not four2 == s:
            return 1
        elif not four1 == s and four2 == s:
            return 2
    # Compare High Card
    for s in sequence:
        if high1 == s and not high2 == s:
            return 1
        elif not high1 == s and high2 == s:
            return 2
    return 0

def test():
    print(royal_flush(['AD', 'QD', 'TD', 'KD', 'JD']) == True)
    print(royal_flush(['AH', 'QD', 'TD', 'KD', 'JD']) == False)
    print(flush(['5H', 'QD', 'TD', 'KD', 'JD']) == False)
    print(flush(['5D', 'QD', 'TD', '2D', 'JD']) == True)
    print(straight(['5D', '6D', '7D', '8D', '9D']) == True)
    print(straight(['2D', '4D', '3C', '5D', '6H']) == True)
    print(straight(['AD', 'KD', 'JC', 'QD', 'TH']) == True)
    print(straight(['5D', 'AC', '7D', '8C', 'AD']) == False)
    print(straight_flush(['5D', 'AC', '7D', '8C', 'AD']) == False)
    print(straight_flush(['5D', '6D', '7D', '8D', '9D']) == True)
    print(one_pair(['5D', '5C', '2H', '9S', '3D']) == True)
    print(two_pairs(['5D', '5C', '5H', '9S', '9D']) == False)
    print(two_pairs(['5D', '5C', '5H', '2S', '9D']) == False)
    print(two_pairs(['5D', '5C', '2H', '2S', '9D']) == True)
    print(three_of_a_kind(['5D', '5C', '5H', '9S', '9D']) == True)
    print(three_of_a_kind(['5D', '3C', '2H', '5S', '9D']) == False)
    print(four_of_a_kind(['5D', '5C', '5H', '5S', '9D']) == True)
    print(four_of_a_kind(['5D', '5C', '5H', '9S', '9D']) == False)
    print(full_house(['5D', '5C', '5H', '9S', '9D']) == True)
    print(full_house(['5D', '5C', '4H', '9S', '9D']) == False)
    print(compare_straight_flushes(['5D', '6D', '7D', '8D', '9D'], ['TD', '6D', '7D', '8D', '9D']) == 2)
    print(compare_straight_flushes(['5D', '6D', '7D', '8D', '9D'], ['5C', '6C', '7C', '8C', '9C']) == 0)
    print(compare_four_of_a_kind(['5D', '5C', '5H', '5S', '9D'], ['5D', '5C', '5H', '5S', 'TD']) == 2)
    print(compare_four_of_a_kind(['5D', '5C', '5H', '5S', '9D'], ['6D', '6C', '6H', '6S', '2D']) == 2)
    print(compare_full_house(['5D', '5C', '5H', '9S', '9D'], ['6D', '6C', '6H', '2S', '2D']) == 2)
    print(compare_full_house(['5D', '5C', '9H', '9S', '9D'], ['6D', '6C', '6H', '2S', '2D']) == 1)
    print(compare_by_value(['5D', '5C', '9H', '9S', '9D'], ['6D', '6C', '6H', '2S', '2D']) == 1)
    print(compare_by_value(['2D', '5C', '9H', '9S', '9D'], ['6D', '6C', 'KH', '2S', '2D']) == 2)
    print(compare_by_value(['2D', '6C', '9H', 'KS', '6D'], ['6D', '6C', 'KH', '2S', '9D']) == 0)
    print(compare(['5H', '5C', '6S', '7S', 'KD'], ['2C', '3S', '8S', '8D', 'TD']) == 2)
    

def solution():
    (player1, player2) = load_hands()
    wins1 = 0
    for i in range(len(player1)):
        verdict = compare(player1[i], player2[i])
        print((player1[i], player2[i], verdict))
        if verdict == 1:
            wins1 += 1
    print("Player one won: " + str(wins1) + " times")


solution()
test()
