# Contributing

## Description
This guide explains how to contribute to the project [BE-Beasties](https://github.com/IMT-TAF-UE-H/BE-Beasties),
as a [project GitHub organisation](https://github.com/IMT-TAF-UE-H)'s member.

## Metadata
- **Timestamp**: 2024-03-08
- **Last update**: 2024-03-08

## Development environment setup

### Join the organisation
To join the [project GitHub organisation](https://github.com/IMT-TAF-UE-H),
you have to accept an invitation from the organisation's administrator,
received in the mailbox related to your GitHub account.
If you don't receive the invitation yet, please leave a message on the teaching unit
[Discord server, groupe-2 channel](https://discord.com/channels/798574579441205288/1200379614011334697).

Next, create a `Personal Access Token (classic)` with at least `repo`, `workflow`, `write:org`, and `gist` scopes.
You can follow the [official GitHub tutorial](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/managing-your-personal-access-tokens#creating-a-personal-access-token-classic).
Save it secretly somewhere to use it in the future (e.g., to clone the repository).

### Getting the source code
To get and edit the source code on your own computer, 
import the repository with: `git clone https://github.com/PROCOM-ERP/IMT-TAF-UE-H.git`.
Choose `Token Authentication` and the previous personal token you just created.

### Prerequisites to compile and run the main program
See [DEPLOYING.md](./DEPLOYING.md) file to compile and run the main program.

## Contributing

### Adding new feature
To implement a new feature, create a new branch `feature-XXX` from the `integration` branch,
XXX being the name of your feature written in lowercase with dashes as word separators.
Once implemented and tested thoroughly, create a pull-request from `feature-XXX` branch to `integration` branch.
The assessors will give their review and agreement, and the feature will be merged.

### Create new release
When all features are ready to make a stable version, `integration` branch is merged to the `main` branch,
[CHANGELOG.md](./CHANGELOG.md) file is updated,
and a release is created with a name following the [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

### Hotfix production version
If a production stable version has any problem, the `hotfix` branch is created from the `main` / `integration` branch to fix it, 
identified with the date (YYYY-MM-DD), and following the (e.g., hotfix-2024-03-08).

## Rules and recommendations
This project follows specific rules to ensure code quality and efficient collaboration.
By following these practices, we can ensure that the codebase remains clean and organised,
and that each feature is fully tested before it's deployed.

### Branch management
The main branches in this repository are:

- `main`: This branch is used for production-ready code.
- `integration`: This branch is used for the integration of new features.
  After a feature is implemented and tested thoroughly, it gets merged into this branch using a pull-request.
- `hotfix`: This branch is used for fixing critical problems on the `main`.
- `feature-XXX` Other branches are created depending on the feature you are working.

### Other good practices
- Always pull the latest changes from the `integration` branch before starting work on a new feature.
- Commit small, atomic changes that implement a single feature or fix a specific problem.
- Write clear, informative commit messages that describe the changes made.
- Always use pull requests to merge changes from a branch to another.

### Documentation
In order to maintain consistency and clarity across the project, some documentation standards were adopted.


#### C++ code documentation
C++ code documentation is tailored for use with [Doxygen](https://www.doxygen.nl/manual/docblocks.html).
For instance:
```c++
/**
 * @file sum_example.cpp
 * @brief Example file demonstrating a simple function to add two numbers.
 * @author Author's username
 * @date YYYY-MM-DD
 */

#include <iostream>

/**
 * Calculates the sum of two numbers.
 * 
 * @param a First operand of the sum operation.
 * @param b Second operand of the sum operation.
 * @return The sum of a and b.
 */
int sum(int a, int b) {
    return a + b;
}

int main() {
    int result = sum(5, 3);
    std::cout << "The sum is: " << result << std::endl;
    return 0;
}
```

## Communicate with the team
To talk with the different project contributors, the groupe-2 channel on the [Discord server]
(https://discord.com/channels/798574579441205288/1200379614011334697) is available.
