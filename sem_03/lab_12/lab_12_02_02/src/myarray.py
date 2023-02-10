import ctypes as c
import os


lib = c.cdll.LoadLibrary(os.path.abspath("array.dll"))


def fibonacci_fill(n):
    _fibonacci_fill = lib.fibonacci_fill
    _fibonacci_fill.argtypes = (c.POINTER(c.c_int), c.c_int)
    _fibonacci_fill.restypes = c.c_int

    if n < 1:
        return 1, list()

    arr = (c.c_int * n)()

    rc = _fibonacci_fill(arr, n)

    return rc, list(arr)


def myfilter(arr):
    _filter = lib.filter
    _filter.argtypes = (c.POINTER(c.c_int), c.c_int, c.POINTER(c.c_int), c.POINTER(c.c_int))
    _filter.restypes = None

    src_n = len(arr)
    src = (c.c_int * src_n)(*arr)
    dst_n = c.c_int(0)
    dst = (c.c_int * src_n)()

    _filter(src, src_n, dst, dst_n)

    if dst_n.value > 0:
        return list(dst)[:dst_n.value]
    else:
        return list()


if __name__ == "__main__":
    print("\nfibonacci_fill tests:")
    print(fibonacci_fill(1))
    print(fibonacci_fill(2))
    print(fibonacci_fill(5))
    print(fibonacci_fill(10))
    print(fibonacci_fill(0))
    print(fibonacci_fill(-3))
    print("\nfilter tests:")
    print(myfilter([1, 1, 1, 2, 2, 3, 4]))
    print(myfilter([1, 2, 3, 4]))
    print(myfilter([1, 1, 1, 1]))
    print(myfilter([3]))