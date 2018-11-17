I've found that picosat-965 causes an assertion failure when `picosat_push`/`picosat_pop` are used with `picosat_deref_partial`. I came up with a small reproducible code. Please take a look at [repro.c](https://github.com/soonho-tri/picosat-repro/blob/master/repro.c) file.

Repro Steps:
```bash
./configure.sh --debug      # to include debugging code and symbols
make                        # build picosat-965
gcc repro.c ./libpicosat.a  # build repro.c
./a.out
```

Output:
```
Assertion failed: (best), function minautarky, file picosat.c, line 7082.
[1]    67622 abort      ./a.out

```

Tested Environments:
 - Ubuntu-16.04 / x86_64 + gcc (Ubuntu 5.5.0-12ubuntu1~16.04)
 - macOSX-10.14.1 + clang (Apple LLVM version 10.0.0 (clang-1000.11.45.5))
