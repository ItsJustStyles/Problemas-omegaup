def busquedaBinaria(numeros, objetivo):
    izquierda = 0
    derecha = len(numeros) - 1
    while derecha >= izquierda:
        medio = (derecha+izquierda)//2
        if numeros[medio] == objetivo:
            return medio
        elif numeros[medio] > objetivo:
            derecha = medio - 1
        else:
            izquierda = medio + 1
    return -1
        

def main():
    n = int(input())
    numeros = list(map(int, input().split()))
    numeros.sort()
    encontrado = busquedaBinaria(numeros, 8)
    print(encontrado)
main()