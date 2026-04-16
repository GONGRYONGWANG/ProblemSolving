while True:
    s = input()
    if s == ".":
        break
    stack = []
    state = 0
    for i in range(len(s)):
        if s[i] == "(":
            stack.append("S")
            
        if s[i] == "[":
            stack.append("L")
            
        if s[i] == ")":
            if stack == [] or stack[-1] != "S":
                state = 1
                break
            del stack[-1]
            
        if s[i] == "]":
            if stack == [] or stack[-1]!= "L":
                state = 1
                break
            del stack[-1]
    if state==0 and stack == []:
        print("yes")
    else:
        print("no")