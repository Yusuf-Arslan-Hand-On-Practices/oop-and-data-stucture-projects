import java.util.ArrayList;
import java.util.GregorianCalendar;
import java.util.List;


public class MainFlights {

    public static class Flight {
        private String flightNo;
        private GregorianCalendar departureTime;
        private GregorianCalendar arrivalTime;

        public Flight(String flightNo, GregorianCalendar departureTime, GregorianCalendar arrivalTime) {
            this.flightNo = flightNo;
            this.departureTime = departureTime;
            this.arrivalTime = arrivalTime;
        }

        /**
         * It returns the flight number.
         */
        public String getFlightNo() {
            return flightNo;
        }

        /**
         * It sets the departure time.
         */
        public void setDepartureTime(GregorianCalendar departureTime) {
            this.departureTime = departureTime;
        }

        /**
         * It returns the departure time.
         */
        public GregorianCalendar getDepartureTime() {
            return departureTime;
        }

        /**
         * It sets the arrival time.
         */
        public void setArrivalTime(GregorianCalendar arrivalTime) {
            this.arrivalTime = arrivalTime;
        }

        /**
         * It returns the arrival time.
         */
        public GregorianCalendar getArrivalTime() {
            return arrivalTime;
        }

        /*
            * It returns the flight duration in minutes.
            */
        public int getFlightDuration() {
            long duration = arrivalTime.getTimeInMillis() - departureTime.getTimeInMillis();
            return (int) (duration / 60000);
        }

    }


    public static class Itinerary {
        private List<Flight> flights;
    
        public Itinerary(List<Flight> flights) {
            this.flights = flights;
        }
    
        /**
         * This function returns the total travel time of a flight itinerary in minutes
         */
        public int getTotalTravelTime()
        {
            GregorianCalendar firstDepartureTime = flights.get(0).getDepartureTime();
            GregorianCalendar lastArrivalTime = flights.get(0).getArrivalTime();
    
            for (Flight flight : flights) {
                if (flight.getDepartureTime().before(firstDepartureTime)) {
                    firstDepartureTime = flight.getDepartureTime();
                }
    
                if (flight.getArrivalTime().after(lastArrivalTime)) {
                    lastArrivalTime = flight.getArrivalTime();
                }
            }
    
            // get total travel time by minutes
            return (int) ((lastArrivalTime.getTimeInMillis() - firstDepartureTime.getTimeInMillis()) / 60000);
        }
    
        /**
         * This function returns the total flight time of all flights in the itinerary
         */
        public int getTotalFlightTime()
        {
            int getTotalFlightTime = 0;
    
            for (Flight flight : flights) {
                getTotalFlightTime += flight.getFlightDuration();
            }
    
            return getTotalFlightTime;
        }
    }
    
    public static void main(String[] args) {
        List<Flight> flights = new ArrayList<>();
        flights.add(new Flight("US230", 
                    new GregorianCalendar(2014, 4, 5, 5, 5, 0),
                    new GregorianCalendar(2014, 4, 5, 6, 15, 0)));
        flights.add(new Flight("US235", 
                    new GregorianCalendar(2014, 4, 5, 6, 55, 0),
                    new GregorianCalendar(2014, 4, 5, 7, 45, 0)));
        flights.add(new Flight("US237", 
                    new GregorianCalendar(2014, 4, 5, 9, 35, 0),
                    new GregorianCalendar(2014, 4, 5, 12, 55, 0)));
        
        Itinerary itinerary = new Itinerary(flights);
        System.out.println(itinerary.getTotalTravelTime());
        System.out.println(itinerary.getTotalFlightTime());
    }
}
