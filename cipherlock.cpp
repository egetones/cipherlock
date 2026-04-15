#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Renk kodları (Linux Terminali için)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"

using namespace std;

void processFile(string inputPath, string outputPath, string key) {
    // Dosyayı BINARY (ikili) modda açıyoruz. Metin değil, byte okuyacağız.
    ifstream inputFile(inputPath, ios::binary);
    if (!inputFile) {
        cerr << RED << "[!] Hata: Girdi dosyası açılamadı: " << inputPath << RESET << endl;
        return;
    }

    // Veriyi okumak için bir tampon (buffer) oluştur
    // Dosyanın sonuna kadar tüm içeriği bir vektöre atıyoruz
    vector<char> buffer((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    cout << CYAN << "[*] Dosya belleğe alındı (" << buffer.size() << " bytes)." << RESET << endl;
    cout << CYAN << "[*] XOR işlemi uygulanıyor..." << RESET << endl;

    // XOR Şifreleme / Şifre Çözme Mantığı
    // Veri ^ Anahtar = Şifreli Veri
    // Şifreli Veri ^ Anahtar = Orijinal Veri
    for (size_t i = 0; i < buffer.size(); i++) {
        buffer[i] ^= key[i % key.length()];
    }

    // Çıktı dosyasını yaz
    ofstream outputFile(outputPath, ios::binary);
    if (!outputFile) {
        cerr << RED << "[!] Hata: Çıktı dosyası oluşturulamadı." << RESET << endl;
        return;
    }

    outputFile.write(buffer.data(), buffer.size());
    outputFile.close();

    cout << GREEN << "[+] İşlem Başarılı! Dosya kaydedildi: " << outputPath << RESET << endl;
}

int main(int argc, char* argv[]) {
    cout << R"(
   ______ _       _                  __    _            _    
  / ____/(_)___  | |__   ___ _ __   / /   | | ___   ___| | __
 | |     | | '_ \| '_ \ / _ \ '__| / /    | |/ _ \ / __| |/ /
 | |___  | | |_) | | | |  __/ |   / /___  | | (_) | (__|   < 
  \____| |_| .__/|_| |_|\___|_|  /_____/  |_|\___/ \___|_|\_\
           |_|                                               
    )" << endl;
    
    if (argc != 4) {
        cout << "Kullanım: ./cipherlock <girdi_dosyasi> <cikti_dosyasi> <anahtar>" << endl;
        cout << "Örnek: ./cipherlock gizli.txt sifreli.lock mysecretkey" << endl;
        return 1;
    }

    string inputPath = argv[1];
    string outputPath = argv[2];
    string key = argv[3];

    processFile(inputPath, outputPath, key);

    return 0;
}
