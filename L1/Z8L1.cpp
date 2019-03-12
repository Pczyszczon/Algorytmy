#include <iostream>

using namespace std;

class Ulamek{
    public:
        Ulamek(int licznik, int mianownik=1): _licznik(licznik), _mianownik(mianownik) {}
        
        Ulamek operator+ (const Ulamek& u){
            return Ulamek(_licznik*u._mianownik+u._licznik*_mianownik, _mianownik*u._mianownik); 
        }
        Ulamek operator- (const Ulamek& u){
            return Ulamek(_licznik*u._mianownik-u._licznik*_mianownik, _mianownik*u._mianownik); 
        }
        Ulamek operator* (const Ulamek& u){
            return Ulamek(_licznik*u._licznik, _mianownik*u._mianownik); 
        }
        Ulamek operator/ (const Ulamek& u){
            return Ulamek(_licznik*u._mianownik, u._licznik*_mianownik); 
        }
    
        friend std::ostream &operator<<(std::ostream &output, const Ulamek& u){
            if (u._licznik == u._mianownik)
                return output << 1;
            else
                return output << u._licznik << "/" << u._mianownik;
        }
        friend std::istream & operator >>(std::istream & input, Ulamek & u){
            cout << "Podaj licznik: ";
            input >> u._licznik;
            cout << "Podaj mianownik: ";
            input >> u._mianownik;
            return input;
        }

    private:
        int _licznik;
        int _mianownik;
};

int main(){
    Ulamek u(1,2);
    Ulamek u2(4,5);
    cout << u+u2 << endl;
    cin >> u2;
    cout << u2 << endl;
    return 0;
}
