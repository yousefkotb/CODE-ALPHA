// task 2
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void displayDirectory(const fs::path& path) {
    if (fs::exists(path) && fs::is_directory(path)) {
        for (const auto& entry : fs::directory_iterator(path)) {
            std::cout << entry.path() << std::endl;
        }
    }
}

void createNewDirectory(const fs::path& path) {
    try {
        fs::create_directory(path);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void copyFile(const fs::path& source, const fs::path& destination) {
    try {
        fs::copy(source, destination);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    int userChoice;
    std::string inputPath1, inputPath2;

    while (true) {
        std::cout << "1. Display Directory\n2. Create New Directory\n3. Copy File\n4. Exit\nEnter your choice: ";
        std::cin >> userChoice;

        switch (userChoice) {
            case 1:
                std::cout << "Enter directory path: ";
                std::cin >> inputPath1;
                displayDirectory(inputPath1);
                break;
            case 2:
                std::cout << "Enter new directory path: ";
                std::cin >> inputPath1;
                createNewDirectory(inputPath1);
                break;
            case 3:
                std::cout << "Enter source file path: ";
                std::cin >> inputPath1;
                std::cout << "Enter destination file path: ";
                std::cin >> inputPath2;
                copyFile(inputPath1, inputPath2);
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
