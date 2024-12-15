#include "Subject.h"

#include <cctype>
#include <sstream>

std::string Subject::f3(const std::unordered_map<std::string, std::string>& args) {
    std::string text = args.at("text");
    std::string operation = args.at("operation");

    if (operation == "replace") {
        size_t pos = text.find(args.at("find"));
        if (pos != std::string::npos) {
            text.replace(pos, args.at("find").length(), args.at("replace_with"));
        }
    } else if (operation == "find") {
        size_t pos = text.find(args.at("find"));
        return (pos != std::string::npos) ? std::to_string(pos) : "-1";
    } else if (operation == "capitalize_words") {
        std::istringstream stream(text);
        std::string word, result;
        while (stream >> word) {
            if (!word.empty()) {
                word[0] = std::toupper(word[0]);
            }
            result += word + " ";
        }
        text = result;
        text.pop_back();
    } else if (operation == "capitalize_sentences") {
        bool capitalize_next = true;
        for (char& ch : text) {
            if (capitalize_next && std::isalpha(ch)) {
                ch = std::toupper(ch);
                capitalize_next = false;
            }
            if (ch == '.' || ch == '!' || ch == '?') {
                capitalize_next = true;
            }
        }
    } else if (operation == "number_sentences") {
        std::istringstream stream(text);
        std::string sentence, result;
        int sentence_number = 1;
        while (std::getline(stream, sentence, '.')) {
            if (!sentence.empty()) {
                result += std::to_string(sentence_number++) + ". " + sentence + ".\n";
            }
        }
        text = result;
    }

    return text;
}