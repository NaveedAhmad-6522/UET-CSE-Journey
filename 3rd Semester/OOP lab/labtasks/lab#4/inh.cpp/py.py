import random
exi_flage=False
my_list=[]

while not exi_flage:
    user_input=input("enter a number (Or done to terminate)");
    if user_input.lower()=="done":
     exi_flage=True
    else:
        try:
          value=float(user_input)
          my_list.append(value)
        except ValueError:
          print("enter a valid numbr")
           

if my_list:
   average=sum(my_list)/len(my_list)
   print(f"the aveerage vale {average}")
else:
   print("enter a valid data")