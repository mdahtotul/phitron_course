def display_person(**kwargs):
    for key, value in kwargs.items():
        print(f"{key}: {value}")


display_person(Name="Amir Khan", Age="45")

numbers = [7, 6, 5, 3, 3, 2, 1]
print(numbers[-4])

numbers = [7, 8, 5, 4, 3, 2, 4]
print(numbers[::-1])
