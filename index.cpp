#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

const string BACK_TO_MENU = "<-";

// ANSI escape codes for colors
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

// Function to clear the console
void clearConsole()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

// Function to pause the console
void pauseConsole()
{
	cout << "Press Enter to continue...";
	cin.ignore();
}

// Function to get user input
string getUserInput()
{
	string input;

	while (true)
	{
		getline(cin, input);
		if (!input.empty())
		{
			break;
		}
		cout << "Input cannot be empty. Please try again: ";
	}
	return input;
}

// Function to check spelling
bool checkSpelling(const string& word, const string& userInput)
{
	return word == userInput;
}

// Function to load words from a file
vector<string> loadWords(const string& filename)
{
	vector<string> words;
	ifstream file(filename);
	if (!file)
	{
		cerr << "Error opening file: " << filename << endl;
		return words;
	}
	string word;
	while (file >> word)
	{
		words.push_back(word);
	}
	return words;
}

// Function to save words to a file
void saveWords(const vector<string>& words, const string& filename)
{
	ofstream file(filename);
	if (!file)
	{
		cerr << "Error opening file: " << filename << endl;
		return;
	}
	for (const auto& word : words)
	{
		file << word << "\n";
	}
}

// Function for spelling practice
void spellingPractice(const vector<string>& words)
{
	int correctCount = 0;

	clearConsole();
	cout << CYAN << "Type the correct spelling of the given words.\n\n"
		<< RESET;
	cout << YELLOW << "Enter '<-' to go back to the main menu.\n\n"
		<< RESET;

	cout << "How many words out of " << words.size() << " do you want to practice? ";
	int numWords;
	cin >> numWords;
	cin.ignore(); // To consume the newline character left by cin

	while (numWords > words.size() || numWords <= 0)
	{
		cout << RED << "Invalid number of words.\n"
			<< RESET;
		cout << "Entre Again: ";
		cin >> numWords;
		cin.ignore(); // To consume the newline character left by cin

	}

	for (int i = 0; i < numWords; ++i)
	{
		cout << "Spell this word: " << words[i] << "\n";
		string userInput = getUserInput();

		if (userInput == BACK_TO_MENU)
		{
			return;
		}

		if (checkSpelling(words[i], userInput))
		{
			cout << GREEN << "Correct!\n\n"
				<< RESET;
			correctCount++;
		}
		else
		{
			cout << RED << "Incorrect. The correct spelling is: " << words[i] << "\n\n"
				<< RESET;
		}
	}

	cout << CYAN << "Spelling practice completed!\n"
		<< RESET;
	cout << "You spelled " << correctCount << " out of " << numWords << " words correctly.\n";
	pauseConsole();
}

// Function to add a new word to the list
void addWord(vector<string>& words)
{
	clearConsole();
	while (true)
	{
		cout << YELLOW << "Enter '<-' to go back to the main menu.\n\n"
			<< RESET;
		cout << "Enter the new word to add (no spaces allowed): ";
		string newWord = getUserInput();

		if (newWord == BACK_TO_MENU)
		{
			return;
		}

		if (newWord.find(' ') != string::npos)
		{
			cout << RED << "Word contains spaces. Please try again.\n"
				<< RESET;
		}
		else if (find(words.begin(), words.end(), newWord) != words.end())
		{
			cout << RED << "Word already exists in the list. Please try again.\n"
				<< RESET;
		}
		else
		{
			words.push_back(newWord);
			cout << GREEN << "Word added successfully!\n"
				<< RESET;
			break;
		}
	}
	pauseConsole();
}

// Function to view spelling practice words
void viewWords(const vector<string>& words)
{
	clearConsole();
	cout << CYAN << "Spelling Practice Words:\n"
		<< RESET;

	for (const auto& word : words)
	{
		cout << word << "\n";
	}
	pauseConsole();
}

void displayMenu()
{
	clearConsole();
	cout << "---------------------------------------\n"; 
	cout << MAGENTA << "Developed by Muhammad Bin Khalid\n"
		<< RESET;
	cout << "----------------------------------------\n";
	cout << BLUE << "Welcome to the Spelling Practice Application!\n"
		<< RESET;
	cout << "1. Start Spelling Practice\n";
	cout << "2. Add a New Word\n";
	cout << "3. View Spelling Practice Words\n";
	cout << "4. Exit\n";
	cout << "Please choose an option: ";
}

int main()
{
	vector<string> words = loadWords("words.txt");
	if (words.empty())
	{
		// Add predefined words when file is empty or newly created
		words = { "apple", "banana", "orange", "grape", "strawberry" };
		saveWords(words, "words.txt");
	}
	while (true)
	{
		displayMenu();
		string choice = getUserInput();

		if (choice == "1")
		{
			spellingPractice(words);
		}
		else if (choice == "2")
		{
			addWord(words);
			saveWords(words, "words.txt");
		}
		else if (choice == "3")
		{
			viewWords(words);
		}
		else if (choice == "4")
		{
			cout << "Exiting the application. Goodbye!\n";
			break;
		}
		else
		{
			cout << RED << "Invalid option. Please try again.\n"
				<< RESET;
			pauseConsole();
		}
	}



	return 0;
}
