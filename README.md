# BE-Beasties

## Description

The project BE-Beasties is part of the "UE-TAF PA-DI-CPP-H-B Advanced C++ programming" teaching unit,
of the engineering course at IMT Atlantique.
The project assignment is available on the [teaching unit Moodle workspace](https://moodle.imt-atlantique.fr/pluginfile.php/36084/mod_resource/content/1/BE.pdf)
(subject to the right of access to the platform), and in [assignment.pdf](./docs/assignment.pdf) file.

## Using / Deploying our system

You can find a [deployment guide](./docs/DEPLOYING.md) on how to compile and use our system,
in the [documentation](./docs) section.

## Metadata

- **Timestamp**: 2024-03-08
- **Last update**: 2024-03-08
- **Status**: In development
- **Current Version**: 0.1.0
- **Supported Platforms**: Linux / Windows WSL
- **Programming languages**:
    - C++ 17
- **Libraries / Frameworks / Platforms**:
    - C++ STL
- **Compatibility Issues** : None known at this time

## Repository architecture

```
BE-Beasties/                     This repository
├── README.md                          This document
├── LICENSE.md                         License in place for this project
├── Makefile                           File for compiling code into executable file, using make Linux dependency
├── .gitattributes                     Used to adjust how Git handles changes to certain files, ensuring consistent behavior for all contributors
├── .gitignore                         Text file that tells Git which files or directories to ignore in a project
├── .github/                           Used by GitHub review management and CI/CD workflows when available
│   └── CODEOWNERS                     Detail which team-member has to review which changes
├── docs/                              All GitHub and project documentation
│   ├── assignment.pdf                 Project global assignment
│   ├── CONTRIBUTING.md                Explains how to contribute to the project, by respecting some rules
│   ├── DEPLOYING.md                   A comprehensive guide on how to compile and run the application
│   └── CHANGELOG.md                   Tracked changes in the project's lifecycle
└── src/                               All the source code of the project
    ├── main.cpp                       Application entrypoint
    ├── SomeClassFile.h                A C++ header file for a class (CamelCase)
    └── SomeClassFile.cpp              A C++ source file for a class (CamelCase)
```

## Contributing

[CONTRIBUTING.md](docs/CONTRIBUTING.md) file explains how to contribute to the project,
and what are the contributing rules.

## License

We are under the MIT License, find out more in the [License](./LICENSE.md) section.

## Acknowledgements

Many thanks to the different contributors for their contribution to the project.
Find their names and missions in [Contributors](#contributors) section.

## Contributors
- BOPS
- Jovillios
- GabrielDum
- Ellafnz
- jonathanlys01
