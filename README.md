# Spelling Practice Application With Feedback

## Overview
This is a simple C++ console application designed to help users practice their spelling. The application allows users to start a spelling practice session, add new words to the practice list, view the current list of words, and exit the application.

## Features
- **Spelling Practice**: Users can practice spelling words from a predefined list or a list loaded from a file.
- **Add New Words**: Users can add new words to the practice list.
- **Delete Words**: Users can delete words from the practice list.
- **View Words**: Users can view the current list of words for practice.
- **Save and Load Words**: The application saves the list of words to a file and loads them when the application starts.
- Clear and pause the console for better user experience.
- Centered Message Display.
- Input Validations
- Colored Text

## Installation
1.	Clone the repository:
    ```ssh
       git clone https://github.com/MIbnEKhalid/ICTLabProject.git
    ```
2.	Navigate to the project directory:
    ```ssh
       cd ICTLabProject
    ```

## Compilation 
To compile the application, follow one of these methods:

1.	Using Batch Files:
       -	Run `compile(index).bat` to compile `index.cpp`.
       -	Run `compile(UIless).bat` to compile `UIless.cpp`.
         
    Make sure you have g++ installed in your deivce

   
2.	Using Command Line:
       -	Use the following command to compile:
       ```ssh
           g++ -o spelling_practice filename.cpp
       ```
       
    Make sure you have g++ installed in your deivce
    
3.	Using an IDE:
       -	Copy and paste the code into your IDE and compile it directly.
  
You Can Download and Run PreBuil Application from Release: [Download PreBuil Application](https://github.com/MIbnEKhalid/ICTLabProject/releases/tag/release)

### Dev-C++ Instructions
If you are using Dev-C++, follow these instructions before running the program:
1. Click on the `Tools` button on the top bar.
2. Click on `Compiler Options`.
3. Click on `Settings`.
4. Click on `Code Generation`.
5. Change the Language standard to `ISO C++11`.


## Troubleshooting
If you encounter issues compiling this program, try compiling `UIless.cpp`.
This file does not contain the `CentredMessage` function or `color codes`, which might resolve your compilation issues.

## Dependencies
### C++11 or later
### CentredMessage
The CentredMessage function displays a centered message in the console.
It uses the console screen buffer information to determine the console width and centers the message accordingly.

Github Link: [github.com/MIbnEKhalid/CentreTheMessageCpp](https://github.com/MIbnEKhalid/CentreTheMessageCpp)
### Required Libaries
- `iostream`: For input/output operations.
- `windows.h`: For console functions like SetConsoleCursorPosition, GetStdHandle, etc.
- `fstream`: For file input/output operations.
- `string`: For string operations.
- `vector`: For vector operations.
- `algorithm`: For algorithm operations.
- `conio.h`: For console input/output operations.
- `iomanip`: For input/output manipulations. (Required for only CenterMessage function)
- `sstream`: For string stream operations. (Required for only CenterMessage function)


## Usage
1. **Start the Application**: Run the application executable.
2. **Main Menu**:
    - **1. Start Spelling Practice**: Begin a spelling practice session.
    - **2. Add a New Word**: Add a new word to the practice list.
    - **3. View Spelling Practice Words**: View the current list of words.
    - **4. Delete Spelling Practice Words**: Delete words from the practice list.
    - **5. Exit**: Exit the application.

## Special Commands
- During any input prompt, entering `<-` will take you back to the main menu.

## Data Storage
- `words.txt`: The file where the list of words is saved and loaded from.
  
## License 

**Note:** Only The Source Code Of This Website Is Covered Under The **[MIT License](https://opensource.org/license/mit)**.  
The Project Documentation Covered Under The **[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](https://creativecommons.org/licenses/by-nc-sa/4.0/)** But Some **Images, Blog Posts, And Other Content Are NOT  
Covered Under This License And Remain The Intellectual Property Of The Author**.

See the [LICENSE](LICENSE.md) file for details.
 
## Contact

For questions or contributions, please contact Muhammad Bin Khalid at [mbktechstudio.com/Support](https://mbktechstudio.com/Support/), [support@mbktechstudio.com](mailto:support@mbktechstudio.com) or [chmuhammadbinkhalid28.com](mailto:chmuhammadbinkhalid28.com).
