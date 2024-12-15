#include "Wrapper.h"
#include "Subject.h"

Wrapper::Wrapper(Subject* obj, MethodType method, const std::unordered_map<std::string, std::string>& defaults)
    : object(obj), method(method), defaultArgs(defaults) {}

std::string Wrapper::operator()(const std::unordered_map<std::string, std::string>& args) {
    std::unordered_map<std::string, std::string> allArgs = defaultArgs;
    for (const auto& arg : args) {
        allArgs[arg.first] = arg.second;
    }
    return method(allArgs);
}