<?php 
/* Get a list of integers from user seperated by comma.
 * Find the minimum and maximum number.
 * Show the sum of numbers entered.
 * Calculate the average of this numbers. 
 * Issues:
 * User must enter valid numbers without a trailing comma, there's no input check.
 */
?>
<!doctype html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<title>Min, Max, Sum and Avg</title>
	</head>
	<body>
	
	<h1>Min, Max, Sum and Avg</h1>

	<form action="#" method="post">
  
		Enter your numbers seperated by comma (,): <input type="text" name="numbers">
		<input type="submit" value="Calculate">
		
	</form> 

	<?php
	//Check if the user has entered anything:
	if(!empty($_POST["numbers"]))
	{
		/* Seperate input by comma to get numbers.
		 * Maybe user decided to put some spaces after comma.
		 * This is why we're using "trim()" function to get rid of spaces.
		 */
		 
		 //Let's split input by comma:
		 $user_numbers = explode(",", $_POST["numbers"]);
		 
		 //Now that we've all the values, thim all of them to get rid of spaces:
		 
		 $trimmed = array_map('trim', $user_numbers);
		 
		 //Get the minimum value from numbers:
		 echo "Minimum number is: ".min($trimmed)."<br>";
		 
		 //Get the maximum value from numbers:
		 echo "Maximum number is: ".max($trimmed)."<br>";
		 
		 //Get the sum of numbers:
		 echo "Sum of numbers: ".array_sum($trimmed)."<br>";
		 
		 //Get the avg of numbers. Note that we're using "count" to get array items count:
		 echo "Avg of numbers: ".array_sum($trimmed)/count($trimmed);
		
	}
	
	?>

	</body>
</html>

