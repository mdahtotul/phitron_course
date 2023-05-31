""" 
in, not, not in, is, is not, and, or, if, elif, else, ==, !=, <, >, <=, >=
"""

a = 4
if a > 5:
    print("a is greater than 5")
elif a == 5:
    print("a is equal to 5")
else:
    print("a is less than 5")

boss = True
if boss is True:
    print("Tel ar bakso niye astesi")
else:
    print("lunch ar pore asen")


# nested conditions
coin = "head"
if boss == True:
    print("Boss you are joss")
    if coin == "tail":
        print("batting kor")
    else:
        print("bowling kor")
else:
    print("you are loss")
