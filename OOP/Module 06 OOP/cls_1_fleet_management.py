class Company:
    def __init__(
        self,
        title,
    ) -> None:
        self.name = title

    @staticmethod
    def get_name(title):
        return f"Company name: {title}"


class Platform:
    def __init__(self, title) -> None:
        self.name = title

    def get_name(self):
        return f"Platform name: {self.name}"


obj = Platform("Phitron")
print(obj.get_name())

obj2 = Company("Pioneer")
print(obj2.get_name("Pioneer"))
