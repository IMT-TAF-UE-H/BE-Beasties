# Compiler et exécuter le programme principal

## Prérequis
- GNU Compiler Collection (GCC) ou n'importe quel compilateur C++ installé sur le système.
- Utilitaire `make` installé sur le système pour compiler avec le Makefile.

## Compiler le code source du projet

Pour compiler le projet une fois téléchargé, suivez les étapes suivantes dans votre terminal bash :

```bash
cd path/to/the/project
make
```

Ceci compilera le code source en utilisant le Makefile, et produira un exécutable nommé `main`.

## Démarrer le programme via l'exécutable
Après avoir [compilé le projet](#compiler-et-exécuter-le-programme-principal), vous pouvez lancer l'exécutable avec:
```bash
./main [config]
```
L'argument `config` est optionnel, et doit correspondre à un nom de fichier `.conf` dans le répertoire `config/`.
Cela
Il remplace la configuration de `default.conf`. 
Tous les paramètres non spécifiés seront pris dans la configuration par défaut, 
qui doit être définie dans le paramètre `DEFAULT_CONFIG_FILE`.
Par exemple, la commande suivante utilisera le fichier de configuration `config/default.conf` :
```bash
./main default
```
Equivalent à :
```bash
./main
```

**_NB_**: Si un problème de permission apparaît, lancer `chmod +x main` pour rendre le fichier exécutable.
