#ifndef GLOBALCONFIG_H
#define GLOBALCONFIG_H

#include <string>
#include <map>

class GlobalConfig
{
private:
    std::map<std::string, std::string> configMap;
    static std::shared_ptr<GlobalConfig> instance;

    GlobalConfig(); // private constructor

    void loadConfigFromFile(const std::string &filename);
    void setLimites();

public:
    static std::shared_ptr<GlobalConfig> getInstance();

    std::string getConfig(const std::string &key) const;
};

#endif
