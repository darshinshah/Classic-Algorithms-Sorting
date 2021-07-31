print('TOWER OF HANOI')

def move(n, source, dest, temp):
  # function called pass values in order ==> disc, Source Rod/Station, Destination Rod/Station, Temporary Rod/Station
      if n==1:
        print('Move Disc From: ',source, '==> To Destination: ==>', dest,'\n')
      else:
        move(n-1,source,temp,dest)
        print('Move Disc From: ',source, '==> To Destination: ==>', dest,'\n')
        move(n-1,temp,dest,source)

# n is number of discs 
n = int(input('Enter Number of Discs: '))
print('\n')
move(n,'A','C','B'); #calling function