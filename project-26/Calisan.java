public class Calisan {
    // Değişkenler
    private String isim; 
    private String departman; 
    private double maas; 
    private int seviye; // 1-5 arasında

    // Getter ve Setter metotları
    public String get_isim() {
        return isim;
    }

    public String get_departman() {
        return departman;
    }

    public double get_maas() {
        return maas;
    }

    public int get_seviye() {
        return seviye;
    }

    public void set_departman(String departman) {
        this.departman = departman;
    }

    // Seviye setter metodu
    private void set_seviye(int seviye) {
        // Seviye 1-5 arasında olmalı
        if (seviye < 1 || seviye > 5) {
            throw new RuntimeException("Seviye 1-5 arasında olmalı!");
        }
        this.seviye = seviye;
    }

    // Maaş setter metodu
    private void set_maas(double maas) {
        if (maas < 0) {
            throw new RuntimeException("Maaş negatif olamaz!");
        }
        this.maas = maas;
    }

    // toString metodu
    @Override
    public String toString() {
        return isim + ", " + departman + ", " + maas;
    }

    // Zam yap metodu
    public double zamYap(int oran) {
        if (oran == 0) {
            throw new RuntimeException("Zam oranı 0 olamaz!");
        }
        double zam = maas * oran / 100;
        maas += zam;
        return zam;
    }

    // Promosyon yap metodu
    public double promosyonYap() {
        if (seviye == 5) {
            throw new RuntimeException("Daha fazla promosyon yapılamaz.");
        }
        // Seviye 1 arttırılıyor
        seviye++;

        // Yeni maaş hesaplanıyor
        double oran = seviye * 0.05;
        double zam = maas * oran;
        maas += zam;
        return zam;
    }

    // Toplam zam metodu
    public int toplamZam(int[] zamArray, int index) {
        if (index == zamArray.length) {
            return 0;
        }
        // Dizideki sayılar pozitif degilse, hata fırlat
        if (zamArray[index] <= 0) {
            throw new RuntimeException("Dizi sadece pozitif sayı içerebilir.");
        }
        int toplam = zamArray[index] + toplamZam(zamArray, index + 1);
        return toplam;
    }

    // Constructor metodu
    public Calisan(String isim, String departman, double maas, int seviye) {
        this.isim = isim;
        this.departman = departman;
        set_maas(maas);
        set_seviye(seviye);
    }

    public static void main(String[] args) {

        Calisan ali = new Calisan("ali", "hukuk", 5000, 4);
        Calisan veli = new Calisan("veli", "muhasebe", 4000, 5);
        Calisan ayse = new Calisan("ayse", "ik", 3000, 3);

        System.out.println(ali);
        System.out.println(veli);
        System.out.println(ayse);

        String ali_departman = ali.get_departman();
        int ali_seviye = ali.get_seviye();
        double ali_maas = ali.get_maas();
        String ali_isim = ali.get_isim();

        System.out.println(ali_isim);
        System.out.println(ali_departman);
        System.out.println(ali_maas);
        System.out.println(ali_seviye);

        ali.set_departman("ik");
        ali.set_seviye(2);
        ali.set_maas(2000);

        System.out.println(ali);

        double ali_zam = ali.zamYap(50);
        System.out.println(ali_zam);


        ali.promosyonYap();
        ali_zam = ali.promosyonYap();
        System.out.println(ali_zam);
        ali.promosyonYap();

        int[] zamArray = {8,7,6,5,4,1};
        int zam = ali.toplamZam(zamArray, 0);
        System.out.println(zam);
    }

   
}
