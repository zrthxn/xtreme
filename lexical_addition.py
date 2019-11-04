# a simple parser for python. use get_number() and get_word() to read
# def parser():
#     while 1:
#         data = list(input().split(' '))
#         for number in data:
#             if len(number) > 0:
#                 yield(number)   

# input_parser = parser()

# def get_word():
#     global input_parser
#     return next(input_parser)

# def get_number():
#     data = get_word()
#     try:
#         return int(data)
#     except ValueError:
#         return float(data)

# numpy and scipy are available for use

from numpy import ones
from sys import exit

def print_series(n,a,b,number_of_tries):
    # print(f"Reaching for number of Tries = {number_of_tries}")
    array = ones(number_of_tries)
    array *= a
    for index in range(len(array)-1,-1,-1):
        for _ in range(b-a):
            if not sum(array) == n:
                array[index]+=1
                continue
            else:
                print("YES")
                [print(int(x),end= " ") for x in array]
                return True
    return False


I = list(input().split(' '))

n = int(I[0])
a = int(I[1])
b = int(I[2])

if 2 * a > n:
    print("NO")
    exit()

min_number_possible = int(n / b) +1
max_number_possible = int(n / a) 

# print(n/a)
while True:
    status = print_series(n, a, b, min_number_possible)
    if status == True:
        exit()
    else:
        min_number_possible+=1
        if min_number_possible > 100000 or min_number_possible > max_number_possible:
            print("NO")
            exit()
        if sum(ones(min_number_possible)*a) > n:
            # print(sum(ones(min_number_possible)*a))
            # print(n)
            print("NO")

            exit()