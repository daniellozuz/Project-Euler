import sys
from fractions import Fraction


def series(depth):
    return Fraction(1) / (Fraction(2) + series(depth - 1)) if depth >= 0 else Fraction(0)


def approximation(depth):
    return Fraction(1) + series(depth)


def more_digits_in_numerator(fraction):
    return len(str(fraction.numerator)) > len(str(fraction.denominator))


def solution(limit):
    sys.setrecursionlimit(limit + 50)
    return sum(more_digits_in_numerator(approximation(number)) for number in range(limit))


if __name__ == '__main__':
    print(solution(1000))
