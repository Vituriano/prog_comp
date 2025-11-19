#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

void print(const std::vector<int>& tracks, int sum) {
}

int main() {
    // Garante que a entrada/saída do C++ seja rápida
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    // Lê uma linha inteira de entrada de cada vez, para processar cada caso de teste
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        
        int tape_capacity;
        int num_tracks;
        
        // Extrai a capacidade da fita e o número de faixas
        ss >> tape_capacity >> num_tracks;
        
        std::vector<int> tracks(num_tracks);
        // Extrai a duração de cada faixa
        for (int i = 0; i < num_tracks; ++i) {
            ss >> tracks[i];
        }

        int best_sum = -1; // Armazena a melhor soma encontrada até agora. -1 indica nenhuma solução válida.
        std::vector<int> best_tracks_combination;

        // O 'i' representa uma máscara de bits (bitmask). Cada bit representa uma faixa.
        // O loop vai de 0 até (2^num_tracks - 1), cobrindo todas as combinações possíveis.
        for (int i = 0; i < (1 << num_tracks); ++i) {
            int current_sum = 0;
            std::vector<int> current_tracks_combination;

            // Para cada combinação (máscara 'i'), verificamos quais faixas estão incluídas.
            for (int j = 0; j < num_tracks; ++j) {
                // A operação (i & (1 << j)) verifica se o j-ésimo bit está ligado em 'i'.
                if (i & (1 << j)) {
                    // Se estiver ligado, adicionamos a faixa à combinação atual.
                    current_sum += tracks[j];
                    current_tracks_combination.push_back(tracks[j]);
                }
            }

            // Verificamos se a combinação atual é válida e melhor que a anterior
            if (current_sum <= tape_capacity && current_sum > best_sum) {
                best_sum = current_sum;
                best_tracks_combination = current_tracks_combination;
            }
        }

        // Imprime a melhor combinação encontrada para o caso de teste atual
        print(best_tracks_combination, best_sum);

    for (size_t i = 0; i < best_tracks_combination.size(); ++i) {
        std::cout << tracks[i] << (i == tracks.size() - 1 ? "" : " ");
    }
    std::cout << " sum:" << sum << std::endl;
    }

    return 0;
}
