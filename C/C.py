# Limits
#            10000000.00000 [12] 00% 0.00000
#         10000000000.00000 [15] 10% 10000000.00001
#      10000000000000.00000 [18] 20% 10000000000.00001
#   10000000000000000.00000 [21] 30% 10000000000000.00001
# 1000000000000000000.00000 [23] 40% 10000000000000000.00001

N = int(input())
rates = [0, 1000000000001, 1000000000000001,
         1000000000000000001, 1000000000000000000001]
suma = 0
for i in range(N):
    ent, frac = [int(x) for x in input().split(".")]
    suma += ent * 10**5 + frac
rate = -1

if suma > 1000000000000000000000:
    rate = 4
elif suma > 1000000000000000000:
    rate = 3
elif suma > 1000000000000000:
    rate = 2
elif suma > 1000000000000:
    rate = 1
else:
    rate = 0

ganancia = suma
suma *= rate

last = suma % 10
suma //= 10
nextToLast = suma % 10

if last > 5 or (last == 5 and nextToLast % 2 == 1):
    suma += 1

p1 = ganancia // 10**5
p2 = ganancia % 10**5
s1 = suma // 10**5
s2 = suma % 10**5

print("%d.%05d %d%% %d.%05d" % (p1, p2, rate*10, s1, s2))