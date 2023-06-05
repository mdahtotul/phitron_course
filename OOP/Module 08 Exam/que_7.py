""" 
Modify the Cricketer class to find the youngest player using the concept of operator overloading and lastly print his name.
"""


class Person:
    def __init__(self, name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight


class Cricketer(Person):
    def __init__(self, name, age, height, weight) -> None:
        super().__init__(name, age, height, weight)

    def __lt__(self, other):
        return self.age < other.age


Sakib = Cricketer("Sakib", 38, 68, 91)
Mushfiq = Cricketer("Mushfiq", 36, 55, 82)
Mustafiz = Cricketer("Mustafiz", 27, 69, 86)
Riyad = Cricketer("Riyad", 39, 72, 92)

young_player = min([Sakib, Mushfiq, Mustafiz, Riyad])
print(young_player.name)
