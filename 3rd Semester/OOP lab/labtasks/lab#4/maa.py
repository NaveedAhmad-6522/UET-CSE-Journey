def tempConvert():
    # Input temperature in Celsius
    celsius = float(input("Enter temperature in Celsius: "))

    # Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9/5) + 32
    
    # Display the result
    print(f"{celsius} degrees Celsius is equal to {fahrenheit} degrees Fahrenheit.")

 # Function Call in Python
tempConvert()