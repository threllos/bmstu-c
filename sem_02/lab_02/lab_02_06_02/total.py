version = [0, 1, 2]
size = [10, 100, 1000, 10000]
repeats = [1, 10, 100, 1000, 5000]
 
for i in range(len(version)):
    for j in range(len(size)):
        for d in range(len(repeats)):
            f = open("time_" + str(size[j]) + "_" + str(repeats[d]) + "_" + str(version[i]) + ".txt", "r")
            s = 0
            for line in f:
                s += int(line) * 1e-6
            f.close()
            f = open("total_" + str(size[j]) + "_" + str(repeats[d]) + "_" + str(version[i]) + ".txt", "w")
            f.write(str(round(s, 4)))
            f.close()