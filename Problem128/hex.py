from functools import lru_cache
from itertools import count


def get_ring(number):
    return int(((9 + 12 * (number - 1)) ** 0.5 - 3) / 6 + 1 - 10 ** -10)


def get_neighbours(number):
    if number == 1:
        return [2, 3, 4, 5, 6, 7]

    if number == 2:
        return [8, 9, 3, 1, 7, 19]
    if number == 3:
        return [9, 10, 11, 4, 1, 2]
    if number == 4:
        return [3, 11, 12, 13, 5, 1]
    if number == 5:
        return [1, 4, 13, 14, 15, 6]
    if number == 6:
        return [7, 1, 5, 15, 16, 17]
    if number == 7:
        return [19, 2, 1, 6, 17, 18]

    ring = get_ring(number)
    orientation = number - hex_inside(ring)

    if orientation - 6 * ring == 0:
        return ultimate_tile(number, ring)

    if orientation - 1 - 0 * ring == 0:
        return top_corner(number, ring)
    if orientation - 1 - 1 * ring == 0:
        return left_top_corner(number, ring)
    if orientation - 1 - 2 * ring == 0:
        return left_bottom_corner(number, ring)
    if orientation - 1 - 3 * ring == 0:
        return bottom_corner(number, ring)
    if orientation - 1 - 4 * ring == 0:
        return right_bottom_corner(number, ring)
    if orientation - 1 - 5 * ring == 0:
        return right_top_corner(number, ring)

    if orientation - 1 - 1 * ring < 0:
        return left_top_edge(number, ring)
    if orientation - 1 - 2 * ring < 0:
        return left_edge(number, ring)
    if orientation - 1 - 3 * ring < 0:
        return left_bottom_edge(number, ring)
    if orientation - 1 - 4 * ring < 0:
        return right_bottom_edge(number, ring)
    if orientation - 1 - 5 * ring < 0:
        return right_edge(number, ring)
    if orientation - 1 - 6 * ring < 0:
        return right_top_edge(number, ring)

    print('Error!')
    return None


def ultimate_tile(number, ring):
    return [
        number + 6 * ring + 6,
        number - 6 * ring + 1,
        number - 6 * ring - 6 * (ring - 1) + 1,
        number - 6 * (ring - 1) - 6,
        number - 1,
        number + 6 * ring + 5,
    ]


def top_corner(number, ring):
    return [
        number + 6 * ring,
        number + 6 * ring + 1,
        number + 1,
        number - 6 * (ring - 1),
        number + 6 * ring - 1,
        number + 6 * ring + 6 * (ring + 1) - 1,
    ]


def left_top_corner(number, ring):
    return [
        number + 6 * ring,
        number + 6 * ring + 1,
        number + 6 * ring + 2,
        number + 1,
        number - 6 * (ring - 1) - 1,
        number - 1,
    ]


def left_bottom_corner(number, ring):
    return [
        number - 1,
        number + 6 * ring + 1,
        number + 6 * ring + 2,
        number + 6 * ring + 3,
        number + 1,
        number - 6 * (ring - 1) - 2,
    ]


def bottom_corner(number, ring):
    return [
        number - 6 * (ring - 1) - 3,
        number - 1,
        number + 6 * ring + 2,
        number + 6 * ring + 3,
        number + 6 * ring + 4,
        number + 1,
    ]


def right_bottom_corner(number, ring):
    return [
        number + 1,
        number - 6 * (ring - 1) - 4,
        number - 1,
        number + 6 * ring + 3,
        number + 6 * ring + 4,
        number + 6 * ring + 5,
    ]


def right_top_corner(number, ring):
    return [
        number + 6 * ring + 6,
        number + 1,
        number - 6 * (ring - 1) - 5,
        number - 1,
        number + 6 * ring + 4,
        number + 6 * ring + 5,
    ]


def left_top_edge(number, ring):
    return [
        number + 6 * ring,
        number + 6 * ring + 1,
        number + 1,
        number - 6 * (ring - 1),
        number - 6 * (ring - 1) - 1,
        number - 1,
    ]


