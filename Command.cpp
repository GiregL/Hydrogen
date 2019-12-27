//
// Created by lezenn on 27/12/2019.
//

#include "Command.h"

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/wait.h>

Command::Command(std::string line)
{
    std::vector<std::string> parts;
    std::string accumulator;
    for (char & v : line)
    {
        if (v == ' ' || v == '\t')
        {
            // Split
            parts.push_back(accumulator);
            accumulator.clear();
        }
        else
        {
            accumulator.push_back(v);
        }
    }
    parts.push_back(accumulator);

    command_name = parts[0];
    parts.erase(parts.begin());
    arguments = parts;
}

int Command::execute()
{
    int return_code;
    int pid(fork());
    if (pid == 0)
    {
        // Child
        return_code = execvp(command_name.c_str(), reinterpret_cast<char *const *>(arguments.data()));
        perror("Failed to start processus");
        exit(return_code);
    }
    else if (pid > 0)
    {
        // Parent
        waitpid(pid, &return_code, 0);
    }
    else
    {
        // Error
        return_code = pid;
    }
    std::cout << "Executed " << command_name << std::endl;
    this->return_code = return_code;
    return return_code;
}

std::string Command::get_command_name() const {
    return command_name;
}
