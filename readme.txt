Course -
	Programming with C/C++ 4: Computer Gamees in 2D 5SD814 HT2022

Student -
	Mikkel Jonas Sørensen

Assignment - 
	I was supposed to make a configuration system where the user changes values in a .txt file
	which then should be used in the code to manipulate certain aspects, such as size of the 
	window. We were given a template of our Config class which we then worked out from.

Usage -
	The solution includes a config.txt file in the /assets/ folder. This file contains the 
	different variables that the user can manipulate without touching the code.
	
	The code checks if the file contains the keyword, before looking for the value.
	If the code cannot find the keyword, it returns false.

Collaboration -
	I talked to a fellow student, Jakub Orlowski, about how they store the information from
	the ifstream. He suggested that I should use unordered_map which I then did and saved me
	great time! Thank you!
