N = int (input())
c_count = 0
moumuriflag = False
for a0 in range(N):
  a = a0 + 1
  if (a**3 > N):
    break
  for b0 in range(N- a0):
    b = b0 + a
    if(a*b*b > N):
        break
    if(a*b > N):
        break
    c_max = N//(a*b)
    if c_max >= b:
      c_count = c_count + c_max - b + 1
    else:
      moumuriflag = True
#      print ( a,b,c_max)
      break
print (c_count)
