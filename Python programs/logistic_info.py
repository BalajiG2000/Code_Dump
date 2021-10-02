import matplotlib.pyplot as plt
r= 3.853
n=[i for i in range(50)]
xn=[]
xn.append(0.25)
for i in range(49):
  xn.append(r*xn[-1]*(1-xn[-1]))

plt.title("r="+str(r))
plt.xlabel("n")
plt.ylabel("xn")
plt.plot(n,xn,color="teal")