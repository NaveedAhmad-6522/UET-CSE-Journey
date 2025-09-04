exitf=False
my_list=[]
while not exitf:
    data=input("enter value (or done to finish)")
    if data.lower()=="done":
        exitf=True
    else:
        try:
            value=float(data)
            my_list.append(value)
        except ValueError:
            print("enter valid number")

if my_list:
    average=sum(my_list)/len(my_list)
    print(f"erthimatic mean of list {average} ")