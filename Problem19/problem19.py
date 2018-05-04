'''
ProjectEuler
Problem 19 : Counting Sundays
'''

months = {
    1 : [31, 31],
    2 : [28, 29],
    3 : [31, 31],
    4 : [30, 30],
    5 : [31, 31],
    6 : [30, 30],
    7 : [31, 31],
    8 : [31, 31],
    9 : [30, 30],
    10 : [31, 31],
    11 : [30, 30],
    12 : [31, 31]
}
days = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']

day_of_week = 0
day = 1
month = 1
year = 1901
suns = 0
while year != 2000:
    print((day, month, year, days[day_of_week], suns))
    if year % 4 == 0:
        leap = 1
    else:
        leap = 0
    day = (day % months[month][leap] + 1)
    day_of_week = (day_of_week + 1) % 7
    if day == 1 and day_of_week == 6:
        suns += 1
    if day == 1:
        month = month % 12 + 1
        if month == 1:
            year += 1
