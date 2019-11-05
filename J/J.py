import heapq

N, J = [int(x) for x in input().split()]
expected = [int(x) for x in input().split()]
jiren = [int(x) for x in input().split()]
ricardo = [int(x) for x in input().split()]
sirai = [int(x) for x in input().split()]
F = []
sums = 0 
for i in range(N):
    val = max([ricardo[i], sirai[i]])
    sums += val
    diff = jiren[i]-val
    heapq.heappush(F, -diff)

for i in range(J):
    val = -heapq.heappop(F)
    sums += val

expectedSum = sum(expected)

if(expectedSum > sums):
    print("Don't do it, buddy")
else:
    print(sums)