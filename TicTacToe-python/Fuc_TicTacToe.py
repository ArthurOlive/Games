def draw(space):
    print(space[6]+'|'+space[7]+'|'+space[8])
    print(space[3]+'|'+space[4]+'|'+space[5])
    print(space[0]+'|'+space[1]+'|'+space[2])
    esc = int(input("Digite o espaco que deseja ocupar"))
    return (esc-1)

def processChoice(space):
    esc = draw(space)
    err = -1
    if((space[esc] == ' ') and (esc <= 8) and (esc >= 0)):
        return esc
    return err

def marc(vez, space):
    escolha = processChoice(space)
    if(vez == 0 and escolha != -1):
        space[escolha] = 'x'
        return space
    elif(vez == 1 and escolha != -1):
        space[escolha] = 'O'
        return space
    else:
        print("Problema!!!")
        pass
    if(escolha == -1):
        print("escolha invalida")
        pass
def logic_game(space):
    gameover = 0
    if(space[0] == space[1] == space[2]) and space[1] != ' ' :
        gameover = 1
    if(space[3] == space[4] == space[5]) and space[4] != ' ':
        gameover = 1
    if(space[6] == space[7] == space[8]) and space[7] != ' ':
        gameover = 1
    if(space[0] == space[3] == space[6]) and space[3] != ' ':
        gameover = 1
    if(space[1] == space[4] == space[7]) and space[4] != ' ':
        gameover = 1
    if(space[2] == space[5] == space[8]) and space[5] != ' ':
        gameover = 1
    if(space[0] == space[4] == space[8]) and space[4] != ' ':
        gameover = 1
    if(space[2] == space[4] == space[6]) and space[4] != ' ':
        gameover = 1
    return gameover
