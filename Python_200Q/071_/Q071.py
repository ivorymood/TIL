def getPrime(x):
    if x % 2 == 0:
        return

    for i in range(3, int(x / 2), 2):
        if x % i == 0:
            break;
    else:
        return x

listdata = [117, 119, 1113, 11113, 11119]
ret = filter(getPrime, listdata)
print(list(ret))
print(getPrime(2))

def getPrime2(n):
    ret = [2]
    if n <= 2:
        return ret

    for i in range(3, n + 1, 2):
        for k in range(3, int(i / 2), 2):
            a = i % k;
            if a == 0:
                break
        else:
            ret.append(i)

    return ret

ret = getPrime2(10)
print(ret)