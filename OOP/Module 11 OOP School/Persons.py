import random
from School import School


class Person:
    def __init__(self, name) -> None:
        self.name = name


class Teacher(Person):
    def __init__(self, name) -> None:
        super().__init__(name)

    def teach(self):
        pass

    def __repr__(self) -> str:
        return f"{self.name}"

    def evaluate_exam(self):
        marks = random.randint(33, 100)
        return marks


class Student(Person):
    def __init__(self, name, classroom) -> None:
        self.__id = None
        self.classroom = classroom
        self.subjects = []
        self.marks = {}
        self.subject_grade = {}
        self.grade = None
        super().__init__(name)

    def calculate_final_grade(self):
        total = 0
        for grade in self.subject_grade.values():
            point = School.grade_to_value(grade)
            total += point
            print(self.name, grade, point)

        points_avg = total / len(self.subject_grade)

        self.grade = School.value_to_grade(points_avg)
        print(
            f"{self.name} final grade -> {self.grade} with average {points_avg} points"
        )

    @property
    def id(self):
        return self.__id

    @id.setter
    def id(self, value):
        self.__id == value
