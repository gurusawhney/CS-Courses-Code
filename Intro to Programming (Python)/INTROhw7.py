# Gurumeher Sawhney HW CS1114
# This program prints out a Caesar cipher. I checked for uppercase, lowercase,
# and spaces and added it to a new string
shift_by = int(input("What shift should we apply:"))
input_word = input("Please enter a word: ")
enc_word = ""
for letter in input_word:
    if(letter.islower() == True):
        lett = ord(letter)-ord('a')
        enc_lett = ((lett+shift_by)%26)+ord('a')
        enc_letter = chr(enc_lett)
        enc_word += enc_letter
    if(letter.isupper() == True):
        lett = ord(letter)-ord('A')
        enc_lett = ((lett+shift_by)%26)+ord('A')
        enc_letter = chr(enc_lett)
        enc_word += enc_letter
    if(letter == " "):
        enc_word += " "
print("The encoded word is:",enc_word)

# This program creates a 5x10 power table using nested for loops and the
# equation given to us  row i, column j is j^i
import math
for power in range(1,5+1):
    for num in range(1,10+1):
        print(int(math.pow(num,power)),end = "\t")

# This program asks the user to guess a random number between 1-100 using a
# boolean and storing the latest upper and lower values and question count
import random
print("I thought of a number between 1 and 100! Try to guess it.")
answer = int(random.random()*100)
is_right = False
qcount = 0
oldupp = 100
oldlow = 1
while(is_right == False):
    guess = int(input("Try to guess what it is: "))
    qcount += 1
    if(guess < answer):
        lower = guess+1
        upper = oldupp
        print("Wrong guess. Guess in range",lower,"to",upper,"You have",5-qcount,"more chances")
    elif(guess > answer):
        upper = guess-1
        lower = oldlow
        print("Wrong guess. Guess in range",lower,"to",upper,"You have",5-qcount,"more chances")
    if(guess == answer):
        is_right = True
        break
    if(qcount == 5):
        break
    oldupp = upper
    oldlow = lower
if(is_right == True):
    print("Congrats! You guessed my number in",qcount,"guesses.")
else:
    print("Sorry, you did not find the correct answer.")

