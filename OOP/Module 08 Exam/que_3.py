class ThreeInstance:
    def __init__(self, a, b, c) -> None:
        self.a = a
        self.b = b
        self.c = c

    def sum(self):
        return self.a + self.b + self.c

    def factorial(self):
        fact = 1
        for i in range(1, self.b + 1):
            fact *= i

        return fact


obj = ThreeInstance(2, 3, 4)
print(obj.sum())
print(obj.factorial())
