def Desenha(erros, palavra):
    print(" *---*")
    print(" |   |")
    if(erros == 0):
        print("     |")
        print("     |")
        print("     |")
        print("     |")
        print("========")
    if(erros == 1):
        print(" 0   |")
        print("     |")
        print("     |")
        print("     |")
        print("========")
    if(erros == 2):
        print(" 0   |")
        print(" |   |")
        print("     |")
        print("     |")
        print("========")
    if(erros == 3):
        print(" 0   |")
        print("/|   |")
        print("     |")
        print("     |")
        print("========")
    if(erros == 4):
        print(" 0   |")
        print("/|\  |")
        print("     |")
        print("     |")
        print("========")
    if(erros == 5):
        print(" 0   |")
        print("/|\  |")
        print("/    |")
        print("     |")
        print("========")
    if(erros == 6):
        print(" 0   |")
        print("/|\  |")
        print("/ \  |")
        print("     |")
        print("========")

    print("\nPalavra", palavra.mostrarPalavra(), "\n")
    print("Letras erradas: ")
    for x in getattr(palavra, "letrasErradas"):
        print(x)
    print()
    print("Letras certas: ")
    for x in getattr(palavra, "letrasCertas"):
        print(x)
    print()
def LerLista():
    lista = []
    with open("lista_palavras.txt", 'r') as listar:
        linha = listar.readline()
        temp = ''
        for x in linha:
            if(x == ',' or x == '.'):
                lista.append(temp)
                temp = ''
            else:
                temp += x
    return lista

def gameOver(palavra):
    if (len(str(getattr(palavra, "palavra")[0])) == getattr(palavra, "acertos")):
        print ("Voce acertou!!!")
        return False
    elif(getattr(palavra, "erros") == 6):
        print("Voce perdeu")
        return False
    else:
        return True
