from School import School, ClassRoom, Subject
from Persons import Student, Teacher


def main():
    school = School("Kalakakali High School", "Agrabad, Chittagong")

    # add classroom
    cls_eight = ClassRoom("08")
    school.add_classroom(cls_eight)

    cls_nine = ClassRoom("09")
    school.add_classroom(cls_nine)

    cls_ten = ClassRoom("10")
    school.add_classroom(cls_ten)

    # add students
    student_1 = Student("Kala Chan", cls_eight)
    school.student_admission(student_1)

    student_2 = Student("Chan Mia", cls_eight)
    school.student_admission(student_2)

    student_3 = Student("Hablu Ablu", cls_eight)
    school.student_admission(student_3)

    student_4 = Student("Kala Chan", cls_nine)
    school.student_admission(student_4)

    student_5 = Student("Chan Mia", cls_nine)
    school.student_admission(student_5)

    student_6 = Student("Hablu Ablu", cls_nine)
    school.student_admission(student_6)

    #  add teacher & subject
    sub_1_teacher = Teacher("Robiul vai")
    sub_1 = Subject("Physics", sub_1_teacher)
    cls_eight.add_subject(sub_1)

    sub_2_teacher = Teacher("Nag vai")
    sub_2 = Subject("Chemistry", sub_2_teacher)
    cls_eight.add_subject(sub_2)

    sub_3_teacher = Teacher("Totul vai")
    sub_3 = Subject("Mathematics", sub_3_teacher)
    cls_eight.add_subject(sub_3)

    # exam
    cls_eight.take_semester_final()

    print(school)


if __name__ == "__main__":
    main()
