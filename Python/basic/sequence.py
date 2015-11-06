def count(sequence, item):
    total = 0
    for x in sequence:
        if item == x:
            total = total + 1
    return total

def purify(list):
    ret = []
    for x in list:
        if (x % 2) == 0:
            ret.append(x)
    return ret

def product(list):
    ret = 1
    for x in list:
        ret = ret * x
    return ret
    
def remove_duplicates(list):
    ret = []
    for x in list:
        if x not in ret:
            ret.append(x)
    return ret

def remove_duplicates(list):
    copy = list[:]
    copy.sort()
    ret = []
    prev = 0
    for x in copy:
        if (ret is None) or x != prev:
            prev = x
            ret.append(prev)
    return ret

def median(list):
    list.sort()
    length = len(list)
    if length % 2:
        return list[length / 2]
    elif length != 0:
        return (list[length / 2] + list[length / 2 - 1]) / 2.0
