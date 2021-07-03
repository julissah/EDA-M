import numpy as np
import os
intRango = np.arange(1, 101) #Elegir rango de datos
numeros = np.random.choice(intRango, size = (100), replace = False) # Elegir el numero de datos a generar
file = open("drive//MyDrive//Colab//XN100.txt", "w") # Seleccionar nombre del archivo
for x in numeros:
  file.write(str(x))
file.close()