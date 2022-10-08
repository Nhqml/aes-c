project('AES', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

lib = library('aes',
              'aes.c',
              install: true)

test_exe = executable('test_exe',
                      'test.c',
                      link_with: lib,
                      install: true
)
