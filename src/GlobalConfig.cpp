#include "GlobalConfig.h"
#include <iostream>
#include <fstream>

#include "Camouflage.h"
#include "Carapace.h"
#include "Nageoire.h"
#include "Oreilles.h"
#include "Yeux.h"
#include "Bestiole.h"
#include "Nageoire.h"
#include "Milieu.h"
#include "BestioleFactory.h"


GlobalConfig::GlobalConfig()
{
    loadConfigFromFile("default.conf");
    setLimites();
}

/**
 * @brief Charge la configuration depuis un fichier
 * 
 * @param filename 
 */
void GlobalConfig::loadConfigFromFile(const std::string &filename)
{
    std::ifstream configFile(filename);
    if (configFile.is_open())
    {
        std::string line;
        while (std::getline(configFile, line))
        {
            size_t commentPos = line.find('#');
            size_t delimiterPos = line.find('=');
            if (delimiterPos != std::string::npos && (commentPos == std::string::npos || commentPos > delimiterPos))
            {
                std::string key = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 1);
                if(key == "DEFAULT_CONFIG_FILE")
                {
                    loadConfigFromFile(value);
                }
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

/**
 * @brief Définit les constantes de l'aquarium 
 * 
 */
void GlobalConfig::setLimites()
{
    int width = std::stoi(getConfig("width"));
    int height = std::stoi(getConfig("height"));
    int delay = std::stoi(getConfig("delay"));
    int nbBestioles = std::stoi(getConfig("nbBestioles"));
    double MAX_VITESSE = std::stod(getConfig("MAX_VITESSE"));
    double MIN_VITESSE = std::stod(getConfig("MIN_VITESSE"));
    int vieMin = std::stoi(getConfig("vieMin"));
    int vieMax = std::stoi(getConfig("vieMax"));

    double DIST_MAX_VOISINS = std::stod(getConfig("DIST_MAX_VOISINS"));
    double DIST_COLLISION = std::stod(getConfig("DIST_COLLISION"));
    double PSI_MIN = std::stod(getConfig("PSI_MIN"));
    double PSI_MAX = std::stod(getConfig("PSI_MAX"));
    double OMEGA_MAX = std::stod(getConfig("OMEGA_MAX"));
    double ETA_MAX = std::stod(getConfig("ETA_MAX"));
    double NU_MAX = std::stod(getConfig("NU_MAX"));
    double DELTA_O_MIN = std::stod(getConfig("DELTA_O_MIN"));
    double DELTA_O_MAX = std::stod(getConfig("DELTA_O_MAX"));
    double DELTA_Y_MIN = std::stod(getConfig("DELTA_Y_MIN"));
    double DELTA_Y_MAX = std::stod(getConfig("DELTA_Y_MAX"));
    double GAMMA_O_MIN = std::stod(getConfig("GAMMA_O_MIN"));
    double GAMMA_O_MAX = std::stod(getConfig("GAMMA_O_MAX"));
    double GAMMA_Y_MIN = std::stod(getConfig("GAMMA_Y_MIN"));
    double GAMMA_Y_MAX = std::stod(getConfig("GAMMA_Y_MAX"));
    double ALPHA_MIN = std::stod(getConfig("ALPHA_MIN"));
    double ALPHA_MAX = std::stod(getConfig("ALPHA_MAX"));

    double probaNaissanceSpontanee = std::stod(getConfig("probaNaissanceSpontanee"));
    double probaClonage = std::stod(getConfig("probaClonage"));
    double p_kamikaze = std::stod(getConfig("p_kamikaze"));
    double p_peureuse = std::stod(getConfig("p_peureuse"));
    double p_gregaire = std::stod(getConfig("p_gregaire"));
    double p_prevoyante = std::stod(getConfig("p_prevoyante"));

    double p_carapace = std::stod(getConfig("p_carapace"));
    double p_nageoire = std::stod(getConfig("p_nageoire"));
    double p_oreilles = std::stod(getConfig("p_oreilles"));
    double p_yeux = std::stod(getConfig("p_yeux"));
    double p_camouflage = std::stod(getConfig("p_camouflage"));

    int maxParDecorateur = std::stoi(getConfig("maxParDecorateur"));


    Camouflage::setLimites(PSI_MIN, PSI_MAX);
    Carapace::setLimites(OMEGA_MAX, ETA_MAX);
    Nageoire::setLimites(NU_MAX);
    Oreilles::setLimites(DELTA_O_MIN, DELTA_O_MAX, GAMMA_O_MIN, GAMMA_O_MAX);
    Yeux::setLimites(ALPHA_MIN, ALPHA_MAX, DELTA_Y_MIN, DELTA_Y_MAX, GAMMA_Y_MIN, GAMMA_Y_MAX);
    Bestiole::setLimites(MAX_VITESSE, MIN_VITESSE, vieMax, vieMin);
    Milieu::setLimites(DIST_MAX_VOISINS, DIST_COLLISION, probaNaissanceSpontanee, probaClonage);
    BestioleFactory::setLimites(p_kamikaze, p_peureuse, p_gregaire, p_prevoyante);



}

std::shared_ptr<GlobalConfig> GlobalConfig::getInstance()
{
    if (instance == nullptr)
    {
        std::shared_ptr<GlobalConfig> newShared(new GlobalConfig());
        instance = std::move(newShared);
    }
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
