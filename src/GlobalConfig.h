#ifndef GLOBALCONFIG_H
#define GLOBALCONFIG_H

#include <string>
#include <map>

class GlobalConfig
{
private:
    std::map<std::string, std::string> configMap;

    GlobalConfig(); // private constructor

    void loadConfigFromFile(const std::string &filename);

public:
    static GlobalConfig &getInstance();

    std::string getConfig(const std::string &key) const;
};

#endif
