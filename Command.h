//
// Created by lezenn on 27/12/2019.
//

#ifndef HYDROGEN_COMMAND_H
#define HYDROGEN_COMMAND_H

#include <string>
#include <vector>

class Command {

public:
    Command(std::string line);
    ~Command() = default;

    int execute();

    std::string get_command_name() const;

private:
    std::string command_name;
    std::vector<std::string> arguments; // does not include command name
    int return_code;
};


#endif //HYDROGEN_COMMAND_H
