JC = javac
R = java
SRC = simulation/
DRIVER = test/MainTest

COMP:
	$(JC) $(SRC)*.java $(DRIVER).java -d bin
	$(R) -cp bin $(DRIVER)

CLR:
	rm bin -r

