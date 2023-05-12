import heapq

q = int(input())

main = dict()

bedeh_cnt = dict()
talab_cnt = dict()

bal = dict()
bal_sorted = []

for _ in range(q):
    op = input()
    if op[0] == "1":
        _, s1, s2, x = op.split()
        x = float(x)

        try:
            bal[s1]
        except KeyError:
            bal[s1] = 0
        try:
            bal[s2]
        except KeyError:
            bal[s2] = 0

        try:
            bedeh_cnt[s1]
        except KeyError:
            bedeh_cnt[s1] = 0
        try:
            bedeh_cnt[s2]
        except KeyError:
            bedeh_cnt[s2] = 0
        try:
            talab_cnt[s1]
        except KeyError:
            talab_cnt[s1] = 0
        try:
            talab_cnt[s2]
        except KeyError:
            talab_cnt[s2] = 0
        
        try:
            main[s1]
        except KeyError:
            main[s1] = dict()
        
        try:
            main[s2]
        except KeyError:
            main[s2] = dict()

        try:
            old = main[s1][s2]
            main[s1][s2] += x

            # oldbals1 = bal[s1]
            # oldbals2 = bal[s2]
            # bal.pop(s1)
            # bal.pop(s2)
            # bal[s1] = oldbals1 - x
            # bal[s2] = oldbals2 + x
            bal[s1] -= x
            bal[s2] += x
            if old == 0:
                talab_cnt[s1] += 1
                bedeh_cnt[s2] += 1
            elif old < 0:  
                if main[s1][s2] == 0:
                    talab_cnt[s2] -= 1
                    bedeh_cnt[s1] -= 1
                elif main[s1][s2] > 0:   
                    talab_cnt[s2] -= 1
                    bedeh_cnt[s1] -= 1

                    talab_cnt[s1] += 1
                    bedeh_cnt[s2] += 1

        except KeyError:
            # oldbals1 = bal[s1]
            # oldbals2 = bal[s2]
            # bal.pop(s1)
            # bal.pop(s2)
            # bal[s1] = oldbals1 - x
            # bal[s2] = oldbals2 + x   
            bal[s1] -= x
            bal[s2] += x       
            main[s1][s2] = x
            talab_cnt[s1] += 1
            bedeh_cnt[s2] += 1

        try:
            main[s2][s1] += -x
        except KeyError:
            main[s2][s1] = -x

        # print(main)
        # print(bedeh_cnt)
        # print(talab_cnt)

    if op[0] == "4":
        _, s = op.split()
        print(bedeh_cnt[s])
    if op[0] == "5":
        _, s = op.split()
        print(talab_cnt[s])
    if op[0] == "6":
        _, s1, s2 = op.split()

        try:
            main[s1][s2]
        except KeyError:
            main[s1][s2] = 0
            main[s2][s1] = 0

        if format(-main[s1][s2], ".2f") == "-0.00":
            print("0.00")
        else:
            print(format(-main[s1][s2], ".2f"))

    if op[0] == "2":
        ma = min(bal.keys(), key=(lambda k: (-bal[k], k)))
        if bal[ma] > 0:
            print(ma)
        else:
            print(-1)
    if op[0] == "3":
        mi = min(bal.keys(), key=(lambda k: (bal[k], k)))
        if bal[mi] >= 0:
            print(-1)
        else:
            print(mi)