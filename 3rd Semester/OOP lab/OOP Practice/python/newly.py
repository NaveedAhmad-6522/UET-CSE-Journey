number = int(input("Enter a number: "))

if number % 2 == 0:
    print(f"The number {number} is even.")
    for i in range(number, 0, -1):
        print(i)
else:
    print(f"The number {number} is odd.")
    for i in range(number, -1, -1):
        print(i)
