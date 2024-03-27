# BE-Bestioles

## Etudiants
- Thibaut RUZICKA
- Jules DECAESTECKER
- Gabriel DUMONT
- Ella FERNANDEZ
- Jonathan LYS

## Description

Le projet BE-Bestioles fait partie de l'UE "UE-TAF PA-DI-CPP-H-B Advanced C++ programming",
de l'école d'ingénieur IMT Atlantique. Les exigences du livrable sont spécifiées sur le [Moodle de l'IMT Atlantique](https://moodle.imt-atlantique.fr/pluginfile.php/36084/mod_resource/content/1/BE.pdf),
(sous réserve de droits d'accès), mais aussi dans le fichier [docs/assignment.pdf](./docs/assignment.pdf).

## Déploiement et utilisation

Un [guide de déploiement et d'utilisation](./docs/DEPLOYING.md), expliquant comment compiler et utiliser l'application,
est disponible dans la section [documentation](./docs).

## Informations relatives

- **Plateformes supportées**: Linux (Ubuntu 22.04 LTS),  Windows (WSL requis)
- **Langages de programmation**:
    - C++ 14
- **Librairies / Frameworks / Plateformes**:
    - C++ STL

## Architecture de fichiers du dépôt

```
BE-Bestioles/                     Le dépôt de code
├── README.md                          Ce document
├── Makefile                           Fichier permettant de compiler le code en un exécutable grâce à make
├── docs/                              Documentation du projet
│   ├── assignment.pdf                 Cahier des charges / Exigences du projet
│   ├── DEPLOYING.md                   Guide expliquant le déploiement et l'utilisation de l'application
│   ├── MODELING.md                    Rapport de conception de l'application
│   ├── slides.pdf                     Slides de présentation du projet
│   └── diagrams/                      Diagrammes UML de cas d'utilisation, de classes et de séquences
│       └── ... 
└── src/                               Code source du projet
    ├── main.cpp                       Point d'entrée de l'application
    ├── SomeClassFile.h                Fichier header de classe C++
    └── SomeClassFile.cpp              Fichier source de classe C++
```


