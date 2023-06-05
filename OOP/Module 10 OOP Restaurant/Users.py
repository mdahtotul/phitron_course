from abc import ABC, abstractmethod


class User(ABC):
    def __init__(self, name, phone, email, address) -> None:
        self.name = name
        self.phone = phone
        self.email = email
        self.address = address


class Customer(User):
    def __init__(self, name, phone, email, address, money) -> None:
        self.wallet = money
        self.__order = None
        self.due_amount = 0
        super().__init__(name, phone, email, address)

    @property
    def order(self):
        return self.__order

    @order.setter
    def order(self, order):
        self.__order = order

    def place_order(self, order):
        self.order = order
        self.due_amount += order.bill
        print(f"{self.name} has placed an order for {order.bill}")

    def eat_food(self, order):
        print(f"{self.name} is eating {order.name}")

    def pay_for_order(self, order):
        # TODO: Check if customer has enough money
        # TODO: submit payment to the manager
        self.wallet -= order.bill

    def give_tips(self, amount):
        # TODO: Check if customer has enough money
        # TODO: submit payment to the waiter
        self.wallet -= amount

    def write_review(self, stars):
        pass


class Employee(User):
    def __init__(
        self, name, phone, email, address, salary, starting_date, department
    ) -> None:
        self.salary = salary
        self.due_amount = salary
        self.starting_date = starting_date
        self.department = department
        super().__init__(name, phone, email, address)

    def receive_salary(self):
        self.due_amount = 0


class Chef(Employee):
    def __init__(
        self,
        name,
        phone,
        email,
        address,
        salary,
        starting_date,
        department,
        cooking_item,
    ) -> None:
        self.cooking_item = cooking_item
        super().__init__(name, phone, email, address, salary, starting_date, department)


class Waiter(Employee):
    def __init__(
        self,
        name,
        phone,
        email,
        address,
        salary,
        starting_date,
        department,
    ) -> None:
        self.tips_earning = 0
        super().__init__(name, phone, email, address, salary, starting_date, department)

    def take_order(self, order):
        pass

    def transfer_order(self, order):
        pass

    def serve_food(self, order):
        pass

    def receive_tips(self, amount):
        self.tips_earning += amount


class Manager(Employee):
    def __init__(
        self, name, phone, email, address, salary, starting_date, department
    ) -> None:
        super().__init__(name, phone, email, address, salary, starting_date, department)
