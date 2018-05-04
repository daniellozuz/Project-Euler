'''
ProjectEuler
Problem 102 : Trinagle containment
'''

def load_triangles():
    '''Loads a list of triangles from .txt file'''
    f = open("triangles.txt", 'r')
    triangles = []
    for line in f:
        coords = line[:-1].split(',')
        A = (int(coords[0]), int(coords[1]))
        B = (int(coords[2]), int(coords[3]))
        C = (int(coords[4]), int(coords[5]))
        triangles.append([A, B, C])
    return triangles

def find_axes_crossings(A, B):
    '''Returns a list of points crossing Cartesian plane axes between point A and point B'''
    sign = lambda x: x and (1, -1)[x < 0]
    points = []
    if sign(A[0]) == sign(B[0]) and sign(A[1]) == sign(B[1]): # No crossings
        return []
    if abs(sign(A[0]) - sign(B[0])) == 2: # Crossing OY
        points.append((0, A[1] - (A[1] - B[1]) * (abs(A[0]) / (abs(A[0]) + abs(B[0])))))
    if abs(sign(A[1]) - sign(B[1])) == 2: # Crossing OX
        points.append((A[0] + (B[0] - A[0]) * (abs(A[1]) / (abs(A[1]) + abs(B[1]))), 0))
    if sign(A[0]) == 0 or sign(A[1]) == 0: # Point A on axis
        points.append(A)
    if sign(B[0]) == 0 or sign(B[1]) == 0: # Point B on axis
        points.append(B)
    return points

def is_origin_surrounded(points):
    '''Checks whether given points surround origin from all four directions'''
    sign = lambda x: x and (1, -1)[x < 0]
    if len(points) < 4:
        return False
    else:
        top = False
        bottom = False
        left = False
        right = False
        for p in points:
            if p[0] == 0 and sign(p[1]) == 1:
                top = True
            if p[0] == 0 and sign(p[1]) == -1:
                bottom = True
            if p[1] == 0 and sign(p[0]) == -1:
                left = True
            if p[1] == 0 and sign(p[0]) == 1:
                right = True
        return top and bottom and left and right

def test():
    print(find_axes_crossings((-340, 495), (153, -910)))
    print(find_axes_crossings((-4, 5), (2, -1)))
    print(find_axes_crossings((2, 4), (4, -4)))
    print(find_axes_crossings((4, 5), (6, 9)))
    print(load_triangles())

def solution():
    triangles = load_triangles()
    amount = 0
    for tri in triangles:
        points = []
        A = tri[0]
        B = tri[1]
        C = tri[2]
        points.extend(find_axes_crossings(A, B))
        points.extend(find_axes_crossings(B, C))
        points.extend(find_axes_crossings(A, C))
        if is_origin_surrounded(points):
            amount += 1
    print("Found " + str(amount) + " points")


solution()
