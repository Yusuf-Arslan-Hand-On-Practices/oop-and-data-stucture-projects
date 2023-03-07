public class Main {
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
