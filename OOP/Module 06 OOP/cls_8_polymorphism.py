class Animal:
    def __init__(self, name) -> None:
        self.name = name

    def make_sound(self):
        print("Chilla chilli kori")


class Cat(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)

    def make_sound(self):
        print("Meow")


class Dog(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)

    def make_sound(self):
        print("Gheu Gheu")


class Cow(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)

    def make_sound(self):
        print("hamba hamba")


billi = Cat("Billi")
billi.make_sound()

kutta = Dog("Kutta")
kutta.make_sound()

hamba = Cow("Hamba")
hamba.make_sound()


##################################################

from math import pi


class Shape:
    def __init__(self, name) -> None:
        self.name = name


class Rectangle(Shape):
    def __init__(self, name, length, width) -> None:
        self.length = length
        self.width = width
        super().__init__(name)

    # this function calculates the area of a rectangle based on length and width
    def area(self):
        return self.length * self.width


class Triangle(Shape):
    def __init__(self, name, height, width) -> None:
        self.h = height
        self.w = width
        super().__init__(name)

    # this function calculates the area of a triangle based on height and width
    def area(self):
        return 0.5 * self.h * self.w


class Circle(Shape):
    def __init__(self, name, radius) -> None:
        self.radius = radius
        super().__init__(name)

    # this function calculates the area of a circle based on their radius
    def area(self):
        return pi * self.radius**2
