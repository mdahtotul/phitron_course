class Vehicle:  # this is base class
    def __init__(self, name, price) -> None:
        self.name = name
        self.price = price

    def move(self):
        return f"Moving {self.name}..."

    def __repr__(self) -> str:
        return f"{self.name} {self.price}"


class Bus(Vehicle):  # this is derived class
    def __init__(self, name, price, seat) -> None:
        self.seat = seat
        super().__init__(
            name, price
        )  # inheriting property and method from base class(Vehicle)

    def __repr__(self) -> str:  # calling base class (Vehicle) representation method
        return super().__repr__()


class ACBus(Bus):  # this is another derived class
    def __init__(self, name, price, seat, temperature) -> None:
        self.temperature = temperature
        super().__init__(
            name, price, seat
        )  # inheriting property and method from derived class(Bus)

    def __repr__(self) -> str:  # calling derived class (Bus) representation method
        return super().__repr__() + f" Temperature: {self.temperature}deg"


class Truck(Vehicle):
    def __init__(self, name, price, weight) -> None:
        self.weight = weight
        super().__init__(name, price)

    def __repr__(self) -> str:
        return super().__repr__()


class PickUpTruck(Truck):
    def __init__(self, name, price, weight, capacity) -> None:
        self.capacity = capacity
        super().__init__(name, price, weight)

    def __repr__(self) -> str:
        return super().__repr__() + f" {self.capacity}"


green_line = ACBus("Green Line", 500000, 50, 20)
print(green_line)


