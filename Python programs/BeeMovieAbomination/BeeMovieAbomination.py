import pyautogui as pg
import keyboard as k
import time

class MassDestruction():
    def __init__(self):
        """ This opens file with the bee movie script and makes a list to iterate through
        The key parameter is the kye that has to be pressed to stop and start the writing """

        self.BeeMovieScript = open("Python programs\BeeMovieAbomination\HistorysGreatestWeapon.txt", "r")
        self.BeeMovieWords = self.BeeMovieScript.read().split()
        self.BeeMovieScript.close()
        self.stopped = False
        FAILSAFE = True
        time.sleep(3)
        self.destroy()

    def destroy(self):
        """ Iterates through all words in the list """

        while bool(self.BeeMovieWords) is True:
            if k.is_pressed("1") and self.stopped is False:
                self.change()
            
            # If the number '1' is pressed, the program will stop until you press it again
            self.stopped = False
            pg.typewrite(self.BeeMovieWords[0])
            pg.press("enter")
            self.BeeMovieWords.pop(0)

    def change(self):
        """ This is to stop typing all the words when space is hit """
        
        k.wait("1")
        self.stopped = True
        self.destroy()
        
        

MassDestruction()
# Test it in an app like notepad

