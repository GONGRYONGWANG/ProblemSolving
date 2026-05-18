from collections import defaultdict, deque

def solution(n, wires):
    INF = int(1e9)
    answer = INF
    
    edges = defaultdict(list)
    
    for wire in wires:
        edges[wire[0]].append(wire[1])
        edges[wire[1]].append(wire[0])
    
    
    def with_out_count(wire, node):
        q = []
        q.append([node, set([node])])
        ans = 0
        
        while q: 
            cur_node, cur_visited = q.pop()
            ans += 1
            
            for next_node in edges[cur_node]:
                if [cur_node, next_node] == wire or [next_node, cur_node] == wire or next_node in cur_visited:
                    continue
                    
                temp_set = set(cur_visited)
                temp_set.add(next_node)
                q.append([next_node, temp_set])
        
        return ans
        

    
    for wire in wires: 
        # 1. wire 없이 전력망 count 
        cnt1= with_out_count(wire, wire[0])
        cnt2= with_out_count(wire, wire[1])
        
        answer = min(abs(cnt1-cnt2), answer)
        
        
    
    return answer