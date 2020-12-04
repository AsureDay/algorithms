import matplotlib.pyplot as plt
import re
classic_method_time_list = []
better_method_time_list = []
nlist = []

fig, ax = plt.subplots()

float_num_pattern = r"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?"
int_num_pattern = r"[-+]?\d+"
with open("tests_withO.txt",'r') as file:
	for line in file:
		if(line[0] == 'n'):
			nlist.append(int(re.search(int_num_pattern,line)[0]))
		elif(line[0] == 's'):
			classic_method_time_list.append(float(re.search(float_num_pattern,line)[0]))
		elif(line[0] == 'b'):
			better_method_time_list.append(float(re.search(float_num_pattern,line)[0]))

ax.set_xlabel("Размер матрицы (N)")
ax.set_ylabel("Время перемножения (с)")
print(nlist)
#plt.plot(nlist,classic_method_time_list)
plt.plot(nlist,better_method_time_list)
plt.show()