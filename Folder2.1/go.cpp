#include <iostream> //To talk
#include <cstdlib> // For the random
#include <ctime> // More for the randomness
using namespace std; // Using the standard namespace
// string words[] = {"in", "then", "if", "bye", "nice", "no", "yes", "okay", "fine", "poverty", "hola", "kid", "shreya", "lose", "win", "bad", "yep", "try", "cat", "dog", "go", "for", "kola", "hand", "head", "way", "pick", "chose"}; // Choices
string words[] = {"boolean", "string", "integer", "character", "float", "double", "array", "if", "else", "for", "while", "loop", "var", "function", "parameters", "variable", "constant", "algorithm", "machine learning", "deep learning", "operating system", "linux", "mac", "windows", "xor", "or", "nor", "and", "nand", "nor", "xnor", "coding", "program", "sarah"};
bool pick(int); // It will ask for input then return whether it's in or not
bool already(char);
int mainline(); // The main line
void draw(); // Draws the hangman
int lives = 6; // Number of lives
int pos; // The position of the word in the array
int total = 0; // Total number of correct guesses
int word_length = 0; // How long the word is
string theword; // The word
char worder[100]; // char[] of the spaces
char lett[26];
int alphaPos = 0;
bool done = false;
int main() {
    srand(time(NULL));
    int rows = (sizeof(words)/sizeof(words[0]));
    pos = rand() % rows;
    theword = words[pos];
    for (int i = 0; i < sizeof(theword); i++) {
        if (theword[i]) {word_length++; worder[i] = '_';}
    }
    cout << worder << /*endl << word_length << */endl;
    draw();
    mainline();
    return 0;
}
int mainline() {
    if (!done) {
        if (pick(pos)) {
            cout << "Congrats. You got it right!" << endl;
            if ((total) >= (word_length-1)) {
                cout << worder << endl;
                cout << "Yay! You got it! You win!!!!!" << endl;
                done = true;
                return 0;
            } else {
                draw();
                cout << "Lives:: " << lives << endl;
                cout << worder << endl;
                mainline();
            }
        } else {
            cout << "Nope. Try Again" << endl;
            lives--;
            if (lives <= 0) {
                cout << "You lost. The correct word was:: " << words[pos] << endl;
                done = true;
                return 0;
            } else {
                draw();
                cout << "Lives:: " << lives << endl;
                cout << worder << endl;
                mainline();
            }
        }
    }
    return 0;
}
bool already(char cho) {
    for (int i = 0; i < sizeof(lett); i++) {
        if (lett[i] == cho) {
            return true;
        }
    }
    lett[alphaPos] = cho;
    alphaPos++;
    return false;
}
bool pick(int word) {
    char think;
    cout << "Pick a letter, any letter:: ";
    cin >> think;
    if (already(think)) {
        cout << "Um... you've already said that. Try again?" << endl;
        mainline();
    }
    bool yes = false;
    int tot = 0;
    for (int i = 0; i < sizeof(words[word]); i++)
        if (words[word][i] == think) {
            worder[i] = think;
            yes = true;
            tot++;
        }
    total+=tot;
    return yes;
}
void draw() {
    if (lives == 0) {
        cout << "        \n  ______\n  |    | \n|* *|  | \n- | -  |  \n / \\   |  \n       | \n  _____|___" << endl;
    }
    else if (lives == 1) {
        cout << "        \n  ______\n  |    | \n|* *|  | \n- | -  |  \n /     |  \n       | \n  _____|___" << endl;
    }
    else if (lives == 2) {
        cout << "        \n  ______\n  |    | \n|* *|  | \n- | -  |  \n       |  \n       | \n  _____|___" << endl;
    }
    else if (lives == 3) {
        cout << "        \n  ______\n  |    | \n|* *|  | \n  | -  |  \n       |  \n       | \n  _____|___" << endl;
    }
    else if (lives == 4) {
        cout << "        \n  ______\n  |    | \n|* *|  | \n  |    |  \n       |  \n       | \n  _____|___" << endl;
    }
    else if (lives == 5) {
        cout << "        \n  ______\n  |    | \n|* *|  | \n       |  \n       |  \n       | \n  _____|___" << endl;
    }
    else if (lives == 6) {
        cout << "        \n  ______\n  |    | \n       | \n       |  \n       |  \n       | \n  _____|___" << endl;
    }
}
