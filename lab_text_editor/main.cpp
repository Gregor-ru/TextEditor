#include "Engine.h"
#include "Wrapper.h"
#include "Subject.h"
#include "FileReader.h"
#include <iostream>

int main() {
    // Чтение содержимого файла
    std::string filename = "input.txt";
    std::string fileContent;

    try {
        FileReader fileReader(filename);
        fileContent = fileReader.getFileContent();
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    Subject subj;
    Wrapper wrapper(&subj, [&subj](const std::unordered_map<std::string, std::string>& args) { return subj.f3(args); },
        { {"operation", ""}, {"text", ""}, {"find", ""}, {"replace_with", ""} });

    Engine engine;
    engine.register_command(&wrapper, "command1");

    std::cout << "\nFile content:\n" << fileContent << "\n\n";

    // Операция: Замена слова
    std::unordered_map<std::string, std::string> args_replace = {
        {"operation", "replace"},
        {"text", fileContent},
        {"find", "oldWord"},
        {"replace_with", "newWord"}
    };
    std::cout << "Replace operation:\n" << engine.execute("command1", args_replace) << "\n\n";

    // Операция: Поиск словосочетания
    std::unordered_map<std::string, std::string> args_find = {
        {"operation", "find"},
        {"text", fileContent},
        {"find", "targetPhrase"}
    };
    std::cout << "Find operation:\n";
    int position = std::stoi(engine.execute("command1", args_find));
    std::cout << "Position of target phrase: " << (position >= 0 ? std::to_string(position) : "not found") << "\n\n";

    // Операция: Сделать первую букву каждого слова заглавной
    std::unordered_map<std::string, std::string> args_capitalize_words = {
        {"operation", "capitalize_words"},
        {"text", fileContent}
    };
    std::cout << "Capitalize words operation:\n" << engine.execute("command1", args_capitalize_words) << "\n\n";

    // Операция: Сделать первую букву каждого предложения заглавной
    std::unordered_map<std::string, std::string> args_capitalize_sentences = {
        {"operation", "capitalize_sentences"},
        {"text", fileContent}
    };
    std::cout << "Capitalize sentences operation:\n" << engine.execute("command1", args_capitalize_sentences) << "\n\n";

    // Операция: Нумерация предложений с новой строки
    std::unordered_map<std::string, std::string> args_number_sentences = {
        {"operation", "number_sentences"},
        {"text", fileContent}
    };
    std::cout << "Number sentences operation:\n" << engine.execute("command1", args_number_sentences) << "\n\n";

    return 0;
}
