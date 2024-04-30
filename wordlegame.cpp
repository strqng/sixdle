using namespace std;
#include <iostream> 
#include <string> 
#include <fstream> 
#include <vector> 
#include <ctime> 


// open file, pixck random word
string getWord(const string& filename)
{
    // empty string/vector for file intake
    vector<string> words;
    string word;

    ifstream textFile(filename);
    //scan each line of the file
    while (getline(textFile, word))
    {
        words.push_back(word);
    }
    //if it cant find words
    if (words.empty())
    {
        return " ";
    }
    //grab a random index of the sixletter.txt file, make it the guessing word
    srand(static_cast<unsigned int>(time(nullptr)));
    int randIndex = rand() % words.size();
    //return random word
    return words[randIndex];

}

//print vector contents, which is the users guess so far
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
    // vector made of "_", gets replaced when letters are found
    vector<string> correct(6, "_");
    while (true)
    {
        std::cout << "\nGuess: " << endl;
        cin >> guess;
        // keep track of guesses
        guessCount++;
        // for i < the size of the words/guess, keep playing
        for (int i = 0; i < guess.size() && i < word.size(); i++)
        {
            //if guess index matched word index, update correct vector
            if (guess[i] == word[i])
            {
                correct[i] = guess[i];
            }
            // loop through word, if any index of it matches user guess, it is in the word, but wrong spot
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

        //if user loses the game
        if (guessCount == 6 && guess != word)
        {
            std::cout << "6 guesses reached, you lost";
            break;
        }
        // if user wins the game
        if (guess == word)
        {
            std::cout << "Correct! Thank you for playing!";
            break;
        }
    }

    return 0;
}

int main()
{
    std::cout << "sixdle, worlde with six letters" << endl;

    // call function to get random word from sixletter.txt
    string filename = "sixletter.txt";
    string randWord = getWord(filename);

    // call wordGuess() to start game
    wordGuess(randWord);

    return 0;
}
