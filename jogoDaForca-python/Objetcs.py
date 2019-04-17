class Palavra():
    def __init__(self, palavra):
        self.palavra = list(palavra)
        self.letrasCertas = []
        self.letrasErradas = []
        self.erros = 0
        self.acertos = 0
    def process(self,letra):
            temp_tam_err = len(self.letrasErradas)
            lt = list(filter(lambda x: x in letra, str(self.palavra)))
            if ( lt != []):
                self.letrasCertas.append(letra)
            else:
                self.letrasErradas.append(letra)
            if(len(self.letrasErradas) > temp_tam_err):
                self.erros += 1
                print("Erro!!")
            else:
                self.acertos += list(self.palavra[0]).count(letra)
                print("Acerto")
    def mostrarPalavra(self):
        palavraShow = ''
        for x in str(self.palavra[0]):

            let = list(filter(lambda u: u in x, self.letrasCertas))
            if(let != []):
                palavraShow += let[0]
                let = []
            else:
                palavraShow +='_'
        return palavraShow
