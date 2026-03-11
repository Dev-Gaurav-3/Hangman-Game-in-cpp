#include <bits/stdc++.h>
using namespace std;

struct WordHint {
    string word;
    string hint; // hint before the round starts
};

void drawHangman(int chance) {
    cout << "\n";

    if (chance == 0) cout << "  O\n";
    if (chance == 1) cout << "  O\n  |\n";
    if (chance == 2) cout << "  O\n /|\n";
    if (chance == 3) cout << "  O\n /|\\\n";
    if (chance == 4) cout << "  O\n /|\\\n /\n";
    if (chance >= 5) cout << "  O\n /|\\\n / \\\n";
}

int main() {

    vector<WordHint> words = {                     // vector storing words and their hints 
        {"apple", "A fruit"},
        {"computer", "Electronic machine"},
        {"programming", "Writing code"},
        {"algorithm", "Step by step problem solving"},
        {"keyboard", "Used for typing"},
        {"developer", "Person who writes software"},
        {"variable", "Stores a value in programming"},
        {"function", "Reusable block of code"},
        {"compiler", "Converts code into machine language"},
        {"debugging", "Finding and fixing errors in code"},
        {"internet", "Global network connecting computers"},
        {"database", "Organized collection of data"},
        {"pointer", "Stores memory address in C++"},
        {"recursion", "Function calling itself"},
        {"iteration", "Repeating a set of instructions"},
        {"binary", "Number system using 0 and 1"},
        {"encryption", "Securing data by encoding it"},
        {"network", "Connected group of computers"},
        {"firewall", "Security system for networks"},
        {"linux", "Popular open-source operating system"},
    };

    srand(time(0)); // give times in seconds

    int idx = rand() % words.size(); 

    string word = words[idx].word;
    string hint = words[idx].hint;

    string guessed(word.length(), '_');

    int chance = 0;
    int maxAttempts = 6;

    cout << "====== HANGMAN ======\n";
    cout << "Hint: " << hint << endl;

    while (chance < maxAttempts && guessed != word) {

        cout << "\nWord: " << guessed << endl;

        cout << "Guess a letter: ";
        char guess;
        cin >> guess;

        bool found = false;

        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                found = true;
            }
        }

        if (!found) {
            chance++;
            cout << "Wrong guess!\n";
        }

        drawHangman(chance);
    }

    if (guessed == word)
        cout << "\nYou Win! The word was: " << word << endl;
    else
        cout << "\nGame Over! The word was: " << word << endl;

}
