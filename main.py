import argparse

from translator import encode, decode


def str2bool(v):
    if isinstance(v, bool):
       return v
    if v.lower() in ('yes', 'true', 't', 'y', '1'):
        return True
    elif v.lower() in ('no', 'false', 'f', 'n', '0'):
        return False
    else:
        raise argparse.ArgumentTypeError('Boolean value expected.')


def configure_parser():
    parser = argparse.ArgumentParser(description='I Ching Hexagram Encoder/Decoder.')
    parser.add_argument('-e', '--encode', type=str,
                        help='Encode via double translation of Base64 to I Ching hexagrams.')
    parser.add_argument('-d', '--decode', type=str,
                        help='Decode I Ching hexagrams.')
    parser.add_argument('-s', '--shuffle', type=str2bool, nargs='?', const=True, default=False,
                        help='Shuffle keymap for more insecurity through obscurity.')
    parser.add_argument('-k', '--key', type=str,
                        help='Base64 character ordering if encoded with shuffle.')
    parser.add_argument('-o', '--output', type=str,
                        help='Output file to write.')
    parser.add_argument('-f', '--file', type=str2bool, nargs='?', const=True, default=False,
                        help='File input flag.')
    return parser


if __name__ == "__main__":
    parser = configure_parser()
    args = vars(parser.parse_args())
    if args['encode'] is not None:
        if args['file'] is not None:
            hexagrams = encode(args['encode'], args['shuffle'], file=True)
        else:
            hexagrams = encode(args['encode'], args['shuffle'])
        print(hexagrams)
    elif args['decode'] is not None:
        if args['file'] is not None:
            print(decode(args['decode'], key=args['key'], file=args['file'], output=args['output']))
        print(decode(args['decode'], key=args['key']))

