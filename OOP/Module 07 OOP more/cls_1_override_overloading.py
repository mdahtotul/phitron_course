# example of overriding
class Person:
    def __init__(self, name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight

    def eat(self):
        return f"vat, mangso, polau, etc."

    def exercise(self):
        raise NotImplementedError


class Cricketer(Person):
    def __init__(self, name, age, height, weight, team) -> None:
        self.team = team
        super().__init__(name, age, height, weight)
        super().__init__(name, age, height, weight)

    def eat(self):
        text = f"vegetables, fruits, milk, egg, etc."
        print(text)
        return text

    def exercise(self):
        text = f"Taka diye loha algai"
        print(text)
        return text

    def __add__(self, other):
        return self.age + other.age

    def __mul__(self, other):
        return self.weight * other.weight

    def __gt__(self, other):
        return self.age > other.age


sakib = Cricketer("Sakib", 38, 68, 91, "Bangladesh")
sakib.eat()
sakib.exercise()

mushi = Cricketer("Mushfiq", 36, 65, 78, "Bangladesh")

# example of overloading
print(45 + 63)
print("sakib" + "tamim")
print([1, 2, 3] + [4, 5, 6])
print(sakib + mushi)
print(sakib * mushi)
