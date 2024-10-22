from stack import Stack

def print_assert(pred:str, true:str, msg:str=""):
    assert true==pred, msg
    print(pred)

def infix_to_postfix(
    infix:list[str], 
    rank:dict[str, int]={"^":3, "/":2, "*":1, "+":0, "-":0}
):
    postfix = []
    stack = Stack(maxlen=len(infix))
    for char in infix:
        if char.isalnum(): # if alphabhet or number append to postfix
            postfix.append(char)
        elif char in rank.keys(): # if an operator then push to stack
                # check precedence
            if stack.stack_top >= 0:
                if rank[char] <= rank[stack.get_stack_top()]:
                    postfix.append(stack.pop())
            stack.push(char)
        else: 
            raise ValueError(f"{char}???")

    while stack.stack_top >= 0:
        postfix.append(stack.pop())
    return "".join(postfix)

print_assert(
    infix_to_postfix(infix=list("a+b*c")),
    "abc*+"
)
print_assert(
    infix_to_postfix(infix=list("a*b+c")),
    "ab*c+"
)
print_assert(
    infix_to_postfix(infix=list("a-b+c")),
    "ab-c+"
)
print_assert(
    infix_to_postfix(infix=list("a+b-c")),
    "ab+c-"
)
print_assert(
    infix_to_postfix(infix=list("a/b+c")),
    "ab/c+"
)
print_assert(
    infix_to_postfix(infix=list("a*b/c")),
    "abc/*"
)
print_assert(
    infix_to_postfix(infix=list("a^b^c")),
    "ab^c^"
)
