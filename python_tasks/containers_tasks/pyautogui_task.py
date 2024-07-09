import pyautogui
from time import sleep




try:
    location1 = None
    location2 = None
    location3 = None
    location4 = None

    while location1 is None:

        #open Extantion and install clang
        location1 = pyautogui.locateOnScreen('extention.png')
        sleep(1)
        pyautogui.click(location1.left+15,location1.top+5)
        pyautogui.typewrite('clan')
        sleep(2)
      
        location2 = pyautogui.locateOnScreen('clang.png')
        sleep(1)
        pyautogui.click(location2.left+10,location2.top+10)
        sleep(2)
      
        location3 = pyautogui.locateOnScreen('install.png')
        sleep(1)
        pyautogui.click(location3.left+15,location3.top+10)

        sleep(2)

        #install c++ testmate
        location4 = pyautogui.locateOnScreen('ex.png')
        pyautogui.tripleClick(location4.left,location4.top+10)
        sleep(1)
        pyautogui.hotkey('delete')
        sleep(1)
        pyautogui.typewrite('c++ testmate')
        sleep(3)
        pyautogui.click(location2.left+10,location2.top+10)
        sleep(2)
        pyautogui.click(location3.left+15,location3.top+10)

        sleep(2)

        #install c++ helper
        location4 = pyautogui.locateOnScreen('ex.png')
        pyautogui.tripleClick(location4.left,location4.top+10)
        sleep(1)
        pyautogui.hotkey('delete')
        sleep(1)
        pyautogui.typewrite('c++ helper')
        sleep(3)
        pyautogui.click(location2.left+10,location2.top+10)
        sleep(2)
        pyautogui.click(location3.left+15,location3.top+10)

        sleep(2)


        #install cmake
        location4 = pyautogui.locateOnScreen('ex.png')
        pyautogui.tripleClick(location4.left,location4.top+10)
        sleep(1)
        pyautogui.hotkey('delete')
        sleep(1)
        pyautogui.typewrite('cmake')
        sleep(4)
        pyautogui.click(location2.left+10,location2.top+10)
        sleep(2)
        pyautogui.click(location3.left+15,location3.top+10)



        sleep(2)
        #install cmake tools
        location4 = pyautogui.locateOnScreen('ex.png')
        pyautogui.tripleClick(location4.left,location4.top+10)
        sleep(1)
        pyautogui.hotkey('delete')
        sleep(1)
        pyautogui.typewrite('cmake tools')
        sleep(4)
        pyautogui.click(location2.left+10,location2.top+10)
        sleep(2)
        pyautogui.click(location3.left+15,location3.top+10)        



except pyautogui.ImageNotFoundException:
    print("iMAGE NOT FOUND")
