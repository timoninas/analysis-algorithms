def getFail(substring):
    fail = [0]*len(substring)
    for i in range(1,len(substring)):
        k = fail[i-1]
        while k > 0 and substring[k] != substring[i]:
            k = fail[k-1]
        if substring[k] == substring[i]:
            k = k + 1
        fail[i] = k
    return fail

def kmp(substring, text):
    index = -1
    f = getFail(substring)
    k = 0
    for i in range(len(text)):
        while k > 0 and substring[k] != text[i]:
            k = f[k-1]
        if substring[k] == text[i]:
            k = k + 1
        if k == len(substring):
            index = i - len(substring) + 1
            break

    return index

def getSlide(pattern, m):
    slide = 256*[-1]
    for i in range(m):
        slide[ ord(pattern[i]) ] = i;
    return slide

def bm(pattern, text):
    patternLoc = len(pattern)
    textLoc = len(text)

    slide = getSlide(pattern, patternLoc)
    length = 0

    while(length <= (textLoc - patternLoc)):
        tmp = patternLoc - 1
        while (tmp >= 0 and pattern[tmp] == text[length + tmp]):
            tmp -= 1
        if (tmp < 0):
            return length
        else:
            length += max(1, tmp-slide[ord(text[length + tmp])])


print(kmp('aba', 'babscsdavbarabadf'))
print(bm('aba', 'babscsdavbarabadf'))
