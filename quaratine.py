# aliyah khan
# 11/15/2020
# program 10b

# Pre-conditions: seatchart is a list of lists. Each individual list is a list
#                 of strings and all strings are unique. Each string represents
#                 a name and will have one uppercase letter followed by 1 or more
#                 lowercase letters. person will also be a string that follows
#                 the same rules and may or may not appear in seatchart.
# Post-condition: if person is not in seatchart, an empty list is returned. If
#                 person is in seatchart, a list of each name adjacent to person
#                 in seatchart is returned.
def getQuarantineList(seatchart, person):
    #list for the students who need to quarantine
    quarantineStudents = []
    arraySize = 0
    totalRows = len(seatchart)
    index = 0
    #find the array the student with covid is in
    whichArrayFound = -1
    #where they are in said array
    studentWithCovidPosition = -1
    #finding the student with covid
    for i in seatchart:
        #print(i)
        if person in i:
            studentWithCovidPosition = i.index(person)
            whichArrayFound = index
            arraySize = len(i)
        index += 1
    #returns an empty list
    if studentWithCovidPosition == -1:
        return quarantineStudents
    #the students aroud the infected student
    leftStudentPosition = studentWithCovidPosition - 1
    rightStudentPosition = studentWithCovidPosition + 1
    upStudentArray = whichArrayFound - 1
    downStudentArray = whichArrayFound + 1
    #checking each position to make sure there is someone to add to the list
    if leftStudentPosition >= 0:
        quarantineStudents.append(seatchart[whichArrayFound][leftStudentPosition])
    if rightStudentPosition < arraySize:
        quarantineStudents.append(seatchart[whichArrayFound][rightStudentPosition])
    if upStudentArray >= 0:
        quarantineStudents.append(seatchart[upStudentArray][studentWithCovidPosition])
    if downStudentArray < totalRows:
        quarantineStudents.append(seatchart[downStudentArray][studentWithCovidPosition])
    return quarantineStudents

# This runs a lot of tests.
def test():

    # A regular looking classroom, more than 2 rows and 2 columns.
    scienceClass = [["Anya", "Jane", "Mick", "Lauren"],
                ["Jamil", "Prince", "Janie", "Talia"],
                ["George", "Madison", "Connor", "Jade"]]
    
    print(getQuarantineList(scienceClass, "Prince"))

    # First test corners.
    print(getQuarantineList(scienceClass, "Anya"))
    print(getQuarantineList(scienceClass, "Lauren"))
    print(getQuarantineList(scienceClass, "George"))
    print(getQuarantineList(scienceClass, "Jade"))

    # Next test borders.
    print(getQuarantineList(scienceClass, "Jane"))
    print(getQuarantineList(scienceClass, "Jamil"))
    print(getQuarantineList(scienceClass, "Connor"))
    print(getQuarantineList(scienceClass, "Talia"))

    # Now test inside and someone not in the class.
    print(getQuarantineList(scienceClass, "Janie"))
    print(getQuarantineList(scienceClass, "Prince"))
    print(getQuarantineList(scienceClass, "James"))

    # This case is usually tricky!
    smallClass = [["Joe"]]
    print(getQuarantineList(smallClass, "Joe"))
    print(getQuarantineList(smallClass, "NotJoe"))

    # Next the one row class.
    atfrontClass = [["Alia","Ben","Cynthia","Darnay","Evelyn"]]
    print(getQuarantineList(atfrontClass, "Alia"))
    print(getQuarantineList(atfrontClass, "Darnay"))
    print(getQuarantineList(atfrontClass, "Evelyn"))
    print(getQuarantineList(atfrontClass, "Flynn"))

    # Lastly, one column
    onecolClass = [["Alia"],["Ben"],["Cynthia"],["Darnay"],["Evelyn"]]
    print(getQuarantineList(onecolClass, "Alia"))
    print(getQuarantineList(onecolClass, "Darnay"))
    print(getQuarantineList(onecolClass, "Evelyn"))
    print(getQuarantineList(onecolClass, "Flynn"))

# Run it!
test()
