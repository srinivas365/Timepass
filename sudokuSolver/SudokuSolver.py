import numpy as np


def check(x,y,n):
    global question
    for i in range(0,9):
        if question[x][i] == n:
            return False
        for i in range(0,9):
            if question[i][y] == n:
                return False
        Xb = (x//3)*3
        Yb = (y//3)*3
        for i in range(0,3):
            for j in range(0,3):
                if question[Xb+i][Yb+j] == n :
                    return False
    return True

def findSolution():
    global question
    for x in range(9):
        for y in range(9):
            if question[x][y] == 0:
                for n in range(1,10):
                    if check(x,y,n):
                        question[x][y] = n
                        findSolution()
                        question[x][y] = 0
                return
    print(np.matrix(question))
   
#INITIALIZE HERE
question = [[0,2,6,0,0,0,8,1,0],
            [3,0,0,7,0,8,0,0,6],
            [4,0,0,0,5,0,0,0,7],
            [0,5,0,1,0,7,0,9,0],
            [0,0,3,9,0,5,1,0,0],
            [0,4,0,3,0,2,0,5,0],
            [1,0,0,0,3,0,0,0,2],
            [5,0,0,2,0,4,0,0,9],
            [0,3,8,0,0,0,4,6,0]]
print("[+]The Queestion is : \n")
print(np.matrix(question))
print("\n[+]The Solution is : \n")
findSolution()
printInfo();


def printInfo():
    print("hello world from srinivas")

def mannem():
    print("hello world from mannem")
