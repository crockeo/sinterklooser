# sinterklooser

This is an app created to choose the optimal distribution of what is effectively
a set of Secret Santas for the Dutch Holiday Sinterklaas.

### USAGE

After getting the code from this GitHub, you just want to cmake it, and then
make it.

```bash
$ cmake . # Generating the Makefile
$ make    # Actually building the project.
```

After you have everything built, check out the example graph networks for how
you should structure your graph application. Once you have your data set, you
want to run the program on it:

```bash
$ ./build/bin/sinterklooser <path/to/file>
```
