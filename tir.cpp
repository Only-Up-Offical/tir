#include <iostream>
#include <fstream>
#include <filesystem>

void newCommand(const std::string& name) {
    try {
        std::filesystem::create_directory(name);

        std::string path = name + "/main.py";
        std::ofstream file(path);
        file << "print('Hello World')";

        std::cout << "Project " << name << " created!" << std::endl;
    } catch (...) {
        std::cout << "Failed to create project" << std::endl;
    }
}

void clearCommand(const std::string& name){
    std::filesystem::remove_all(name);
    std::cout << "Deleted project!" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "Only Up's package manager\n"
                     "\n"
                     "Available commands:\n"
                     "    tir new <project_name> // Creates folder with that name and main.cpp script in that folder\n"
                     "    tir clear <project_name> // Deletes folder with that name\n"
                     "\n"
                     "Stay updated!\n";
        return 0;
    }

    if (std::string(argv[1]) == "new" && argc > 2) {
        std::string projectName = argv[2];
        newCommand(projectName);
    } else if (std::string(argv[1]) == "clear" && argc > 2) {
        std::string projectName = argv[2];
        clearCommand(projectName);
    }

    return 0;
}
