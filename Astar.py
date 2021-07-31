import numpy as np

def initialize():
  graph=np.array([
  [0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,140, 118,  0 ,0, 75],
  [0, 0 ,0  ,0  ,0  ,211  ,90 ,0  ,0  ,0  ,0  ,0  ,0  ,101  ,0  ,0  ,0  ,85 ,0  ,0],
  [0  ,0  ,0  ,120  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,138  ,146  ,0  ,0  ,0  ,0  ,0],
  [0  ,0  ,120  ,0, 0,  0,  0,  0,  0,  0,  75, 0,  0,  0,  0,  0,  0,  0,  0,  0],
  [0, 0,  0,  0,  0,  0,  0,  86, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0],
  [0, 211,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  99, 0,  0,  0,  0],
  [0, 90, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0,  0,  0,  0,  0,  0,  0],
  [0, 0,  0,  0,  86, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  98, 0,  0],
  [0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  87, 0,  0,  0,  0,  0,  0,  92, 0],
  [0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  70, 0,  0,  0,  0,  0,  111, 0, 0,  0],
  [0, 0 ,0, 75, 0,  0,  0,  0,  0,  70, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0],
  [0, 0,  0,  0,  0,  0,  0,  0,  87, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0],
  [0, 0,  0 ,0  ,0, 0,  0,  0 ,0, 0,  0 ,0, 0,  0,  0 ,151, 0,  0,  0,  71],
  [0, 101,  138,  0,  0,  0,  0,  0,  0,  0,  0 ,0, 0,  0,  97, 0,  0,  0,  0,  0],
  [0, 0 ,146, 0,  0,  0,  0,  0,  0 ,0, 0,  0,  0,  97, 0,  80, 0,  0,  0,  0],
  [140, 0,  0,  0,  0,  99, 0,  0,  0,  0,  0,  0,  151,  0,  80, 0,  0 ,0  ,0, 0],
  [118, 0,  0 ,0, 0,  0,  0,  0,  0,  111,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0],
  [0, 85, 0 ,0, 0,  0,  0,  98, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  142,  0],
  [0, 0,  0 ,0, 0,  0,  0,  0,  92  ,0, 0,  0 ,0, 0,  0,  0,  0,  142,  0,  0],
  [75,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 ,0, 71, 0,  0,  0,  0,  0,  0,  0]
  ])
  heuristic = np.array([366, 0, 160, 242, 161, 176, 77,151,226,244,241,234,380,100,193,253,329,80,199,374])
  return graph,heuristic

def func_start_node():
  snode = int(input('Enter a start node value in between 0-19'))
  snode = snode
  if snode<0 or snode>19:
    print('ERROR ==> Please Enter A Start node Vlaue in between the given range only!!!\n')
    snode = func_start_node()
  return snode

def Find_tuple(starting_node,graph,heuristic,o_list,c_list,a):
  flag = 0
  if a == 0:
    for i in o_list:
      if i[0] == starting_node:
        flag = 1
        break
  else:
    for i in o_list:
      if i[1] == starting_node:
        flag = 1
        break
  if flag == 1:
    return i
  else:
    return [0,0]

def find_succ(starting_node,graph,heuristic,o_list,c_list):
  print('finding successor function here______________')
  for i in range(0,len(graph[starting_node])):
    if graph[starting_node][i] != 0: #if the link exist
      index = Find_tuple(starting_node,graph,heuristic,o_list,c_list,0) #parent node
      child_index=Find_tuple(i,graph,heuristic,o_list,c_list,0) #child node open
      child_index_closed = Find_tuple(i,graph,heuristic,c_list,o_list,0) #child node closed list
      if child_index and child_index_closed == [0,0]: #it doesnt exist in both list
        o_list.append([i,index[1] - heuristic[starting_node] + graph[starting_node][i] + heuristic[i]])
      else: # exists either in open or closed
        if child_index_closed[1] > (index[1] - heuristic[starting_node] + graph[starting_node][i] + heuristic[i]):
          #exists in closed list
          o_list.append([i,index[1] - heuristic[starting_node] + graph[starting_node][i] + heuristic[i]])
          print('\n\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ Exists in closed list $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$')
          c_list.remove(child_index_closed)
        else: #exists in open list
          if child_index[1] > (index[1] - heuristic[starting_node] + graph[starting_node][i] + heuristic[i]):
            o_list.append([i,index[1] - heuristic[starting_node] + graph[starting_node][i] + heuristic[i]])
          print('\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Exists in open list @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@')
          #else is not written as no update condition 
        print('Append Function:',o_list) #hereeaeeeeeeee
  return o_list,starting_node,heuristic,c_list

def del_parent(starting_node,graph,heuristic,o_list,c_list):
  index = Find_tuple(starting_node,graph,heuristic,o_list,c_list,0)
  o_list.remove(index)
  c_list.append(index)
  return o_list,starting_node,heuristic,c_list

def find_mini(starting_node,graph,heuristic,o_list,c_list):
  print('\n\nfinding minimum function here______________')
  #function to find minimum heuristic value of elements in open list
  print('\n\nOPEN==>',type(o_list),o_list)
  print('CLOSED==>',type(c_list),c_list)
#starting_node = min(heuristic[o_list])
#starting_node = np.argmin(starting_node)
  #for i in range(0,len(o_list)):
  mini = o_list[0][1]
  for i in o_list:
    if mini > i[1]:
      mini = i[1]
  print(mini)  
  starting_node = Find_tuple(mini,graph,heuristic,o_list,c_list,1)
  starting_node = starting_node[0]
  print('next Starting node willl be==> ',starting_node)
  return o_list,starting_node,heuristic,c_list

def gbfs(starting_node,graph,heuristic,o_list,c_list):
  #this is main gbfs function   
  if len(o_list) == 0:
    print('************************************************Failue***********************************')
    exit(1)
  else:
    if heuristic[starting_node] == 0:
      starting_node = Find_tuple(starting_node,graph,heuristic,o_list,c_list,0)
      c_list.append(starting_node)
      print('\n\n***************Goal Node FOund***********') 
      print('\nPath is:==>',c_list)
      print('Goal Node is:',starting_node)
      #checking if the start node selectedis goal node or not
      return starting_node,graph,heuristic,o_list,c_list
    else:
      print('\nNot a Goal Node')
      o_list,starting_node,heuristic,c_list = find_succ(starting_node,graph,heuristic,o_list,c_list)
      
      o_list,starting_node,heuristic,c_list = del_parent(starting_node,graph,heuristic,o_list,c_list)

      o_list,starting_node,heuristic,c_list = find_mini(starting_node,graph,heuristic,o_list,c_list)

      starting_node,graph,heuristic,o_list,c_list = gbfs(starting_node,graph,heuristic,o_list,c_list)
      #we need to find successors of the selected node appends successor to the open list
      #finding the minimum/cheapest value in open list
      #starting_node,graph,heuristic,o_list,c_list = gbfs(starting_node,graph,heuristic,o_list,c_list)
  
#main here
o_list = []
c_list = []
graph,heuristic = initialize()   #this is for static grpah initialization process:
starting_node = func_start_node() #getting usser input for starting node
o_list.append([starting_node,heuristic[starting_node]]) #just to stay safe from none-error
print(o_list)
starting_node,graph,heuristic,o_list,c_list = gbfs(starting_node,graph,heuristic,o_list,c_list)