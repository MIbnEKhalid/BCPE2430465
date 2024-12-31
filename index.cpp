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

// Function to clear the console
void clearConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

// Function to pause the console
void pauseConsole() {
	cout << "Press Enter to continue...";
	cin.ignore();
}

// Function to get user input
string getUserInput() {
	string input;

	while (true) {
		getline(cin, input);
		if (!input.empty()) {
			break;
		}
		cout << "Input cannot be empty. Please try again: ";
	}
	return input;
}

// Function to check spelling
bool checkSpelling(const string& word, const string& userInput) {
	return word == userInput;
}

// Function to load words from a file
vector<string> loadWords(const string& filename) {
	vector<string> words;
	ifstream file(filename);
	if (!file) {
		cerr << "Error opening file: " << filename << endl;
		return words;
	}
	string word;
	while (file >> word) {
		words.push_back(word);
	}
	return words;
}

// Function to save words to a file
void saveWords(const vector<string>& words, const string& filename) {
	ofstream file(filename);
	if (!file) {
		cerr << "Error opening file: " << filename << endl;
		return;
	}
	for (const auto& word : words) {
		file << word << "\n";
	}
}

// Function for spelling practice
void spellingPractice(const vector<string>& words) {
	int correctCount = 0;

	clearConsole();
	cout << "Type the correct spelling of the given words.\n\n";
	cout << "Enter '<-' to go back to the main menu.\n\n";

	for (const auto& word : words) {
		cout << "Spell this word: " << word << "\n";
		string userInput = getUserInput();

		if (userInput == BACK_TO_MENU) {
			return;
		}

		if (checkSpelling(word, userInput)) {
			cout << "Correct!\n\n";
			correctCount++;
		}
		else {
			cout << "Incorrect. The correct spelling is: " << word << "\n\n";
		}
	}

	cout << "Spelling practice completed!\n";
	cout << "You spelled " << correctCount << " out of " << words.size() << " words correctly.\n";
	pauseConsole();
}

// Function to add a new word to the list
void addWord(vector<string>& words) {
	clearConsole();
	while (true) {
		cout << "Enter '<-' to go back to the main menu.\n\n";
		cout << "Enter the new word to add (no spaces allowed): ";
		string newWord = getUserInput();

		if (newWord == BACK_TO_MENU) {
			return;
		}

		if (newWord.find(' ') != string::npos) {
			cout << "Word contains spaces. Please try again.\n";
		}
		else if (find(words.begin(), words.end(), newWord) != words.end()) {
			cout << "Word already exists in the list. Please try again.\n";
		}
		else {
			words.push_back(newWord);
			cout << "Word added successfully!\n";
			break;
		}
	}
	pauseConsole();
}

// Function to view spelling practice words
void viewWords(const vector<string>& words) {
	clearConsole();
	cout << "Spelling Practice Words:\n";

	for (const auto& word : words) {
		cout << word << "\n";
	}
	pauseConsole();
}

void displayMenu() {
	clearConsole();
	cout << "Welcome to the Spelling Practice Application!\n";
	cout << "1. Start Spelling Practice\n";
	cout << "2. Add a New Word\n";
	cout << "3. View Spelling Practice Words\n";
	cout << "4. Exit\n";
	cout << "Please choose an option: ";
}

int main() {
	vector<string> words = loadWords("words.txt");
	if (words.empty()) {
		// Add predefined words whem file is empty or when new;ly created
		words = { "apple", "banana", "orange", "grape", "strawberry" };
		saveWords(words, "words.txt");
	}
	while (true) {
		displayMenu();
		string choice = getUserInput();

		if (choice == "1") {
			spellingPractice(words);
		}
		else if (choice == "2") {
			addWord(words);
			saveWords(words, "words.txt");
		}
		else if (choice == "3") {
			viewWords(words);
		}
		else if (choice == "4") {
			cout << "Exiting the application. Goodbye!\n";
			break;
		}
		else {
			cout << "Invalid option. Please try again.\n";
			pauseConsole();
		}
	}

	return 0;
}
