
/*
 * Ad Soyad: Busra Dikmenkaya
 * No: 220706062
 */

/*
 * Soyut Urun sinifi
 */
public abstract class Urun {
    private String tur;
    private String marka;
    private double fiyat;
    private int adet;

    // default constructor
    public Urun() {
    }

    // Setters
    public void setTur(String tur) {
        this.tur = tur;
    }

    public void setMarka(String marka) {
        this.marka = marka;
    }

    public void setFiyat(double fiyat) {
        this.fiyat = fiyat;
    }

    public void setAdet(int adet) {
        this.adet = adet;
    }

    // Getters
    public String getTur() {
        return tur;
    }

    public String getMarka() {
        return marka;
    }

    public double getFiyat() {
        return fiyat;
    }

    public int getAdet() {
        return adet;
    }

    // Soyut methodlar
    public abstract Object urunGir(Object urun);

    public abstract void urunSorgula(Object urun);
}
