
/*
 * Ad Soyad: Busra Dikmenkaya
 * No: 220706062
 */
import java.util.Scanner;

/*
 * Fotograf makinesi sinifi
 */
public class FotografMakinesi extends Urun {
    private int dijitalZoom;
    private int optikZoom;

    // default constructor
    public FotografMakinesi() {
    }

    // Setters
    public void setDijitalZoom(int dijitalZoom) {
        this.dijitalZoom = dijitalZoom;
    }

    public void setOptikZoom(int optikZoom) {
        this.optikZoom = optikZoom;
    }

    // Getters
    public int getDijitalZoom() {
        return dijitalZoom;
    }

    public int getOptikZoom() {
        return optikZoom;
    }

    /*
     * Product sinifindan override edilmis urunGir metodu
     */
    @Override
    public Object urunGir(Object product) {
        try {
            String input;
            Scanner inputScanner = new Scanner(System.in);
            FotografMakinesi fotografMakinesi = (FotografMakinesi) product;
            System.out.print("\tMarka giriniz: ");
            input = inputScanner.nextLine();
            fotografMakinesi.setMarka(input);

            System.out.print("\tDijital zoom degeri giriniz: ");
            input = inputScanner.nextLine();
            fotografMakinesi.setDijitalZoom(Integer.parseInt(input));

            System.out.print("\tOptik zoom degeri giriniz: ");
            input = inputScanner.nextLine();
            fotografMakinesi.setOptikZoom(Integer.parseInt(input));

            System.out.print("\tFiyat giriniz (TL): ");
            input = inputScanner.nextLine();
            fotografMakinesi.setFiyat(Double.parseDouble(input));

            System.out.print("\tAdet giriniz: ");
            input = inputScanner.nextLine();
            fotografMakinesi.setAdet(Integer.parseInt(input));

            fotografMakinesi.setTur("FotografMakinesi");
            return product;

        } catch (Exception e) {
            System.out.println("\tLutfen FotografMakinesi tipinde bir nesne giriniz.");
        }

        return null;
    }

    /*
     * Product sinifindan override edilmis urunSorgula metodu
     */
    @Override
    public void urunSorgula(Object product) {
        try {

            FotografMakinesi fotografMakinesi = (FotografMakinesi) product;
            System.out.println("\t----------------------------");
            System.out.println("\tMarka: " + fotografMakinesi.getMarka());
            System.out.println("\tDijital zoom degeri: " + fotografMakinesi.getDijitalZoom() + "x");
            System.out.println("\tOptik zoom degeri: " + fotografMakinesi.getOptikZoom() + "x");
            System.out.println("\tFiyat: " + fotografMakinesi.getFiyat());
            System.out.println("\tAdet: " + fotografMakinesi.getAdet());
        } catch (Exception e) {
            System.out.println("\tLutfen FotografMakinesi tipinde bir nesne giriniz.");
        }
    }
}
