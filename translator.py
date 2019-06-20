import base64
import random

from hexagram import SORTED_HEXAGRAMS

B64_CHARACTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'
KEYMAP = {}


def build_hexagram_output(hexagrams):
    output = "\n"
    for hexagram in hexagrams:
        output += str(hexagram) + "\n"
    return output


def encode(msg, shuffle=False, file=False):
    if shuffle:
        print("Shuffling...")
        shuffled = ''.join(random.sample(B64_CHARACTERS, len(B64_CHARACTERS)))
        print("Key: {}".format(shuffled))
        KEYMAP.update(zip(shuffled, SORTED_HEXAGRAMS))
    else:
        KEYMAP.update(zip(B64_CHARACTERS, SORTED_HEXAGRAMS))
    if file:
        msg = "./" + msg
        with open(msg, 'rb') as f:
            b64_encoded = base64.b64encode(f.read()).decode('utf-8')
    else:
        b64_encoded = base64.b64encode(bytes(msg, encoding='utf-8')).decode('utf-8')
    hexagrams = []
    for letter in b64_encoded.replace('=', ''):
        hexagrams.append(KEYMAP[letter])
    return build_hexagram_output(hexagrams)


def decode(encoded, key=None, file=False, output=None):
    if key:
        KEYMAP.update((zip(key, SORTED_HEXAGRAMS)))
    else:
        KEYMAP.update((zip(B64_CHARACTERS, SORTED_HEXAGRAMS)))
    if file:
        with open(encoded, "rb") as f:
            encoded_hexagrams = f.read().decode('utf-8').split("\n\n")
    else:
        encoded_hexagrams = encoded.split("\n\n")
    lookup_hexagrams = []
    for hexagram in encoded_hexagrams:
        for existing in SORTED_HEXAGRAMS:
            e = existing
            if hexagram.strip() == str(e).strip():
                lookup_hexagrams.append(e)

    decoded = ""
    for h1 in lookup_hexagrams:
        for letter, h2 in KEYMAP.items():
            if h2 == h1:
                decoded += letter
    missing_padding = len(decoded) % 4
    padded = decoded + '=' * (4 - missing_padding) if missing_padding else decoded
    if file:
        with open(output, 'wb') as f:
            padded_bytes = bytes(padded, 'utf-8')
            f.write(bytes(base64.decodestring(padded_bytes)))
        return "File written at '{}'".format(output)
    return base64.b64decode(padded).decode('utf-8')