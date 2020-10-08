<?php
/* A simple number guess game written in PHP.
 * Script picks a random integer between 1-10
 * User tries to guess the number. 
 * This was a test script for my students on Discord. */
 
/* Start a session to store informations such as guessed number */
session_start(); ?>
<!doctype html>
<html lang="tr">
	<head>
		<meta charset="utf-8">
		<title>Simple Number Guess Game</title>
	</head>
	<body>
	
	<h1>Simple Number Guess Game</h1>
	<?php
//Generate a random number between 1-10
//If there's no number set for this game, set it. Otherwise that means game has already started. Don't do anything.
		if(empty($_SESSION["sayi"]))
		{
			//Generate random number and store it under 'sayi'
			$_SESSION["sayi"] = rand(1,10);
			//This is the counter for player's guesses. It's zeroed at the beginning of the game.
			$_SESSION["sayac"] = 0;
		}
		//For debug purposes, you can check which number has chosen. But this part is commented out for now.
		//echo '<h2>Chosen number is: '.$_SESSION["sayi"].'</h2>';
	?>

	<form action="#" method="post">
  
		Your Guess: <input type="text" name="gelensayi">
		<input type="submit" value="Guess">
		
	</form> 

	<?php
	
	//Declare a variable to store player's guess:
	$tahmin;

	//If the guess button is clicked, do your magic like this:
	if(!empty($_POST["gelensayi"]))
	{
		//Check if the player "actually" entered a number:
		if(is_numeric($_POST["gelensayi"]))
		{
			//So it seems it's really a number. Let's get this guess first:
			$tahmin = $_POST["gelensayi"];
			//There's a valid guess. Counter should go up by 1:
			$_SESSION["sayac"]++;

			//Compare the chosen number and the guess. If guess is lower than the chosen number:
			if($tahmin < $_SESSION["sayi"])
			{
				//Alert user to go up!
				echo "Up!";
			}
			//And if the player guessed a number greater than chosen number:
			else if($tahmin > $_SESSION["sayi"])
			{
				//Alert user to go down!
				echo "Down!";
			}
			//So if it's not greater or lower, that means player has won the game:
			else
			{
				//Alert user:
				echo "Congratulations! You've guessed the number at ".$_SESSION["sayac"]." guesses!";

				//Destroy the session so we can start another game:
				session_destroy();

				//Put a link to play again:
				echo '<a href="number_guess.php">Play again</a>';
			}
				//Show player his/her guess:
				echo "<h3>Your guess is: ".$_POST["gelensayi"]."</h3>";
		}
	
	}
	
	?>

	</body>
</html>

