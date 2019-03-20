def z(x, y):
    return ((x + y) ** 2 - (100 - x - y) ** 2) ** 0.5


def solution(packing):
    return sum(z(x, y) for x, y in packing) + packing[0][0] + packing[-1][1]


def best_packing():
    balls = [50, 48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49]
    return [(x, y) for x, y in zip(balls[:-1], balls[1:])]


if __name__ == '__main__':
    print(solution(best_packing()))
