# Compile and run the main program

## Prerequisites
- GNU Compiler Collection (GCC) or any compatible C++ compiler installed on your system.
- `make` utility installed on your system for processing the Makefile.

## Compile the Project

To compile the project once downloaded, use the following steps on your bash terminal:

```bash
cd path/to/the/project
make
```

This will compile the source code using the Makefile,and produce an executable named `main`.

## Run the executable
After [compiling the project](#compile-the-project), you can run the executable with:
```bash
./main [config]
```
`config` argument is optional, and must correspond to the name of a `.conf` file in the folder `config/`. It overrides configuration from `default.conf` Any unspecified parameters will be picked from the default config that has to be set in the `DEFAULT_CONFIG_FILE` parameter. </br>
For instance, this command will use the `config/default.conf` config file :
```bash
./main default
```
Which is equivalent to :
```bash
./main
```

**_NB_**: if any permission problem appears, run `chmod +x main` to make it executable
