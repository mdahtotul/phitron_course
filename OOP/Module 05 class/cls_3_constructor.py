class Phone:
    manufacturer = "China"

    def __init__(self, owner, brand, price):
        self.owner = owner
        self.brand = brand
        self.price = price

    def send_sms(self, number, text):
        text = f"Sending sms to {number} \n message: {text}"
        return text


ph = Phone("Chan mia", "Oppo", 9800)
print(ph.owner, ph.brand, ph.price)

ph2 = Phone("Papa's princess", "iPhone", 120000)
print(ph2.owner, ph2.brand, ph2.price)


class Pen:
    manufacturer = "Bangladesh"

    def __int__(self, brand, color, body):
        self.brand = brand
        self.color = color
        self.body = body


pen = Pen("All Time", "black", "plastic")
print(pen.brand, pen.color, pen.body)
pen2 = Pen("Good Luck", "green", "metal")
