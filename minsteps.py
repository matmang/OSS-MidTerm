def minsteps(n):
    if n > 1:
        steps = minsteps(n - 1)
        if n % 2 == 0:
            steps = min(steps, minsteps(n//2))
        if n % 3 == 0:
            steps = min(steps, minsteps(n//3))
        return steps + 1
    else:
        return 0

def greedy_minsteps(n):
    if n > 1:
        if n % 3 == 0:
            return 1 + greedy_minsteps(n//3)
        if n % 2 == 0:
            return 1 + greedy_minsteps(n//2)
        else:
            return 1 + greedy_minsteps(n-1)
    else:
        return 0

def memo_minsteps(n):
    memo = [0 for _ in range(n+1)]
    def loop(n):
        if n > 1:
            if memo[n] == 0:
                steps = loop(n-1)
                if n % 2 == 0:
                    steps = min(steps, loop(n//2))
                if n % 3 == 0:
                    steps = min(steps, loop(n//3))
                memo[n] = steps + 1
            return memo[n]
        else:
            return 0
    return loop(n)

def dyn_minsteps(n):
    memo = [0 for _ in range(n+1)]
    for i in range(1, n+1):
        if memo[i] == 0:
            steps = memo[i] + 1
            

def run_minsteps(n):
    from time import perf_counter
    start = perf_counter()
    answer = greedy_minsteps(n)
    finish = perf_counter()
    print('minsteps(',n,')=> ', answer, sep="")
    print(round(finish-start),"seconds")