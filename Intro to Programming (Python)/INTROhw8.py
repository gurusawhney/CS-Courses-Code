# Gurumeher Sawhney HW CS1114
# This program prints out a calendar using a month function and leap year check
def main1():
    month = ["","January","February","March","April","May","June","July","August","September","October","November","December"]
    days_per_month = [0,31,28,31,30,31,30,31,31,30,31,30,31]
    year = int(input("Please enter the year: "))
    start_date = int(input("Please enter the number (1-7) of the day of the week 1/1 starts: "))
    isleap = leapyearcheck(year)
    if isleap == 1:
        days_per_month[2] = 29
    for index in range(1,len(month)):
        print("\n",month[index],year)
        monthmaker(days_per_month[index],start_date)
        end_date = (start_date+days_per_month[index]%7)%7
        if end_date == 0:
            end_date = 7
        start_date = end_date
    
def monthmaker(days,start):
    string = "Mon\tTues\tWed\tThurs\tFri\tSat\tSun"
    print(string)
    num_days = []
    for i in range(1,days+1):
        num_days.append(i)
    res_days = []
    for i in range(1,start):
        res_days.append(" ")
    res_days += num_days
    for index in range(0,len(res_days)):
        if index > 0 and index % 7 == 0:
            print()
        print(res_days[index],end = "\t")
    
def leapyearcheck(year):
    isleap = -1
    if year % 4 == 0:
        if year % 100 == 0 and year % 400 == 0 :
            isleap = 1
        elif year % 100 == 0:
            isleap = -1
        else:
            isleap = 1
    return isleap

# This program as multiple functions that play with a sentence
def main2():
    line = input("Please enter your sentence: ")
    print(firstword(line))
    print(sentence_without_firstword(line))
    print(reverseline(line))
    
def firstword(line):
    space_index = line.find(" ")
    return line[0:space_index]

def sentence_without_firstword(line):
    space_index = line.find(" ")
    return line[space_index+1:]

def reverseline(line):
    res_line = ""
    while line.find(" ") >= 0:
        word = firstword(line)
        res_line = word +" "+res_line
        line = sentence_without_firstword(line)
    res_line = line +" "+ res_line
    return res_line

# This program draws a pine tree
def main3():
    num = int(input("How many triangles in your pine tree would you like? "))
    space = int(input("How many spaces away from the margin would you like the treee? "))
    char = input("What character do you want to use?")
    for i in range(2,num+2):
        construct(i,char,space,num)
def construct(n,char,space,num):
    for line_number in range(1,n+1):
        line = " "*space+" "*(num-n+1)+" "*(n-line_number)+char*(line_number*2-1)
        print(line)

main1()
main2()
main3()
