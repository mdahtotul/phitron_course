import pyautogui

""" 
# this way to print pyramid in editor
n = 5
for i in range(n):
    for j in range(i + 1):
        pyautogui.write("#", interval=0.15)

    pyautogui.press("enter")
"""


n = int(input())

for i in range(n):
    for j in range(i + 1):
        print("#", end="")
        pyautogui.moveTo(1000 + 40 * j, 500 + 40 * i)
        pyautogui.dragTo(980 + 40 * j, 520 + 40 * i, duration=0.15)
        pyautogui.dragTo(1020 + 40 * j, 520 + 40 * i, duration=0.15)
        pyautogui.dragTo(1000 + 40 * j, 500 + 40 * i, duration=0.15)
    print()
