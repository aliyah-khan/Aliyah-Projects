#aliyah khan
#12/4/2020
#program 12

#list to hold the conversions
conversionList = []

#functions for converting what the user wants
#each conversion function does the calculation, rounds to 2 decimals, and returns that value
#1 inch = 2.54 centimeters
def inches2centimeters(inches):
    centimeters = inches * 2.54
    roundedValue = round(centimeters, 2)
    return roundedValue

#1 gallon = 3.79 Liters
def gallons2liters(gallons):
    liters = gallons * 3.79
    roundedValue = round(liters, 2)
    return roundedValue

#1 mile = 1.61 kilometers
def miles2kilometers(miles):
    kilometers = miles * 1.61
    roundedValue = round(kilometers, 2)
    return roundedValue

#1 pound = .45 kilograms
def pounds2kilograms(pounds):
    kilograms = pounds * .45
    roundedValue = round(kilograms, 2)
    return roundedValue

#function to read the file
def readFileInfo(fileName):
    with open(fileName) as f:
        fileContent = f.readlines()
    return fileContent

#menu for the user
def displayConversionMenu(headerMessage):
    print(headerMessage)
    print("1. inches to centimeters")
    print("2. gallons to liters")
    print("3. miles to kilometers")
    print("4. pounds to kilograms")
    quit = int(input("5. Quit\n"))
    return quit

#making sure that the user inputs a number 1-5
def validateMenuOption(menuItem):
    if menuItem > 0 and menuItem < 6:
        return True
    else:
        return False
    
def processInchConversion(fileContent, fileToSaveConversions):
    outputFile = open(fileToSaveConversions, "w")
    for line in fileContent:
        num = float(line)
        #doing the conversion
        centimeter = inches2centimeters(num)
        #adding to the list and getting rid of white space
        conversionList.append(line.strip() + "\t\t--> " + str(centimeter))
    #taking the info in the list and putting that into the output file
    for item in conversionList:
        print(item)
        print()
        outputFile.write(item)
        outputFile.write("\n")
    outputFile.close()

def processGallonConversion(fileContent, fileToSaveConversions):
    outputFile = open(fileToSaveConversions, "w")
    for line in fileContent:
        num = float(line)
        #doing the conversion
        gallon = gallons2liters(num)
        #adding to the list, gtting rid of white space
        conversionList.append(line.strip() + "\t\t--> " + str(gallon))
    #into the output file
    for item in conversionList:
        print(item)
        print()
        outputFile.write(item)
        outputFile.write("\n")
    outputFile.close()

def processMileConversion(fileContent, fileToSaveConversions):
    outputFile = open(fileToSaveConversions, "w")
    for line in fileContent:
        num = float(line)
        #conversion
        mile = miles2kilometers(num)
        #adding to the list, gtting rid of white space
        conversionList.append(line.strip() + "\t\t--> " + str(mile))
    #into the output file
    for item in conversionList:
        print(item)
        print()
        outputFile.write(item)
        outputFile.write("\n")
    outputFile.close()
    

def processPoundConversion(fileContent, fileToSaveConversions):
    outputFile = open(fileToSaveConversions, "w")
    for line in fileContent:
        num = float(line)
        #conversion
        pound = pounds2kilograms(num)
        #adding to the list, gtting rid of white space
        conversionList.append(line.strip() + "\t\t--> " + str(pound))
    #into the output file
    for item in conversionList:
        print(item)
        print()
        outputFile.write(item)
        outputFile.write("\n")
    outputFile.close()

print("Welcome to the Imperial to Metric System Converter!")
#user input
menuItem = displayConversionMenu("What conversion would you like to make?")
#validating the user's response
isMenuItemGood = validateMenuOption(menuItem)
#will keep bothering the user if they continue with invalid responses
while isMenuItemGood == False:
    menuItem = displayConversionMenu("Invalid selection\nPlease select correct menu item below:")
    isMenuItemGood = validateMenuOption(menuItem)
#more user input
fileName = input("Which file would you like to convert? (inches.txt, gallons.txt, miles.txt, or pounds.txt)\n")
fileContent = readFileInfo(fileName)

#when the user is done making conversions
fileToSaveConversions = input("In which file would you like your conversion results saved in? (End the file name with .txt)\n")

#processing the user's response and calling the apropriate function
if menuItem == 1:
    processInchConversion(fileContent, fileToSaveConversions)
    print("Your conversions have been saved to the file", fileToSaveConversions)
if menuItem == 2:
    processGallonConversion(fileContent, fileToSaveConversions)
    print("Your conversions have been saved to the file", fileToSaveConversions)
if menuItem == 3:
    processMileConversion(fileContent, fileToSaveConversions)
    print("Your conversions have been saved to the file", fileToSaveConversions)
if menuItem == 4:
    processPoundConversion(fileContent, fileToSaveConversions)
    print("Your conversions have been saved to the file", fileToSaveConversions)
if menuItem == 5:
    print("Thanks for using the Imperial to Metric System Converter!")









