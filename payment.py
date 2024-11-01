#Aliyah Khan
#10/18/20
#program 6c

#getting the user's input
payPerHour = float(input("How much (in dollars) are you paid per hour? "))
regWorkWeek = int(input("How many hours are in the regular work week? "))
overtimeRate = float(input("What is the overtime rate? "))
weeksWorked = int(input("How many weeks are you working? "))

#variable for the print statement displaying the 100% total amount of money
displayTotalPay = 0.0

#function to calculate the regular pay
def regularPay(payPerHour, regWorkWeek, hoursWorked):
    weeklySalary = 0.0
    if payPerHour > -1:
        if hoursWorked < regWorkWeek:
            weeklySalary = payPerHour * hoursWorked
        else:
            weeklySalary = payPerHour * regWorkWeek
        return weeklySalary
    
#function to calculate overtime pay
def overtimePay(payPerHour, regWorkWeek, hoursWorked, overtimeRate):
    weeklyOvertime = 0.0
    if hoursWorked > regWorkWeek:
        weeklyOvertime = (hoursWorked - regWorkWeek) * payPerHour * overtimeRate
    else:
        weeklyOvertime = 0
    return weeklyOvertime

#function for the regular and overtime pay weekly, and then add those two and then add all those results
def main(payPerHour, regWorkWeek, overtimeRate, weeksWorked):
    #variable for the 100% total pay
    totalPay = 0.0
    #iterates for each week
    for i in range(weeksWorked):
        #keep track of the weeks
        weekCounter = i+1
        #user input
        hoursWorked = int(input("How many hours did you work in week " + str(weekCounter) + "? "))
        #making variables for the functions above
        regPay = regularPay(payPerHour, regWorkWeek, hoursWorked)
        overPay = overtimePay(payPerHour, regWorkWeek, hoursWorked, overtimeRate)
        #adding up the return statements for the weekly totals
        weeklyTotalPay = regPay + overPay
        #printing weekly
        print("Week ", weekCounter, " regular pay = $", round(regPay, 2), ", overtime pay = $", round(overPay, 2), ", total pay = $",round(weeklyTotalPay, 2),sep = "")
        #printing out the final total pay
        totalPay = totalPay + weeklyTotalPay
        displayTotalPay = totalPay
        if weekCounter == weeksWorked:
            print("Total pay for ",weeksWorked, " weeks = $", round(displayTotalPay, 2), sep = "")
        
main(payPerHour, regWorkWeek, overtimeRate, weeksWorked)






