import matplotlib.pyplot as plt

matrix_sizes = [100, 500, 1000, 1500, 2000]
time_1_thread = [13, 440, 4316, 16805, 32353]
time_2_threads = [11, 236, 2019, 7551, 16096]
time_4_threads = [8, 129, 984, 3568, 7969]
time_8_threads = [7, 113, 721, 2570, 5955]
time_16_threads = [6, 90, 643, 2133, 5075]
time_32_threads = [12, 150, 1046, 3930, 8345]

plt.figure(figsize=(10, 6))

plt.plot(matrix_sizes, time_1_thread, marker='', linestyle='-', color='blue', label='1')
plt.plot(matrix_sizes, time_2_threads, marker='', linestyle='-', color='red', label='2')
plt.plot(matrix_sizes, time_4_threads, marker='', linestyle='-', color='orange', label='4')
plt.plot(matrix_sizes, time_8_threads, marker='', linestyle='-', color='green', label='8')
plt.plot(matrix_sizes, time_16_threads, marker='', linestyle='-', color='purple', label='16')
plt.plot(matrix_sizes, time_32_threads, marker='', linestyle='-', color='brown', label='32')

plt.xlabel('Размер матрицы')
plt.ylabel('Время (мс) - лог. шкала') 
plt.title('Зависимость времени выполнения от размера матрицы и количества потоков')

plt.yscale('log')

plt.legend(title='Количество потоков')

plt.grid(True)

plt.tight_layout()
plt.show()