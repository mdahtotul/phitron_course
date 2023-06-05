def double_decker():
    print("starting the double decker")

    def inner_func():
        print("inside the inner")
        return 200

    return inner_func


print(double_decker()())


def do_something(work):
    print("Work started")
    work()
    print("Work ended")


def coding():
    print("coding in python")


def sleeping():
    print("sleeping and dreaming")


do_something(coding)


def outer_fun(x):
    def inner_fun(y):
        return x + y

    return inner_fun


add = outer_fun(5)  # value of x is 5
result = add(3)  # value of y is 3
print(result)
