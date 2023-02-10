import matplotlib.pyplot as plt

version = [0, 1, 2]
size = [10, 100, 1000, 10000]
repeats = [1, 10, 100, 1000, 5000]

# График 1: Количество повторов | среднее время

y0 = []
x0 = repeats[:]
for i in range(len(repeats)):
    g = open("avg_10000_" + str(repeats[i]) + "_0.txt", "r")
    y0.append(float(g.readline()))
    g.close()

y1 = []
x1 = repeats[:]
for i in range(len(repeats)):
    g = open("avg_10000_" + str(repeats[i]) + "_1.txt", "r")
    y1.append(float(g.readline()))
    g.close()

y2 = []
x2 = repeats[:]
for i in range(len(repeats)):
    g = open("avg_10000_" + str(repeats[i]) + "_2.txt", "r")
    y2.append(float(g.readline()))
    g.close()

plt.title("Среднее время работы массива из 10000 элементов")
plt.xlabel("Количество повторов")
plt.ylabel("Среднее время работы")
plt.plot(x0, y0, x1, y1, x2, y2)
plt.savefig('plot1.svg')
plt.close()

# График 2: Размер массива | среднее время

y0 = []
x0 = size[:]
for i in range(len(size)):
    g = open("avg_" + str(size[i]) + "_5000_0.txt", "r")
    y0.append(float(g.readline()))
    g.close()

y1 = []
x1 = size[:]
for i in range(len(size)):
    g = open("avg_" + str(size[i]) + "_5000_1.txt", "r")
    y1.append(float(g.readline()))
    g.close()

y2 = []
x2 = size[:]
for i in range(len(size)):
    g = open("avg_" + str(size[i]) + "_5000_2.txt", "r")
    y2.append(float(g.readline()))
    g.close()

plt.title("Среднее время работы при 5000 повторений")
plt.xlabel("Размер массива")
plt.ylabel("Среднее время работы")
plt.plot(x0, y0, x1, y1, x2, y2)
plt.savefig('plot2.svg')
plt.close()

# График 3: Количество повторов | общее время

y0 = []
x0 = repeats[:]
for i in range(len(repeats)):
    g = open("total_10000_" + str(repeats[i]) + "_0.txt", "r")
    y0.append(float(g.readline()))
    g.close()

y1 = []
x1 = repeats[:]
for i in range(len(repeats)):
    g = open("total_10000_" + str(repeats[i]) + "_1.txt", "r")
    y1.append(float(g.readline()))
    g.close()

y2 = []
x2 = repeats[:]
for i in range(len(repeats)):
    g = open("total_10000_" + str(repeats[i]) + "_2.txt", "r")
    y2.append(float(g.readline()))
    g.close()

plt.title("Общее время работы массива из 10000 элементов")
plt.xlabel("Количество повторов")
plt.ylabel("Общее время работы")
plt.plot(x0, y0, x1, y1, x2, y2)
plt.savefig('plot3.svg')
plt.close()

# График 4: Размер массива | общее время

y0 = []
x0 = size[:]
for i in range(len(size)):
    g = open("total_" + str(size[i]) + "_5000_0.txt", "r")
    y0.append(float(g.readline()))
    g.close()

y1 = []
x1 = size[:]
for i in range(len(size)):
    g = open("total_" + str(size[i]) + "_5000_1.txt", "r")
    y1.append(float(g.readline()))
    g.close()

y2 = []
x2 = size[:]
for i in range(len(size)):
    g = open("total_" + str(size[i]) + "_5000_2.txt", "r")
    y2.append(float(g.readline()))
    g.close()

plt.title("Общее время работы при 5000 повторений")
plt.xlabel("Размер массива")
plt.ylabel("Общее время работы")
plt.plot(x0, y0, x1, y1, x2, y2)
plt.savefig('plot4.svg')
plt.close()
