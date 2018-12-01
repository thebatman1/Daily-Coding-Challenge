#!/usr/bin/env python3.6


def cons(a, b):

    def f(a, b):
        return (a, b)

    def pair(f):
        return f(a, b)
    return pair(f)


def main():
    tup = [int(x) for x in input("Enter two integers: ").split()]
    x, y = tup[0], tup[1]
    print(cons(x, y))


if __name__ == '__main__':
    main()
