def verificarPosicion(i,j):
    return not (fila[i] or columna[j] or diagonales1[i + j] or diagonales2[i - j + 7])
    
def colocarReinas(colocadas):
    if len(colocadas) == 8:
        return True
    for i in range(8):
        for j in range(8):
            if not tablero[i][j] and verificarPosicion(i,j):
                tablero[i][j] = True
                fila[i] = True
                columna[j] = True
                diagonales1[i + j] = True
                diagonales2[i - j + 7] = True
                tuplareina = (i + 1, j + 1)
                colocadas.append(tuplareina)
                if colocarReinas(colocadas):
                    return True
                colocadas.pop()
                tablero[i][j] = False
                fila[i] = False
                columna[j] = False
                diagonales1[i + j] = False
                diagonales2[i - j + 7] = False
                
    return False

fila = [False] * 8
columna = [False] * 8
diagonales1 = [False] * 15
diagonales2 = [False] * 15
tablero = [[False]*8 for _ in range(8)]
colocadas = int(input())
coordenadas_colocadas = []
for i in range(colocadas):
    k,j = map(int, input().split())
    coordenadas_colocadas.append((k,j))
    tablero[k-1][j-1] = True
    fila[k-1] = True
    columna[j-1] = True
    diagonales1[k - 1 + j - 1] = True
    diagonales2[k - 1 - (j - 1) + 7] = True
    
if not colocarReinas(coordenadas_colocadas):
    print(0)
else:
    for i in coordenadas_colocadas:
        print(*i)