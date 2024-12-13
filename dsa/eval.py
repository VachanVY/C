# implement a multiple stack concept to check if a string os a palindrome or not
from stack import Stack
from infix_to_postfix import infix_to_prefix

def eval(above, before, op):
    match op:
        case "+":
            return above+before
        case "-":
            return before-above
        case "*":
            return above*before
        case "/":
            return before/above
        case "^":
            return before**above

def eval_postfix(expr:list[str]):
    stack = Stack(maxlen=len(expr)*2)
    ops = ["*", "/", "-", "+", "^"]

    for char in expr:
        if char.isalnum():
            stack.push(float(char))
        elif char in ops:
            first = stack.pop()
            second = stack.pop()
            stack.push(eval(above=first, before=second, op=char))
    return stack.pop()


print(postfix:=infix_to_prefix(infix=list("((2^6+8)*7-8)/7"))) # 70.8571
print(eval_postfix(postfix))

# def palindrome(string:str):
#     length = len(string)
#     stack = Stack(maxlen=length)
#     for i in range(length//2):
#         stack.push(string[i])
    
#     i += (2 if length % 2 != 0 else 1)
#     while stack.stack_top >= 0:
#         if string[i] != stack.pop():
#             return False
#         i+=1
#     return True


# print(palindrome("abba"))
# print(palindrome("malayalam"))

