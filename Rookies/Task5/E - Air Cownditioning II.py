import sys


def check(cows, acs):
    for pos in range(1, 101):
        cooling = 0
        for ac in acs:
            start, end, power, _ = ac
            if start <= pos <= end:
                cooling += power

        requirement = 0
        for cow in cows:
            start, end, cool = cow
            if start <= pos <= end:
                requirement = cool
                break

        if cooling < requirement:
            return False

    return True


input = sys.stdin.read
data = input().strip().split("\n")

n, m = map(int, data[0].split())

cows = []
for i in range(1, n + 1):
    cow = list(map(int, data[i].split()))
    cows.append(cow)

acs = []
for i in range(n + 1, n + m + 1):
    ac = list(map(int, data[i].split()))
    acs.append(ac)

mi = float('inf')

for mask in range(1 << m):
    selected_acs = []
    cost = 0

    for i in range(m):
        if mask & (1 << i):
            selected_acs.append(acs[i])
            cost += acs[i][3]

    if check(cows, selected_acs):
        mi = min(mi, cost)

print(mi)
