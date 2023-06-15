
/*
 * Ad Soyad: Busra Dikmenkaya
 * No: 220706062
 */
import java.util.Scanner;

/*
 * Cep telefonu sinifi
 */
public class CepTelefonu extends Urun {
    private int ekranYenilemeHizi;
    private int bellekKapasitesi;
    private int kameraCozunurluk;

    // default constructor
    public CepTelefonu() {
    }

    // Setters
    public void setEkranYenilemeHizi(int ekranYenilemeHizi) {
        this.ekranYenilemeHizi = ekranYenilemeHizi;
    }

    public void setBellekKapasitesi(int bellekKapasitesi) {
        this.bellekKapasitesi = bellekKapasitesi;
    }

    public void setKameraCozunurluk(int kameraCozunurluk) {
        this.kameraCozunurluk = kameraCozunurluk;
    }

    // Getters
    public int getEkranYenilemeHizi() {
        return ekranYenilemeHizi;
    }

    public int getBellekKapasitesi() {
        return bellekKapasitesi;
    }

    public int getKameraCozunurluk() {
        return kameraCozunurluk;
    }

    /*
     * Soyut siniftan override edilmis urunGir fonksiyonu
     */
    @Override
    public Object urunGir(Object product) {
        /*
         * Farkli bir siniftan nesne gelip gelmedigini kontrol et
         * geldiyse try-catch bloku ile hatayi yakala
         */
        try {
            String input;
            Scanner inputScanner = new Scanner(System.in);
            CepTelefonu cepTelefonu = (CepTelefonu) product;
            System.out.print("\tMarka giriniz: ");
            input = inputScanner.nextLine();
            cepTelefonu.setMarka(input);

            System.out.print("\tEkran yenileme hizini giriniz (Hz): ");
            input = inputScanner.nextLine();
            cepTelefonu.setEkranYenilemeHizi(Integer.parseInt(input));

            System.out.print("\tBellek kapasitesi giriniz (GB): ");
            input = inputScanner.nextLine();
            cepTelefonu.setBellekKapasitesi(Integer.parseInt(input));

            System.out.print("\tKamera cozunurlugu giriniz (MP): ");
            input = inputScanner.nextLine();
            cepTelefonu.setKameraCozunurluk(Integer.parseInt(input));

            System.out.print("\tFiyat giriniz (TL): ");
            input = inputScanner.nextLine();
            cepTelefonu.setFiyat(Double.parseDouble(input));

            System.out.print("\tAdet giriniz: ");
            input = inputScanner.nextLine();
            cepTelefonu.setAdet(Integer.parseInt(input));

            cepTelefonu.setTur("CepTelefonu");

            return product;

        } catch (Exception e) {
            System.out.println("\ttLutfen CepTelefonu tipinde bir nesne giriniz.");
        }

        return null;
    }

    /*
     * Soyut Urun classindan override edilmis urunSorgula metodu
     */
    @Override
    public void urunSorgula(Object product) {
        try {
            CepTelefonu cepTelefonu = (CepTelefonu) product;
            System.out.println("\t----------------------------");
            System.out.println("\tMarka: " + cepTelefonu.getMarka());
            System.out.println("\tEkran yenileme hizi: " + cepTelefonu.getEkranYenilemeHizi() + " Hz");
            System.out.println("\tBellek kapasitesi: " + cepTelefonu.getBellekKapasitesi() + " GB");
            System.out.println("\tKamera cozunurlugu: " + cepTelefonu.getKameraCozunurluk() + " MP");
            System.out.println("\tFiyat: " + cepTelefonu.getFiyat() + " TL");
            System.out.println("\tAdet: " + cepTelefonu.getAdet());
        } catch (Exception e) {
            System.out.println("\tLutfen CepTelefonu tipinde bir nesne giriniz.");
        }
    }
}
