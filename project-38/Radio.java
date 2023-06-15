class Radio implements Device {
    @Override
    public void turnOn() {
        System.out.println("Radio is on");
    }

    @Override
    public void turnOff() {
        System.out.println("Radio is off");
    }
}