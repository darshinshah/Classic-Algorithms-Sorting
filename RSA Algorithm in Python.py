p = int(input('Enter the First Prime No. : '))
q = int(input('Enter the Second Prime No. : '))

n=p*q
z=(p-1)*(q-1)

def gcd(x, y):
   while(y):
       x, y = y, x % y
   return x

for e in range (2,z):
  if(gcd(z,e)==1):
      break
print('\nThe Encryption Key is : ')
print(e)
for d in range (0,z):
  if ((d*e)%z)==1:
    print('The Decryption Key is : ')
    print(d)
    break

msg=int(input('Enter the number to encrypt:'))

ciphertext=(msg**e)
ciphertext=ciphertext % n
print('The Cipher Text is : ')
print(ciphertext)

original = ciphertext ** d
original = original%n
print('The Original Text is : ')
print(original)
