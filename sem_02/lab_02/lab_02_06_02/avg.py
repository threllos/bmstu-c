version = [0, 1, 2]
size = [10, 100, 1000, 10000]
repeats = [1, 10, 100, 1000, 5000]
 
for i in range(len(version)):
    for j in range(len(size)):
        for d in range(len(repeats)):
            f = open("time_" + str(size[j]) + "_" + str(repeats[d]) + "_" + str(version[i]) + ".txt", "r")
            s = 0
            n = 0
            for line in f:
                s += int(line)
                n += 1
            avg = s / n * 1e-6
            f.close()
            f = open("avg_" + str(size[j]) + "_" + str(repeats[d]) + "_" + str(version[i]) + ".txt", "w")
            f.write(str(round(avg, 4)))
            f.close()