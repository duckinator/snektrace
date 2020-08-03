# snektrace

Run a Python module or script, and dump logs of all audit hooks to a file.

The format for each event is `EVENT=<event>\nDATA=<data>`, and each event
is separated by two newlines (`\n\n`).

```
$ echo "print('hello, world')" > test.py
$ ./snektrace test.py logs.txt
hello, world
$ tail -n 4 logs.txt

EVENT=cpython._PySys_ClearAuditHooks
DATA='()'

$
```

## Dependencies

In theory, this is all you need:

- GNU Make
- clang
- Python 3.8

## Building

Just run `make`.

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/duckinator/snektrace.

The code for snektrace is available under the [MIT License](http://opensource.org/licenses/MIT).
