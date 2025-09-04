Python 3.12.0 (tags/v3.12.0:0fb18b0, Oct  2 2023, 13:03:39) [MSC v.1935 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> number=int(input("enter a number"))
enter a number5
>>> number=int(input("enter a number"))
enter a number
Traceback (most recent call last):
  File "<pyshell#1>", line 1, in <module>
    number=int(input("enter a number"))
ValueError: invalid literal for int() with base 10: ''
>>> 
>>> 
>>> 
>>> 
>>> 
>>> 
>>> # Get a number from the user
... number = int(input("Enter a number: "))
... 
... # Use a loop to print the first 5 multiples of the entered number
... for i in range(1, 6):
...     multiple = number * i
...     print(f"{number} x {i} = {multiple}")
