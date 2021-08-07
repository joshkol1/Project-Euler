if __name__ == "__main__":
    f = open("../problem_inputs/p059_ciphertext.txt", "r")
    ciphertext = [int(s) for s in f.readline().split(",")]
    for a in range(26):
        for b in range(26):
            for c in range(26):
                key = ""
                key += chr(ord('a')+a)
                key += chr(ord('a')+b)
                key += chr(ord('a')+c)
                xor_result = [ciphertext[i]^ord(key[i%3]) for i in range(len(ciphertext))]
                msg = ''.join([chr(c) for c in xor_result])
                if "the" in msg and "and" in msg and "then" in msg:
                    print(sum(xor_result))
    