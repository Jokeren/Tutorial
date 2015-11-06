def is_even(x):
    if x % 2:
        return False
    else:
        return True

def is_int(x):
    if x - int(x) == 0:
        return True
    else:
        return False

def digit_sum(n):
    s = str(n)
    total = 0
    for c in s:
        total += int(c)
    return total

def factorial(x):
    if x == 0:
        return 1
    else:
        return x * factorial(x - 1)

def is_prime(x):
    if x <= 1:
        return False
    for n in range(2, x):
        if (x % n) == 0:
            return False
    else:
        return True
        
