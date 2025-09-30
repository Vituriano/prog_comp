#include <iostream>
#include <vector>

int main() {
    int N, K, Q;
    std::cin >> N >> K >> Q;

    std::vector<int> correct_answers(N + 1, 0);

    for (int i = 0; i < Q; ++i) {
        int winner;
        std::cin >> winner;
        correct_answers[winner]++;
    }

    for (int player = 1; player <= N; ++player) {
        int final_score = K - Q + correct_answers[player];

        if (final_score > 0) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}
