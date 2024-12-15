#include "Engine.h"
#include "Wrapper.h"

void Engine::register_command(Wrapper* wrapper, const std::string& command_name) {
    commands[command_name] = wrapper;
}

std::string Engine::execute(const std::string& command_name, const std::unordered_map<std::string, std::string>& args) {
    if (commands.find(command_name) != commands.end()) {
        return (*commands[command_name])(args);
    }
    return "Command not found.";
}