correct_password = "naveed"

while True:
    user_input = input("Enter password: ")
    
    if user_input == correct_password:
        print("Login successful!")
        break
    else:
        print("Incorrect password. Try again.")
