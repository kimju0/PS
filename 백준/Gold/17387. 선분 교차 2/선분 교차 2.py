import sys
from fractions import Fraction
x1,y1,x2,y2=map(int,sys.stdin.readline().split())
x3,y3,x4,y4=map(int,sys.stdin.readline().split())
if (x2-x1)**2+(y2-y1)**2<(x4-x3)**2+(y4-y3)**2:x1,y1,x2,y2,x3,y3,x4,y4=x3,y3,x4,y4,x1,y1,x2,y2
#(1,2)가 더 긴 선분
if x1==x2 and x3==x4: a1,a2=10000000,10000000
elif x1==x2 and x3!=x4: a1,a2=10000000,Fraction(y3-y4,x3-x4)
elif x1!=x2 and x3==x4: a1,a2=Fraction(y1-y2,x1-x2),10000000
else: a1,a2=Fraction(y1-y2,x1-x2),Fraction(y3-y4,x3-x4)

if a2==a1:
    if a2==10000000:
        x1,x2,x3,x4,y1,y2,y3,y4=y1,y2,y3,y4,x1,x2,x3,x4
        a2,a1=0,0
    
    if x1<x2:x1,x2,y1,y2=x2,x1,y2,y1
    if x3<x4:x3,x4,y3,y4=x4,x3,y4,y3

    b1,b2=y1-x1*a1,y3-x3*a2
    if b1!=b2:print(0)
    elif x1<=x3 and x2<=x4 and x4<=x1:print(1)
        #(x4,y4)가 긴 선분 위에 있어야 함
    elif x1>x3 and x3>=x2:print(1)
        #(x3,y3)가 긴 선분 위에 있어야 함
    else:print(0)

else:
    if x1<x2:x1,x2,y1,y2=x2,x1,y2,y1
    if x3<x4:x3,x4,y3,y4=x4,x3,y4,y3
    if a1==10000000: 
        b2=y3-x3*a2
        inter_x=x1
        inter_y=a2*inter_x+b2
    elif a2==10000000:
        b1=y1-x1*a1 
        inter_x=x3
        inter_y=a1*inter_x+b1
    else: 
        b1,b2=y1-x1*a1,y3-x3*a2
        inter_x=(b2-b1)/(a1-a2)
        inter_y=a1*inter_x+b1
    if x1>=inter_x and inter_x>=x2 and max(y1,y2)>=inter_y and inter_y>=min(y1,y2) and x3>=inter_x and inter_x>=x4 and max(y3,y4)>=inter_y and inter_y>=min(y3,y4): print(1)
    else: print(0)