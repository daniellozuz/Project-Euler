def iterate(possibilities):
    new_possibilities = [[0 for _ in range(10)] for _ in range(10)]
    for n in range(10):
        for a in range(10):
            for b in range(10):
                if n + a + b <= 9:
                    new_possibilities[n][a] += possibilities[a][b]
    return new_possibilities


def solution():
    possibilities = [[1 for _ in range(10)] for _ in range(10)]
    for _ in range(18):
        possibilities = iterate(possibilities)
    return sum(possibilities[a][b] for a in range(1, 10) for b in range(10))

if __name__ == '__main__':
    print(solution())
