#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Trump {
    private:
        std::string suit;
        int num;

    public:
        void set_trump(std::string _suit, int _num) {
            suit = _suit;
            num = _num;
        }

        void view_card() {
            std::cout << suit << " ";
            if (num == 11) std::cout << "Jack" << std::endl;
            else if (num == 12) std::cout << "Queen" << std::endl;
            else if (num == 13) std::cout << "King" << std::endl;
            else std::cout << num << std::endl;
        }

        int return_num() {
            if (num == 11) return 10;
            else if (num == 12) return 10;
            else if (num == 13) return 10;
            return num;
        }
};

std::vector<Trump> resetDeck() {
    std::vector<Trump> deck;

    for (int i = 1; i < 53; i++) {
        Trump card;
        if (i < 14) card.set_trump("Spade  ", i);
        else if (i < 27) card.set_trump("Diamond", i-13);
        else if (i < 40) card.set_trump("Heart  ", i-26);
        else card.set_trump("Clover ", i-39);
        deck.push_back(card);
    }

    return deck;
}

int randomfunc(int j)
{
    return rand() % j;
}

int main(void) {
    std::vector<Trump> deck;
    deck = resetDeck();
    srand(time(NULL));
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(rand() % 10));

    /* Print Trump card deck */
    // for (auto c : deck) {
    //     c.view_card();
    // }

    std::vector<Trump> dealer;
    std::vector<Trump> player;

    dealer.push_back(deck.back());
    deck.pop_back();
    player.push_back(deck.back());
    deck.pop_back();
    dealer.push_back(deck.back());
    deck.pop_back();
    player.push_back(deck.back());
    deck.pop_back();

    int dealer_score = 0;
    int player_score = 0;

    for (auto c : dealer) {
        dealer_score += c.return_num();
    }
    for (auto c : player) {
        player_score += c.return_num();
    }

    while (player_score < 22) {
        std::cout << "[ Dealer ]" << std::endl;
        std::cout << "******* *" << std::endl;
        for (int i = 1; i < dealer.size(); i++) {
            dealer[i].view_card();
        }
        std::cout << "----------" << std::endl;
        std::cout << "[ Player ]" << std::endl;
        for (auto c : player) {
            c.view_card();
        }

        char draw_ans;
        std::cout << "Do you want draw?(Y/N) : ";
        std::cin >> draw_ans;

        if (draw_ans == 'Y' || draw_ans == 'y') {
            player.push_back(deck.back());
            player_score += deck.back().return_num();
            deck.pop_back();
        } else if (draw_ans == 'N' || draw_ans == 'n') {
            if (player_score > dealer_score)std::cout << "You Wins!" << std::endl;
            else if (player_score == dealer_score) std::cout << "Draws" << std::endl;
            else std::cout << "You Lose..." << std::endl;
            std::cout << "!~~ Game Over ~~ !" << std::endl;
            return 0;
        }

        if (dealer_score <= 16) {
            dealer.push_back(deck.back());
            dealer_score += deck.back().return_num();
            deck.pop_back();
        }
    }

    std::cout << "[ Dealer ]" << std::endl;
    std::cout << "******* *" << std::endl;
        for (int i = 1; i < dealer.size(); i++) {
            dealer[i].view_card();
        }
    std::cout << "----------" << std::endl;
    std::cout << "[ Player ]" << std::endl;
    for (auto c : player) {
        c.view_card();
    }

    std::cout << "You Burst and Lose..." << std::endl;
    std::cout << "!~~ Game Over ~~ !" << std::endl;

    return 0;
}