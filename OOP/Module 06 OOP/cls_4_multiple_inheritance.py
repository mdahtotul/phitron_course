class Family:
    def __init__(self, family_name) -> None:
        self.family_name = family_name


class School:
    def __init__(self, school_name, school_id, school_level) -> None:
        self.school_id = school_id
        self.school_name = school_name
        self.school_level = school_level


class Sports:
    def __init__(self, game) -> None:
        self.game = game


class Student(Family, School, Sports):
    def __init__(
        self, name, age, family_name, school_name, school_id, school_level, game
    ) -> None:
        self.name = name
        self.age = age
        Family.__init__(self, family_name)
        School.__init__(self, school_name, school_id, school_level)
        Sports.__init__(self, game)

    def __repr__(self) -> str:
        return f"{self.name} {self.age} {self.family_name} {self.school_name} {self.school_id} {self.school_level} {self.game}"
