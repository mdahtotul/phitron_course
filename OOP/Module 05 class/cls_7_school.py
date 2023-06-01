class Student:
    def __init__(self, name, cls, id):
        self.name = name
        self.id = id
        self.cls = cls

    def __repr__(self) -> str:
        return f"Student {self.name} is in class {self.cls} and has id {self.id}"


class Teacher:
    def __init__(self, name, subject, id) -> None:
        self.name = name
        self.subject = subject
        self.id = id

    def __repr__(self) -> str:
        return f"Teacher {self.name} teaches {self.subject} and has id {self.id}"


class School:
    def __init__(self, name, students, teachers) -> None:
        self.name = name
        self.students = students
        self.teachers = teachers

    def add_teacher(self, name, subject):
        id = len(self.teachers) + 101
        teacher = Teacher(name, subject, id)
        self.teachers.append(teacher)

    def enroll(self, name, cls, fee):
        if fee < 6500:
            return "not enough fee"
        else:
            id = len(self.students) + 1
            student = Student(name, cls, id)
            self.students.append(student)
            return f"Enrolled student {name} in class {cls} with id {id}"

    def __repr__(self) -> str:
        print(f"Welcome to {self.name}")
        print("----------Our Teachers----------")
        for teacher in self.teachers:
            print(teacher)
        print("----------Our Students----------")
        for student in self.students:
            print(student)

        return "Thank you for visiting us."


# alia = Student("Alia Torkari", 9, 1)
# ranbeer = Teacher("Ranbeer Kapoor", "Math", 1)
# print(alia)
# print(ranbeer)

phitron = School("Phitron School", [], [])
phitron.enroll("Alia Torkari", "IX", 6500)
phitron.enroll("Ranbeer Kapoor", "IX", 8200)
phitron.enroll("Kareena Kapoor", "X", 7000)
phitron.enroll("Saif Ali Khan", "X", 9000)

phitron.add_teacher("Tom Cruise", "Math")
phitron.add_teacher("Angelina Jolie", "English")
phitron.add_teacher("Brad Pitt", "Science")

print(phitron)
