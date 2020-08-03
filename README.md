# snektrace

Run a Python module or script, and dump logs of all audit hooks to a file.

The format for each event is `event: <event>\ndata: <data>`, and each event
is separated by two newlines (`\n\n`).

This format was chosen because it is compatible with [Server-Sent Events/Event Source](https://developer.mozilla.org/en-US/docs/Web/API/Server-sent_events/Using_server-sent_events#Examples).

```
$ echo "print('hello, world')" > test.py
$ ./snektrace test.py logs.txt
hello, world
$ tail -n 4 logs.txt

event: cpython._PySys_ClearAuditHooks
data: '()'

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
