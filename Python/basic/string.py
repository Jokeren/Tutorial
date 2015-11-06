def reverse(x):
    t = ""
    length = len(x)
    for i in range(0, length):
        t += x[length - i - 1]
    return t

def anti_vowel(text):
    vowel = "aeiouAEIOU"
    ret = ""
    for c in text:
        for k in vowel:
            if k == c:
                break
        else:
            ret += c
    return ret

def censor(text, word):
    t = text.split()
    length = len(word)
    for idx, v in enumerate(t):
        if v == word:
            t[idx] = "*"*length
    return " ".join(t)
