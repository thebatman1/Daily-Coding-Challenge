#!/usr/bin/env python3.6
"""
    Input: No of steps in the staircase (N) and a space separated list of the
    no of steps that can be climbed at a time.
    Output: No of unique ways the staircase can be climbed
"""

def staircase(n, X):
    cache = [0 for _ in range(n + 1)]
    cache[0] = 1
    for i in range(1, n + 1):
        cache[i] += sum(cache[i - x] for x in X if i - x >= 0)
    return cache[n]


def main():
    steps = int(input("Enter the no of steps: "))
    steps_at_a_time = [int(x) for x in input("Enter the no of steps that can "
                                             + "be taken at a time: ").split()]
    ans = staircase(steps, steps_at_a_time)
    print(f"No of ways we can climb are: {ans}")


if __name__ == '__main__':
    main()
