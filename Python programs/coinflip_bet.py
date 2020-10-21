import random

money = 100

def coin_flip(guess, bet):
  if bet <= 0:
    print('--------------------------')
    print('Your bet should be above 0')
    return 0
    print('--------------------------')
  
  print('---------------------')
  print('You guessed: ' + guess)
  print('---------------------')
  result = random.randint(1, 2)
  
  if result == 1:
    print('Heads!')
  elif result == 2:
    print('Tails!')
    
  if (guess == 'Heads' and result == 1) or (guess == 'Tails' and result == 2):
    print('You won ' + str(bet) + ' dollars!')
    print('-------------------------------')
    return bet
  else:
    print('You lost ' + str(bet) + ' dollars!')
    print('-------------------------------')
    return -bet

coin_flip('Heads', 50)
