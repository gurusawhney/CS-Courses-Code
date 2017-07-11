# Gurumeher Sawhney HW CS1114
# This program questions 1-4 of the homework
import random
def main_q1():
    num = int(input("Enter an integer for the number of inputs you would like: "))
    lst = []
    for i in range(1,num+1):
        lst.append(i)
    print(create_permutation(lst))
def create_permutation(lst):
    for i in range(len(lst)):
        num = random.randint(0,len(lst)-1)
        lst.insert(num,lst.pop())
    return lst
#############################################
def main_q2():
    lst1 = []
    print("Please enter inputs into lst1 and when done type 'done': ")
    seen_done = False
    while(seen_done == False):
        curr_input = input()
        if(curr_input == 'done'):
            seen_done = True
        else:
            curr_num = int(curr_input)
            lst1.append(curr_num)
    lst2 = []
    print("Please enter inputs into 1st2 and when done type 'done': ")
    seen_done = False
    while(seen_done == False):
        curr_input = input()
        if(curr_input == 'done'):
            seen_done = True
        else:
            curr_num = int(curr_input)
            lst2.append(curr_num)

    if len(lst2) == len(lst1):
        res_list = add_list(lst1,lst2)
        for item in res_list:
            print(item)
    else:
        print("Lists are different lengths")
def add_list(lst1,lst2):
    res_lst = []
    for index in range(0,len(lst1)):
        num1 = lst1[index]
        num2 = lst2[index]
        res_num = num1+num2
        res_lst.append(res_num)
    return res_lst
#############################################
def main_q3():
    lst = []
    amount = int(input("Please enter the amount of inputs you want in the list: "))
    for i in range(0,amount):
        num = int(input("Enter an input: "))
        lst.append(num)
    print("The original list is:",lst)
    print("The prefix list is",create_prefix_lists(lst))
def create_prefix_lists(lst):
    res_lst = []
    for element in range(len(lst)+1):
        res_lst.append(lst[:element])
    return res_lst
#############################################
def main_q4():
    print("User, please enter the menu items:")
    menu_list = read_menu()
    print("Customers, please order your food:")
    total_price = 0
    for i in range(3):
        order_list = read_customer_order()
        price = compute_price(menu_list,order_list)
        total_price += price
    print("The total price is",(total_price*1.235)) 
def read_menu():
    num = int(input("How many items are on the menu? "))
    menu_lst = []
    for i in range(num):
        item = input("Enter item in the form 'name:price': ").split(":")
        menu_lst.append(item)
    return menu_lst
def read_customer_order():
    seen_done = False
    order_lst = []
    print("What would you like to order?")
    while seen_done == False:
        food = input()
        if food == "done":
            seen_done = True
        else:
            order_lst.append(food)
    return order_lst
def compute_price(menu_list,order_list):
    total_price = 0
    for order in order_list:
        for food in menu_list:
            if food[0] == order:
                total_price += int(food[1])
    return total_price
#############################################
main_q1()
main_q2()
main_q3()
main_q4()
