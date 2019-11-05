import math


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y


class Distance:
    def __init__(self, p, q):
        self.p = p
        self.q = q
        self.d = sqrDistance(p, q)

    def __lt__(self, other):
        return self.d < other.d


def sqrDistance(p, q):
    x = p.x - q.x
    y = p.y - q.y
    return x*x+y*y


def area(d1, d2):
    a = math.sqrt(sqrDistance(d1.p, d2.p))
    b = math.sqrt(sqrDistance(d1.q, d2.p))
    return a*b


def getCenter(d):
    x = (d.p.x + d.q.x) / 2
    y = (d.p.y + d.q.y) / 2
    return Point(x, y)


T = int(input())
while T:
    T -= 1
    N = int(input())
    distances = list()
    points = list()
    for i in range(N):
        x, y = [int(x) for x in input().split()]
        points.append(Point(x, y))
    for a in range(N):
        for b in range(a+1, N):
            distances.append(Distance(points[a], points[b]))
    distances = sorted(distances)
    s = 0
    e = 0

    num_distances = len(distances)
    maxArea = 0.0

    while(e < num_distances):
        while(distances[s].d == distances[e].d):
            e += 1
            if(not e < num_distances):
                break
        for i in range(s, e):
            for j in range(i+1, e):
                if(getCenter(distances[i]) == getCenter(distances[j])):
                    ar = area(distances[i], distances[j])
                    maxArea = maxArea if maxArea > ar else ar
        s = e

    if maxArea == 0.0:
        maxArea = -1.0
    print("%.9f" % maxArea)