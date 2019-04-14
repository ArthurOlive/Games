import Objetcs
import Funcs
from random import choices

temp_lista = Funcs.LerLista()
print(temp_lista)
palavra = Objetcs.Palavra(choices(temp_lista))

while (Funcs.gameOver(palavra)):
    Funcs.Desenha(getattr(palavra, "erros"), palavra)
    try:
        letra = str(input("Digite uma letra: "))
    except:
        print("Entrada errada!!!")
        continue
    palavra.process(letra)
print("A palavra era ", getattr(palavra,"palavra")[0])
