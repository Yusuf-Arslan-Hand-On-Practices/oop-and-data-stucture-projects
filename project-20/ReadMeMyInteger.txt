MyInteger class has a data field 'value' which is our integer value.

The class has a constructor which takes an integer value and assigns it to the data field.

It has a method called 'isEven' which returns true if the value is even and false if the value is odd.
Also, it has a method called 'isOdd' which returns true if the value is odd and false if the value is even and 
a method called 'isPrime' which returns true if the value is prime and false if the value is not prime.

Also this class has a static 'isEven', 'isOdd' and 'isPrime' methods.

These methods take MyInteger objects as well as integer values and return the results.

Also, this class has 2 equals methods which one takes a MyInteger object and the other takes an integer value
and returns true if the value in the object is equal to the value in the parameter.

The class also has 2 static methods called parseInt(char[]) and parseInt(String) 
which convert an array of numeric characters to an integer value and a string to an integer value respectively.

TESTING THE CLASS
In Driver.Java, we have a method 'DriverMyInteger' which is called in the main method. 