n, m, k, s = map(int, raw_input().split());
dollars = map(int, raw_input().split());
pounds = map(int, raw_input().split());

v = []

for i in range(m):
    t, c = map(int, raw_input().split());
    v.append([t, c, i+1]);

def sum_all (day, k):

    dmin = 0x3f3f3f3f;
    pmin = 0x3f3f3f3f;


    for i in range(day+1):
        dmin = min(dmin, dollars[i]);
        pmin = min(pmin, pounds[i]);

    # if (n == 50 and m == 50 and k == 26 and s == 10000):
        # print "chegou aqui"

    result = [i[1]*dmin if i[0] == 1 else i[1]*pmin for i in v]

    # if (n == 50 and m == 50 and k == 26 and s == 10000):
        # print "chegou aqui2"
    result.sort()

    return sum(result[:k])

def show_answer(left, k):
    dmin = 0;
    pmin = 0;

    for i in range(left+1):
        if (dollars[dmin] > dollars[i]):
            dmin = i

        if (pounds[pmin] > pounds[i]):
            pmin = i

    aux = sorted (v, key=lambda x: x[1]*dollars[dmin] if x[0] == 1 else x[1]*pounds[pmin])

    for i in range(k):
        if (v[i][0] == 1):
            print v[i][2], dmin+1
        else:
            print v[i][2], pmin+1

if __name__ == '__main__':

    left, right = 0, len(v)
    while right-left > 1:
        mid = (left+right)/2 - 1
        # print left, mid, right
        aux = sum_all (mid, k)
        if (s < aux):
            left = mid+1
        else:
            right = mid+1

    # if (n == 50 and m == 50 and k == 26 and s == 10000):
    #     print "chamou funcao com left:", left
    #     r = sum_all(left, k);
    #     print "-1"

    if (left >= n or sum_all(left, k) > s):
        print "-1"
    else:
        print left+1
        show_answer(left, k)
