ciphertext=input("Enter the text: ")
ciphertext = ciphertext.lower()
key=input("Enter the Key: ")
key = key.lower()
hi=[0]*len(ciphertext)
if(len(ciphertext)==len(key)):
    print("Length are same : ")
    for i in range(0,len(key)):
        hi[i]=chr(((ord(ciphertext[i])+ord(key[i])-194)%26)+97)
    print(hi)
else:
    print("Length are not same, please rerun the program")