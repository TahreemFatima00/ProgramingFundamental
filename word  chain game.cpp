#include <iostream>
using namespace std;

class WordChainGame {
public:
    void startGame() {
        string usedWords[100];  
        string currentWord, lastWord;
        char lastChar = '\0';
        int playerTurn = 1;
        int usedCount = 0;  

        cout << "Word Chain Game! Player 1 starts:\n";

        while (true) {
            cout << "Player " << playerTurn << ", enter a word: ";
            cin >> currentWord;

            bool wordUsed = false;
            for (int i = 0; i < usedCount; ++i) {
                if (usedWords[i] == currentWord) {
                    wordUsed = true;
                    break;
                }
            }
            
            if (wordUsed) {
                cout << "This word has already been used! Try again.\n";
                continue;
            }

            if (lastChar == '\0') {
                usedWords[usedCount++] = currentWord; 
                lastChar = currentWord.back();       
            } 
            else {
                if (currentWord[0] != lastChar) {
                    cout << "The word must start with '" << lastChar << "'. Try again.\n";
                    continue;
                }
                usedWords[usedCount++] = currentWord;  
                lastChar = currentWord.back();      
            }

            playerTurn = (playerTurn == 1) ? 2 : 1;
        }
    }
};

int main() {
    WordChainGame game;
    game.startGame();
    return 0;
}
