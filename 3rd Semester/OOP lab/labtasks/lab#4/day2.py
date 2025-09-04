#exit_flag=False
#while not exit_flag:
   # line=input(">")
    #if line.lower()=="bye":
    #/*  exit_flag=True
   # else:
     #   print(line)#
#def temp_fre():
    #celsius=float(input("Enter temprature in celsius"))
    #fehrenhiet=(celsius*9/5)+32
    #print(f"{celsius} im fehrenhiet is {fehrenhiet}")
#temp_fre()
#import random
"""
dice_patterns = { # Create a dictionary to store dice face patterns
    1: "[-----]\n[         ]\n[    0   ]\n[         ]\n[-----]",
    2: "[-----]\n[0       ]\n[         ]\n[       0]\n[-----]",
    3: "[-----]\n[0       ]\n[    0   ]\n[       0]\n[-----]",
    4: "[-----]\n[0     0]\n[         ]\n[0     0]\n[-----]",
    5: "[-----]\n[0     0]\n[    0   ]\n[0     0]\n[-----]",
    6: "[-----]\n[0     0]\n[0     0]\n[0     0]\n[-----]"
}
num=random.randint(1,6)
print("the rolled \n number is ", num)
if num in dice_patterns:
    print(dice_patterns[num])
else:
    print("invalid!")
 """
# Day 05
# 🧠 Quiz Master - Test Your Knowledge with Python!
"""
import random

# Define a list of questions and answers as tuples (question, answer)
qa_pairs = [ ("What is 2 + 2?", "4"),
             ("What is 10 * 5?", "50"),
             ("What is 15 - 7?", "8"),
             ("What is 30 / 3?", "10"),
             ("What is 2 ** 3?", "8") ]
qa_pairs[2]=("what is 2_2","0")
# Shuffle the question-answer pairs to get a random order
random.shuffle(qa_pairs)
score=0
for question,answer in qa_pairs:
    print(f"{question} ")
    user_answer=input()
    if user_answer==answer:
        print("correct")
        score+=1
    else:
        print("wrong")
print(f"you score {score} out of {len(qa_pairs)}")
if score==len(qa_pairs):
    print("you're quiz champion!")

"""
"""
import random
chars="qwertyuioplkjhgffddssazzxcbnk,,./==-98709798y1t6`t7"
password=""
password_lenght=int(input("enter lenght"))
for i in range(password_lenght):
    password+=random.choice(chars)

print(password)
"""
"""
hours_worked = float(input("Enter hours worked: "))
hourly_rate = float(input("Enter hourly rate (in $): "))

# Calculate pay based on regular and overtime rates
if hours_worked > 40:
    regular_pay = 40 * hourly_rate
    overtime_hours = hours_worked - 40
    overtime_pay = overtime_hours * (hourly_rate * 1.5)  # Overtime rate is 1.5 times the hourly rate
    total_pay = regular_pay + overtime_pay
else:
    total_pay = hours_worked * hourly_rate

# Display the calculated pay
print(f"Pay: ${total_pay:.2f}")
"""
"""
import random

# Generate a random number between 1 and 5
num = random.randint(1, 5)
guess = None

# Keep prompting the user to guess the number until they guess correctly
while guess != num:
    # Allowing the user to input their guess as an integer
    guess = int(input("Guess a number between 1 and 5: "))
    
    # Check if the guessed number matches the generated random number
    if guess == num:
        print("Congratulations! You won :)")  # Print a success message if the guess is correct
        break                                 # Exit the loop if the guess is correct
    else:
        print("Try Again :(")  # Print a message to try
        """


 """
# Day 09
# Calculating Arithmetic Mean in Python

# Initialize the exit flag to control the loop
exit_flag = False

# Initialize an empty list to store numbers
num_list = list()

# Continuously prompt the user to enter numbers
while not exit_flag:
    data = input("Enter a number (type 'done' to finish): ")

    if data.lower() == "done":      # Allowing both 'done' and 'Done'
        exit_flag = True
    else:
        try:
            value = float(data)     # Convert input to a float type
            num_list.append(value)  # Add the value to the list
        except ValueError:
            print("Invalid input. Please enter a valid number.")

# Calculate the average of the numbers in the list
if num_list:    # Check if the list is not empty to avoid ZeroDivisionError
    average = sum(num_list) / len(num_list)
    print("Average: ", average)    # Print the calculated average
else:
    print("No data entered. Cannot calculate average.")  # Print a message if no data is entered

"""
