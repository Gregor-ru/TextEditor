#ifndef WRAPPER_H
#define WRAPPER_H

#include <string>
#include <unordered_map>
#include <functional>

class Subject;

class Wrapper {
public:
    using MethodType = std::function<std::string(const std::unordered_map<std::string, std::string>&)>;

    Wrapper(Subject* obj, MethodType method, const std::unordered_map<std::string, std::string>& defaults);

    std::string operator()(const std::unordered_map<std::string, std::string>& args);

private:
    Subject* object;
    MethodType method;
    std::unordered_map<std::string, std::string> defaultArgs;
};

#endif // WRAPPER_H