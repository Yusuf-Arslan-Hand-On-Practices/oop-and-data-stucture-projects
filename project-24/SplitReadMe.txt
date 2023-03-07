In this implementation we have a static function that returns the a ArrayList of String that
are split by the delimeters that are passed in.

In this function we have a loop that iterates through the string and checks if the current
character is a delimeter.
If it is not, we add the current char to the String Builder object.

If it is, we check if the String Builder object has any characters in it.
If it does, we add the String Builder object to the ArrayList and clear the String Builder object.

This is repeated until the end of the string is reached.

