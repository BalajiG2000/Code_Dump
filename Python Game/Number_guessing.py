import random
attempts_list = []
def show_score():
    if len(attempts_list) <= 0:
        print("There is currently no high score, it's yours for the taking!\n")
    else:
        print("The current high score is {} attempts\n".format(min(attempts_list)))
def start_game():
    random_number = int(random.randint(1, 10))
    print("Hello traveler! Welcome to the game of guesses!")
    player_name = input("What is your name?")
    wanna_play = input("\nHi, {}, would you like to play the guessing game? (Enter Yes/No) ".format(player_name))
    # Where the show_score function USED to be
    attempts = 0
    show_score()
    while wanna_play.lower() == "yes":
        try:
            guess = int(input("Pick a number between 1 and 10 "))
            if guess < 1 or guess > 10:
                raise ValueError("Please guess a number within the given range: ")
            if guess == random_number:
                print("Nice! You got it!\n")
                attempts += 1
                attempts_list.append(attempts)
                print("It took you {} attempts\n".format(attempts))
                play_again = input("Would you like to play again? (Enter Yes/No): ")
                attempts = 0
                show_score()
                random_number = int(random.randint(1, 10))
                if play_again.lower() == "no":
                    print("That's cool, have a good one!")
                    break
            elif guess > random_number:
                print("It's lower\n")
                attempts += 1
            elif guess < random_number:
                print("It's higher\n")
                attempts += 1
        except ValueError as err:
            print("Oh no!, that is not a valid value. Try again...")
            print("({})".format(err))
    else:
        print("That's cool, have a good one!")
if __name__ == '__main__':
    start_game()
