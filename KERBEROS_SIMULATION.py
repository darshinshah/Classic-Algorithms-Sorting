import numpy as np
userDB = ['Anmol','Mohit','Meet','Darshin','Prasham','Yash','Harsh','Shaunak','Rushad']
kdc_name = 'MyKDC'
session_key1 = 1
tgt_private_key = 3
user_private_key = 5
session_key2 = 2
service_key_private = 10

def client_login(username,user_ip):
  if username in userDB:
    tgt = np.array([tgt_private_key, username,kdc_name,user_ip,session_key1]) 
    # encrypt using kdc private key
    print('\nTicket Granting Ticket ==> ',tgt)
    return ( tgt, session_key1, user_private_key )
  else:
    print('\nUsername not found')
    exit(1)

def user_request_service(tgt, session_key1, user_private_key,user_name,user_ip):
  user_key = 5
  if user_key == user_private_key:
    print('\nUser authenticated')
    authenticator = np.array([session_key1, user_name,user_ip])
    print('\nAuthenticator packet ==> ',authenticator,'\n')
    service_name = input('Enter the Service you want to Contact E.g. Mail Server: ==>')
    return (tgt, authenticator, service_name)
  else:
    print('User not authenticated XXXXX')


def user2kdc_authenticator(tgt, authenticator, service_name):
  print(tgt[0])
  if int(tgt[0]) == tgt_private_key:
    print('\nKDC ACCEPTED USER ==> opening authenticator ticket')
    if authenticator[0] == tgt[4]:
      print('\nUser is now TRUSTED ==> service ticket will be made now\n')
      service_ticket = np.array([service_key_private, authenticator[1], service_name, authenticator[2], session_key2])
      print('\nService Ticket ==> ',service_ticket)
      return (int(tgt[4]), service_ticket, session_key2)
  else:
    print('User not authenticated XXXXX')

def user2service(session_key1_authenticator, service_ticket, session_key2,user_ip):
  if session_key1 == session_key1_authenticator:
    print('\nValidated ==> now we will send request to mail server')
    new_authenticator = np.array([session_key2, service_ticket[1],user_ip])
    print('\nNew authenticatorticket form user to service',new_authenticator)
    return (new_authenticator, service_ticket)
    #      authenticator = np.array([session_key1, user_name,user_ip])
  else:
    print('Not a valid key')

def final_Auth_service(new_authenticator, service_ticket ):
  if int(service_ticket[0]) == service_key_private: # kdc authentiction
    if int(service_ticket[4]) == int(new_authenticator[0]): # user authenticaiton
      print('\nAuthentication by sevice is successful')
      print('\n *********************************\n\nACKNOWLEDGEMENT RETURNED ==> USER VALIDATED ==> USER USES THE SERVICE')
    else:
      print('user not granted service due to some error #Tumse Na Ho Payega')
  else:
    print('\nAuthentication by sevice is not successful')


user_name = input('\nEnter the username')
user_ip= '192.168.1.1'
tgt, session_key1, user_private_key = client_login(user_name,user_ip)

tgt, authenticator, service_name = user_request_service(tgt, session_key1, user_private_key,user_name,user_ip)

session_key1_authenticator, service_ticket, session_key2 = user2kdc_authenticator(tgt, authenticator, service_name)

new_authenticator, service_ticket = user2service(session_key1_authenticator, service_ticket, session_key2,user_ip)

final_Auth_service(new_authenticator, service_ticket)