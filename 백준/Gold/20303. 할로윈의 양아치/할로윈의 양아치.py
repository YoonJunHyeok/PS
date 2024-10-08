from collections import defaultdict

def solve_knapsack(k, graph):
    length = len(graph)
    dp = [0]*k

    for idx in range(length):
        num_of_friend, num_of_candy = graph[idx]
        for y in range(k - 1, num_of_friend-2, -1):
            if y >= num_of_friend:
                dp[y] = max(dp[y], dp[y - num_of_friend] + num_of_candy)

    return dp[k - 1]

def get_graph(n, candies, friends):
    graph = []

    visited = [False] * n
    for idx in range(n):
        if visited[idx]:
            continue

        friend_cnt = 0
        candy_cnt = 0
        visited[idx] = True
        q = [idx]

        while q:
            cur_idx = q.pop()
            friend_cnt += 1
            candy_cnt += candies[cur_idx]

            for nxt_idx in friends[cur_idx]:
                if visited[nxt_idx]:
                    continue

                visited[nxt_idx] = True
                q.append(nxt_idx)

        graph.append((friend_cnt, candy_cnt))

    return graph

def solution(n, k, candies: list, friends):
    graph = get_graph(n, candies, friends)

    ans = solve_knapsack(k, graph)

    return ans

def main():
    n, m, k = map(int, input().strip().split())

    candies = list(map(int, input().strip().split()))

    friends = defaultdict(list)
    for _ in range(m):
        a, b = map(int, input().strip().split())
        friends[a - 1].append(b - 1)
        friends[b - 1].append(a - 1)

    ans = solution(n, k, candies, friends)
    print(ans)

if __name__=='__main__':
    main()