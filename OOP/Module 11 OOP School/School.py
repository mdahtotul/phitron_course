class School:
    def __init__(self, name, address) -> None:
        self.name = name
        self.address = address
        self.teachers = {}
        # composition
        self.classrooms = {}

    @staticmethod
    def calculate_grade(mark):
        if 80 <= mark <= 100:
            return "A+"
        elif 70 <= mark < 80:
            return "A"
        elif 60 <= mark < 70:
            return "A-"
        elif 50 <= mark < 60:
            return "B"
        elif 40 <= mark < 50:
            return "C"
        elif 33 <= mark < 40:
            return "D"
        else:
            return "F"

    @staticmethod
    def grade_to_value(grade):
        grade_map = {
            "A+": 5.00,
            "A": 4.00,
            "A-": 3.50,
            "B": 3.00,
            "C": 2.00,
            "D": 1.00,
            "F": 0.00,
        }
        return grade_map[grade]

    @staticmethod
    def value_to_grade(value):
        if 4.5 <= value <= 5.00:
            return "A+"
        elif 3.5 <= value < 4.5:
            return "A"
        elif 3.0 <= value < 3.5:
            return "A-"
        elif 2.5 <= value < 3.0:
            return "B"
        elif 2.0 <= value < 2.5:
            return "C"
        elif 1.0 <= value < 2.0:
            return "D"
        else:
            return "F"

    def add_classroom(self, classroom):
        self.classrooms[classroom.name] = classroom

    def add_teacher(self, subject, teacher):
        self.teachers[subject] = teacher

    def student_admission(self, student):
        class_name = student.classroom.name
        if class_name in self.classrooms:
            # TODO: set student id, (roll number) at the time of adding the student
            self.classrooms[class_name].add_student(student)
        else:
            print(f"Classroom - {class_name} not found")

    def __repr__(self) -> str:
        print("------------ All Classrooms ---------------")
        for key, value in self.classrooms.items():
            print(key)

            print(f"------------ Students ---------------")
            cls = self.classrooms[key]
            for student in cls.students:
                print(student.name)
            print("\n")

            print(f"------------ Subject and Teacher ---------------")
            for subject in cls.subjects:
                print(f"Teacher -> {subject.teacher.name} || Sub: {subject.name}")
            print("\n")

            print(f"------------ Exam Marks ---------------")
            for student in cls.students:
                print(f"Student: {student.name} -->")
                for key, value in student.marks.items():
                    print(f"{key} -> {value} -> {student.subject_grade[key]}")
                print("\n")

            print("\n")

        return "status: 200"


class ClassRoom:
    def __init__(self, name) -> None:
        self.name = f"Class - {name}"
        # composition
        self.students = []
        self.subjects = []

    def add_student(self, student):
        serial_id = f"{self.name}-{len(self.students) + 1}"
        student.id = serial_id
        self.students.append(student)

    def add_subject(self, subject):
        self.subjects.append(subject)

    def take_semester_final(self):
        for subject in self.subjects:
            subject.exam(self.students)

        for student in self.students:
            student.calculate_final_grade()

    def __str__(self) -> str:
        return f"{self.name}-{len(self.students)}"

    # TODO: sort students by grade
    def get_top_students(self):
        pass


class Subject:
    def __init__(self, name, teacher) -> None:
        self.name = name
        self.teacher = teacher
        self.max_marks = 100
        self.pass_marks = 33

    def exam(self, students):
        for student in students:
            mark = self.teacher.evaluate_exam()
            student.marks[self.name] = mark
            student.subject_grade[self.name] = School.calculate_grade(mark)

    def __repr__(self) -> str:
        return self.name
