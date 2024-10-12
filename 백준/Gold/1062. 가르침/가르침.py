from itertools import combinations

def encode(word):
    ret = 0
    for char in word:
        ret |= 1 << (ord(char) - ord('a'))

    return ret

def main():
    N, K = map(int, input().strip().split())
    words = []
    must_learn = 0
    for _ in range(N):
        word = input()
        encoded_word = encode(word)
        words.append(encoded_word)
        must_learn |= encoded_word

    if K < 5:
        print(0)
        return
    elif K == 26:
        print(N)
        return

    base = encode('antic')
    # 필수에서 a, n, t, i, c는 제거
    must_learn &= ~base

    must_learn_char = []
    for idx in range(26):
        if base & (1 << idx):
            continue
        if must_learn & (1 << idx):
            must_learn_char.append(chr(ord('a') + idx))

    if len(must_learn_char) <= K - 5:
        print(N)
        return

    answer = 0
    for selected_char in combinations(must_learn_char, K - 5):
        selected = encode(''.join(selected_char))
        selected |= base

        cnt = 0
        for word in words:
            if word & selected == word:
                cnt += 1

        answer = max(answer, cnt)

    print(answer)

if __name__=="__main__":
    main()