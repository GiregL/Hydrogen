#include <iostream>
#include <string>

#include "Command.h"

void print_prompt()
{
    std::cout << ">>> ";
}

std::string get_command()
{
    std::string res;
    std::getline(std::cin, res);
    return res;
}

int loop()
{
    bool finished(false);
    while (!finished)
    {
        print_prompt();
        std::string command = get_command();
        Command cmd = Command{command};

        if (cmd.get_command_name() == "exit")
        {
            finished = true;
        }
        else
        {
            int return_code = cmd.execute();
            std::cout << "Return code for [" << cmd.get_command_name() << "] : " << return_code << std::endl;
            std::cout.flush();
        }
    }
    return 0;
}

int main()
{
    return loop();
}