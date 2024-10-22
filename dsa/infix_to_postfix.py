from stack import Stack

def infix_to_prefix(
    infix:list[str],
    rank:dict[str, int]={"^":3, "/":2, "*":1, "+":0, "-":0}
):
    braces_open, braces_closed = "(", ")"
    stack, postfix = Stack(maxlen=len(infix)), []
    for char in infix:
        if char==braces_open:
            stack.push(char)
        elif char.isalnum():
            postfix.append(char)
        elif char in rank.keys():
            if (
                (stack.stack_top >= 0) and
                (not (stack.get_stack_top() in "()")) and
                (rank[char] <= rank[stack.get_stack_top()])
            ):
                postfix.append(stack.pop())
            stack.push(char)
        elif char==braces_closed:
            while True:
                poped = stack.pop()
                if poped == braces_open:
                    break
                postfix.append(poped)

    while stack.stack_top >= 0:
        postfix.append(stack.pop())
    return postfix


if __name__ == "__main__":
    print(
        infix_to_prefix(list("((a+b)-c*(d/e))+f"))
    )
    print(
        infix_to_prefix(list("((1+2*3/5)^6+7)-8"))
    )
    print(
        infix_to_prefix(list("((A+B)-C*(D/E))+F"))
    )
    print(
        infix_to_prefix(list("((a^b+c)*f-d)/e"))
    )
