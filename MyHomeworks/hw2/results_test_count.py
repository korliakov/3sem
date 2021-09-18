import numpy as np
import matplotlib.pyplot as plt


with open("Discrete1.txt") as f:
    
    text_Discrete1 = f.read()
    

with open("Segment1.txt") as f:
    
    text_Segment1 = f.read()
    
with open("Set1.txt") as f:
    
    text_Set1 = f.read()
    
    
Discrete1_points = [tuple(el.split(' , ')) for el in text_Discrete1.strip().split('\n')]
Segment1_points = [tuple(el.split(' , ')) for el in text_Segment1.strip().split('\n')]
Set1_points = [tuple(el.split(' , ')) for el in text_Set1.strip().split('\n')]

X_d = [float(el[0]) for el in Discrete1_points]
Y_d = [float(el[1]) for el in Discrete1_points]
X_d = np.log2(X_d) #для логарифмического масштаба по x
#X_d = [1/i for i in X_d] #для обратной пропорциональности

print(X_d)
print(Y_d)

X_s = [float(el[0]) for el in Segment1_points]
Y_s = [float(el[1]) for el in Segment1_points]
X_s = np.log2(X_s) #для логарифмического масштаба по x
#X_s = [1/i for i in X_s] #для обратной пропорциональности

print(X_s)
print(Y_s)

X_ss = [float(el[0]) for el in Set1_points]
Y_ss = [float(el[1]) for el in Set1_points]
X_ss = np.log2(X_ss) #для логарифмического масштаба по x
#X_ss = [1/i for i in X_ss] #для обратной пропорциональности

print(X_ss)
print(Y_ss)



plt.figure(figsize=(16, 9))

plt.minorticks_on()
plt.grid(which='major',
        color = 'k', 
        linewidth = 2) 
plt.grid(which='minor', 
        color = 'k', 
        linestyle = ':')


plt.title('Discrete(5) \n Segment(0,4) \n Set({1, 3, 5, 7, 23, 48, 57, 60, 90, 99}) \n search interval (0, 100)', size = 16)
#plt.legend(labels = ('p(test-', ), loc = 'upper left')
plt.xlabel(r'$log_{2}(test-count) \:\: $', fontsize = 16)
plt.ylabel(r'$p \:\: $', fontsize = 16)
plt.tick_params(axis='both', which='major', labelsize=16)
plt.ticklabel_format(style='plain')




plt.scatter(X_d, Y_d, color = 'b', s=100)
plt.plot(X_d, Y_d, linewidth=3, color = 'red', label = 'Discrete')

plt.scatter(X_s, Y_s, color = 'b', s=100)
plt.plot(X_s, Y_s, linewidth=3, color = 'green', label = 'Segment')

plt.scatter(X_ss, Y_ss, color = 'b', s=100)
plt.plot(X_ss, Y_ss, linewidth=3, color = 'black', label = 'Set')

plt.legend()
plt.show()















    
