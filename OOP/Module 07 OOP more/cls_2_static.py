class Shopping:
    cart = []  # class attribute # static attribute
    origin = "china"

    def __init__(self, name, location, price):
        self.name = name  # instance attribute
        self.location = location  # instance attribute
        self.price = price  # instance attribute

    def purchase(self, item, price, amount):
        remaining = amount - price
        print(
            f"Your remaining balance is ${remaining} after purchasing {item} at ${price} "
        )

    @classmethod
    def hudai_dekhi(self, item):
        print(f"kinbo na hudai dekhtesi {item}")

    @staticmethod
    def multiply(a, b):
        print(a * b)


Shopping.purchase("shoes", "Jamuna", 100, 500)

Shopping.hudai_dekhi("lungi")
Shopping.multiply(4, 5)
