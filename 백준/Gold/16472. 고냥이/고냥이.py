import sys
input = sys.stdin.readline

N = int(input())
sentence = input().strip()
left = 0
answer = 0
dict = {}

for right in range(len(sentence)):
    dict.setdefault(sentence[right], 0)
    dict[sentence[right]] += 1

    while len(dict) > N:
        dict[sentence[left]] -= 1
        if dict[sentence[left]] <= 0:
            del dict[sentence[left]]
        left += 1

    answer = max(answer, right - left + 1)
print(answer)