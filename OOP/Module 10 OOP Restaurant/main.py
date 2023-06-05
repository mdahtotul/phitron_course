from Menu import Pizza, Burger, Drinks, Menu
from Restaurant import Restaurant
from Users import Manager, Chef, Waiter, Customer
from Order import Order


def main():
    menu = Menu()

    # add pizza to menu
    pizza_1 = Pizza("Margherita", 1000, "Large", ["Cheese"], ["Olives", "Mushrooms"])
    menu.add_menu_item("pizza", pizza_1)
    pizza_2 = Pizza("Pepperoni", 700, "Large", ["Tomato", "Cheese"], ["Pepperoni"])
    menu.add_menu_item("pizza", pizza_2)
    pizza_3 = Pizza("BBQ Chicken", 800, "Large", ["Tomato", "Cheese"], ["Chicken"])
    menu.add_menu_item("pizza", pizza_3)
    pizza_4 = Pizza("Hawaiian", 900, "Large", ["Tomato", "Cheese"], ["Pineapple"])
    menu.add_menu_item("pizza", pizza_4)

    # add burger to menu
    burger_1 = Burger("Cheese Burger", 500, "Beef", ["Cheese", "Onion"])
    menu.add_menu_item("burger", burger_1)
    burger_2 = Burger("Chicken Burger", 600, "Chicken", ["Cheese", "Onion"])
    menu.add_menu_item("burger", burger_2)
    burger_3 = Burger("Naga Burger", 700, "Chicken", ["Cheese", "Onion"])
    menu.add_menu_item("burger", burger_3)

    # add drink to menu
    drink_1 = Drinks("Coke", 25, "250ml", True)
    menu.add_menu_item("drink", drink_1)
    drink_2 = Drinks("Pepsi", 20, "250ml", True)
    menu.add_menu_item("drink", drink_2)
    drink_3 = Drinks("7up", 25, "250ml", True)
    menu.add_menu_item("drink", drink_3)
    coffee = Drinks("Mocha", 300, "1 cup", False)
    menu.add_menu_item("drink", coffee)

    restaurant = Restaurant("Khaja Baba Restaurant", 2000, menu)

    # add employees
    manager = Manager(
        "Kala Chan",
        "01611759902",
        "kala@chan.com",
        "Kaliapu",
        "20000",
        "Jan 1, 2020",
        "manager",
    )

    restaurant.add_employee("manager", manager)

    chef = Chef(
        "Kopa baborchi",
        "016xxxxxxxx",
        "kopa@chef.com",
        "Nagarpur",
        500,
        "Jan 1, 2020",
        "chef",
        "kacchi",
    )

    restaurant.add_employee("chef", chef)

    waiter = Waiter(
        "Chotu waiter",
        "017xxxxxxxx",
        "chotu@waiter.com",
        "chupripara",
        8000,
        "Jan 1, 2020",
        "Waiter",
    )

    restaurant.add_employee("waiter", waiter)

    # add customer
    customer_1 = Customer("Saki", "017xxxxxxxx", "saki@pakhi.com", "gulshan", 1000)
    order_1 = Order(customer_1, [pizza_3, coffee])
    customer_1.pay_for_order(order_1)
    restaurant.add_order(order_1)
    restaurant.receive_payment(order_1, 2000, customer_1)

    print(f"Revenue: {restaurant.revenue}, Balance: {restaurant.balance}")

    # add customer
    customer_2 = Customer(
        "Sakibba", "017xxxxxxxx", "sakibba@hotmail.com", "gulshan", 1500
    )
    order_2 = Order(customer_2, [pizza_3, burger_3, coffee])
    customer_2.pay_for_order(order_2)
    restaurant.add_order(order_2)
    restaurant.receive_payment(order_2, 5000, customer_2)

    print(f"Revenue: {restaurant.revenue}, Balance: {restaurant.balance}")

    # show menu
    # menu.show_menu()
    # show employee
    # restaurant.show_employee()
    # show revenue
    restaurant.pay_expanse(restaurant.rent, "Rent")
    print(f"Revenue: {restaurant.revenue}, Balance: {restaurant.balance}")

    restaurant.pay_salary(chef)
    print(f"Revenue: {restaurant.revenue}, Balance: {restaurant.balance}")


if __name__ == "__main__":
    main()
