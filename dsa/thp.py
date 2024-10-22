# from stack import Stack

# S, A, D = [Stack(maxlen=3) for _ in range(3)]
# S.push(3)
# S.push(2)
# S.push(1)
# print(f"S:{S}\nA:{A}\nD:{D}\n\n\n")

# def thp(
#     S:Stack, 
#     A:Stack, 
#     D:Stack, 
#     lenS:int # length of S
# ):
#     if lenS > 0:
#         if lenS==1:
#             D.push(S.pop())
#         thp(S, D, A, lenS-1)
#         thp(A, S, D, lenS-1)
    
# thp(S, A, D, lenS=3)
# print(f"S:{S}\nA:{A}\nD:{D}")    




    