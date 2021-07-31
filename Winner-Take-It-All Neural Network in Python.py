import numpy as np
#numpy is used for working with arrays
inputX, outputY = input("Enter the number of input and output nodes:").split(' ')
inputX= int(inputX)
outputY= int(outputY)
alpha = 0.8
lines=np.zeros((outputY,inputX))
outs = [0]*outputY
Xvals = [0]*inputX
Xvals = np.asarray(Xvals)
outs = np.asarray(outs)
print(type(outs))
print(type(Xvals))
print(type(lines))
beark = '---------------------------------------------------'
print(beark)
print(' Output Neurons ',outs)
print(' Input Neurons ',Xvals)
print(' lines weights ',lines)
print(beark)
for i in range(0,inputX):
  print('Value Input = ',i,' Out of total = ',inputX-1)
  Xvals[i] = input()
print(beark)
print(' Output Neurons ',outs)
print(' Input Neurons ',Xvals)
print(' lines weights ',lines)
print(beark)
for i in range(0,outputY):
  for j in range(0,inputX):
    print(lines)
    temp = int(input("Enter the weights for output neuron"))
    lines[i][j] = temp
    print(beark)
  outs[i] = sum(Xvals*lines[i])

print(' Output Neurons ',outs)
print(' Input Neurons ',Xvals)
print(' lines weights ',lines)

winer = np.argmax(outs)
print(winer)

print(' lines weights ',lines)
#vals = alpha*(Xvals - lines[winer])
#print(vals)
#print(Xvals)
print(lines[winer])
lines[winer] = lines[winer]+vals
print(' lines weights ',lines)
