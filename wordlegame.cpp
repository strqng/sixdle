using namespace std;
#include <iostream> 
#include <string> 
#include <fstream> 
#include <vector> 
#include <ctime> 


// open file, pixck random word
string getWord(const string& filename)
{
    std::cout << "game launched!";
    vector<string> words;
    string word;
    ifstream textFile(filename);

    while (getline(textFile, word))
    {
        words.push_back(word);
    }

    if (words.empty())
    {
        return " ";
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    int randIndex = rand() % words.size();

    return words[randIndex];

}

template<typename T>
void displayVector(const vector<T>& vec) 
{
    cout << "Current Status: ";
    for (const T& element : vec) 
    {
        cout << element;
    }
    cout << endl;
}

string wordGuess(const string& randWord)
{
    string word = randWord;
    string guess;
    int guessCount = 0;

    vector<string> correct(6, "_");
    while (true)
    {
        std::cout << "\nGuess: " << endl;
        cin >> guess;
        guessCount++;

            for(int i = 0; i < guess.size() && i < word.size(); i++)
            {
                if (guess[i] == word[i])
                {
                    correct[i] = guess[i];
                }

                for (int j = 0; j < word.size(); j++)
                {
                    if (guess[i] == word[j] && guess[i] != word[i])
                    {
                        std::cout << guess[i] << " is in the word, but the wrong spot" << endl;
                    }
                }
            }
        // update current guesses
        displayVector(correct);
        std::cout << "Total guesses: " << guessCount << "/6" << endl;

        //if all 6 letters are correct end the game

        if (guessCount == 6 && guess != word)
        {
            std::cout << "6 guesses reached, you lost";
            break;
        }
        if (guess == word)
        {
            std::cout << "Correct! Thank you for playing!";
            break;
        }
    }

    return 0;
}


//main
int main()
{
    // user input to launch game
    std::cout << "sixdle, worlde with six letters" << endl;
    std::cout << "Enter '1' To begin" << endl;
    int playGame;
    cin >> playGame;

    // if want to play, launch
    if (playGame == 1)
    {
        string filename = "sixletter.txt";
        string randWord = getWord(filename);
        wordGuess(randWord);
    }
    else
    {
        return 0;
    }
    return 0;
}