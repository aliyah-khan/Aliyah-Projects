#aliyah khan
#11/7/2020
#program 9a

def countElectoralVotes(votesA,votesB,electoralVotes):
    electoralVoteTotal = 0
    index = 0
    #iterates through the the lists and checks to see which candidate has more votess
    for i in votesA:
        if votesA[index] > votesB[index]:
            #takes the electoral votes earned by candidate A and adds them up
            electoralVoteTotal = electoralVoteTotal + electoralVotes[index]
        index += 1
    #return the electoral votes earned by candidte A
    return electoralVoteTotal

def testCountElectoralVotes():
    print (countElectoralVotes([9,3,8,2,6],[2,5,3,8,1],[10,4,9,12,11]))
    print (countElectoralVotes([1,2,3,4,5],[6,5,3,2,1],[3,9,6,1,4]))
    print (countElectoralVotes([8,5,7,3,12],[3,10,11,2,9],[11,14,6,2,6]))
    print (countElectoralVotes([100,50,80,99,210],[85,51,79,3,211],[10,2,20,17,3]))
    
testCountElectoralVotes()

