#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream> 
#include <windows.h>   
#include <conio.h>
#include <iomanip> 
#include <sstream>   

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

void CentredMessage(const string& textMessage)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	rows = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	istringstream iss(textMessage);
	string line;

	while (getline(iss, line))
	{
		if (line.size() <= rows)
		{
			int startPosition = (rows - line.size()) / 2;
			cout << setw(startPosition + line.size()) << line << endl;
		}

		else
		{
			// Split the line into two parts for better centering
			size_t middle = line.size() / 2;
			string part1 = line.substr(0, middle);
			string part2 = line.substr(middle);
			int startPositionPart1 = (rows - part1.size()) / 2;
			int startPositionPart2 = (rows - part2.size()) / 2;
			cout << setw(startPositionPart1 + part1.size()) << part1 << endl;
			cout << setw(startPositionPart2 + part2.size()) << part2 << endl;
		}
	}
}

void rlines(const string& textMessage)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	rows = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	istringstream iss(textMessage);
	string line;

	if (textMessage.size() > 1)
	{
//Only One Character is allowed
		return;
	}

	for (int i = 0; i < rows; i++)
	{
		cout << textMessage;
	}
	cout << "\n";
} 

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
void displayMenu()
{
	clearConsole();
	rlines("-");
	cout << YELLOW;
	CentredMessage("Developed by Muhammad Bin Khalid");
	CentredMessage("Source Code: https://github.com/MIbnEKhalid/ICTLabProject");
	cout << RESET;
	rlines("-");

	cout << CYAN;
	CentredMessage("\nWelcome to the Spelling Practice Application!\n");
	cout << RESET;

	cout << "1. Start Spelling Practice\n";
	cout << "2. Add a New Word\n";
	cout << "3. View Spelling Practice Words\n";
	cout << "4. Exit\n";
	cout << "Please choose an option: ";
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
	string numWords;
	cin >> numWords;
	cin.ignore(); // To consume the newline character left by cin



	while (!isdigit(numWords[0]) || numWords.size() > 1)
	{
		if (numWords == BACK_TO_MENU)
		{
			return;
			displayMenu();
		}
		cout << RED << "Invalid Input\n"
			<< RESET;
		cout << "Entre Again: ";
		cin >> numWords;
		cin.ignore(); // To consume the newline character left by cin

	}
	int num = stoi(numWords);

	while (num > words.size() || num < 1)
	{
		if (numWords == BACK_TO_MENU)
		{
			return;
			displayMenu();
		}
		cout << RED << "Invalid number of words.\n"
			<< RESET;
		cout << "Entre Again: ";
		cin >> numWords;
		cin.ignore(); // To consume the newline character left by cin

	}

	for (int i = 0; i < num; ++i)
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

