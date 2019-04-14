import Fuc_TicTacToe

#começa a função main
nome_player1 = input ("Digite o nome do primeiro jogador: ")
nome_player2 = input ("Digite o nome do segundo jogador: ")

space = [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '] #vetor utilizado no jogo

vez = 0
gameover = 0
while(gameover == 0):
     Fuc_TicTacToe.marc(vez%2, space)
     gameover =  Fuc_TicTacToe.logic_game(space)
     vez += 1
Fuc_TicTacToe.draw(space)
