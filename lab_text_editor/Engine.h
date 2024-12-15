#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <unordered_map>
#include <map>

class Wrapper; 

class Engine {
public:
    void register_command(Wrapper* wrapper, const std::string& command_name);
    std::string execute(const std::string& command_name, const std::unordered_map<std::string, std::string>& args);

private:
    std::map<std::string, Wrapper*> commands;
};

#endif // ENGINE_H