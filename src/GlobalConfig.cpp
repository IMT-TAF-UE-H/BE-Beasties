#include "GlobalConfig.h"
#include <iostream>
#include <fstream>

GlobalConfig::GlobalConfig()
{
    loadConfigFromFile("config.txt");
}

void GlobalConfig::loadConfigFromFile(const std::string &filename)
{
    std::ifstream configFile(filename);
    if (configFile.is_open())
    {
        std::string line;
        while (std::getline(configFile, line))
        {
            size_t commentPos = line.find('//');
            size_t delimiterPos = line.find('=');
            if (delimiterPos != std::string::npos && (commentPos == std::string::npos || commentPos > delimiterPos))
            {
                std::string key = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 1);
                configMap[key] = value;
            }
        }
        configFile.close();
    }
    else
    {
        std::cerr << "Error: Unable to open config file " << filename << std::endl;
    }
}

GlobalConfig &GlobalConfig::getInstance()
{
    static GlobalConfig instance;
    return instance;
}

std::string GlobalConfig::getConfig(const std::string &key) const
{
    auto it = configMap.find(key);
    if (it != configMap.end())
    {
        return it->second;
    }
    else
    {
        std::cerr << "Error: Configuration key " << key << " not found" << std::endl;
        return "";
    }
}
