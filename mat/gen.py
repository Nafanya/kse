import numpy as np

from numpy.linalg import cond as cond
from numpy.linalg import solve

def gen_hilbert(n):
    return [[1. /  (i + j - 1) for j in range(1, n+1)] for i in range(1, n+1)]

def gen_good_cond(n):
    pass #return [[ for j in range(n)] for i in range(n)]

def main():
    pass

if __name__ == '__main__':
    main()
