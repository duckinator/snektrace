#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>
#include <unistd.h>

static FILE *file = NULL;

int audit_hook(const char *event, PyObject *args, void *userData) {
    // I can find no documentation whatsoever on expected return values?!
    fprintf(file, "EVENT=%s\nDATA=", event);
    PyObject_Print(PyObject_Repr(args), file, 0);
    fputs("\n\n", file);
    return 0;
}

int main(int argc, char *argv[]) {
    PyConfig config;

    if (argc == 1) {
        fprintf(stderr, "Usage: %s MODULE [FILE]\n", argv[0]);
        fprintf(stderr, "Runs MODULE, dumping all audit hooks to FILE (default=stderr).");
        exit(1);
    }

    if (argc == 3) {
        file = fopen(argv[2], "w");
    } else {
        file = stderr;
    }

    PySys_AddAuditHook(audit_hook, NULL);
    PyConfig_InitPythonConfig(&config);
    wchar_t *module_name = Py_DecodeLocale(argv[1], NULL);

    int len = strlen(argv[1]);
    if (strcmp(argv[1] + len - 3, ".py") == 0) {
        // If it's a .py file, run it as a file.
        config.run_filename = module_name;
    } else {
        // Otherwise, run it as a module.
        config.run_module = module_name;
    }
    Py_InitializeFromConfig(&config);

    return Py_RunMain();
}