def left_edge(number, ring):
    return [
        number - 1,
        number + 6 * ring + 1,
        number + 6 * ring + 2,
        number + 1,
        number - 6 * (ring - 1) - 1,
        number - 6 * (ring - 1) - 2,
    ]


def left_bottom_edge(number, ring):
    return [
        number - 6 * (ring - 1) - 3,
        number - 1,
        number + 6 * ring + 2,
        number + 6 * ring + 3,
        number + 1,
        number - 6 * (ring - 1) - 2,
    ]


def right_bottom_edge(number, ring):
    return [
        number - 6 * (ring - 1) - 3,
        number - 6 * (ring - 1) - 4,
        number - 1,
        number + 6 * ring + 3,
        number + 6 * ring + 4,
        number + 1,
    ]


def right_edge(number, ring):
    return [
        number + 1,
        number - 6 * (ring - 1) - 4,
        number - 6 * (ring - 1) - 5,
        number - 1,
        number + 6 * ring + 4,
        number + 6 * ring + 5,
    ]


def right_top_edge(number, ring):
    return [
        number + 6 * ring + 6,
        number + 1,
        number - 6 * (ring - 1) - 5,
        number - 6 * (ring - 1) - 6,
        number - 1,
        number + 6 * ring + 5,
    ]


@lru_cache(maxsize=None)
def hex_inside(ring):
    if ring == 0:
        return 0
    if ring == 1:
        return 1
    return 6 * (ring - 1) + hex_inside(ring - 1)


@lru_cache(maxsize=None)
def is_prime(number):
    if number < 2:
        return False
    divisor = 2
    limit = int(number ** 0.5)
    while divisor <= limit:
        if number % divisor == 0:
            return False
        divisor += 1
    return True


def has_three_primes(number):
    return sum(is_prime(abs(number - neighbour)) for neighbour in get_neighbours(number)) == 3


def tests():
    assert get_ring(1) == 0
    assert get_ring(7) == 1
    assert get_ring(8) == 2
    assert get_ring(19) == 2
    assert get_ring(20) == 3
    assert get_ring(37) == 3

    assert hex_inside(0) == 0
    assert hex_inside(1) == 1
    assert hex_inside(2) == 7
    assert hex_inside(3) == 19

    assert top_corner(8, get_ring(8)) == [20, 21, 9, 2, 19, 37]
    assert left_top_corner(10, get_ring(10)) == [22, 23, 24, 11, 3, 9]
    assert left_bottom_corner(12, get_ring(12)) == [11, 25, 26, 27, 13, 4]
    assert bottom_corner(14, get_ring(14)) == [5, 13, 28, 29, 30, 15]
    assert right_bottom_corner(16, get_ring(16)) == [17, 6, 15, 31, 32, 33]
    assert right_top_corner(18, get_ring(18)) == [36, 19, 7, 17, 34, 35]

    assert left_top_edge(9, get_ring(9)) == [21, 22, 10, 3, 2, 8]
    assert left_edge(11, get_ring(11)) == [10, 24, 25, 12, 4, 3]
    assert left_bottom_edge(13, get_ring(13)) == [4, 12, 27, 28, 14, 5]
    assert right_bottom_edge(15, get_ring(15)) == [6, 5, 14, 30, 31, 16]
    assert right_edge(17, get_ring(17)) == [18, 7, 6, 16, 33, 34]
    assert right_top_edge(36, get_ring(36)) == [60, 37, 19, 18, 35, 59]

    assert ultimate_tile(19, get_ring(19)) == [37, 8, 2, 7, 18, 36]

    print('Tests passed!')


def simulate():
    counter = 0
    for n in range(10 ** 3):
        if has_three_primes(n + 1):
            counter += 1
            print(counter, n + 1)


def solution(nth):
    counter = 0
    for tile in map(top_tile, count(0)):
        if has_three_primes(tile):
            counter += 1
            if counter == nth:
                return tile
        if has_three_primes(tile + 1):
            counter += 1
            if counter == nth:
                return tile + 1


def top_tile(ring):
    '''Only top tiles and one before them yield positive results'''
    return 3 * ring * (ring + 1) + 1


if __name__ == '__main__':
    tests()

    simulate()

    print(solution(2000))

    print(hex_inside.cache_info())
    print(is_prime.cache_info())
