class Restaurant:
    def __init__(self, name, rent, menu=[]) -> None:
        self.name = name
        self.orders = []
        self.chef = []
        self.waiter = []
        self.manager = []
        self.menu = menu
        self.rent = rent
        self.revenue = 0
        self.balance = 0
        self.expense = 0
        self.profit = 0

    def add_order(self, order):
        self.orders.append(order)

    def add_employee(self, type, employee):
        if type == "manager":
            self.manager.append(employee)
        elif type == "chef":
            self.chef.append(employee)
        elif type == "waiter":
            self.waiter.append(employee)

    def receive_payment(self, order, amount, customer):
        if order.bill <= amount:
            self.revenue += order.bill
            self.balance += order.bill
            customer.due_amount = 0
            return amount - order.bill
        else:
            print("Not enough money. Pay more")

    def pay_expanse(self, amount, description):
        if amount < self.balance:
            self.expense += amount
            self.balance -= amount
            print(f"Expense {amount} for {description} is paid.")
        else:
            print("Not enough balance.")

    def pay_salary(self, employee):
        if employee.salary < self.balance:
            self.balance -= employee.salary
            self.expense += employee.salary
            employee.receive_salary()
            print(f"{employee.name} is paid {employee.salary}TK")
        else:
            print(f"Not enough balance to pay {employee.name}'s salary'")

    def show_employee(self):
        print(f"\n------------ Manager ------------")
        for item in self.manager:
            print(f"{item.name} - {item.salary}TK")

        print(f"\n------------ Chef ------------")
        for item in self.chef:
            print(f"{item.name} - {item.salary}TK")

        print(f"\n------------ Waiter ------------")
        for item in self.waiter:
            print(f"{item.name} - {item.salary}TK")
