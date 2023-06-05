from abc import ABC, abstractmethod
from datetime import datetime


class Ride_Sharing:
    def __init__(self, company_name) -> None:
        self.company_name = company_name
        self.rides = []
        self.drivers = []
        self.riders = []

    def add_rider(self, rider):
        self.riders.append(rider)

    def add_driver(self, driver):
        self.drivers.append(driver)

    def __repr__(self) -> str:
        return f"Company Name: {self.company_name} -> Riders: {len(self.riders)} and Drivers: {len(self.drivers)}"


class User(ABC):
    def __init__(self, name, email, phone, nid) -> None:
        self.name = name
        self.email = email
        self.phone = phone
        self.__id = 0
        self.__nid = nid
        self.wallet = 0

    @abstractmethod
    def display_profile(self):
        raise NotImplementedError


class Rider(User):
    def __init__(
        self, name, email, phone, nid, current_location, initial_amount
    ) -> None:
        self.current_ride = None
        self.wallet = initial_amount
        self.current_location = current_location
        super().__init__(name, email, phone, nid)

    def display_profile(self):
        print(
            f"Name: {self.name}\nEmail: {self.email}\nPhone: {self.phone}\nNID: {self.__nid}\nWallet: {self.wallet}"
        )

    def load_cash(self, amount):
        if amount > 0:
            self.wallet += amount

    def update_location(self, current_location):
        self.current_location = current_location

    def request_ride(self, ride_sharing, destination):
        if not self.current_ride:
            ride_request = Ride_Request(self, destination)
            ride_matcher = Ride_Matching(ride_sharing.drivers)
            self.current_ride = ride_matcher.find_driver(ride_request)

    def show_current_ride(self):
        if self.current_ride:
            print(self.current_ride)
        else:
            print("No current ride")


class Driver(User):
    def __init__(self, name, email, phone, nid, current_location) -> None:
        self.current_location = current_location
        self.wallet = 0
        super().__init__(name, email, phone, nid)

    def display_profile(self):
        print(
            f"Name: {self.name}\nEmail: {self.email}\nPhone: {self.phone}\nNID: {self.__nid}\Location: {self.current_location}"
        )

    def accept_ride(self, ride):
        ride.set_driver(self)


class Ride:
    def __init__(self, start_location, end_location) -> None:
        self.start_location = start_location
        self.end_location = end_location
        self.driver = None
        self.rider = None
        self.start_time = None
        self.end_time = None
        self.estimated_fare = None

    def set_driver(self, driver):
        self.driver = driver

    def start_ride(self):
        self.start_time = datetime.now()

    def end_ride(self, rider, amount):
        self.end_time = datetime.now()
        self.rider.wallet -= self.estimated_fare
        self.driver.wallet += self.estimated_fare

    def __repr__(self) -> str:
        return f"Ride details: From {self.start_location} to {self.end_location}"


class Ride_Request:
    def __init__(self, rider, end_location):
        self.rider = rider
        self.end_location = end_location


class Ride_Matching:
    def __init__(self, drivers) -> None:
        self.available_drivers = drivers

    def find_driver(self, ride_request):
        if len(self.available_drivers) > 0:
            # TODO: Find the closest driver based on ride request
            driver = self.available_drivers[0]
            ride = Ride(ride_request.rider.current_location, ride_request.end_location)
            driver.accept_ride(ride)
            return ride


class Vehicle(ABC):
    speed = {
        "car": 60,
        "bike": 50,
        "cng": 35,
    }

    def __init__(self, vehicle_type, license_plate, rate) -> None:
        self.vehicle_type = vehicle_type
        self.license_plate = license_plate
        self.rate = rate
        self.__id = 0
        self.status = "available"
        super().__init__()

    @abstractmethod
    def start_drive(self, start_location, end_location):
        pass


class Car(Vehicle):
    def __init__(self, vehicle_type, license_plate, rate) -> None:
        super().__init__(vehicle_type, license_plate, rate)

    def start_drive(self, start_location, end_location):
        self.status = "unavailable"


# check the class integration

niye_jao = Ride_Sharing("Niye Jao")
sakib = Rider("Sakib", "sakib@gmail.com", "01700000000", "123456789", "Mohakhali", 1200)
niye_jao.add_rider(sakib)
kala_pakhi = Driver(
    "Kala Pakhi", "kala@sada.com", "01611759902", "123456790", "Gulshan"
)

niye_jao.add_driver(kala_pakhi)
print(niye_jao)
sakib.request_ride(niye_jao, "Banani")
sakib.show_current_ride()
