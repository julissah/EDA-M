import numpy as np
from time import process_time
import os

def insertionSort(arr):    
    for i in range(1, len(arr)): 
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key
    
with open('Source\n100.txt', 'r') as f:
    content = f.read()
res = [int(i) for i in content.split()]
t1_start = process_time()
insertionSort(res)
t1_stop = process_time()
time = t1_stop-t1_start
print(res)
print(time)