class Phone:
    price = 19000
    color = "blue"
    brand = "Samsung"

    # The first argument of the method is always self. This is a reference to the object itself.
    def call(self):
        print("Ring-ring!")

    def send_sms(self, number, text):
        print(f"Sending sms to {number} \n message: {text}")


ph = Phone()
ph.call()
ph.send_sms("+380501234567", "Hello, my friend!")


class Calculator:
    brand = "Casio MS990"

    def add(self, x, y):
        print(f"Sum of {x} and {y} is {x + y}")

    def subtract(self, x, y):
        print(f"Difference of {x} and {y} is {x - y}")

    def multiply(self, x, y):
        print(f"Product of {x} and {y} is {x * y}")

    def divide(self, x, y):
        print(f"Quotient of {x} and {y} is {x / y}")

    def power(self, x, y):
        print(f"{x} to the power of {y} is {x ** y}")

    def root(self, x, y):
        print(f"{y} root of {x} is {x ** (1 / y)}")
