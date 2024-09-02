#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>

class Perceptron{
    private: 
        std:: vector<double> pesos;
        double bias;
        double taxa_de_aprendizado;

        public:

        Perceptron(int tamanho_entrada, double taxa) : pesos(tamanho_entrada, 0.0), bias(0.0), taxa_de_aprendizado(taxa){}

        int prever(const std::vector<double>&entradas){
            double soma = bias;
            for(size_t i = 0; i< pesos.size(); i++){
                soma += pesos[i] *entradas[i];
            }
            return (soma >= 0) ? 1 : 0;
        }

void treinar(const std::vector<std::vector<double>>& entradas_treinamento, const std::vector<int>& rotulos, int epocas){
    for(int epoca = 0; epoca <epocas; epoca++){
        for(size_t i = 0; i < entradas_treinamento.size(); ++i){
            int previsao = prever(entradas_treinamento[i]);
            int erro = rotulos[i] - previsao;
            
            for(size_t j = 0; j<pesos.size(); ++j){
                pesos[j] += taxa_de_aprendizado*erro*entradas_treinamento[i][j];
            }
            bias += taxa_de_aprendizado * erro;
        }
    }
}
};

int main(){
    std::vector<std::vector<double>>entradas_treinamento = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    std::vector<int> rotulos = {0,0,0,1};

    Perceptron perceptron(2, 0.1);
    perceptron.treinar(entradas_treinamento, rotulos, 10);

    for(const auto& entrada: entradas_treinamento){
        std:: cout << "Entrada: ("<< entrada[0] << ", " << entrada[1] << ") -> Previsao: " << perceptron.prever(entrada) << std::endl;
    }    
    return 0;
}