from abc import ABC, abstractmethod


class User(ABC):
    roles = ["Owner", "Manager", "Receptionist", "Chief", "Waiter", "Customer"]

    def __init__(self, name, phone, role="Customer") -> None:
        self.__id = 0
        self.name = name
        self.phone = phone
        self.role = role
