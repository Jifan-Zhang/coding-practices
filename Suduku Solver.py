import pandas as pd
import numpy as np
import sys
import copy
data=pd.DataFrame([[np.NaN]*9]*9)
#question data
data=pd.DataFrame(
                      [[0,0,0,0,0,0,0,9,0],
                       [7,0,0,0,0,4,0,0,0],
                       [0,0,0,0,2,0,1,0,0],
                       [0,0,1,0,9,0,2,0,0],
                       [0,0,0,8,0,0,0,0,0],                  
                       [5,0,0,0,0,0,0,0,7],              
                       [0,0,0,0,0,0,0,0,0],   
                       [0,0,0,7,0,5,0,0,8],                
                       [0,9,4,0,0,0,3,0,0]])

#create backpack (only do once)
backpack=[]
for i in range(9):
    backpack.append([0]*9)
for i in range(9):
    for j in range(9):
        if(data.iloc[i,j] == 0):
            x=int(i/3)*3
            y=int(j/3)*3
            backpack[i][j]= list(set(data.iloc[i].append(data.iloc[:,j]).append(data.iloc[ x, y:y+3 ])
                                                                                 .append(data.iloc[ x+1 , y:y+3 ])
                                                                                 .append(data.iloc[ x+2 , y:y+3])) ^ set([1,2,3,4,5,6,7,8,9,0]))
        else:
            backpack[i][j]=[]

def mainfunction():
    global data; global backpack
    for i in range(9):
        for j in range(9):
            if(data.iloc[i,j]!=0):
                continue      
            if(len(backpack[i][j])==1):
                data.iloc[i,j]=backpack[i][j][0]
                revise(i,j,backpack[i][j][0])
                return 0
            rowst=[]
            colst=[]
            sqlst=[]
            rowst=backpack[i][:j] + backpack[i][j+1:]
            for m in range(9):
                if(m==i):
                    continue
                colst.append(backpack[m][j])  
            x=int(i/3)*3
            y=int(j/3)*3
            sqlst=backpack[x][y:y+3]+backpack[x+1][y:y+3]+backpack[x+2][y:y+3]
            sqlst.remove(backpack[i][j])
            for number in backpack[i][j]:
                if (  (str(number) not in str(rowst))  or (str(number) not in str(colst))  or (str(number) not in str(sqlst))  ):
                    data.iloc[i,j]=number
                    revise(i,j,number)
                    return(0)
    return -1

def random_try():
    global data; global backpack
    data_backup=data.copy()
    backpack_backup=copy.deepcopy(backpack)
    #find the shortest backpack list
    x=-1;y=-1;length=10
    for i in range(9):
        for j in range(9):
            if(data.iloc[i,j]!=0):
                continue
            if(len(backpack[i][j])<length):
                x=i;y=j;length=len(backpack[i][j])    
    tmp=backpack[x][y]
    
    for item in tmp:
        flag=0
        data.iloc[x,y]=item
        revise(x,y,item)          
        callme() 
        if(data.sum().sum()==405):
            print("All Done.")
            sys.exit(data)
        for i in range(9):
            for j in range(9):
                if((len(backpack[i][j])==0) and (data.iloc[i,j]==0)):                         
                    flag=1
                    break
            if(flag==1):
                break
        if(flag==1):
            data=data_backup.copy()
            backpack=copy.deepcopy(backpack_backup)
            continue
        if(flag==0):
            random_try_return=random_try()
            if(random_try_return==-1):
                data=data_backup.copy()
                backpack=copy.deepcopy(backpack_backup)
                continue
    return -1
        

def revise(i,j,number):
    global backpack
    backpack[i][j]=[]
    for m in range(9):
        try:
            backpack[i][m].remove(number)
        except:
            pass
        
        try:
            backpack[m][j].remove(number)
        except:
            pass
        
        x=int(i/3)*3
        y=int(j/3)*3
        
    try:
        backpack[x][y].remove(number)
    except:
            pass
    try:
        backpack[x+1][y].remove(number)    
    except:
            pass
    try:
        backpack[x+2][y].remove(number)    
    except:
            pass
    try:
        backpack[x][y+1].remove(number)    
    except:
            pass
    try:
        backpack[x+1][y+1].remove(number)    
    except:
            pass
    try:
        backpack[x+2][y+1].remove(number)    
    except:
            pass
    try:
        backpack[x][y+2].remove(number)    
    except:
            pass
    try:
        backpack[x+1][y+2].remove(number)    
    except:
            pass    
    try:
        backpack[x+2][y+2].remove(number)    
    except:
            pass

def callme():
    while(1):
        i=mainfunction()
        if(i==-1):
            break



##Program Start
while(1):
    callme()
    if(data.sum().sum()==405):
        break
    else:
        res=random_try()
    if(res==1):
        print("SUCCESS")
        break
    if(res==-1):
        print("Fatal problem occured: All guessings are wrong.")
        print(data)
        sys.exit(-1)

    

