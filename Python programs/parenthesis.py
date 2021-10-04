s=input()
o = "{[("
c= "}])"
l=len(s)
d=[]
b={')': '(', '}': '{', ']': '['}
for i in s:
    if i in o:
        d.append(i)
    elif i in c:
        if len(d)==0:
            print("false")
        if d[-1]==b[i]:
            d.pop()
        else:
            print("false")
if len(d)==0:
    print("TRUE")
