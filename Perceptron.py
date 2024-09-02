


def funcao_passo(z):
    if z>0:
        return 1
    else:
        return 0

def perceptron(entrada, alvo, taxa, epocas):
    pesos = [0,0,0]

    for e in range(epocas):
        for j in range(4):
            ent = entrada[j]

            y= 0
            for i in range(3):
                y += pesos[i] * ent[i]
            z = funcao_passo(y)
            erro = alvo[j] - z
            if erro !=0:
                for i in range(3):
                    pesos[i] = pesos[i] + taxa * erro * ent[i]
        return pesos

