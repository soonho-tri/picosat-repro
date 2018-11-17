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


