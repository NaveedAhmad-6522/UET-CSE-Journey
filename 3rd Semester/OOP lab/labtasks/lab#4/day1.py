exit_flag = False  # Initialize the exit flag to False

while not exit_flag:
    line = input("> ")  # Prompt the user for input with a '>' prompt
    
    if line.lower() == "bye":
        exit_flag = True  # If the user types 'bye', set the exit_flag to True
    else:
        print(line)  # If the user types something else, print the input
