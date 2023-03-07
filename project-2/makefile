JC = javac
R = java
SUPER = interface_Aka/
SUB = src_Aka/
DRIVER = test
JFlags = 


Aka:
	$(JC) $(JFlags) $(SUPER)*.java $(SUB)*.java $(DRIVER).java  -d classfiles
	$(R) -cp classfiles $(DRIVER)

javadoc:
	javadoc $(SUPER)*.java $(SUB)*.java -d javadoc

clean:
	rm javadoc/ classfiles/ -r

