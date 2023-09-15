matriz = [[1, 2],
          [3, 4]]

matrizB = [[2, 5],
           [6, 3]]

soma = 0

for i in range(len(matrizB)):
    for j in range(len(matriz)):
        soma = 0
        for k in range(len(matriz)):
            soma += matriz[i][k] * matrizB[k][j]

        print(soma)
