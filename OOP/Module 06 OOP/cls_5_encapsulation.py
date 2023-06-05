""" 
@access modifier
Public attributes: can be accessed from anywhere
Private attributes: can be accessed only from inside the class
Protected attributes: can be accessed from inside the class and from its child class

encapsulation: hiding the private attributes from outside the class
"""


class Bank:
    def __init__(self, holder_name, init_deposit) -> None:
        self.holder_name = holder_name  # public attribute
        self._branch = "Dhaka"  # protected attribute
        self.__balance = init_deposit  # private attribute

    def deposit(self, amount):
        self.__balance += amount

    def withdraw(self, amount):
        if amount > self.__balance:
            print("Insufficient Balance")
        else:
            self.__balance -= amount

    def get_balance(self):
        return self.__balance


rafsun = Bank("Rafsun", 1000)

print(rafsun.holder_name)
print(rafsun.__balance)
