#include <iostream>
#include <iomanip>
#include <cmath> // Necessário para a função ceil

// Função principal do programa
int main() {
    int x; // Total de números a serem impressos
    int y; // Número de colunas na tabela
    
    // --- 1. Entrada de Dados ---
    std::cout << "Digite o número total de elementos (x): ";
    std::cin >> x;

    if (x <= 0) {
        std::cerr << "Erro: O número total de elementos deve ser positivo.\n";
        return 1;
    }

    std::cout << "Digite o número de colunas para a tabela (y): ";
    std::cin >> y;

    if (y <= 0) {
        std::cerr << "Erro: O número de colunas deve ser positivo.\n";
        return 1;
    }
    
    // Calcula o número de linhas necessárias. 
    // Usamos 'ceil' (teto) para garantir que sempre haja linhas suficientes, mesmo que a última esteja incompleta.
    // Exemplo: 23 elementos em 5 colunas -> 23 / 5 = 4.6. ceil(4.6) = 5 linhas.
    int linhas = static_cast<int>(std::ceil(static_cast<double>(x) / y));

    std::cout << "\n--- Tabela de " << x << " Números (" << linhas << " Linhas x " << y << " Colunas) ---\n";
    
    // --- 2. Lógica de Impressão (Por Coluna) ---
    
    // Loop externo: itera sobre as LINHAS (i)
    for (int i = 0; i < linhas; ++i) {
        
        // Loop interno: itera sobre as COLUNAS (j)
        for (int j = 0; j < y; ++j) {
            
            // Fórmula para calcular o número a ser impresso na posição (i, j)
            // O número é calculado assim:
            // 1. A coluna atual (j) * o número de linhas (linhas) nos dá o início da coluna.
            // 2. Adicionamos o índice da linha (i) para ir para o número correto dentro da coluna.
            // 3. Adicionamos 1, pois a contagem é baseada em 1 (de 1 a x).
            int numero = (j * linhas) + i + 1;
            
            // Se o número calculado for maior que o total de elementos (x), 
            // significa que esta célula deve ficar vazia.
            if (numero <= x) {
                // Imprime o número com espaçamento uniforme (setw(4))
                std::cout << std::setw(4) << numero;
            } else {
                // Imprime espaços vazios para manter a formatação da coluna
                std::cout << std::setw(4) << " ";
            }
        }
        
        // Pula para a próxima linha após completar todas as colunas
        std::cout << std::endl;
    }

    return 0; // Saída bem-sucedida do programa
}