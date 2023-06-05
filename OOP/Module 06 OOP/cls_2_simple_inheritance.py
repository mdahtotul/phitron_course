class Laptop:
    def __init__(self, brand, price, color, memory) -> None:
        self.brand = brand
        self.price = price
        self.color = color
        self.memory = memory

    def run(self):
        return f"Running laptop: {self.brand}"

    def coding(self):
        return f"Coding on laptop: {self.brand}"


class Phone:
    def __init__(self, brand, name, price, color, dual_sim) -> None:
        self.brand = brand
        self.name = name
        self.price = price
        self.color = color
        self.dual_sim = dual_sim

    def run(self):
        return f"Phone tipa tipi kore"

    def phone_call(self, number, text):
        return f"Sending SMS to: {number} with: {text}"


class Camera:
    def __init__(self, brand, price, color, pixel) -> None:
        self.brand = brand
        self.price = price
        self.color = color
        self.pixel = pixel

    def run(self):
        return f"Click click"


""" 
base class, parent class, common attribute + functionality class
derived class, child class , uncommon attribute + functionality class
"""


# Simple Inheritance
class Device:
    def __init__(self, brand, price, color, type) -> None:
        self.brand = brand
        self.price = price
        self.color = color
        self.type = type

    def run(self):
        return f"Running {self.type}..."


class Laptop(Device):
    def __init__(self, brand, price, color, type, memory) -> None:
        self.memory = memory
        super().__init__(brand, price, color, type)

    def coding(self):
        return f"Coding on laptop: {self.brand}"


class Phone(Device):
    def __init__(self, brand, price, color, type, dual_sim) -> None:
        self.dual_sim = dual_sim
        super().__init__(brand, price, color, type)

    def phone_call(self, number, text):
        return f"Sending SMS to: {number} with: {text}"


class Camera(Device):
    def __init__(self, brand, price, color, type, pixel) -> None:
        self.pixel = pixel
        super().__init__(brand, price, color, type)

    def run(self):
        return f"Click click"


my_phone = Phone("iPhone", 120000, "Black", "Phone", False)
print(my_phone.brand)
