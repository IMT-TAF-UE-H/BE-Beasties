#ifndef GLOBALCONFIG_H
#define GLOBALCONFIG_H

#include <string>
#include <map>

class GlobalConfig
{
private:
    static std::map<std::string, std::string> configMap;
    static std::shared_ptr<GlobalConfig> instance;

    GlobalConfig(); // private constructor

public: 

    static void loadConfigFromFile(const std::string &filename);
    static void setLimites();
    static std::string getConfig(const std::string &key); 

};

#endif
