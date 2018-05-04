'''
ProjectEuler
Problem 613 : Pythagorean Ant
'''

# Lawl, I just input the following into Wolfram:
# integrate integrate arctg((y-30)/x)-arctg(y/(x-40)) dy dx from y=0 to 30-(3x/4) from x=0 to 40
# I got the result:
# 50 (32 log(2) + 9 log(3) - 25 log(5))                     XXX WHYYYY???
# Which turns out to be:
# -408.3863717460636120555...
# Divided by area of 600, converted to degrees and divided by 360:
# 38.99802585285
# Substracted 180 and divided by 360:
# -0.3916721504 - The result


from math import pi, atan2
from scipy import integrate


A = 40
B = 30
area = 600


def f(y, x):
    return atan2(B-y, -x) - atan2(-y, A-x)


def bounds_y(x):
    return [0, B - B*x/A]


def bounds_x():
    return [0, A]


result = integrate.nquad(f, [bounds_y, bounds_x])
print(result[0] / (2*pi) / area)
