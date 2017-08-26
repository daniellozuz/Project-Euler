'''
ProjectEuler
Problem 607 : Marsh Crossing
'''

from math import sqrt


def trip_time(path):
    '''Calculates the time of Marsh Crossing.'''
    v = [10, 9, 8, 7, 6, 5, 10]
    s = []
    t = []
    for i in range(len(path) - 1):
        s.append(sqrt((path[i+1][0] - path[i][0])**2 + (path[i+1][1] - path[i][1])**2))
        t.append(s[i] / v[i])

    return sum(t)

def calc_y(x, i):
    '''Calculates y so that point (x,y) is on a line separating regions.'''
    y = x - (50 - 25*sqrt(2)) - (i-1)*10*sqrt(2)
    return y

def create_path(xs):
    '''Returns a list of points as tuples.'''
    A = (0, 0)
    B = (100, 0)
    pts = []
    for i in range(len(xs)):
        pts.append((xs[i], calc_y(xs[i], i + 1)))
    return [A] + pts + [B]

def pick_best(xs, dx):
    '''Try moving every point by dx in both directions and pick minimum from all guesses.'''
    best_xs = []
    best_t = 1000
    for x1 in [xs[0] - dx, xs[0], xs[0] + dx]:
        for x2 in [xs[1] - dx, xs[1], xs[1] + dx]:
            for x3 in [xs[2] - dx, xs[2], xs[2] + dx]:
                for x4 in [xs[3] - dx, xs[3], xs[3] + dx]:
                    for x5 in [xs[4] - dx, xs[4], xs[4] + dx]:
                        for x6 in [xs[5] - dx, xs[5], xs[5] + dx]:
                            xss = [x1, x2, x3, x4, x5, x6]
                            path = create_path(xss)
                            trip_t = trip_time(path)
                            if trip_t < best_t:
                                best_t = trip_t
                                best_xs.clear()
                                best_xs = xss
    return (best_xs, best_t)


# Starting value
xs = [15, 30, 45, 58, 71, 84]
print("Starting xs: " + str(xs))
print("Starting time: " + str(trip_time(create_path(xs))))

for dx in [1/10**ele for ele in range(10)]:
    best_t = 999
    prev_best_t = 1000
    while prev_best_t > best_t:
        prev_best_t = best_t
        (new_xs, best_t) = pick_best(xs, dx)
        if best_t < prev_best_t:
            xs = new_xs

    print("Dx = " + str(dx) + " yielded the following time: " + str(best_t))
