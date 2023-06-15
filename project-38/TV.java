class TV implements Device {
    @Override
    public void turnOn() {
        System.out.println("TV is on");
    }

    @Override
    public void turnOff() {
        System.out.println("TV is off");
    }

    @Override
    public void reset() {
        System.out.println("TV is resetting");
    }

    @Override
    public void printStatus() {
        Device.super.printStatus();
        System.out.println("I am a TV.");
    }

}