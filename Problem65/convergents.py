import math
from abc import ABC
from fractions import Fraction


class Base(ABC):
    def convergent(self, limit):
        return Fraction(self.constant()) + self.series(self.approximation(limit))

    def series(self, generator):
        try:
            return Fraction(1) / (next(generator) + self.series(generator))
        except StopIteration:
            return Fraction(0)

    def approximation(self, limit):
        return self.limited_generator(limit)

    def limited_generator(self, limit):
        gen = self.generator()
        while limit > 1:
            limit -= 1
            yield Fraction(next(gen))

    def constant(self):
        raise NotImplementedError

    def generator(self):
        raise NotImplementedError


class Sqrt2(Base):
    def constant(self):
        return 1

    def generator(self):
        while True:
            yield 2


class Sqrt23(Base):
    def constant(self):
        return 4

    def generator(self):
        while True:
            yield 1
            yield 3
            yield 1
            yield 8


class E(Base):
    def constant(self):
        return 2

    def generator(self):
        x = 2
        while True:
            yield 1
            yield x
            yield 1
            x += 2


def solution(limit):
    return sum(int(digit) for digit in str(E().convergent(limit).numerator))


if __name__ == '__main__':
    limit = 10
    print(Sqrt2().convergent(limit) - 2 ** 0.5)
    print(Sqrt23().convergent(limit) - 23 ** 0.5)
    print(E().convergent(limit) - math.e)
    print(solution(100))
