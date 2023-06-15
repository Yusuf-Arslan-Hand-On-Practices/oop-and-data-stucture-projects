
/*
 * Ad Soyad: Busra Dikmenkaya
 * No: 220706062
 */
import java.util.Scanner;

/*
 * DemoUrun sinifi.
 * Urun siniflarini (CepTelefonu ve FotografMakinesi) 
 * test eder.
 */
public class DemoUrun {
    private Urun[] urunListesi;
    private int girilenUrunSayisi;

    /*
     * Constructor
     * max urun sayisi ile bir DemoUrun nesnesi olusturur.
     */
    public DemoUrun(int maks_urun) {
        urunListesi = new Urun[maks_urun];
        girilenUrunSayisi = 0;
    }

    public static void baslikYazdir() {
        System.out.println("*******************************************");
        System.out.println("*** STOK URUN GIRIS VE SORGULAMA PANELI ***");
        System.out.println("*******************************************");
    }

    public static void menuYazdir() {
        System.out.println();
        System.out.println("MENU:");
        System.out.println("(1) Urun gir");
        System.out.println("(2) Urun sorgula");
        System.out.println("(3) Urun listesi sifirla");
        System.out.println("(4) Programi sonlandir");
    }

    public static void menuUrunSec() {
        System.out.println("\t(1) Cep Telefonu");
        System.out.println("\t(2) Fotograf Makinesi");
    }

    public int getOptikZoom(FotografMakinesi urun) {
        return urun.getOptikZoom();
    }

    public void urunListesiSifirlar() {
        for (int i = 0; i < urunListesi.length; i++) {
            urunListesi[i] = null;
        }
        girilenUrunSayisi = 0;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        baslikYazdir();
        System.out.print("\nStoka girilecek urun sayisi: ");
        int maks_urun = input.nextInt();
        DemoUrun demo = new DemoUrun(maks_urun);
        while (true) {
            menuYazdir();
            System.out.println("\nIslem seciniz: ");
            System.out.println("---------------");
            int secim = input.nextInt();
            if (secim == 1) {
                if (demo.girilenUrunSayisi >= maks_urun) {
                    System.out.println("\tMaksimum urun sayisi: " + maks_urun);
                    System.out.println("\tGirilen urun sayisi: " + demo.girilenUrunSayisi);
                    System.out.println("\tYeni urun girilmez!");
                    continue;
                }
                System.out.println("\tUrun giris");
                menuUrunSec();
                while (true) {
                    System.out.print("\n\tUrun seciniz: ");
                    int urunTipi = input.nextInt();
                    if (urunTipi == 1) {
                        CepTelefonu cepTelefonu = new CepTelefonu();
                        cepTelefonu.urunGir(cepTelefonu);
                        demo.urunListesi[demo.girilenUrunSayisi] = cepTelefonu;
                        demo.girilenUrunSayisi++;
                        break;
                    } else if (urunTipi == 2) {
                        FotografMakinesi fotografMakinesi = new FotografMakinesi();
                        fotografMakinesi.urunGir(fotografMakinesi);
                        demo.urunListesi[demo.girilenUrunSayisi] = fotografMakinesi;
                        demo.girilenUrunSayisi++;
                        break;
                    } else {
                        System.out.println("\tUrun secimi icin 1 ya da 2 degerini giriniz!");
                    }
                }

            } else if (secim == 2) {
                System.out.println("\tUrun Sorgulama");
                menuUrunSec();
                while (true) {
                    System.out.print("\n\tUrun seciniz: ");
                    int urunTipi = input.nextInt();
                    if (urunTipi == 1) {
                        boolean urunMevcut = false;
                        for (int i = 0; i < demo.girilenUrunSayisi; i++) {
                            Urun urun = demo.urunListesi[i];
                            if (urun.getTur().equals("CepTelefonu")) {
                                CepTelefonu cepTelefonu = (CepTelefonu) urun;
                                cepTelefonu.urunSorgula(cepTelefonu);
                                urunMevcut = true;
                            } else {
                                urunMevcut = false;
                            }
                        }
                        if (!urunMevcut) {
                            System.out.println("\tUrun listesinde cep telefonu bulunmadi!");
                        }
                        break;
                    } else if (urunTipi == 2) {
                        boolean urunMevcut = false;
                        for (int i = 0; i < demo.girilenUrunSayisi; i++) {
                            Urun urun = demo.urunListesi[i];
                            if (urun.getTur().equals("FotografMakinesi")) {
                                FotografMakinesi fotografMakinesi = (FotografMakinesi) urun;
                                fotografMakinesi.urunSorgula(fotografMakinesi);
                                urunMevcut = true;
                            } else {
                                urunMevcut = false;
                            }
                        }
                        if (!urunMevcut) {
                            System.out.println("\tUrun listesinde fotograf makinesi bulunmadi!");
                        }
                        break;
                    } else {
                        System.out.println("\tUrun secimi icin 1 ya da 2 degerini giriniz!");
                    }
                }

            } else if (secim == 3) {
                demo.urunListesiSifirlar();
                System.out.println("\tUrun listesi sifirlandi!");
                System.out.print("\tStoka girilecek urun sayisi: ");
                maks_urun = input.nextInt();
                demo = new DemoUrun(maks_urun);
            } else if (secim == 4) {
                System.out.println("\tProgram sonlandiriliyor...");
                break;
            } else {
                System.out.println("Islem secimi icin 1 ve 4 arasi bir sayi giriniz!");
            }

        }

        input.close();
    }
}
