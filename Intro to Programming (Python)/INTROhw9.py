# Gurumeher Sawhney HW CS1114
# This program contains questions 1-4 on the homework

def main_q1():
    lst = []
    amount = int(input("Please enter the amount of inputs you want in the list: "))
    for i in range(0,amount):
        num = int(input("Enter number(positive or negative): "))
        lst.append(num)
    print(max_abs_val(lst))
def max_abs_val(lst):
    max_val = abs(lst[0])
    for val in lst:
        curr_val = abs(val)
        if curr_val > max_val:
            max_val = curr_val
    return max_val

def main_q2():
    lst = []
    amount = int(input("Please enter the amount of inputs you want in the list: "))
    for i in range(0,amount):
        curr_ch = input("Enter value to search: ")
        lst.append(curr_ch)
    val = input("Which value are you looking for: ")
    print(find_all(lst,val))
def find_all(lst,val):
    res_lst = []
    for index in range(0,len(lst)):
        curr = lst[index]
        if curr == val:
            res_lst.append(index)
    return res_lst

def main_q3():
    lst = []
    amount = int(input("Please enter the amount of inputs you want in the list: "))
    for i in range(0,amount):
        curr_ch = input("Enter value: ")
        lst.append(curr_ch)
    print("The current list is",lst)
    print("reverse1's output is",reverse1(lst))
    print("reverse2's output is",reverse2(lst))
def reverse1(lst):
    res_lst = []
    for index in range((len(lst)-1),0-1,-1):
        curr = lst[index]
        res_lst.append(curr)
    return res_lst
def reverse2(lst):
    for index in range(0,len(lst)//2):
        new_place = (len(lst)-1)-index
        x = lst[index]
        lst[index] = lst[new_place]
        lst[new_place] = x
    return lst

def main_q4():
    line = input("Please enter a string of letters: ")
    lst = string_enc(line)
    print("The encoder is: ",lst)
    res_line = string_dec(lst)
    print("The decoder is: ",res_line)    
    
def string_enc(line):
    master_lst = []
    index = 0
    while index < len(line):
        lst = []
        char = line[index]
        lst.append(char)
        char_count = 1
        for i in range(index,len(line)-1):
            if char == line[i+1]:
                char_count +=1
            else:
                break
        lst.append(char_count)
        master_lst.append(lst)
        index += char_count
    return master_lst

def string_dec(lst):
    res_string = ""
    for value in lst:
        res_string += value[0]*int(value[1])
    return res_string

main_q1()
main_q2()
main_q3()
main_q4()
