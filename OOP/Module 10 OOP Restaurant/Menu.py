class Food:
    def __init__(self, name, price) -> None:
        self.name = name
        self.price = price
        self.cooking_time = 15


class Burger(Food):
    def __init__(self, name, price, meat, ingredients) -> None:
        self.meat = meat
        self.ingredients = ingredients
        super().__init__(name, price)


class Pizza(Food):
    def __init__(self, name, price, size, ingredients, toppings) -> None:
        self.size = size
        self.ingredients = ingredients
        self.toppings = toppings
        super().__init__(name, price)


class Drinks(Food):
    def __init__(self, name, price, size, is_cold=True) -> None:
        self.size = size
        self.is_cold = is_cold
        super().__init__(name, price)


# composition
class Menu:
    def __init__(self) -> None:
        self.pizzas = []
        self.burgers = []
        self.drinks = []

    def add_menu_item(self, item_type, item):
        if item_type == "pizza":
            self.pizzas.append(item)
        elif item_type == "burger":
            self.burgers.append(item)
        elif item_type == "drink":
            self.drinks.append(item)

    def remove_menu_item(self, item_type, item):
        if item_type == "pizza" and item in self.pizzas:
            self.pizzas.remove(item)
        elif item_type == "burger" and item in self.burgers:
            self.burgers.remove(item)
        elif item_type == "drink" and item in self.drinks:
            self.drinks.remove(item)

    def show_menu(self):
        print(f"\n------------Pizza Menu------------")
        for pizza in self.pizzas:
            print(f"{pizza.name} - {pizza.price}TK")

        print(f"\n------------Burger Menu------------")
        for burger in self.burgers:
            print(f"{burger.name} - {burger.price}TK")

        print(f"\n------------Drink Menu------------")
        for drink in self.drinks:
            print(f"{drink.name} - {drink.price}TK")
