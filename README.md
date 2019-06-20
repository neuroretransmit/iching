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

**Decoding**

```bash
$ python main.py -d "$(python main.py -e 'yeet')"
yeet
```