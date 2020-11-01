def tower_of_hanoi(n, source, dest, temp):
    global count
    if n > 1:
        tower_of_hanoi(n-1, source, temp, dest)
        count += 1
        # print(source,"에서",dest,"로 원반 하나를 이동")
        tower_of_hanoi(n-1, temp, dest, source)
    else:
        # print(source,"에서",dest,"로 원반 하나를 이동")
        count += 1


for n in [4,6,8,16,24,25,26]:
    count = 0
    from time import perf_counter
    start = perf_counter()
    tower_of_hanoi(n,'a','b','c')
    finish = perf_counter()
    print("원반",n,"개 :",count,"번 이동,", round(finish-start))