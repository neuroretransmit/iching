import argparse
from translator import encode, decode


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='I Ching Hexagram Encoder/Decoder.')
    parser.add_argument('-e', '--encode', type=str,
                        help='Encode via double translation of Base64 to I Ching hexagrams.')
    parser.add_argument('-d', '--decode', type=str,
                        help='Decode I Ching hexagrams.')
    args = vars(parser.parse_args())
    if args['encode'] is not None:
        hexagrams = encode(args['encode'])
        print(hexagrams)
    elif args['decode'] is not None:
        print(decode(args['decode']))
