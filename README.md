# iching

`iching` is an encoder/decoder based on the book *[I Ching](https://en.wikipedia.org/wiki/I_Ching)* which maps base64
values to *I Ching* hexagrams and decodes them using an efficient 2D trigram lookup table.

## Usage

```bash
usage: main.py [-h] [-e ENCODE] [-d DECODE]

I Ching Hexagram Encoder/Decoder.

optional arguments:
  -h, --help            show this help message and exit
  -e ENCODE, --encode ENCODE
                        Encode via double translation of Base64 to I Ching
                        hexagrams.
  -d DECODE, --decode DECODE
                        Decode I Ching hexagrams.

```

### Examples

**Encoding**

```bash
$ python main.py -e "yeet"

==========
====  ====
====  ====
====  ====
==========
==========

====  ====
====  ====
====  ====
==========
====  ====
====  ====

==========
====  ====
==========
==========
====  ====
====  ====

====  ====
==========
==========
==========
====  ====
==========

==========
====  ====
==========
==========
====  ====
==========

==========
==========
==========
==========
==========
==========

```

**Encoding with keymap shuffle**

```bash
$ python main.py -e -s "yeet"
Shuffling...
Key: cNg6Dm2hKO9Z4lPCSrGe85xT0fVwRupHbAQnsjXiqaJz1UYdFLWtk+3yBEIo7vM/

====  ====
====  ====
====  ====
==========
==========
====  ====

====  ====
====  ====
==========
====  ====
====  ====
==========

====  ====
====  ====
==========
==========
====  ====
====  ====

==========
==========
==========
==========
====  ====
==========

==========
==========
====  ====
====  ====
==========
====  ====

==========
==========
==========
====  ====
====  ====
==========

```

**Decoding**

```bash
$ python main.py -d "$(cat hexagrams.txt)"
yeet
```

**Decoding with keymap key**
```bash
$python main.py -k "cNg6Dm2hKO9Z4lPCSrGe85xT0fVwRupHbAQnsjXiqaJz1UYdFLWtk+3yBEIo7vM/" -d "$(cat hexagrams.txt)"
yeet
```