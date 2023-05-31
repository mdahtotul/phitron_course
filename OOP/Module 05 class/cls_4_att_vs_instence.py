class Shop:
    cart = []  # class attribute

    def __init__(self, buyer):
        self.buyer = buyer

    def add_to_cart(self, product):
        self.cart.append(product)


linkon = Shop("Linkon")
linkon.add_to_cart("shoes")
linkon.add_to_cart("t-shirt")
print(linkon.cart)

costa = Shop("Costa")
costa.add_to_cart("jeans")
costa.add_to_cart("jacket")
print(costa.cart)


class Shop2:
    shopping_mall = "Jamuna Future Park"

    def __init__(self, buyer):
        self.buyer = buyer
        self.cart = []  # instance attribute

    def add_to_cart(self, product):
        self.cart.append(product)


paul = Shop2("Paul")
paul.add_to_cart("shoes")
paul.add_to_cart("t-shirt")
print(paul.cart)

james = Shop2("James")
james.add_to_cart("jeans")
james.add_to_cart("jacket")
print(james.cart)
