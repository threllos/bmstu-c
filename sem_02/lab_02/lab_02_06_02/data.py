version = [0, 1, 2]
size = [10, 100, 1000, 10000]
repeats = [1, 10, 100, 1000, 5000]

f = open("DATA.txt", "w")
f.write("**Результаты сравнения производительности разных способов работы с элементами массива (время работы в секундах).**\n\n")
f.write("Среднее время работы функции:\n\n")
f.write("| Количество повторов | Размер массива | a[i] | *(a + i) | Работа с указателями |\n")
f.write("| ------ | ------ | ------ | ------ | ------ |\n")
for i in range(len(repeats)):
    for j in range(len(size)):
        r = []
        for d in range(len(version)):
            g = open("avg_" + str(size[j]) + "_" + str(repeats[i]) + "_" + str(version[d]) + ".txt", "r")
            r.append(float(g.readline()))
            g.close()
        f.write("| " + str(repeats[i]) + " | " + str(size[j]) + " | " + "{:.4f}".format(r[0]) + " | " + "{:.4f}".format(r[1]) + " | " + "{:.4f}".format(r[2]) + " |\n")

f.write("\n")
f.write("Общее время работы функции:\n\n")
f.write("| Количество повторов | Размер массива | a[i] | *(a + i) | Работа с указателями |\n")
f.write("| ------ | ------ | ------ | ------ | ------ |\n")
for i in range(len(repeats)):
    for j in range(len(size)):
        r = []
        for d in range(len(version)):
            g = open("total_" + str(size[j]) + "_" + str(repeats[i]) + "_" + str(version[d]) + ".txt", "r")
            r.append(float(g.readline()))
            g.close()
        f.write("| " + str(repeats[i]) + " | " + str(size[j]) + " | " + "{:.4f}".format(r[0]) + " | " + "{:.4f}".format(r[1]) + " | " + "{:.4f}".format(r[2]) + " |\n")
f.close()
