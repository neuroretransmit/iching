# iching

`iching` is an encoder/decoder with an optional substitution cipher using hexagrams from the book *[I Ching](https://en.wikipedia.org/wiki/I_Ching)*. It maps base64 values to *I Ching* hexagrams.

## Requirements

* CMake
* Boost >=1.66
  * `system`
  * `program_options`

## Building

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Usage

```bash
I Ching Hexagram Encoder/Decoder
Options:
  -h [ --help ]                 Print help messages
  -e [ --encode ] arg           Encode message
  -d [ --decode ] arg           Decode message
  -s [ --substitution-cipher ]  Use substitution cipher
  -i [ --input ]                With input file
  -k [ --key ] arg              Key for decoding substitution cipher
```

### Encoding Text

You may redirect any program output to a file by simply adding `> file.extension` to any command below.
Keys for ciphers will not be printed on stdout, so this can be safely done while the key is left on your stderr.


```bash
$ ./iching -e "secret"
== =================== =================
======= ==== ==== ========= ==== ==== ==
== =================== ==== ========= ==
== ==== ========= ==== ==== ============
======= ==== ==== ============== =======
== ========= ==== ==== ==== ==== ==== ==
```

### Encoding a File
```bash
$ ./src/iching -ie filename.extension
== =================== =================
======= ==== ==== ========= ==== ==== ==
== =================== ==== ========= ==
== ==== ========= ==== ==== ============
======= ==== ==== ============== =======
== ========= ==== ==== ==== ==== ==== ==
```

### Encoding with Substitution Cipher
```bash
$ ./iching -se "secret"
KEY: 7CTMeW+uap1nhvorbKGJf/m2Zwl9IxSPdQA3gUR4szNq0cEL6DVijXHBytOkY8F5
======= ==== ============== ==== ==== ==
======= ==== ==== ========= ==== ==== ==
== ============== ==== ==== ========= ==
== ==== ==== ========= ========= ==== ==
== ==== ==== ========= ==== ==== =======
== ==== ========= ==== ==== ============
```

### Encoding File with Substitution Cipher
```bash
$ ./iching -sie filename.ext > file.enc
KEY: 7CTMeW+uap1nhvorbKGJf/m2Zwl9IxSPdQA3gUR4szNq0cEL6DVijXHBytOkY8F5
```

### Decoding
```bash
$ ./iching -id filename.extension > file.ext
```

### Decoding with Substitution Cipher
```bash
$ ./iching -k "7CTMeW+uap1nhvorbKGJf/m2Zwl9IxSPdQA3gUR4szNq0cEL6DVijXHBytOkY8F5" \
           -id filename.extension > filename.ext
```
