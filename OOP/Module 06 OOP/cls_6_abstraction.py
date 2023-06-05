""" 
Abstract base class (abc)
"""
from abc import ABC, abstractmethod


class Animal(ABC):
    @abstractmethod  # enforce all derived classes to implement this method
    def eat(self):
        print("I need food to survive")

    def sleep(self):
        pass

    @abstractmethod
    def move(self):
        pass


class Monkey(Animal):
    def __init__(self, name) -> None:
        self.name = name
        self.category = "Monkey"
        super().__init__()

    def eat(self):
        print(f"Hey nana, eating banana")

    def move(self):
        print(f"Hanging on trees")


laykan = Monkey("Laykan")
laykan.eat()
