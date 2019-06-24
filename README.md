# iching

`iching` is an encoder/decoder based on the book *[I Ching](https://en.wikipedia.org/wiki/I_Ching)* which maps base64 values to I Ching hexagrams and decodes them using an efficient 2D trigram lookup table.

## Usage

```bash
$ ./iching --help
I Ching Hexagram Encoder/Decoder
Options:
  -h [ --help ]          Print help messages
  -e [ --encode ] arg    Encode message
  -d [ --decode ] arg    Decode message
  -s [ --shift-cipher ]  Encode with shift cipher
  -k [ --key ] arg       Key for decoding shift cipher
```

### Encoding Text

You may redirect any program output to a file by simply adding `> file.extension` to any command below.


```bash
$ ./iching -e "secret"
====  ======================================  ==================================
==============  ========  ========  ==================  ========  ========  ====
====  ======================================  ========  ==================  ====
====  ========  ==================  ========  ========  ========================
==============  ========  ========  ============================  ==============
====  ==================  ========  ========  ========  ========  ========  ====
```

### Encoding a File
```bash
$ ./iching -e "`cat filename.extension`"
====  ==================  ==================  ==================================
====  ========  ============================  ========  ========  ==============
==========================================================================  ====
==============  ========  ========  ==================  ==================  ====
==============  ========  ========  ========  ========  ========  ========  ====
============================================  ==================  ==============
...
```

### Encoding with Shift Cipher
```bash
$ ./iching -s -e "secret"
KEY: EzLPYjRkayhnTCv47SgoFV5MOqb+/6emNlD231JWIXUiBKfAupwc0rQ8xHsZd9Gt
======================================================  ========================
====  ==================  ==================  ========  ========  ========  ====
====  ========  ============================  ============================  ====
====  ========  ========  ========  ========  ========  ========  ==============
====  ========  ============================  ========  ========================
========================  ========  ==================  ========  ========  ====
```

### Decoding
```bash
$ ./iching -d "`cat filename.extension`" > filename.decoded-extension
```

### Decoding with Shift Cipher
```bash
$ ./iching -k "D1uZzJYgiEAdehLlT285c0OVCK7mXSkf/vQy4N+IbWR96GPn3wsMaBptrUjxoHqF" \
           -d "`cat filename.extension`" > filename.decoded-extension
```
