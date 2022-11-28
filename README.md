# Compile

```sh
meson setup builddir
meson compile -C builddir
```

This will generate an AES library and a test executable using the library.

# Run

```sh
./builddir/test_exe
```

This will run the test executable.
