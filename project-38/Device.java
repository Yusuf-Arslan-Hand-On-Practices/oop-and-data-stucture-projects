interface Device {
    void turnOn();

    void turnOff();

    void reset();

    default void printStatus() {
        System.out.println("I am a device.");
    }

    static void printVersion() {
        System.out.println("1.0");
    }
}